#include "EnemyPositionSrv.h"
#include <cmath>
#include <iostream>

EnemyPositionSrv::EnemyPositionSrv() : distanceDifference(30.f)
{
    std::cout << "EnemyPositionSrv constructor called" << std::endl;
}

EnemyPositionSrv::~EnemyPositionSrv()
{
    std::cout << "EnemyPositionSrv destructor called" << std::endl;
}

bool EnemyPositionSrv::shouldSpawnEnemy(Position playerPos, Position enemyPos)
{
    if (distanceBetweenPositions(playerPos, enemyPos) < distanceDifference)
    {
        std::cout << "Enemy should spawn" << std::endl;
        return true;
    }
    else
    {
        std::cout << "Enemy should not spawn" << std::endl;
        return false;
    }
}

float EnemyPositionSrv::distanceBetweenPositions(Position playerPos, Position enemyPos)
{
    // Calculate the distance between the two positions
    // Euclidean distance formula
    // d = sqrt((x2 - x1)^2 + (y2 - y1)^2)
    // where (x1, y1) is the player's position and (x2, y2) is the enemy's position
    float dx = playerPos.x - enemyPos.x;
    float dy = playerPos.y - enemyPos.y;
    return std::sqrt(dx * dx + dy * dy);
}