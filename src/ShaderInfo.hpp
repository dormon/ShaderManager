#ifndef _SHADERINFO_HPP_
#define _SHADERINFO_HPP_

#include<GL/glew.h>
#include<GL/glu.h>
#include<iostream>

/**
 * This function return information about shader object/program
 * @param ShaderObject shader object or shader program
 * @return returns information
 */
std::string GetShaderInfo(GLuint ShaderObject);

/**
 * This function returns information from OpenGL
 * @return returns information
 *
 */
//std::string GetGLError();

#endif//_SHADERINFO_HPP_
