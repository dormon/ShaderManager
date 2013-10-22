#include"CShaderProgram.hpp"

namespace NDormon{

	void CShaderProgram::CreateShaderProgram_Prologue(){
		this->ShaderProgramID=glCreateProgram();//creates a shader program
		if(!this->ShaderProgramID)//something is wrong
			throw std::string("glCreateProgram failed");//+GetGLError());//error message
		//this->AttributeList=new std::map<std::string,CShaderParameter>();
		//this->UniformList=new std::map<std::string,int>();
	}

	void CShaderProgram::CreateShaderProgram_Epilogue(){
		glLinkProgram(this->ShaderProgramID);//link shader program
		std::cerr<<this->GetProgramInfo(this->ShaderProgramID);
		int Status;//status of linking
		glGetProgramiv(this->ShaderProgramID,GL_LINK_STATUS,&Status);//status
		if(Status==GL_FALSE)//something is wrong
			throw std::string("Shader linking failed");//+GetGLError());//error message
		this->GetParameterList();//get list of shader program parameter
		this->GetSubroutineUniformList();
		//std::cerr<<"DORMONA"<<std::endl;
		//glGetProgramiv(this->ShaderProgramID,GL_COMPUTE_WORK_GROUP_SIZE,
		//		this->WorkGroupSize);
		//std::cerr<<"DORMONB"<<std::endl;
	}

