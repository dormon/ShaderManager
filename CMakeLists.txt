cmake_minimum_required (VERSION 2.6)
project (ShaderManager)

add_library(ShaderManager STATIC
	src/CShader.cpp
	src/CShaderParameter.cpp
	src/CShaderProgram.cpp
	)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/modules/")

find_package(SDL REQUIRED)
if(SDL_FOUND)
	message("SDL found")
	include_directories(${SDL_INCLUDE_DIR})
	target_link_libraries(ShaderManager ${SDL_LIBRARY})
else(SDL_FOUND)
	message("SDL not found")
endif(SDL_FOUND)

find_package(GLEW REQUIRED)
if(GLEW_FOUND)
	message("GLEW found")
	include_directories(${GLEW_INCLUDE_DIR})
	target_link_libraries(ShaderManager ${GLEW_LIBRARY})
else(GLEW_FOUND)
	message("GLEW not found")
endif(GLEW_FOUND)

#set(ShaderManager_LIB_NAME ShaderManager)

install(FILES
	src/CShader.hpp
	src/CShaderProgram.hpp
	src/CShaderParameter.hpp
	DESTINATION include/ShaderManager
	)

install(TARGETS ShaderManager
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	)
