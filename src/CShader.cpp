#include "CShader.hpp"

#include"ShaderInfo.hpp"
#include<stdarg.h>
#include<string.h>

namespace ShaderManager{

int FileTypeSwitch(std::string FileName,unsigned NumType,...){
	va_list args;//argumenty
	va_start(args,NumType);//zacatek argumentu
	for(size_t i=0;i<NumType;++i){
		char* ext=(char*)va_arg(args,char*);
		if(FileName.length()-FileName.rfind(ext)==strlen(ext)){//nalezl se
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


NDormon::CShader::CShader(GLenum type,std::string text){
	this->Text=text;//text
	this->Type=type;//type
	this->CompileShader();
}

NDormon::CShader::CShader(std::string File){
	int length;//lenght of file in bytes
	char*Buffer=(char*)ShaderManager::ReadWholeFile(&length,File);//read whole file
	this->Text=std::string((char*)Buffer,length);//convert to std::string
	switch(ShaderManager::FileTypeSwitch(File,12,"vert","vp","frag","fp","geom","gp","cont","cp","eval","ep","comp","mp")){//type
		case 0:
		case 1:this->Type=GL_VERTEX_SHADER;break;//vertex shader
		case 2:
		case 3:this->Type=GL_FRAGMENT_SHADER;break;//fragment shader
		case 4:
		case 5:this->Type=GL_GEOMETRY_SHADER;break;//geometry shader
		case 6:
		case 7:this->Type=GL_TESS_CONTROL_SHADER;break;//control shader
		case 8:
		case 9:this->Type=GL_TESS_EVALUATION_SHADER;break;//evaluation shader
		case 10:
		case 11:this->Type=GL_COMPUTE_SHADER;break;
		default:throw std::string("Wrong file extension for shader");break;//unknown
	}
	delete[]Buffer;//free buffer data
	this->CompileShader();
}

NDormon::CShader::~CShader(){
	glDeleteShader(this->ShaderID);//deletes a shader
}

void NDormon::CShader::CompileShader(){
	this->ShaderID=glCreateShader(this->Type);//get shader id
	if(glGetError()!=GL_NO_ERROR)std::cerr<<"glCreateShader"<<std::endl;
	if(!this->ShaderID)//something is wrong
		throw std::string("glCreateShader failed");//+GetGLError());//error message
	GLchar*ptr[1]={(GLchar*)this->Text.data()};//retype
	glShaderSource(this->ShaderID,1,(const GLchar**)ptr,NULL);//load shader text
	if(glGetError()!=GL_NO_ERROR)std::cerr<<"glShaderSource"<<std::endl;
	glCompileShader(this->ShaderID);//compile shader
	if(glGetError()!=GL_NO_ERROR)std::cerr<<"glCompileShader"<<std::endl;
	std::string Log=GetShaderInfo(this->ShaderID);
	if(!Log.empty())std::cout<<Log<<std::endl;//print out log
	GLint Status;//status of compilation
	glGetShaderiv(this->ShaderID,GL_COMPILE_STATUS,&Status);//get status
	if(glGetError()!=GL_NO_ERROR)std::cerr<<"glGetShaderiv"<<std::endl;
	if(Status==GL_FALSE)//something is wrong
		throw std::string("Shader compilation failed");//+GetGLError());//error message
}

GLuint NDormon::CShader::GetShaderID(){
	return this->ShaderID;//id of shader
}
