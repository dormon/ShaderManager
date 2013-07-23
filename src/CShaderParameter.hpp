#ifndef _CSHADERPARAMETER_HPP_
#define _CSHADERPARAMETER_HPP_

#include<GL/glew.h>
#include<iostream>

/**
 * @brief This class represents shader parameter
 */
class CShaderParameter
{
	public:
		GLint Location;/// parameter location
		GLenum Type;/// parameter type
		std::string Name;/// parameter name
		GLint Size;/// sizeof parameter
		/**
		 * @brief Constructor
		 *
		 * @param Location parameter location
		 * @param Type parameter type
		 * @param Name parameter name
		 * @param Size parameter Size
		 */
		CShaderParameter(GLint Location,GLenum Type,std::string Name,GLint Size);
		CShaderParameter(){};
};


#endif//_CSHADERPARAMETER_HPP_
