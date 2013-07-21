cmake_minimum_required (VERSION 2.6)
project (ShaderManager)
add_executable(ShaderManager src/main.cpp)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/modules/")

find_package(SDL REQUIRED)
if(SDL_FOUND)
	message("CMAKE_SOURCE_DIR ${CMAKE_SOURCE_DIR}")
	include_directories(${SDL_INCLUDE_DIR})
	target_link_libraries(ShaderManager ${SDL_LIBRARY})
else(SDL_FOUND)
	message("SDL_ not found")
endif(SDL_FOUND)

find_package(GLEW REQUIRED)
if(GLEW_FOUND)
	include_directories(${GLEW_INCLUDE_DIR})
	target_link_libraries(ShaderManager ${GLEW_LIBRARY})
else(GLEW_FOUND)
	message("GLEW_ not found")
endif(GLEW_FOUND)

