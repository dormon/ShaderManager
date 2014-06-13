#include "CShader.hpp"

#include<iostream>
#include<stdarg.h>
#include<string>
#include<cstring>
#include<fstream>
#include<sstream>

namespace ShaderManager{

	int FileTypeSwitch(std::string FileName,unsigned NumType,...){
		va_list args;//argumenty
		va_start(args,NumType);//zacatek argumentu
		for(size_t i=0;i<NumType;++i){
			char* ext=(char*)va_arg(args,char*);
			if(FileName.length()-FileName.rfind(ext)==std::strlen(ext)){//nalezl se
				va_end(args);//konec sekvence argumentu
				return i;//vraceni cisla
			}
		}
		va_end(args);//konec sekcence
		return-1;//ani jeden
	}

	unsigned char*ReadWholeFile(int*Len,std::string File){
		std::ifstream f(File.data(),std::ifstream::binary);//otevreme soubor
		if(!f.good())throw std::string("File "+File+" is corrupt");
		f.seekg(0,std::ios::end);//jdeme na konec
		*Len=f.tellg();//tak tu mame delku (pozice hlavy)
		f.seekg(0,std::ios::beg);//navrat na zacatek
		unsigned char*Data=new unsigned char[*Len];//alokace dat
		f.read((char*)Data,*Len);//precteni souboru
		f.close();//zavreme soubor
		return Data;
	}

};

namespace NDormon{
  GLenum FileToShaderType(std::string File){
		switch(ShaderManager::FileTypeSwitch(File,12,//number of extensions
          "vert","vp",  //vertex     shader extension
          "frag","fp",  //fragment   shader extension
          "geom","gp",  //geometry   shader extension
          "cont","cp",  //control    shader extension
          "eval","ep",  //evaluation shader extension
          "comp","mp")){//compute    shader extension
			case 0:
			case 1:return GL_VERTEX_SHADER;//vertex shader
			case 2:
			case 3:return GL_FRAGMENT_SHADER;//fragment shader
			case 4:
			case 5:return GL_GEOMETRY_SHADER;//geometry shader
			case 6:
			case 7:return GL_TESS_CONTROL_SHADER;//control shader
			case 8:
			case 9:return GL_TESS_EVALUATION_SHADER;//evaluation shader
			case 10:
			case 11:return GL_COMPUTE_SHADER;//compute shader
			default:return 0;//unknown
		}
  }
  std::string Define(std::string Name){
    return"#define "+Name+"\n";
  }

  std::string Define(std::string Name,unsigned Value){
    std::stringstream Result;
    Result<<"#define "<<Name<<" "<<Value<<"u\n";
    return Result.str();
  }

  std::string Define(std::string Name,int Value){
    std::stringstream Result;
    Result<<"#define "<<Name<<" "<<Value<<"\n";
    return Result.str();
  }

  std::string Define(std::string Name,float Value){
    std::stringstream Result;
    Result<<"#define "<<Name<<" "<<Value<<"\n";
    return Result.str();
  }
  std::string Define(std::string Name,std::string Value){
    return"#define "+Name+" "+Value+"\n";
  }

  //throw std::string("Wrong file extension for shader");
  void CShader::LoadFile(std::string File){
		int length;//lenght of file in bytes
		char*Buffer=(char*)ShaderManager::ReadWholeFile(&length,File);//read whole file
		this->Text=std::string((char*)Buffer,length);//convert to std::string
		delete[]Buffer;//free buffer data
  }

	CShader::CShader(std::string File){
    this->Type=FileToShaderType(File);
    this->LoadFile(File);
		this->CompileShader();
	}

	CShader::CShader(GLenum type,std::string text){
		this->Text=text;//text
		this->Type=type;//type
		this->CompileShader();
	}

  CShader::CShader(std::string File,std::string Defs){
    this->Type=FileToShaderType(File);
    this->LoadFile(File);
    this->AppendAfterVersion(Defs);
		this->CompileShader();
  }

  CShader::CShader(std::string File,std::string Defs,unsigned Version,std::string Profile){
    this->Type=FileToShaderType(File);
    this->LoadFile(File);
    this->AppendAfterVersion(Defs);
    this->SetVersion(Version,Profile);
    //std::cerr<<"@@@@@@@"<<this->Text<<"@@@@@@"<<std::endl;
		this->CompileShader();
    //std::cerr<<"CompileShader\n";
  }

  CShader::CShader(std::string File,unsigned Version,std::string Profile){
    this->Type=FileToShaderType(File);
    this->LoadFile(File);
    this->SetVersion(Version,Profile);
		this->CompileShader();
  }

	CShader::~CShader(){
		glDeleteShader(this->ShaderID);//deletes a shader
	}

	void CShader::CompileShader(){
		this->ShaderID=glCreateShader(this->Type);//get shader id
		if(!this->ShaderID)//something is wrong
			throw std::string("glCreateShader failed");//+GetGLError());//error message
		GLchar*ptr[1]={(GLchar*)this->Text.data()};//retype
		glShaderSource(this->ShaderID,1,(const GLchar**)ptr,NULL);//load shader text
		glCompileShader(this->ShaderID);//compile shader
		std::string Log=this->GetShaderInfo(this->ShaderID);
		if(!Log.empty())std::cerr<<Log<<std::endl;//print out log
		GLint Status;//status of compilation
		glGetShaderiv(this->ShaderID,GL_COMPILE_STATUS,&Status);//get status
		if(Status==GL_FALSE)//something is wrong
			throw std::string("Shader compilation failed");//+GetGLError());//error message
	}

	std::string CShader::GetShaderInfo(GLuint ID){
		int Len=0;//length of message
		glGetShaderiv(ID,GL_INFO_LOG_LENGTH,&Len);//gets length of message
		if(Len<=1)return"";
		std::string Info(Len,' ');//create string of Len length
		glGetShaderInfoLog(ID,Len,NULL,&Info[0]);//get message
		return Info;//return message
	}

	GLuint CShader::GetShaderID(){
		return this->ShaderID;//id of shader
	}

  void CShader::SetVersion(unsigned Version,std::string Profile){
    if(Version==0)return;
    int Position=0;
    while((Position=this->Text.find("#version",Position))>=0){
      int LineEndPosition=this->Text.find("\n",Position);
      this->Text.erase(Position,LineEndPosition-Position);
    }

	  std::stringstream Result;
    Result<<"#version "<<Version<<" "<<Profile<<"\n";
    Result<<this->Text;
    this->Text=Result.str();
  }

  void CShader::AppendAfterVersion(std::string Defs){
    if(Defs=="")return;
    int VersionPosition=0;
    int LineEndPosition=0;
    VersionPosition=this->Text.find("#version");
    LineEndPosition=this->Text.find("\n",VersionPosition);
    this->Text.insert(LineEndPosition+1,Defs);
  }

  void CShader::Recompile(){
    glDeleteShader(this->ShaderID);
    this->CompileShader();
  }
  
  GLenum CShader::GetType(){
    return this->Type;
  }

  std::string CShader::GetText(){
    return this->Text;
  }

}
