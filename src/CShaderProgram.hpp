#ifndef _CSHADERPROGRAM_HPP_
#define _CSHADERPROGRAM_HPP_

#include<GL/glew.h>
#include<stdarg.h>
#include<vector>
#include<map>
#include"CShader.hpp"
#include"CShaderParameter.hpp"

/**
 * @brief This class represents shader program
 */
class CShaderProgram
{
	private:
		std::vector<GLuint>ShaderList;///<list of shader object
		std::map<std::string,CShaderParameter>AttributeList;///<list of attributes
		std::map<std::string,CShaderParameter>UniformList;///<list of uniforms
		GLuint ShaderProgramID;///<id of shader program
		void CreateShaderProgram_Prologue();//prologue of creating of shader prg.
		void CreateShaderProgram_Epilogue();//epilogue of creating of shader prg.
		void GetParameterList();
	public:
		/**
		 * Constructor
		 * @param Shader list of shaders
		 * @param Num number of shaders
		 */
		CShaderProgram(CShader**Shader,unsigned Num);
		/**
		 * Constructor
		 * @param Num number of shaders
		 */
		CShaderProgram(unsigned Num,...);
		/**
		 * @brief Constructor
		 *
		 * @param Shader0 shader 0
		 * @param Shader1 shader 1
		 */
		CShaderProgram(std::string Shader0,
				std::string Shader1);
		/**
		 * @brief Constructor
		 *
		 * @param Shader0 shader 0
		 * @param Shader1 shader 1
		 * @param Shader2 shader 2
		 */
		CShaderProgram(std::string Shader0,
				std::string Shader1,
				std::string Shader2);
		/**
		 * @brief Destructor
		 */
		~CShaderProgram();
		/**
		 * @brief This method return ID of linked shader program
		 *
		 * @return ID of linked shader program
		 */
		GLuint GetProgramID();
		/**
		 * @brief Return shader program uniform location
		 *
		 * @param Name name of uniform
		 *
		 * @return returns parameter ID
		 */
		GLint operator[](std::string Name);
		/**
		 * Ziska identifikator atributu
		 * @param AttributeName jmeno atributu
		 * @retunr vracu identifikator atributu
		 */
		GLuint GetAttribute(std::string AttributeName);
		/**
		 * Ziska identifikator uniformni promenne
		 * @param UniformName jmeno uniformni promenne
		 * @retunr vracu identifikator uniformni promenne
		 */
		GLuint GetUniform(std::string UniformName);
		void Use();

		void Set(std::string UniformName,
				GLfloat v0);
		void Set(std::string UniformName,
				GLfloat v0,GLfloat v1);
		void Set(std::string UniformName,
				GLfloat v0,GLfloat v1,GLfloat v2);
		void Set(std::string UniformName,
				GLfloat v0,GLfloat v2,GLfloat v3,GLfloat v4);
		void Set(std::string UniformName,
				GLdouble v0);
		void Set(std::string UniformName,
				GLdouble v0,GLdouble v1);
		void Set(std::string UniformName,
				GLdouble v0,GLdouble v1,GLdouble v2);
		void Set(std::string UniformName,
				GLdouble v0,GLdouble v2,GLdouble v3,GLdouble v4);
		void Set(std::string UniformName,
				GLint v0);
		void Set(std::string UniformName,
				GLint v0,GLint v1);
		void Set(std::string UniformName,
				GLint v0,GLint v1,GLint v2);
		void Set(std::string UniformName,
				GLint v0,GLint v2,GLint v3,GLint v4);
		void Set(std::string UniformName,
				GLuint v0);
		void Set(std::string UniformName,
				GLuint v0,GLuint v1);
		void Set(std::string UniformName,
				GLuint v0,GLuint v1,GLuint v2);
		void Set(std::string UniformName,
				GLuint v0,GLuint v2,GLuint v3,GLuint v4);
		void Set(std::string UniformName,
				GLboolean v0);
		void Set(std::string UniformName,
				GLboolean v0,GLboolean v1);
		void Set(std::string UniformName,
				GLboolean v0,GLboolean v1,GLboolean v2);
		void Set(std::string UniformName,
				GLboolean v0,GLboolean v2,GLboolean v3,GLboolean v4);
		void Set(std::string UniformName,GLsizei Count,GLfloat*Value);
		void Set(std::string UniformName,GLsizei Count,GLdouble*Value);
		void Set(std::string UniformName,GLsizei Count,GLint*Value);
		void Set(std::string UniformName,GLsizei Count,GLuint*Value);
		void Set(std::string UniformName,GLsizei Count,GLboolean*Value);
		void Set(std::string UniformName,GLsizei Count,
				GLboolean Transpose,GLfloat*Value);
		void Set(std::string UniformName,GLsizei Count,
				GLboolean Transpose,GLdouble*Value);
};


#endif//_CSHADERPROGRAM_HPP_
