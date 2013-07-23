#include"ShaderInfo.hpp"

std::string GetShaderInfo(GLuint ID){
	int Len=0;//length of message
	glGetShaderiv(ID,GL_INFO_LOG_LENGTH,&Len);//gets length of message
	if(Len<=1)return"";
	std::string Info(Len,' ');//create string of Len length
	glGetShaderInfoLog(ID,Len,NULL,&Info[0]);//get message
	return Info;//return message
}

/*
std::string GetGLError(){
	GLuint Error=glGetError();//GL error
	if(Error!=GL_NO_ERROR)//is there an error
		return " "+std::string((char*)gluErrorString(Error));//return message
	return "";//return empty strinng
}
*/
