cmake_minimum_required(VERSION 3.28)
project(CMakeSFMLProject LANGUAGES CXX)

#Find python
# Currently this does not work to correctly generate the TextureKeys.h file
# because the python script is not in the same directory as the CMakeLists.txt file
# TODO fix this
find_package(Python3 REQUIRED)

add_custom_command(OUTPUT TextureKeys.h 
    COMMAND ${Python3_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/src/Python/Generate_Textures.py
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/src/Python/Generate_Textures.py
    COMMENT "Generating TextureKeys.h from Generate_Textures.py"
)

add_custom_target(run_codegen 
    DEPENDS TextureKeys.h
)   
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
    src/SpecialItems.cpp
    src/ParentEntity.cpp
    src/TextureManager.cpp)
add_dependencies(Sofias_World run_codegen)

target_compile_features(Sofias_World PRIVATE cxx_std_17)
target_link_libraries(Sofias_World PRIVATE SFML::Graphics)

## Add the test executable  
enable_testing()
add_subdirectory(Test)
