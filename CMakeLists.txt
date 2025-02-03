cmake_minimum_required(VERSION 3.11)

project(OpenGL-Framework)

file(GLOB APP_SRC "src/App/*.cpp")
file(GLOB CAMERA_SRC "src/Camera/*.cpp")
file(GLOB CLOCK_SRC "src/Clock/*.cpp")
file(GLOB INPUT_SRC "src/Input/*.cpp")
file(GLOB RENDERER_SRC "src/Renderer/*.cpp")
file(GLOB RESOURCEMANAGER_SRC "src/ResourceManager/*.cpp")
file(GLOB SHADER_SRC "src/Shader/*.cpp")
file(GLOB TEXTURE_SRC "src/Texture/*.cpp")
file(GLOB SAMPLE_SRC "src/Sample/*.cpp")

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(vendor/glfw)
include_directories(vendor/glfw/include)

add_subdirectory(vendor/glew/build/cmake)
include_directories(vendor/glew/include)

add_executable(OpenGL-Framework src/main.cpp ${APP_SRC} ${CAMERA_SRC} ${CLOCK_SRC} ${INPUT_SRC} ${RENDERER_SRC} ${RESOURCEMANAGER_SRC} ${SHADER_SRC} ${TEXTURE_SRC} ${SAMPLE_SRC} src/OBJLoader/OBJLoader.h src/OBJLoader/OBJLoader.cpp src/Entity/Entity.h src/Entity/Entity.cpp src/Renderer/RenderInfo.cpp)

include_directories(OpenGL-Framework .)
target_link_libraries(OpenGL-Framework PRIVATE glfw glew opengl32)
