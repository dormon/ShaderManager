#include"CShaderSubroutine.hpp"
namespace NDormon{
	CShaderSubroutine::~CShaderSubroutine(){
    if(this->Indices)
		delete[]this->Indices;
	}
  CShaderSubroutine::CShaderSubroutine(){
    this->Indices=NULL;
  }

}

