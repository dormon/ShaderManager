#include"CShaderParameter.hpp"

CShaderParameter::CShaderParameter(
		GLint Location,
		GLenum Type,
		std::string Name,
		GLint Size){
	this->Location=Location;//parameter id
	this->Type=Type;//parameter type
	this->Name=Name;//parameter name
	this->Size=Size;//parameter size
}

