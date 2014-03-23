#ifndef _CSHADERPROGRAM_HPP_
#define _CSHADERPROGRAM_HPP_

#include<GL/glew.h>
#include<stdarg.h>
#include<vector>
#include<map>
#include"CShader.hpp"
#include"CShaderParameter.hpp"
#include"CShaderSubroutine.hpp"
#include"CShaderProgramMacro.hpp"

namespace NDormon{

	/**
	 * @brief This class represents shader program
	 */
	class CShaderProgram
	{
		private:
			std::vector<GLuint>ShaderList;///<list of shader object
			std::map<std::string,CShaderParameter>AttributeList;///<list of attributes
			std::map<std::string,CShaderParameter>UniformList;///<list of uniforms
			CShaderSubroutine Subroutines[6];///subroutines in shaders
			GLuint ShaderProgramID;///<id of shader program
			void CreateShaderProgram_Prologue();///<prologue of creating of shader prg.
			void CreateShaderProgram_Epilogue();///<epilogue of creating of shader prg.
			void GetParameterList();///<obtain shader parameters
			void GetSubroutineUniformList();///<obtain shader subroutines
			std::string GetProgramInfo(GLuint ID);///<obtain program info log
		public:
			GLint WorkGroupSize[3];///< work group size
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
			 */
			CShaderProgram(std::string Shader0);
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
			 * @brief Constructor
			 *
			 * @param Shader0 shader 0
			 * @param Shader1 shader 1
			 * @param Shader2 shader 2
			 * @param Shader3 shader 3
			 */
			CShaderProgram(std::string Shader0,
					std::string Shader1,
					std::string Shader2,
					std::string Shader3);
			/**
			 * @brief Constructor
			 *
			 * @param Shader0 shader 0
			 * @param Shader1 shader 1
			 * @param Shader2 shader 2
			 * @param Shader3 shader 3
			 * @param Shader4 shader 4
			 */
			CShaderProgram(std::string Shader0,
					std::string Shader1,
					std::string Shader2,
					std::string Shader3,
					std::string Shader4);
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
			 * @return vracu identifikator atributu
			 */
			GLuint GetAttribute(std::string AttributeName);
			/**
			 * @brief Returns attribute type
			 *
			 * @param AttributeName attribute name
			 *
			 * @return type of attribute
			 */
			GLenum GetAttributeType(std::string AttributeName);
			/**
			 * @brief Returns size of attribute's array
			 *
			 * @param AttributeName attribute name
			 *
			 * @return size of attribute's array
			 */
			GLint GetAttributeSize(std::string AttributeName);
			/**
			 * Ziska identifikator uniformni promenne
			 * @param UniformName jmeno uniformni promenne
			 * @return vracu identifikator uniformni promenne
			 */
			GLuint GetUniform(std::string UniformName);
			/**
			 * @brief Returns uniform type
			 *
			 * @param UniformName uniform name
			 *
			 * @return type of uniform
			 */
			GLenum GetUniformType(std::string UniformName);
			/**
			 * @brief Returns size of uniform's array
			 *
			 * @param UniformName uniform name
			 *
			 * @return size of uniform's array
			 */
			GLint GetUniformSize(std::string UniformName);
			/**
			 * @brief Sets this shader as active
			 */
			void Use();
			/**
			 * @brief Sets subroutine with name SubroutineName as active in Uniform
			 *
			 * @param ShaderType type of shader
			 * @param Uniform uniform name
			 * @param SubroutineName subroutine name
			 */
			void SetSubroutine(GLenum ShaderType,std::string Uniform,
					unsigned OffSet,std::string SubroutineName);

			DEFDEFFCE(1,f)
			DEFDEFFCE(2,f)
			DEFDEFFCE(3,f)
			DEFDEFFCE(4,f)
			DEFDEFFCE(1,d)
			DEFDEFFCE(2,d)
			DEFDEFFCE(3,d)
			DEFDEFFCE(4,d)
			DEFDEFFCE(1,i)
			DEFDEFFCE(2,i)
			DEFDEFFCE(3,i)
			DEFDEFFCE(4,i)
			DEFDEFFCE(1,ui)
			DEFDEFFCE(2,ui)
			DEFDEFFCE(3,ui)
			DEFDEFFCE(4,ui)
			DEFDEFFCE(1,boolean)
			DEFDEFFCE(2,boolean)
			DEFDEFFCE(3,boolean)
			DEFDEFFCE(4,boolean)
			DEFDEFFCEV(f)
			DEFDEFFCEV(d)
			DEFDEFFCEV(i)
			DEFDEFFCEV(ui)
			DEFDEFFCEV(boolean)



			/*
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
			void Set(std::string UniformName,GLsizei Count,GLboolean*Value);*/
			void Set(std::string UniformName,GLsizei Count,
					GLboolean Transpose,GLfloat*Value);
			void Set(std::string UniformName,GLsizei Count,
					GLboolean Transpose,GLdouble*Value);
	};
	/**
	 * @brief Function converts complex type (GL_FLOAT_VEC3 to GL_FLOAT)
	 *
	 * @param Type OpenGL Type GL_FLOAT_VEC2, ...
	 *
	 * @return GL_FLOAT, ...
	 */
	GLenum ComplexTypeToSimpleType(GLenum Type);

	/**
	 * @brief Function converts complex type (GL_FLOAT_VEC3 to 3)
	 *
	 * @param Type OpenGL Type GL_FLOAT_VEC2, ...
	 *
	 * @return 2, ...
	 */
	GLint ComplexTypeToSize(GLenum Type);
}

#endif//_CSHADERPROGRAM_HPP_
