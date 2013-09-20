#ifndef _CSHADER_HPP_
#define _CSHADER_HPP_

#include<GL/glew.h>
#include<fstream>

namespace NDormon{

	/**
	 * This class represents shader
	 */
	class CShader
	{
		private:
			std::string Text;///<contains shader test
			GLuint ShaderID;///<id of shader
			GLenum Type;///<type of shader (vertex,fragment,geometry,...)
			void CompileShader();///<compile shader
			std::string GetShaderInfo(GLuint ID);///<gets shader info
		public:
			/**
			 * Constructor
			 * @param Type Type of shader
			 * @param Text Text of shader
			 */
			CShader(GLenum Type,std::string Text);
			/**
			 * Constructor
			 * @param FileName Name of file which contains shader
			 */
			CShader(std::string FileName);
			/**
			 * @brief Destructor
			 */
			~CShader();
			/**
			 * @brief This method return ID of compiled shader
			 *
			 * @return ID of compiled shader
			 */
			GLuint GetShaderID();
	};

}

#endif//_CSHADER_HPP_
