#ifndef _CSHADERSUBROUTINE_HPP_
#define _CSHADERSUBROUTINE_HPP_

#include<GL/glew.h>
#include<iostream>
#include<map>
#include"CShaderSubroutineUniform.hpp"

namespace NDormon{
	/**
	 * @brief This class represents shader parameter
	 */
	class CShaderSubroutine
	{
		public:
			/**
			 * @brief List of subroutines uniforms
			 */
			std::map<std::string,CShaderSubroutineUniform>SubroutineUniformList;
			/**
			 * @brief List of subroutines
			 */
			std::map<std::string,GLuint>SubroutineList;
			GLuint*Indices;///<
			GLsizei NumIndices;///<
			/**
			 * @brief Destructor
			 */
			~CShaderSubroutine();
	};
}


#endif//_CSHADERSUBROUTINE_HPP_
