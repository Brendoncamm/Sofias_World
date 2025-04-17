class EnemyPositionSrv
{
    public:
    EnemyPositionSrv();
    ~EnemyPositionSrv();

    struct Position
    {
        int x;
        int y;
    };

    // This function will be used to determine if an enemy should spawn
    // based on the distance between the player and the enemy
    bool shouldSpawnEnemy(Position playerPos, Position enemyPos);
    
    // Used to determine distance between the two positions
    float distanceBetweenPositions(Position playerPos, Position enemyPos);
    private:
    float distanceDifference;

};