	void CShaderProgram::GetParameterList(){
		void(*GetActive[2])(GLuint,GLuint,GLsizei,GLsizei*,GLint*,GLenum*,GLchar*)={
			glGetActiveAttrib,glGetActiveUniform};
		GLint(*GetLocation[2])(GLuint,const GLchar*)={
			glGetAttribLocation,glGetUniformLocation};
		GLenum Active[2]={
			GL_ACTIVE_ATTRIBUTES,GL_ACTIVE_UNIFORMS};
		GLenum MaxLenght[2]={
			GL_ACTIVE_ATTRIBUTE_MAX_LENGTH,GL_ACTIVE_UNIFORM_MAX_LENGTH};
		for(int t=0;t<2;++t){//loop over set of types {attribute,uniform}
			GLint Num;//number of active parameter
			glGetProgramiv(this->ShaderProgramID,Active[t],&Num);//number
			if(!Num)continue;//there are no active parameters
			GLint BufLen;//length of the longest attribute name
			glGetProgramiv(this->ShaderProgramID,MaxLenght[t],&BufLen);
			char*Buffer=new char[BufLen+1];//alocate buffer
			for(GLint i=0;i<Num;++i){//loop over active parameter
				GLenum Type;//type of parameter
				GLint Size;//size of parameter
				std::string Name;//name of parameter
				GLint Location;//location of parameter
				GLsizei Length;
				GetActive[t](this->ShaderProgramID,i,BufLen,&Length,&Size,&Type,Buffer);
				if(Size>1)Buffer[Length-3]='\0';//get rid of [0] part
				Location=GetLocation[t](this->ShaderProgramID,Buffer);//location
				Name=std::string(Buffer);//convert buffer to string
				//std::cerr<<"Name: "<<Name<<std::endl;
				CShaderParameter Param=CShaderParameter(Location,Type,Name,Size);//param
				if(t==0)this->AttributeList.insert(
						std::pair<std::string,CShaderParameter>(Name,Param));
				else this->UniformList.insert(
						std::pair<std::string,CShaderParameter>(Name,Param));
			}
			delete[]Buffer;//free buffer
		}
	}
	void CShaderProgram::GetSubroutineUniformList(){
		GLenum ShaderType[]={
			GL_VERTEX_SHADER,
			GL_TESS_CONTROL_SHADER,
			GL_TESS_EVALUATION_SHADER,
			GL_GEOMETRY_SHADER,
			GL_FRAGMENT_SHADER,
			GL_COMPUTE_SHADER
		};
		for(int i=0;i<6;++i){//loop over shader types
			GLint NumSubroutines;//number of subroutines in this shader
			GLsizei MaxSubroutineNameSize;//max legth of name of subroutine
			glGetProgramStageiv(this->ShaderProgramID,ShaderType[i],//get number of sub.
					GL_ACTIVE_SUBROUTINES,&NumSubroutines);
			if(NumSubroutines>0){//there are subroutines
				glGetProgramStageiv(this->ShaderProgramID,ShaderType[i],//max lenght
						GL_ACTIVE_SUBROUTINE_MAX_LENGTH,&MaxSubroutineNameSize);
				char*BufferName=new char[MaxSubroutineNameSize];//allocate buffer

				for(int sub=0;sub<NumSubroutines;++sub){//loop over subroutines
					glGetActiveSubroutineName(this->ShaderProgramID,ShaderType[i],sub,
							MaxSubroutineNameSize,NULL,BufferName);//obtain name of subroutine
					GLuint Location=glGetSubroutineIndex(this->ShaderProgramID,
							ShaderType[i],BufferName);//obtain index of subroutine
					std::string Name=std::string(BufferName);//convert buffer to string
					this->Subroutines[i].SubroutineList.insert(//insert subroutine
							std::pair<std::string,GLuint>(Name,Location));
				}
				delete[]BufferName;//free buffer
			}

			GLint NumSubroutineUniforms;//number of subroutine uniforms
			GLint MaxSubroutineUniformNameSize;//max legth of subroutine uniforms

			glGetProgramStageiv(this->ShaderProgramID,ShaderType[i],//get number
					GL_ACTIVE_SUBROUTINE_UNIFORMS,&NumSubroutineUniforms);
			if(NumSubroutineUniforms){//there are subroutine uniforms
				unsigned ActIndex=0;
				glGetProgramStageiv(this->ShaderProgramID,ShaderType[i],//get lenght
						GL_ACTIVE_SUBROUTINE_UNIFORM_MAX_LENGTH,&MaxSubroutineUniformNameSize);
				char*BufferName=new char[MaxSubroutineNameSize];//allocate buffer
				for(int sub=0;sub<NumSubroutineUniforms;++sub){
					GLint Size;
					glGetActiveSubroutineUniformiv(this->ShaderProgramID,ShaderType[i],sub,
							GL_UNIFORM_SIZE,&Size);
					GLsizei Length;
					glGetActiveSubroutineUniformName(this->ShaderProgramID,ShaderType[i],sub,
							MaxSubroutineUniformNameSize,&Length,BufferName);//obtain name
					if(Size>1)BufferName[Length-3]='\0';
					std::string Name=std::string(BufferName);
					GLint NumCompatible;
					glGetActiveSubroutineUniformiv(this->ShaderProgramID,ShaderType[i],sub,
							GL_NUM_COMPATIBLE_SUBROUTINES,&NumCompatible);
					GLuint Location;
					Location=glGetSubroutineUniformLocation(this->ShaderProgramID,
							ShaderType[i],BufferName);
					CShaderSubroutineUniform ShaderSubroutineUniform=
						CShaderSubroutineUniform(Location,Size,NumCompatible,Name,ActIndex);
					ActIndex+=Size;
					this->Subroutines[i].SubroutineUniformList.insert(
							std::pair<std::string,CShaderSubroutineUniform>(Name,ShaderSubroutineUniform));
				}
				delete[]BufferName;//free buffer
				this->Subroutines[i].NumIndices=ActIndex;
				this->Subroutines[i].Indices=new GLuint[this->Subroutines[i].NumIndices];
				for(GLsizei ind=0;ind<this->Subroutines[i].NumIndices;++ind)
					this->Subroutines[i].Indices[ind]=0;
			}
		}
	}
	void CShaderProgram::SetSubroutine(GLenum ShaderType,std::string Uniform,unsigned OffSet,
					std::string SubroutineName){
		int WH=0;
		switch(ShaderType){
			case GL_VERTEX_SHADER:WH=0;break;
			case GL_TESS_CONTROL_SHADER:WH=1;break;
			case GL_TESS_EVALUATION_SHADER:WH=2;break;
			case GL_GEOMETRY_SHADER:WH=3;break;
			case GL_FRAGMENT_SHADER:WH=4;break;
			case GL_COMPUTE_SHADER:WH=5;break;
		}
		this->Subroutines[WH].Indices[
			this->Subroutines[WH].SubroutineUniformList[Uniform].Index+OffSet
		]=this->Subroutines[WH].SubroutineList[SubroutineName];
		glUniformSubroutinesuiv(ShaderType,
				this->Subroutines[WH].NumIndices,
				this->Subroutines[WH].Indices);
	}


