#include"CShaderSubroutine.hpp"
namespace NDormon{
	CShaderSubroutine::~CShaderSubroutine(){
		delete[]this->Indices;
	}
}

