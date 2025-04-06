#include "ParentEntity.h"
#include <iostream>

ParentEntity::ParentEntity()
{
    std::cout << "ParentEntity constructor called" << std::endl;
}

ParentEntity::~ParentEntity()
{
    std::cout << "ParentEntity destructor called" << std::endl;
}