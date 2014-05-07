cmake_minimum_required (VERSION 2.6)
project (ShaderManager)

add_library(ShaderManager STATIC
	src/CShader.cpp
	src/CShaderParameter.cpp
	src/CShaderProgram.cpp
	src/CShaderSubroutine.cpp
	src/CShaderSubroutineUniform.cpp
	)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMake/modules/")

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
	src/CShaderProgramMacro.hpp
	src/CShaderParameter.hpp
	src/CShaderSubroutine.hpp
	src/CShaderSubroutineUniform.hpp
	DESTINATION include/ShaderManager
	)

install(TARGETS ShaderManager
	LIBRARY DESTINATION lib
	ARCHIVE DESTINATION lib
	)
