cmake_minimum_required (VERSION 2.6)
project (ShaderManager)

add_library(ShaderManager STATIC
		src/CShader.cpp
		src/CShaderParameter.cpp
		src/CShaderProgram.cpp
		src/ShaderInfo.cpp
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

find_package(GLU REQUIRED)
if(GLU_FOUND)
	message("GLU found")
	include_directories(${GLU_INCLUDE_DIR})
	target_link_libraries(ShaderManager ${GLU_LIBRARY})
else(GLU_FOUND)
	message("GLU not found")
endif(GLU_FOUND)


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