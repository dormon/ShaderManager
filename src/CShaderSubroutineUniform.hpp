#ifndef _CSHADERSUBROUTINEUNIFORM_HPP_
#define _CSHADERSUBROUTINEUNIFORM_HPP_

#include<GL/glew.h>
#include<iostream>

namespace NDormon{
	/**
	 * @brief This class represents shader parameter
	 */
	class CShaderSubroutineUniform
	{
		public:
			GLint Location;///< location of subroutine uniform
			GLint Size;///< size of subroutine uniform array
			GLint NumCompatible;///< number of compatible subroutines
			std::string Name;///<subroutine uniform name
			unsigned Index;///<index into array indices
			/**
			 * @brief Constructor
			 *
			 * @param Location parameter location
			 * @param Type parameter Size
			 * @param Name parameter NumCompatible
			 * @param Size parameter Name
			 */
			CShaderSubroutineUniform(GLint Location,GLint Size,GLint NumCompatible,
					std::string Name,unsigned Index);
			CShaderSubroutineUniform(){};
	};

}


#endif//_CSHADERSUBROUTINEUNIFORM_HPP_
