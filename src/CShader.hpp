#ifndef _CSHADER_HPP_
#define _CSHADER_HPP_

#include<GL/glew.h>
#include<iostream>

namespace NDormon{
  /**
   * @brief Converts filename to type of shader
   *
   * @param FileName filename with extension
   *
   * @return return GL_VERTEX_SHADER, ..., or 0
   */
  GLenum FileToShaderType(std::string FileName);
  std::string Define(std::string Name);
  std::string Define(std::string Name,unsigned Value);
  std::string Define(std::string Name,int Value);
  std::string Define(std::string Name,float Value);
  std::string Define(std::string Name,std::string Value);




	/**
	 * This class represents shader
	 */
	class CShader
	{
//		private:
    public:
			std::string Text;///<contains shader test
			GLuint ShaderID;///<id of shader
			GLenum Type;///<type of shader (vertex,fragment,geometry,...)
			void CompileShader();///<compile shader
			std::string GetShaderInfo(GLuint ID);///<gets shader info
      void LoadFile(std::string File);///<load file with shader
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
       * @brief Constructor
       *
       * @param FileName Name of file that contains shader
       * @param Defs additional definitions, empty definitions are ommited
       */
      CShader(std::string FileName,std::string Defs);
      /**
       * @brief Constructor
       *
       * @param FileName Name of file that contains shader
       * @param Defs additional definitions, empty definitions are ommited
       * @param Version version of shader, if the version is 0 it is not used
       */
      CShader(std::string FileName,std::string Defs,unsigned Version,std::string Profile);
      /**
       * @brief Constructor
       *
       * @param FileName Name of file that contains shader
       * @param Version version of shader, if the version is 0 it is not used
       */
      CShader(std::string FileName,unsigned Version,std::string Profile);
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
      /**
       * @brief Sets version and profile of shader
       *
       * @param Version version
       * @param Profile profile
       */
      void SetVersion(unsigned Version,std::string Profile);
      /**
       * @brief Appends some definitions after version definition
       *
       * @param Defs string containing definitions
       */
      void AppendAfterVersion(std::string Defs);
      /**
       * @brief Recompiles shader
       */
      void Recompile();
      /**
       * @brief Gets type of shader
       *
       * @return type of shader
       */
      GLenum GetType();
      /**
       * @brief Gets text representation of shader
       *
       * @return text of shader
       */
      std::string GetText();

	};

}

#endif//_CSHADER_HPP_
