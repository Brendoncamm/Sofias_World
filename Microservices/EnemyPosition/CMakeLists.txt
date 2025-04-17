cmake_minimum_required(VERSION 3.10)
get_filename_component(PROJECT_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../.." ABSOLUTE)
# Project name and version
project(EnemyPositionSrv VERSION 1.0)

# Use C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(EnemyPositionSrv
    EnemyPositionSrv.cpp
    main.cpp
)
target_include_directories(EnemyPositionSrv 
    PRIVATE
    ${PROJECT_ROOT})

# Link pthreads if needed
find_package(Threads REQUIRED)
target_link_libraries(EnemyPositionSrv PRIVATE Threads::Threads)