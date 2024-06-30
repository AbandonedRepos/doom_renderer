cmake_minimum_required(VERSION 3.16)
project(DoomRenderer)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_INTERPROCEDURAL_OPTIMIZATION TRUE)

add_subdirectory(deps)

file(GLOB_RECURSE EngineSources ${CMAKE_CURRENT_SOURCE_DIR}/src/**.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/**.h)
add_executable(${PROJECT_NAME} ${EngineSources})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/)

find_package(OpenGL REQUIRED)

target_link_libraries(${PROJECT_NAME} PUBLIC OpenGL glm glfw glad assimp)

if(MSVC)
	target_compile_definitions(${PROJECT_NAME} PUBLIC _CRT_SECURE_NO_WARNINGS)
endif()

if(WIN32)
	target_compile_definitions(${PROJECT_NAME} PUBLIC _WIN32) 
endif()

target_compile_definitions(${PROJECT_NAME} PUBLIC RESOURCES_PATH="./resources/")