	std::string CShaderProgram::GetProgramInfo(GLuint ID){
		int Len=0;//length of message
		glGetProgramiv(ID,GL_INFO_LOG_LENGTH,&Len);//gets length of message
		if(Len<=1)return"";
		std::string Info(Len,' ');//create string of Len length
		glGetProgramInfoLog(ID,Len,NULL,&Info[0]);//get message
		return Info;//return message
	}

	CShaderProgram::CShaderProgram(std::string Shader0){
		this->CreateShaderProgram_Prologue();
		CShader*S0=new CShader(Shader0);
		glAttachShader(this->ShaderProgramID,S0->GetShaderID());
		this->ShaderList.push_back(S0->GetShaderID());
		this->CreateShaderProgram_Epilogue();
		delete S0;
	}

	CShaderProgram::CShaderProgram(std::string Shader0,std::string Shader1){
		this->CreateShaderProgram_Prologue();
		CShader*S0=new CShader(Shader0);
		CShader*S1=new CShader(Shader1);
		glAttachShader(this->ShaderProgramID,S0->GetShaderID());
		glAttachShader(this->ShaderProgramID,S1->GetShaderID());
		this->ShaderList.push_back(S0->GetShaderID());
		this->ShaderList.push_back(S1->GetShaderID());
		this->CreateShaderProgram_Epilogue();
		delete S0;
		delete S1;
	}

	CShaderProgram::CShaderProgram(
			std::string Shader0,
			std::string Shader1,
			std::string Shader2){

		this->CreateShaderProgram_Prologue();
		CShader*S0;
		CShader*S1;
		CShader*S2;

		try{
			S0=new CShader(Shader0);
			S1=new CShader(Shader1);
			S2=new CShader(Shader2);
		}catch(std::string&e){
			std::cerr<<e<<std::endl;
		}

		glAttachShader(this->ShaderProgramID,S0->GetShaderID());
		glAttachShader(this->ShaderProgramID,S1->GetShaderID());
		glAttachShader(this->ShaderProgramID,S2->GetShaderID());
		this->ShaderList.push_back(S0->GetShaderID());
		this->ShaderList.push_back(S1->GetShaderID());
		this->ShaderList.push_back(S2->GetShaderID());
		this->CreateShaderProgram_Epilogue();
		delete S0;
		delete S1;
		delete S2;
	}

	CShaderProgram::CShaderProgram(
			std::string Shader0,
			std::string Shader1,
			std::string Shader2,
			std::string Shader3){

		this->CreateShaderProgram_Prologue();
		CShader*S0;
		CShader*S1;
		CShader*S2;
		CShader*S3;

		try{
			S0=new CShader(Shader0);
			S1=new CShader(Shader1);
			S2=new CShader(Shader2);
			S3=new CShader(Shader3);
		}catch(std::string&e){
			std::cerr<<e<<std::endl;
		}

		glAttachShader(this->ShaderProgramID,S0->GetShaderID());
		glAttachShader(this->ShaderProgramID,S1->GetShaderID());
		glAttachShader(this->ShaderProgramID,S2->GetShaderID());
		glAttachShader(this->ShaderProgramID,S3->GetShaderID());
		this->ShaderList.push_back(S0->GetShaderID());
		this->ShaderList.push_back(S1->GetShaderID());
		this->ShaderList.push_back(S2->GetShaderID());
		this->ShaderList.push_back(S3->GetShaderID());
		this->CreateShaderProgram_Epilogue();
		delete S0;
		delete S1;
		delete S2;
		delete S3;
	}

	CShaderProgram::CShaderProgram(
			std::string Shader0,
			std::string Shader1,
			std::string Shader2,
			std::string Shader3,
			std::string Shader4){

		this->CreateShaderProgram_Prologue();
		CShader*S0;
		CShader*S1;
		CShader*S2;
		CShader*S3;
		CShader*S4;

		try{
			S0=new CShader(Shader0);
			S1=new CShader(Shader1);
			S2=new CShader(Shader2);
			S3=new CShader(Shader3);
			S4=new CShader(Shader4);
		}catch(std::string&e){
			std::cerr<<e<<std::endl;
		}

		glAttachShader(this->ShaderProgramID,S0->GetShaderID());
		glAttachShader(this->ShaderProgramID,S1->GetShaderID());
		glAttachShader(this->ShaderProgramID,S2->GetShaderID());
		glAttachShader(this->ShaderProgramID,S3->GetShaderID());
		glAttachShader(this->ShaderProgramID,S4->GetShaderID());
		this->ShaderList.push_back(S0->GetShaderID());
		this->ShaderList.push_back(S1->GetShaderID());
		this->ShaderList.push_back(S2->GetShaderID());
		this->ShaderList.push_back(S3->GetShaderID());
		this->ShaderList.push_back(S4->GetShaderID());
		this->CreateShaderProgram_Epilogue();
		delete S0;
		delete S1;
		delete S2;
		delete S3;
		delete S4;
	}


