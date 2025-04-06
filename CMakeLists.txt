cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(Sofias_World 
    src/main.cpp 
    src/theSofia.cpp
    src/MovementInputHandler.cpp
    src/Game.cpp
    src/SpecialItems.cpp)
target_compile_features(Sofias_World PRIVATE cxx_std_17)
target_link_libraries(Sofias_World PRIVATE SFML::Graphics)
