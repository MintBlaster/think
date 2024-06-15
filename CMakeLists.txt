cmake_minimum_required(VERSION 3.28)
project(think)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

set(EXPORT_COMPILE_COMMANDS ON)

# Set paths
set(SDL2_PATH "C:/Projects/cpp/_Stuff/SDL2-2.30.30-VC")
set(SDL2_IMAGE_PATH "C:/Projects/cpp/_Stuff/SDL2_image-2.8.2-VC")
set(GLEW_PATH "C:/Projects/cpp/_Stuff/glew-2.1.0")
set(STB_PATH "C:/Projects/cpp/_Stuff/STB")
set(GLM_PATH "C:/Projects/cpp/_Stuff/glm")

# Enable Debug build
set(CMAKE_BUILD_TYPE Debug)

# Find SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

# Find SDL2_image
find_package(SDL2_image REQUIRED)

# Set GLEW paths
set(GLEW_INCLUDE_DIR "${GLEW_PATH}/include")
set(GLEW_LIB_DIR "${GLEW_PATH}/lib/Release/x64")
set(GLEW_LIBRARY "${GLEW_LIB_DIR}/glew32.lib")

# Find OpenGL
find_package(OpenGL REQUIRED)
include_directories(${OPENGL_INCLUDE_DIRS})

# Include directories
include_directories(${SDL2_IMAGE_INCLUDE_DIR}
        ${GLEW_INCLUDE_DIR}
        ${STB_PATH}
        ${GLM_PATH}
        Engine/include
        Engine/include/core
        Engine/include/utils
        game
        game/public
        game/public/entities
        game/public/components
)

# Collect all .cpp files for the engine
file(GLOB_RECURSE ENGINE_SOURCES "Engine/src/*.cpp")
# Collect all .cpp files for the game, including subdirectories
file(GLOB_RECURSE GAME_SOURCES "game/*.cpp")

# Combine all sources
set(ALL_SOURCES ${ENGINE_SOURCES} ${GAME_SOURCES})

# Add executable
add_executable(think ${ALL_SOURCES})


# Link SDL2, SDL2_image, OpenGL, and GLEW libraries
target_link_libraries(think ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${OPENGL_LIBRARIES} ${GLEW_LIBRARY})

target_compile_options(think PRIVATE -std=c+20)
