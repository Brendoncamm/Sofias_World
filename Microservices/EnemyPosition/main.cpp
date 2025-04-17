#include "EnemyPositionSrv.h"
#include "common/httplib.h"
#include "common/json.hpp"
#include <iostream>

int main()
{
    std::cout << "EnemyPositionSrv main function called" << std::endl;
    EnemyPositionSrv enemyPositionService = EnemyPositionSrv();

    // My intention with the main function is to have to run the server
    // It will take in the information from the client and perform the appropriate actions

    httplib::Server server;
    // Read in the request from the client
    server.Post("/enemy_position", [&](const httplib::Request& req, httplib::Response& res) {
        // Parse the request body
        EnemyPositionSrv::Position playerPos;
        EnemyPositionSrv::Position enemyPos;
        
        std::cout << "Received request: " << req.body << std::endl;
        // Assuming the request body is in JSON format
        try {
            auto json = nlohmann::json::parse(req.body);
            playerPos.x = json["player_x"];
            playerPos.y = json["player_y"];
            enemyPos.x = json["enemy_x"];
            enemyPos.y = json["enemy_y"];
        }
        catch (const std::exception& e) {
            std::cerr << "Error parsing JSON: " << e.what() << std::endl;
            res.status = 400; // Bad Request
            return;
        }

        // Check if the enemy should spawn
        bool shouldSpawn = enemyPositionService.shouldSpawnEnemy(playerPos, enemyPos);
        nlohmann::json response = { {"spawn_enemy", shouldSpawn} };
        res.set_content(response.dump(), "application/json");
        

    });

    std::cout << "Server is running on http://localhost:5000" << std::endl;
    server.listen("localhost", 5000);
}