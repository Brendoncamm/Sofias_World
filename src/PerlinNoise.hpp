#include <vector>
#include <numeric>    // for std::iota
#include <algorithm>  // for std::shuffle
#include <random>
#include <cmath>

// NOTE: This implementation was generated by ChatGPT.
class PerlinNoise {
public:
    // Constructor: creates a permutation vector based on an initial random shuffle.
    PerlinNoise() {
        // Initialize the permutation vector with 0..255
        p.resize(256);
        std::iota(p.begin(), p.end(), 0);

        // Shuffle using a random engine
        std::default_random_engine engine(std::random_device{}());
        std::shuffle(p.begin(), p.end(), engine);

        // Duplicate the permutation vector to avoid overflow during indexing.
        p.insert(p.end(), p.begin(), p.end());
    }

    // Get a noise value in range [0,1] for coordinates x, y, z.
    double noise(double x, double y, double z) const {
        // Find unit cube that contains the point.
        int X = static_cast<int>(std::floor(x)) & 255;
        int Y = static_cast<int>(std::floor(y)) & 255;
        int Z = static_cast<int>(std::floor(z)) & 255;

        // Find relative x, y, z of point in the cube.
        x -= std::floor(x);
        y -= std::floor(y);
        z -= std::floor(z);

        // Compute fade curves for x, y, z.
        double u = fade(x);
        double v = fade(y);
        double w = fade(z);

        // Hash coordinates of the 8 cube corners.
        int A  = p[X] + Y;
        int AA = p[A] + Z;
        int AB = p[A + 1] + Z;
        int B  = p[X + 1] + Y;
        int BA = p[B] + Z;
        int BB = p[B + 1] + Z;

        // Linearly interpolate between gradients of the cube corners.
        double res = lerp(w, 
                        lerp(v, 
                            lerp(u, grad(p[AA], x, y, z), 
                                     grad(p[BA], x - 1, y, z)),
                            lerp(u, grad(p[AB], x, y - 1, z),
                                     grad(p[BB], x - 1, y - 1, z))
                        ),
                        lerp(v,
                            lerp(u, grad(p[AA + 1], x, y, z - 1),
                                     grad(p[BA + 1], x - 1, y, z - 1)),
                            lerp(u, grad(p[AB + 1], x, y - 1, z - 1),
                                     grad(p[BB + 1], x - 1, y - 1, z - 1))
                        )
                    );
        // Scale result to [0, 1]
        return (res + 1.0) / 2.0;
    }

private:
    std::vector<int> p;

    // Fade function: 6t^5 - 15t^4 + 10t^3
    double fade(double t) const {
        return t * t * t * (t * (t * 6 - 15) + 10);
    }

    // Linear interpolation.
    double lerp(double t, double a, double b) const {
        return a + t * (b - a);
    }

    // Gradient function calculates dot product between a pseudorandom gradient vector and the vector from the input coordinate to the cube corner.
    double grad(int hash, double x, double y, double z) const {
        int h = hash & 15;      // Take the hashed value and take the first 4 bits of it (15 == 0b1111)
        double u = h < 8 ? x : y; // If the most significant bit (MSB) of the hash is 0 then use x. Otherwise, use y.
        double v = h < 4 ? y : (h == 12 || h == 14 ? x : z); // Use y if h is less than 4. If h is 12 or 14, use x; otherwise, use z.
        return ((h & 1) == 0 ? u : -u) + ((h & 2) == 0 ? v : -v);
    }
};