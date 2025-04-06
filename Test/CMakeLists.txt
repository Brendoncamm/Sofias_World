cmake_minimum_required(VERSION 3.18)
project(SofiasWorldTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
)
FetchContent_MakeAvailable(SFML)

add_executable(Sofia_Tests 
    Sofia_Tests.cpp
    ../src/theSofia.cpp
)

target_include_directories(Sofia_Tests
    PRIVATE
    ${PROJECT_SOURCE_DIR}/../src
)

target_link_libraries(Sofia_Tests
    PRIVATE
    SFML::Graphics
)
