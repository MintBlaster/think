cmake_minimum_required(VERSION 3.28)
project(think)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

# Set paths to SDL2 and SDL2_image
set(SDL2_PATH "C:/Projects/cpp/_Stuff/SDL2-2.30.3/x86_64-w64-mingw32")
set(SDL2_IMAGE_PATH "C:/Projects/cpp/_Stuff/SDL2_image-2.8.2/x86_64-w64-mingw32")

# Find SDL2
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

# Find SDL2_image
find_package(SDL2_image REQUIRED)
include_directories(${SDL2_IMAGE_INCLUDE_DIR}
        include
        include/core
        include/core
        include/utils
        include/game/entities
)

# Add your source files
add_executable(think src/main.cpp
        include/utils/think-lib.h
        include/core/RenderWindow.h
        src/core/RenderWindow.cpp
        include/Game.h
        src/Game.cpp
        src/game/entities/Rocket.cpp
        include/game/entities/Rocket.h
        include/utils/UMath.h
        include/core/Entity.h
        src/core/Entity.cpp
        include/core/EntityManager.h
        src/core/EntityManager.cpp
        include/core/Component.h
        src/core/Component.cpp
        include/core/components/EntityRenderer.h
        src/core/components/EntityRenderer.cpp
        include/core/components/Transform.h
        src/core/Resource.cpp
        include/core/Resource.h
        src/core/resources/Texture.cpp
        include/core/resources/Texture.h
        src/core/ResourceManager.cpp
        include/core/ResourceManager.h
        src/core/ServiceLocator.cpp
        include/core/ServiceLocator.h
        include/utils/UTime.h
)

# Link SDL2 and SDL2_image libraries
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY})