	CShaderProgram::CShaderProgram(unsigned Num,...){
		this->CreateShaderProgram_Prologue();//prologue of creating of shader prg.
		va_list args;//arguments
		va_start(args,Num);//start point of arguments
		for(size_t i=0;i<Num;++i){//loop over arguments
			GLuint ShaderID=((CShader*)va_arg(args,CShader*))->GetShaderID();//ID
			glAttachShader(//attach shader object to shader program
					this->ShaderProgramID,//shader program
					ShaderID);//shader object id
			this->ShaderList.push_back(ShaderID);//insert shader object to list
		}
		va_end(args);//end point of arguments
		this->CreateShaderProgram_Epilogue();//epilogue of creating of shader prg.
	}

	CShaderProgram::CShaderProgram(CShader**Shader,unsigned Num){
		this->CreateShaderProgram_Prologue();//prologue of creating of shader prg.
		for(unsigned i=0;i<Num;++i){//loop over shaders
			GLuint ShaderID=Shader[i]->GetShaderID();//shader object ID
			glAttachShader(//attach shader object to shader program
					this->ShaderProgramID,//shader program
					ShaderID);//shader object
			this->ShaderList.push_back(ShaderID);//inser shdaer object to list
		}
		this->CreateShaderProgram_Epilogue();//epilogue of creating of shader prg.
	}

	CShaderProgram::~CShaderProgram(){
		for(int i=0;i<this->ShaderList.size();++i)//loop over shader objects
			glDetachShader(this->ShaderProgramID,this->ShaderList[i]);//detach shader
		glDeleteProgram(this->ShaderProgramID);//deletes shader program
		this->ShaderList.clear();//clear list of shader object
		//delete this->AttributeList;
		//delete this->UniformList;
	}

	GLuint CShaderProgram::GetProgramID(){
		return this->ShaderProgramID;//returns shader program id
	}

	GLint CShaderProgram::operator[](std::string Name){
		return this->UniformList[Name].Location;//uniform id
	}

	GLuint CShaderProgram::GetAttribute(std::string AttributeName){
		return glGetAttribLocation(this->ShaderProgramID,AttributeName.data());
	}

	GLuint CShaderProgram::GetUniform(std::string UniformName){
		return glGetUniformLocation(this->ShaderProgramID,UniformName.data());
	}

