#include"CShaderSubroutineUniform.hpp"

namespace NDormon{
	CShaderSubroutineUniform::CShaderSubroutineUniform(
			GLint Location,
			GLint Size,
			GLint NumCompatible,
			std::string Name,
			unsigned Index){
		this->Location=Location;//parameter id
		this->Size=Size;
		this->NumCompatible=NumCompatible;
		this->Name=Name;
		this->Index=Index;
	}
}

