cmake_minimum_required(VERSION 3.11)

project(OpenGL-Framework)


file(GLOB APP_SRC "App/*.cpp")
file(GLOB CAMERA_SRC "Camera/*.cpp")
file(GLOB CLOCK_SRC "Clock/*.cpp")
file(GLOB INPUT_SRC "Input/*.cpp")
file(GLOB RENDERER_SRC "Renderer/*.cpp")
file(GLOB RESOURCEMANAGER_SRC "ResourceManager/*.cpp")
file(GLOB SHADER_SRC "Shader/*.cpp")
file(GLOB TEXTURE_SRC "Texture/*.cpp")


add_executable(OpenGL-Framework main.cpp ${APP_SRC} ${CAMERA_SRC} ${CLOCK_SRC} ${INPUT_SRC} ${RENDERER_SRC} ${RESOURCEMANAGER_SRC} ${SHADER_SRC} ${TEXTURE_SRC} Sample/sample_triangle.h Sample/sample_triangle.cpp)


include_directories(OpenGL-Framework . C:/Users/milos/Lib)
target_link_libraries(OpenGL-Framework PRIVATE -lglfw3 -lglew32 -lopengl32)