	void CShaderProgram::Use(){
		glUseProgram(this->ShaderProgramID);
	}
	DEFFCE(1,f)
	DEFFCE(2,f)
	DEFFCE(3,f)
	DEFFCE(4,f)
	DEFFCE(1,d)
	DEFFCE(2,d)
	DEFFCE(3,d)
	DEFFCE(4,d)
	DEFFCE(1,i)
	DEFFCE(2,i)
	DEFFCE(3,i)
	DEFFCE(4,i)
	DEFFCE(1,ui)
	DEFFCE(2,ui)
	DEFFCE(3,ui)
	DEFFCE(4,ui)
	DEFFCE(1,boolean)
	DEFFCE(2,boolean)
	DEFFCE(3,boolean)
	DEFFCE(4,boolean)
	DEFFCEV(f)
	DEFFCEV(d)
	DEFFCEV(i)
	DEFFCEV(ui)
	DEFFCEV(boolean)

/*
	void CShaderProgram::Set(
			std::string UniformName,
			GLfloat v0){
		glUniform1f(this->UniformList[UniformName].Location,v0);
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLfloat v0,
			GLfloat v1){
		glUniform2f(this->UniformList[UniformName].Location,v0,v1);
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLfloat v0,
			GLfloat v1,
			GLfloat v2){
		glUniform3f(this->UniformList[UniformName].Location,v0,v1,v2);
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLfloat v0,
			GLfloat v1,
			GLfloat v2,
			GLfloat v3){
		glUniform4f(this->UniformList[UniformName].Location,v0,v1,v2,v3);
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLdouble v0){
		glUniform1d(this->UniformList[UniformName].Location,v0);
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLdouble v0,
			GLdouble v1){
		glUniform2d(this->UniformList[UniformName].Location,v0,v1);
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLdouble v0,
			GLdouble v1,
			GLdouble v2){
		glUniform3d(this->UniformList[UniformName].Location,v0,v1,v2);
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLdouble v0,
			GLdouble v1,
			GLdouble v2,
			GLdouble v3){
		glUniform4d(this->UniformList[UniformName].Location,v0,v1,v2,v3);
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLint v0){
		glUniform1i(this->UniformList[UniformName].Location,v0);
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLint v0,
			GLint v1){
		glUniform2i(this->UniformList[UniformName].Location,v0,v1);
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLint v0,
			GLint v1,
			GLint v2){
		glUniform3i(this->UniformList[UniformName].Location,v0,v1,v2);
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLint v0,
			GLint v1,
			GLint v2,
			GLint v3){
		glUniform4i(this->UniformList[UniformName].Location,v0,v1,v2,v3);
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLuint v0){
		glUniform1ui(this->UniformList[UniformName].Location,v0);
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLuint v0,
			GLuint v1){
		glUniform2ui(this->UniformList[UniformName].Location,v0,v1);
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLuint v0,
			GLuint v1,
			GLuint v2){
		glUniform3ui(this->UniformList[UniformName].Location,v0,v1,v2);
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLuint v0,
			GLuint v1,
			GLuint v2,
			GLuint v3){
		glUniform4ui(this->UniformList[UniformName].Location,v0,v1,v2,v3);
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLboolean v0){
		glUniform1i(this->UniformList[UniformName].Location,v0);
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLboolean v0,
			GLboolean v1){
		glUniform2i(this->UniformList[UniformName].Location,v0,v1);
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLboolean v0,
			GLboolean v1,
			GLboolean v2){
		glUniform3i(this->UniformList[UniformName].Location,v0,v1,v2);
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLboolean v0,
			GLboolean v1,
			GLboolean v2,
			GLboolean v3){
		glUniform4i(this->UniformList[UniformName].Location,v0,v1,v2,v3);
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLsizei Count,
			GLfloat*Value){
		CShaderParameter Param=this->UniformList[UniformName];
		switch(Param.Type){
			case GL_FLOAT:
				glUniform1fv(Param.Location,Count,Value);
				break;
			case GL_FLOAT_VEC2:
				glUniform2fv(Param.Location,Count,Value);
				break;
			case GL_FLOAT_VEC3:
				glUniform3fv(Param.Location,Count,Value);
				break;
			case GL_FLOAT_VEC4:
				glUniform4fv(Param.Location,Count,Value);
				break;
			default:
				break;
		}
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLsizei Count,
			GLdouble*Value){
		CShaderParameter Param=this->UniformList[UniformName];
		switch(Param.Type){
			case GL_DOUBLE:
				glUniform1dv(Param.Location,Count,Value);
				break;
			case GL_DOUBLE_VEC2:
				glUniform2dv(Param.Location,Count,Value);
				break;
			case GL_DOUBLE_VEC3:
				glUniform3dv(Param.Location,Count,Value);
				break;
			case GL_DOUBLE_VEC4:
				glUniform4dv(Param.Location,Count,Value);
				break;
			default:
				break;
		}
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLsizei Count,
			GLint*Value){
		CShaderParameter Param=this->UniformList[UniformName];
		switch(Param.Type){
			case GL_INT:
				glUniform1iv(Param.Location,Count,(const GLint*)Value);
				break;
			case GL_INT_VEC2:
				glUniform2iv(Param.Location,Count,(const GLint*)Value);
				break;
			case GL_INT_VEC3:
				glUniform3iv(Param.Location,Count,(const GLint*)Value);
				break;
			case GL_INT_VEC4:
				glUniform4iv(Param.Location,Count,(const GLint*)Value);
				break;
			default:
				break;
		}
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLsizei Count,
			GLuint*Value){
		CShaderParameter Param=this->UniformList[UniformName];
		switch(Param.Type){
			case GL_UNSIGNED_INT:
				glUniform1uiv(Param.Location,Count,Value);
				break;
			case GL_UNSIGNED_INT_VEC2:
				glUniform2uiv(Param.Location,Count,Value);
				break;
			case GL_UNSIGNED_INT_VEC3:
				glUniform3uiv(Param.Location,Count,Value);
				break;
			case GL_UNSIGNED_INT_VEC4:
				glUniform4uiv(Param.Location,Count,Value);
				break;
			default:
				break;
		}
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLsizei Count,
			GLboolean*Value){
		CShaderParameter Param=this->UniformList[UniformName];
		switch(Param.Type){
			case GL_BOOL:
				glUniform1iv(Param.Location,Count,(const GLint*)Value);
				break;
			case GL_BOOL_VEC2:
				glUniform2iv(Param.Location,Count,(const GLint*)Value);
				break;
			case GL_BOOL_VEC3:
				glUniform3iv(Param.Location,Count,(const GLint*)Value);
				break;
			case GL_BOOL_VEC4:
				glUniform4iv(Param.Location,Count,(const GLint*)Value);
				break;
			default:
				break;
		}
	}
	*/
	void CShaderProgram::Set(
			std::string UniformName,
			GLsizei Count,
			GLboolean Transpose,
			GLfloat*Value){
		CShaderParameter Param=this->UniformList[UniformName];
		switch(Param.Type){
			case GL_FLOAT_MAT2:
				glUniformMatrix2fv(Param.Location,Count,Transpose,(const GLfloat*)Value);
				break;
			case GL_FLOAT_MAT3:
				glUniformMatrix3fv(Param.Location,Count,Transpose,(const GLfloat*)Value);
				break;
			case GL_FLOAT_MAT4:
				glUniformMatrix4fv(Param.Location,Count,Transpose,(const GLfloat*)Value);
				break;
			case GL_FLOAT_MAT2x3:
				glUniformMatrix2x3fv(Param.Location,Count,Transpose,(const GLfloat*)Value);
				break;
			case GL_FLOAT_MAT3x2:
				glUniformMatrix3x2fv(Param.Location,Count,Transpose,(const GLfloat*)Value);
				break;
			case GL_FLOAT_MAT2x4:
				glUniformMatrix2x4fv(Param.Location,Count,Transpose,(const GLfloat*)Value);
				break;
			case GL_FLOAT_MAT4x2:
				glUniformMatrix4x2fv(Param.Location,Count,Transpose,(const GLfloat*)Value);
				break;
			case GL_FLOAT_MAT3x4:
				glUniformMatrix3x4fv(Param.Location,Count,Transpose,(const GLfloat*)Value);
				break;
			case GL_FLOAT_MAT4x3:
				glUniformMatrix4x3fv(Param.Location,Count,Transpose,(const GLfloat*)Value);
				break;
			default:
				break;
		}
	}
	void CShaderProgram::Set(
			std::string UniformName,
			GLsizei Count,
			GLboolean Transpose,
			GLdouble*Value){
		CShaderParameter Param=this->UniformList[UniformName];
		switch(Param.Type){
			case GL_DOUBLE_MAT2:
				glUniformMatrix2dv(Param.Location,Count,Transpose,(const GLdouble*)Value);
				break;
			case GL_DOUBLE_MAT3:
				glUniformMatrix3dv(Param.Location,Count,Transpose,(const GLdouble*)Value);
				break;
			case GL_DOUBLE_MAT4:
				glUniformMatrix4dv(Param.Location,Count,Transpose,(const GLdouble*)Value);
				break;
			case GL_DOUBLE_MAT2x3:
				glUniformMatrix2x3dv(Param.Location,Count,Transpose,(const GLdouble*)Value);
				break;
			case GL_DOUBLE_MAT3x2:
				glUniformMatrix3x2dv(Param.Location,Count,Transpose,(const GLdouble*)Value);
				break;
			case GL_DOUBLE_MAT2x4:
				glUniformMatrix2x4dv(Param.Location,Count,Transpose,(const GLdouble*)Value);
				break;
			case GL_DOUBLE_MAT4x2:
				glUniformMatrix4x2dv(Param.Location,Count,Transpose,(const GLdouble*)Value);
				break;
			case GL_DOUBLE_MAT3x4:
				glUniformMatrix3x4dv(Param.Location,Count,Transpose,(const GLdouble*)Value);
				break;
			case GL_DOUBLE_MAT4x3:
				glUniformMatrix4x3dv(Param.Location,Count,Transpose,(const GLdouble*)Value);
				break;
			default:
				break;
		}
	}

}


