#include"CShaderProgram.hpp"

namespace NDormon{

  bool OpenGL320=false;
  bool OpenGL420=false;
  void InitShaderManager(){
    OpenGL320=true;
    OpenGL420=true;
    std::string Result32="";
    std::string Result42="";
    if(!glCreateShader){Result32+="glCreateShader ";OpenGL320=false;}
    if(!glShaderSource){Result32+="glShaderSource ";OpenGL320=false;}
    if(!glCompileShader){Result32+="glCompileShader ";OpenGL320=false;}
    if(!glDeleteShader){Result32+="glDeleteShader ";OpenGL320=false;}
    if(!glGetShaderiv){Result32+="glGetShaderiv ";OpenGL320=false;}
    if(!glGetShaderInfoLog){Result32+="glGetShaderInfoLog ";OpenGL320=false;}
    if(!glCreateProgram){Result32+="glCreateProgram ";OpenGL320=false;}
    if(!glAttachShader){Result32+="glAttachShader ";OpenGL320=false;}
    if(!glDetachShader){Result32+="glDetachShader ";OpenGL320=false;}
    if(!glLinkProgram){Result32+="glLinkProgram ";OpenGL320=false;}
    if(!glUseProgram){Result32+="glUseProgram ";OpenGL320=false;}
    if(!glDeleteProgram){Result32+="glDeleteProgram ";OpenGL320=false;}
    if(!glGetProgramiv){Result32+="glGetProgramiv ";OpenGL320=false;}
    if(!glGetProgramInfoLog){Result32+="glGetProgramInfoLog ";OpenGL320=false;}
    if(!glGetActiveAttrib){Result32+="glGetActiveAttrib ";OpenGL320=false;}
    if(!glGetAttribLocation){Result32+="glGetAttribLocation ";OpenGL320=false;}
    if(!glGetActiveUniform){Result32+="glGetActiveUniform ";OpenGL320=false;}
    if(!glGetUniformLocation){Result32+="glGetUniformLocation ";OpenGL320=false;}
    if(!glUniform1f){Result32+="glUniform1f ";OpenGL320=false;}
    if(!glUniform2f){Result32+="glUniform2f ";OpenGL320=false;}
    if(!glUniform3f){Result32+="glUniform3f ";OpenGL320=false;}
    if(!glUniform4f){Result32+="glUniform4f ";OpenGL320=false;}
    if(!glUniform1i){Result32+="glUniform1i ";OpenGL320=false;}
    if(!glUniform2i){Result32+="glUniform2i ";OpenGL320=false;}
    if(!glUniform3i){Result32+="glUniform3i ";OpenGL320=false;}
    if(!glUniform4i){Result32+="glUniform4i ";OpenGL320=false;}
    if(!glUniform1ui){Result32+="glUniform1ui ";OpenGL320=false;}
    if(!glUniform2ui){Result32+="glUniform2ui ";OpenGL320=false;}
    if(!glUniform3ui){Result32+="glUniform3ui ";OpenGL320=false;}
    if(!glUniform4ui){Result32+="glUniform4ui ";OpenGL320=false;}
    if(!glUniform1fv){Result32+="glUniform1fv ";OpenGL320=false;}
    if(!glUniform2fv){Result32+="glUniform2fv ";OpenGL320=false;}
    if(!glUniform3fv){Result32+="glUniform3fv ";OpenGL320=false;}
    if(!glUniform4fv){Result32+="glUniform4fv ";OpenGL320=false;}
    if(!glUniform1iv){Result32+="glUniform1iv ";OpenGL320=false;}
    if(!glUniform2iv){Result32+="glUniform2iv ";OpenGL320=false;}
    if(!glUniform3iv){Result32+="glUniform3iv ";OpenGL320=false;}
    if(!glUniform4iv){Result32+="glUniform4iv ";OpenGL320=false;}
    if(!glUniform1uiv){Result32+="glUniform1uiv ";OpenGL320=false;}
    if(!glUniform2uiv){Result32+="glUniform2uiv ";OpenGL320=false;}
    if(!glUniform3uiv){Result32+="glUniform3uiv ";OpenGL320=false;}
    if(!glUniform4uiv){Result32+="glUniform4uiv ";OpenGL320=false;}
    if(!glUniformMatrix2fv){Result32+="glUniformMatrix2fv ";OpenGL320=false;}
    if(!glUniformMatrix2x3fv){Result32+="glUniformMatrix2x3fv ";OpenGL320=false;}
    if(!glUniformMatrix2x4fv){Result32+="glUniformMatrix2x4fv ";OpenGL320=false;}
    if(!glUniformMatrix3fv){Result32+="glUniformMatrix3fv ";OpenGL320=false;}
    if(!glUniformMatrix3x2fv){Result32+="glUniformMatrix3x2fv ";OpenGL320=false;}
    if(!glUniformMatrix3x4fv){Result32+="glUniformMatrix3x4fv ";OpenGL320=false;}
    if(!glUniformMatrix4fv){Result32+="glUniformMatrix4fv ";OpenGL320=false;}
    if(!glUniformMatrix4x2fv){Result32+="glUniformMatrix4x2fv ";OpenGL320=false;}
    if(!glUniformMatrix4x3fv){Result32+="glUniformMatrix4x3fv ";OpenGL320=false;}

    if(!glGetActiveSubroutineName){Result42+="glGetActiveSubroutineName ";OpenGL420=false;}
    if(!glGetActiveSubroutineUniformiv){Result42+="glGetActiveSubroutineUniformiv ";OpenGL420=false;}
    if(!glGetActiveSubroutineUniformName){Result42+="glGetActiveSubroutineUniformName ";OpenGL420=false;}
    if(!glGetProgramStageiv){Result42+="glGetProgramStageiv ";OpenGL420=false;}
    if(!glGetSubroutineIndex){Result42+="glGetSubroutineIndex ";OpenGL420=false;}
    if(!glGetSubroutineUniformLocation){Result42+="glGetSubroutineUniformLocation ";OpenGL420=false;}
    if(!glUniformSubroutinesuiv){Result42+="glUniformSubroutinesuiv ";OpenGL420=false;}
    if(!glUniform1d){Result42+="glUniform1d ";OpenGL420=false;}
    if(!glUniform2d){Result42+="glUniform2d ";OpenGL420=false;}
    if(!glUniform3d){Result42+="glUniform3d ";OpenGL420=false;}
    if(!glUniform4d){Result42+="glUniform4d ";OpenGL420=false;}
    if(!glUniform1dv){Result42+="glUniform1dv ";OpenGL420=false;}
    if(!glUniform2dv){Result42+="glUniform2dv ";OpenGL420=false;}
    if(!glUniform3dv){Result42+="glUniform3dv ";OpenGL420=false;}
    if(!glUniform4dv){Result42+="glUniform4dv ";OpenGL420=false;}
    if(!glUniformMatrix2dv){Result42+="glUniformMatrix2dv ";OpenGL420=false;}
    if(!glUniformMatrix2x3dv){Result42+="glUniformMatrix2x3dv ";OpenGL420=false;}
    if(!glUniformMatrix2x4dv){Result42+="glUniformMatrix2x4dv ";OpenGL420=false;}
    if(!glUniformMatrix3dv){Result42+="glUniformMatrix3dv ";OpenGL420=false;}
    if(!glUniformMatrix3x2dv){Result42+="glUniformMatrix3x2dv ";OpenGL420=false;}
    if(!glUniformMatrix3x4dv){Result42+="glUniformMatrix3x4dv ";OpenGL420=false;}
    if(!glUniformMatrix4dv){Result42+="glUniformMatrix4dv ";OpenGL420=false;}
    if(!glUniformMatrix4x2dv){Result42+="glUniformMatrix4x2dv ";OpenGL420=false;}
    if(!glUniformMatrix4x3dv){Result42+="glUniformMatrix4x3dv ";OpenGL420=false;}

    if(!OpenGL320)throw "OpenGL 3.2 is not available, missing: "+Result32;
    if(!OpenGL420)std::cerr<<"OpenGL 4.2 is not available, missing: "+Result42<<std::endl;
  }

  void CShaderProgram::CreateShaderProgram_Prologue(){
    if(!OpenGL320)throw std::string("OpenGL 3.2 not available");
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

    if(OpenGL420)
      this->GetSubroutineUniformList();

    bool HasComputeShader=false;
    //for(unsigned i=0;i<this->ShaderList.size();++i){
    for(unsigned i=0;i<this->Shaders.size();++i){
      GLint Type=GL_FALSE;
      GLuint Shader=this->Shaders[i]->GetShaderID();
      glGetShaderiv(Shader,GL_SHADER_TYPE,&Type);
      if(Type==GL_COMPUTE_SHADER){
        HasComputeShader=true;
        break;
      }
    }
    if(HasComputeShader)
      glGetProgramiv(this->ShaderProgramID,GL_COMPUTE_WORK_GROUP_SIZE,
          this->WorkGroupSize);
  }

  typedef void(*GETACTIVEFCE)(GLuint,GLuint,GLsizei,GLsizei*,GLint*,GLenum*,GLchar*);
  typedef GLint(*GETLOCATIONFCE)(GLuint,const GLchar*);
  void CShaderProgram::GetParameterList(){
    void(*GetActive[2])(GLuint,GLuint,GLsizei,GLsizei*,GLint*,GLenum*,GLchar*)={
      (GETACTIVEFCE)glGetActiveAttrib,(GETACTIVEFCE)glGetActiveUniform};
    GLint(*GetLocation[2])(GLuint,const GLchar*)={
      (GETLOCATIONFCE)glGetAttribLocation,(GETLOCATIONFCE)glGetUniformLocation};
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
        Name=std::string(Buffer);//convert buffer to string
        if(Name.find("[0]")!=std::string::npos){
          //std::cerr<<"####"<<Name<<std::endl;
          Name.erase(Name.end()-3,Name.end());
          //std::cerr<<"####"<<Name<<std::endl;
        }

        //if(Size>1)Buffer[Length-3]='\0';//get rid of [0] part
        Location=GetLocation[t](this->ShaderProgramID,Name.c_str());//location
        //std::cerr<<Name<<" : "<<Location<<std::endl;
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
          //if(Size>1)BufferName[Length-3]='\0';
          std::string Name=std::string(BufferName);//convert buffer to string
          if(Name.find("[0]")!=std::string::npos){
            //std::cerr<<"####"<<Name<<std::endl;
            Name.erase(Name.end()-3,Name.end());
            //std::cerr<<"####"<<Name<<std::endl;
          }
          GLint NumCompatible;
          glGetActiveSubroutineUniformiv(this->ShaderProgramID,ShaderType[i],sub,
              GL_NUM_COMPATIBLE_SUBROUTINES,&NumCompatible);
          GLuint Location;
          Location=glGetSubroutineUniformLocation(this->ShaderProgramID,
              ShaderType[i],Name.c_str());
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

  void CShaderProgram::CompileShaders(
      unsigned NumShaders,
      std::string*Shaders,
      std::string*Defs,
      unsigned Version,
      std::string Profile){
    //std::cerr<<"Before Prologue\n";
    this->CreateShaderProgram_Prologue();//create shader program
    //std::cerr<<"Before new CShaders*\n";
    CShader**S=new CShader*[NumShaders];//alocate shaders array
    //std::cerr<<"Before for numshaders\n";
    for(unsigned s=0;s<NumShaders;++s)S[s]=NULL;//initilize
    //std::cerr<<"BeforeConstructor\n";

    try{//try to create shaders
      for(unsigned s=0;s<NumShaders;++s)//loop over shaders
        S[s]=new CShader(Shaders[s],Defs[s],Version,Profile);//create shader
    }catch(std::string&e){//catch errors
      for(unsigned s=0;s<NumShaders;++s)//loop over shaders
        if(S[s])delete S[s];//free allocate shaders
      delete[]S;//free shaders array
      throw e;//send error message
    }
    //std::cerr<<"BeforeAttach\n";
    for(unsigned s=0;s<NumShaders;++s){
      glAttachShader(this->ShaderProgramID,S[s]->GetShaderID());
      this->Shaders.push_back(S[s]);
    }
    delete[]S;//free shaders array
    this->CreateShaderProgram_Epilogue();//gets attributes and uniforms
  }

  void CShaderProgram::SortAndCompileShaders(
      unsigned NumStrings,
      std::string*Strings,
      unsigned Version,
      std::string Profile){
    unsigned NumShaders=0;
    for(unsigned s=0;s<NumStrings;++s)//loop over strings
      if(FileToShaderType(Strings[s])!=0)//it is not definition
        NumShaders++;//increment shader count
    std::string*ShaderSources=new std::string[NumShaders];//allocate shaders
    std::string*Defs=new std::string[NumShaders];//allocate definitions
    for(unsigned s=0;s<NumShaders;++s)Defs[s]="";//initialize definitions
    int ActShader=-1;
    for(unsigned s=0;s<NumStrings;++s){//loop over strings
      if(FileToShaderType(Strings[s])!=0){//it is shaders
        ActShader++;//increment shader index
        ShaderSources[ActShader]=Strings[s];//insert shader
      }else{//it is definitions
        if(ActShader<0){//there was no shader
          delete[]ShaderSources;//deallocate shader array
          delete[]Defs;//deallaocate definitions array
          throw std::string("bad arguments");//throw error
        }else Defs[ActShader]+=Strings[s];//set definitinos
      }
    }
    //std::cerr<<"NumShaders: "<<NumShaders<<std::endl;
    //for(unsigned s=0;s<NumShaders;++s){
    //  std::cerr<<ShaderSources[s]<<std::endl;
    //  std::cerr<<Defs[s]<<std::endl;
    //}
    //std::cerr<<"Before this->ComputeShaders\n";
    this->CompileShaders(NumShaders,ShaderSources,Defs,Version,Profile);//compile
    //std::cerr<<"CompileShaders\n";
    delete[]ShaderSources;//deallocate shaders
    delete[]Defs;//deallocate definitions
  }

  CShaderProgram::CShaderProgram(std::string Shader0,unsigned Version,std::string Profile){
    /*this->CreateShaderProgram_Prologue();
      CShader*S0=NULL;
      try{
      S0=new CShader(Shader0);
      }catch(std::string&e){
      if(S0)delete S0;
      throw e;
      }
      glAttachShader(this->ShaderProgramID,S0->GetShaderID());
      this->Shaders.push_back(S0);
      this->CreateShaderProgram_Epilogue();*/
    std::string*Strings=new std::string[1];
    Strings[0]=Shader0;
    this->SortAndCompileShaders(1,Strings,Version,Profile);
    delete[]Strings;
  }

  CShaderProgram::CShaderProgram(
      std::string Shader0,
      std::string Shader1,
      unsigned Version,
      std::string Profile){
    /*this->CreateShaderProgram_Prologue();
      CShader*S0=NULL;
      CShader*S1=NULL;
      try{
      S0=new CShader(Shader0);
      S1=new CShader(Shader1);
      }catch(std::string&e){
      if(S0)delete S0;
      if(S1)delete S1;
      throw e;
      }
      glAttachShader(this->ShaderProgramID,S0->GetShaderID());
      glAttachShader(this->ShaderProgramID,S1->GetShaderID());
    //this->ShaderList.push_back(S0->GetShaderID());
    //this->ShaderList.push_back(S1->GetShaderID());
    //delete S0;
    //delete S1;
    this->Shaders.push_back(S0);
    this->Shaders.push_back(S1);
    this->CreateShaderProgram_Epilogue();*/
    std::string*Strings=new std::string[2];
    Strings[0]=Shader0;
    Strings[1]=Shader1;
    this->SortAndCompileShaders(2,Strings,Version,Profile);
    delete[]Strings;
  }

  CShaderProgram::CShaderProgram(
      std::string Shader0,
      std::string Shader1,
      std::string Shader2,
      unsigned Version,
      std::string Profile){
    /*
       this->CreateShaderProgram_Prologue();
       CShader*S0=NULL;
       CShader*S1=NULL;
       CShader*S2=NULL;

       try{
       S0=new CShader(Shader0);
       S1=new CShader(Shader1);
       S2=new CShader(Shader2);
       }catch(std::string&e){
       if(S0)delete S0;
       if(S1)delete S1;
       if(S2)delete S2;
       throw e;
       }

       glAttachShader(this->ShaderProgramID,S0->GetShaderID());
       glAttachShader(this->ShaderProgramID,S1->GetShaderID());
       glAttachShader(this->ShaderProgramID,S2->GetShaderID());
    //this->ShaderList.push_back(S0->GetShaderID());
    //this->ShaderList.push_back(S1->GetShaderID());
    //this->ShaderList.push_back(S2->GetShaderID());
    //delete S0;
    //delete S1;
    //delete S2;
    this->Shaders.push_back(S0);
    this->Shaders.push_back(S1);
    this->Shaders.push_back(S2);
    this->CreateShaderProgram_Epilogue();
    */
    std::string*Strings=new std::string[3];
    Strings[0]=Shader0;
    Strings[1]=Shader1;
    Strings[2]=Shader2;
    this->SortAndCompileShaders(3,Strings,Version,Profile);
    delete[]Strings;
  }

  CShaderProgram::CShaderProgram(
      std::string Shader0,
      std::string Shader1,
      std::string Shader2,
      std::string Shader3,
      unsigned Version,
      std::string Profile){
    /*
       this->CreateShaderProgram_Prologue();
       CShader*S0=NULL;
       CShader*S1=NULL;
       CShader*S2=NULL;
       CShader*S3=NULL;

       try{
       S0=new CShader(Shader0);
       S1=new CShader(Shader1);
       S2=new CShader(Shader2);
       S3=new CShader(Shader3);
       }catch(std::string&e){
       if(S0)delete S0;
       if(S1)delete S1;
       if(S2)delete S2;
       if(S3)delete S3;
       throw e;
       }

       glAttachShader(this->ShaderProgramID,S0->GetShaderID());
       glAttachShader(this->ShaderProgramID,S1->GetShaderID());
       glAttachShader(this->ShaderProgramID,S2->GetShaderID());
       glAttachShader(this->ShaderProgramID,S3->GetShaderID());
    //this->ShaderList.push_back(S0->GetShaderID());
    //this->ShaderList.push_back(S1->GetShaderID());
    //this->ShaderList.push_back(S2->GetShaderID());
    //this->ShaderList.push_back(S3->GetShaderID());
    //delete S0;
    //delete S1;
    //delete S2;
    //delete S3;
    this->Shaders.push_back(S0);
    this->Shaders.push_back(S1);
    this->Shaders.push_back(S2);
    this->Shaders.push_back(S3);
    this->CreateShaderProgram_Epilogue();
    */
    std::string*Strings=new std::string[4];
    Strings[0]=Shader0;
    Strings[1]=Shader1;
    Strings[2]=Shader2;
    Strings[3]=Shader3;
    this->SortAndCompileShaders(4,Strings,Version,Profile);
    delete[]Strings;

  }

  CShaderProgram::CShaderProgram(
      std::string Shader0,
      std::string Shader1,
      std::string Shader2,
      std::string Shader3,
      std::string Shader4,
      unsigned Version,
      std::string Profile){
    /*
       this->CreateShaderProgram_Prologue();
       CShader*S0=NULL;
       CShader*S1=NULL;
       CShader*S2=NULL;
       CShader*S3=NULL;
       CShader*S4=NULL;

       try{
       S0=new CShader(Shader0);
       S1=new CShader(Shader1);
       S2=new CShader(Shader2);
       S3=new CShader(Shader3);
       S4=new CShader(Shader4);
       }catch(std::string&e){
       if(S0)delete S0;
       if(S1)delete S1;
       if(S2)delete S2;
       if(S3)delete S3;
       if(S4)delete S4;
       throw e;
       }

       glAttachShader(this->ShaderProgramID,S0->GetShaderID());
       glAttachShader(this->ShaderProgramID,S1->GetShaderID());
       glAttachShader(this->ShaderProgramID,S2->GetShaderID());
       glAttachShader(this->ShaderProgramID,S3->GetShaderID());
       glAttachShader(this->ShaderProgramID,S4->GetShaderID());
    //this->ShaderList.push_back(S0->GetShaderID());
    //this->ShaderList.push_back(S1->GetShaderID());
    //this->ShaderList.push_back(S2->GetShaderID());
    //this->ShaderList.push_back(S3->GetShaderID());
    //this->ShaderList.push_back(S4->GetShaderID());
    //delete S0;
    //delete S1;
    //delete S2;
    //delete S3;
    //delete S4;
    this->Shaders.push_back(S0);
    this->Shaders.push_back(S1);
    this->Shaders.push_back(S2);
    this->Shaders.push_back(S3);
    this->Shaders.push_back(S4);
    this->CreateShaderProgram_Epilogue();
    */
    std::string*Strings=new std::string[5];
    Strings[0]=Shader0;
    Strings[1]=Shader1;
    Strings[2]=Shader2;
    Strings[3]=Shader3;
    Strings[4]=Shader4;

    this->SortAndCompileShaders(5,Strings,Version,Profile);
    delete[]Strings;
  }
  CShaderProgram::CShaderProgram(std::string Shader0,
      std::string Shader1,
      std::string Shader2,
      std::string Shader3,
      std::string Shader4,
      std::string Shader5,
      unsigned Version,
      std::string Profile){
    std::string*Strings=new std::string[6];
    Strings[0]=Shader0;
    Strings[1]=Shader1;
    Strings[2]=Shader2;
    Strings[3]=Shader3;
    Strings[4]=Shader4;
    Strings[5]=Shader5;

    this->SortAndCompileShaders(6,Strings,Version,Profile);
    delete[]Strings;

  }
  CShaderProgram::CShaderProgram(std::string Shader0,
      std::string Shader1,
      std::string Shader2,
      std::string Shader3,
      std::string Shader4,
      std::string Shader5,
      std::string Shader6,
      unsigned Version,
      std::string Profile){
    std::string*Strings=new std::string[7];
    Strings[0]=Shader0;
    Strings[1]=Shader1;
    Strings[2]=Shader2;
    Strings[3]=Shader3;
    Strings[4]=Shader4;
    Strings[5]=Shader5;
    Strings[6]=Shader6;

    this->SortAndCompileShaders(7,Strings,Version,Profile);
    delete[]Strings;

  }
  CShaderProgram::CShaderProgram(std::string Shader0,
      std::string Shader1,
      std::string Shader2,
      std::string Shader3,
      std::string Shader4,
      std::string Shader5,
      std::string Shader6,
      std::string Shader7,
      unsigned Version,
      std::string Profile){
    std::string*Strings=new std::string[8];
    Strings[0]=Shader0;
    Strings[1]=Shader1;
    Strings[2]=Shader2;
    Strings[3]=Shader3;
    Strings[4]=Shader4;
    Strings[5]=Shader5;
    Strings[6]=Shader6;
    Strings[7]=Shader7;

    this->SortAndCompileShaders(8,Strings,Version,Profile);
    delete[]Strings;
  }
  CShaderProgram::CShaderProgram(std::string Shader0,
      std::string Shader1,
      std::string Shader2,
      std::string Shader3,
      std::string Shader4,
      std::string Shader5,
      std::string Shader6,
      std::string Shader7,
      std::string Shader8,
      unsigned Version,
      std::string Profile){
    std::string*Strings=new std::string[9];
    Strings[0]=Shader0;
    Strings[1]=Shader1;
    Strings[2]=Shader2;
    Strings[3]=Shader3;
    Strings[4]=Shader4;
    Strings[5]=Shader5;
    Strings[6]=Shader6;
    Strings[7]=Shader7;
    Strings[8]=Shader8;

    this->SortAndCompileShaders(9,Strings,Version,Profile);
    delete[]Strings;
  }
  CShaderProgram::CShaderProgram(std::string Shader0,
      std::string Shader1,
      std::string Shader2,
      std::string Shader3,
      std::string Shader4,
      std::string Shader5,
      std::string Shader6,
      std::string Shader7,
      std::string Shader8,
      std::string Shader9,
      unsigned Version,
      std::string Profile){
    std::string*Strings=new std::string[10];
    Strings[0]=Shader0;
    Strings[1]=Shader1;
    Strings[2]=Shader2;
    Strings[3]=Shader3;
    Strings[4]=Shader4;
    Strings[5]=Shader5;
    Strings[6]=Shader6;
    Strings[7]=Shader7;
    Strings[8]=Shader8;
    Strings[9]=Shader9;


    this->SortAndCompileShaders(10,Strings,Version,Profile);
    delete[]Strings;

  }

  CShaderProgram::CShaderProgram(
      GLenum Type0,std::string Shader0){
    this->CreateShaderProgram_Prologue();
    CShader*S0=NULL;

    try{
      S0=new CShader(Type0,Shader0);
    }catch(std::string&e){
      if(S0)delete S0;
      throw e;
    }

    glAttachShader(this->ShaderProgramID,S0->GetShaderID());
    //this->ShaderList.push_back(S0->GetShaderID());
    //delete S0;
    this->Shaders.push_back(S0);
    this->CreateShaderProgram_Epilogue();
  }
  CShaderProgram::CShaderProgram(
      GLenum Type0,std::string Shader0,
      GLenum Type1,std::string Shader1){
    this->CreateShaderProgram_Prologue();
    CShader*S0=NULL;
    CShader*S1=NULL;

    try{
      S0=new CShader(Type0,Shader0);
      S1=new CShader(Type1,Shader1);
    }catch(std::string&e){
      if(S0)delete S0;
      if(S1)delete S1;
      throw e;
    }

    glAttachShader(this->ShaderProgramID,S0->GetShaderID());
    glAttachShader(this->ShaderProgramID,S1->GetShaderID());
    //this->ShaderList.push_back(S0->GetShaderID());
    //this->ShaderList.push_back(S1->GetShaderID());
    //delete S0;
    //delete S1;
    this->Shaders.push_back(S0);
    this->Shaders.push_back(S1);
    this->CreateShaderProgram_Epilogue();

  }
  CShaderProgram::CShaderProgram(
      GLenum Type0,std::string Shader0,
      GLenum Type1,std::string Shader1,
      GLenum Type2,std::string Shader2){
    this->CreateShaderProgram_Prologue();
    CShader*S0=NULL;
    CShader*S1=NULL;
    CShader*S2=NULL;

    try{
      S0=new CShader(Type0,Shader0);
      S1=new CShader(Type1,Shader1);
      S2=new CShader(Type2,Shader2);
    }catch(std::string&e){
      if(S0)delete S0;
      if(S1)delete S1;
      if(S2)delete S2;
      throw e;
    }

    glAttachShader(this->ShaderProgramID,S0->GetShaderID());
    glAttachShader(this->ShaderProgramID,S1->GetShaderID());
    glAttachShader(this->ShaderProgramID,S2->GetShaderID());
    //this->ShaderList.push_back(S0->GetShaderID());
    //this->ShaderList.push_back(S1->GetShaderID());
    //this->ShaderList.push_back(S2->GetShaderID());
    //delete S0;
    //delete S1;
    //delete S2;
    this->Shaders.push_back(S0);
    this->Shaders.push_back(S1);
    this->Shaders.push_back(S2);
    this->CreateShaderProgram_Epilogue();
  }
  CShaderProgram::CShaderProgram(
      GLenum Type0,std::string Shader0,
      GLenum Type1,std::string Shader1,
      GLenum Type2,std::string Shader2,
      GLenum Type3,std::string Shader3){
    this->CreateShaderProgram_Prologue();
    CShader*S0=NULL;
    CShader*S1=NULL;
    CShader*S2=NULL;
    CShader*S3=NULL;

    try{
      S0=new CShader(Type0,Shader0);
      S1=new CShader(Type1,Shader1);
      S2=new CShader(Type2,Shader2);
      S3=new CShader(Type3,Shader3);
    }catch(std::string&e){
      if(S0)delete S0;
      if(S1)delete S1;
      if(S2)delete S2;
      if(S3)delete S3;
      throw e;
    }

    glAttachShader(this->ShaderProgramID,S0->GetShaderID());
    glAttachShader(this->ShaderProgramID,S1->GetShaderID());
    glAttachShader(this->ShaderProgramID,S2->GetShaderID());
    glAttachShader(this->ShaderProgramID,S3->GetShaderID());
    //this->ShaderList.push_back(S0->GetShaderID());
    //this->ShaderList.push_back(S1->GetShaderID());
    //this->ShaderList.push_back(S2->GetShaderID());
    //this->ShaderList.push_back(S3->GetShaderID());
    //delete S0;
    //delete S1;
    //delete S2;
    //delete S3;
    this->Shaders.push_back(S0);
    this->Shaders.push_back(S1);
    this->Shaders.push_back(S2);
    this->Shaders.push_back(S3);
    this->CreateShaderProgram_Epilogue();
  }
  CShaderProgram::CShaderProgram(
      GLenum Type0,std::string Shader0,
      GLenum Type1,std::string Shader1,
      GLenum Type2,std::string Shader2,
      GLenum Type3,std::string Shader3,
      GLenum Type4,std::string Shader4){
    this->CreateShaderProgram_Prologue();
    CShader*S0=NULL;
    CShader*S1=NULL;
    CShader*S2=NULL;
    CShader*S3=NULL;
    CShader*S4=NULL;

    try{
      S0=new CShader(Type0,Shader0);
      S1=new CShader(Type1,Shader1);
      S2=new CShader(Type2,Shader2);
      S3=new CShader(Type3,Shader3);
      S4=new CShader(Type4,Shader4);
    }catch(std::string&e){
      if(S0)delete S0;
      if(S1)delete S1;
      if(S2)delete S2;
      if(S3)delete S3;
      if(S4)delete S4;
      throw e;
    }

    glAttachShader(this->ShaderProgramID,S0->GetShaderID());
    glAttachShader(this->ShaderProgramID,S1->GetShaderID());
    glAttachShader(this->ShaderProgramID,S2->GetShaderID());
    glAttachShader(this->ShaderProgramID,S3->GetShaderID());
    glAttachShader(this->ShaderProgramID,S4->GetShaderID());
    //this->ShaderList.push_back(S0->GetShaderID());
    //this->ShaderList.push_back(S1->GetShaderID());
    //this->ShaderList.push_back(S2->GetShaderID());
    //this->ShaderList.push_back(S3->GetShaderID());
    //this->ShaderList.push_back(S4->GetShaderID());
    //delete S0;
    //delete S1;
    //delete S2;
    //delete S3;
    //delete S4;
    this->Shaders.push_back(S0);
    this->Shaders.push_back(S1);
    this->Shaders.push_back(S2);
    this->Shaders.push_back(S3);
    this->Shaders.push_back(S4);
    this->CreateShaderProgram_Epilogue();
  }
  void CShaderProgram::SetVersion(unsigned Version,std::string Profile){
    for(unsigned s=0;s<this->Shaders.size();++s)
      this->Shaders[s]->SetVersion(Version,Profile);
  }

  void CShaderProgram::SetVersion(GLenum Type,unsigned Version,std::string Profile){
    for(unsigned s=0;s<this->Shaders.size();++s){
      if(this->Shaders[s]->GetType()==Type){
        this->Shaders[s]->SetVersion(Version,Profile);
      }
    }
  }

  void CShaderProgram::AppendAfterVersion(std::string Defs){
    for(unsigned s=0;s<this->Shaders.size();++s)
      this->Shaders[s]->AppendAfterVersion(Defs);
  }

  void CShaderProgram::AppendAfterVersion(GLenum Type,std::string Defs){
    for(unsigned s=0;s<this->Shaders.size();++s){
      if(this->Shaders[s]->GetType()==Type){
        this->Shaders[s]->AppendAfterVersion(Defs);
      }
    }
  }

  void CShaderProgram::DeleteProgram(){
    for(int i=0;i<this->Shaders.size();++i)//loop over shader objects
      glDetachShader(this->ShaderProgramID,this->Shaders[i]->GetShaderID());//detach shader
    glDeleteProgram(this->ShaderProgramID);//deletes shader program
    this->AttributeList.clear();
    this->UniformList.clear();
  }

  void CShaderProgram::Relink(){
    this->DeleteProgram();//delete previous program

    this->CreateShaderProgram_Prologue();//create new program

    for(unsigned s=0;s<this->Shaders.size();++s){
      this->Shaders[s]->Recompile();//recompile shaders
      glAttachShader(this->ShaderProgramID,this->Shaders[s]->GetShaderID());//attach shader
    }

    this->CreateShaderProgram_Epilogue();//get attribs and uniforms,...
  }


  CShaderProgram::CShaderProgram(unsigned Num,...){
    this->CreateShaderProgram_Prologue();//prologue of creating of shader prg.
    va_list args;//arguments
    va_start(args,Num);//start point of arguments
    for(size_t i=0;i<Num;++i){//loop over arguments
      CShader*Shader=(CShader*)va_arg(args,CShader*);
      //GLuint ShaderID=((CShader*)va_arg(args,CShader*))->GetShaderID();//ID
      glAttachShader(//attach shader object to shader program
          this->ShaderProgramID,//shader program
          Shader->GetShaderID());
      //ShaderID);//shader object id
      //this->ShaderList.push_back(ShaderID);//insert shader object to list
      this->Shaders.push_back(Shader);
    }
    va_end(args);//end point of arguments
    this->CreateShaderProgram_Epilogue();//epilogue of creating of shader prg.
  }

  CShaderProgram::CShaderProgram(CShader**Shader,unsigned Num){
    this->CreateShaderProgram_Prologue();//prologue of creating of shader prg.
    for(unsigned i=0;i<Num;++i){//loop over shaders
      //GLuint ShaderID=Shader[i]->GetShaderID();//shader object ID
      glAttachShader(//attach shader object to shader program
          this->ShaderProgramID,//shader program
          Shader[i]->GetShaderID());
      //ShaderID);//shader object
      //this->ShaderList.push_back(ShaderID);//inser shdaer object to list
      this->Shaders.push_back(Shader[i]);
    }
    this->CreateShaderProgram_Epilogue();//epilogue of creating of shader prg.
  }

  CShaderProgram::~CShaderProgram(){
    /*
    //for(int i=0;i<this->ShaderList.size();++i)//loop over shader objects
    for(int i=0;i<this->Shaders.size();++i)//loop over shader objects
    //glDetachShader(this->ShaderProgramID,this->ShaderList[i]);//detach shader
    glDetachShader(this->ShaderProgramID,this->Shaders[i]->GetShaderID());//detach shader
    glDeleteProgram(this->ShaderProgramID);//deletes shader program
    */
    this->DeleteProgram();

    for(unsigned s=0;s<this->Shaders.size();++s)
      delete this->Shaders[s];

    //this->ShaderList.clear();//clear list of shader object
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
    return this->AttributeList[AttributeName].Location;
    //return glGetAttribLocation(this->ShaderProgramID,AttributeName.data());
  }

  GLenum CShaderProgram::GetAttributeType(std::string AttributeName){
    return this->AttributeList[AttributeName].Type;
  }

  GLint CShaderProgram::GetAttributeSize(std::string AttributeName){
    return this->AttributeList[AttributeName].Size;
  }

  GLuint CShaderProgram::GetUniform(std::string UniformName){
    return this->UniformList[UniformName].Location;
    //return glGetUniformLocation(this->ShaderProgramID,UniformName.data());
  }

  GLenum CShaderProgram::GetUniformType(std::string UniformName){
    return this->UniformList[UniformName].Type;
  }

  GLint CShaderProgram::GetUniformSize(std::string UniformName){
    return this->UniformList[UniformName].Size;
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

  GLenum ComplexTypeToSimpleType(GLenum Type){
    switch(Type){
      case GL_FLOAT:return GL_FLOAT;
      case GL_FLOAT_VEC2:return GL_FLOAT;
      case GL_FLOAT_VEC3:return GL_FLOAT;
      case GL_FLOAT_VEC4:return GL_FLOAT;
      case GL_DOUBLE:return GL_DOUBLE;
      case GL_DOUBLE_VEC2:return GL_DOUBLE;
      case GL_DOUBLE_VEC3:return GL_DOUBLE;
      case GL_DOUBLE_VEC4:return GL_DOUBLE;
      case GL_INT:return GL_INT;
      case GL_INT_VEC2:return GL_INT;
      case GL_INT_VEC3:return GL_INT;
      case GL_INT_VEC4:return GL_INT;
      case GL_UNSIGNED_INT:return GL_UNSIGNED_INT;
      case GL_UNSIGNED_INT_VEC2:return GL_UNSIGNED_INT;
      case GL_UNSIGNED_INT_VEC3:return GL_UNSIGNED_INT;
      case GL_UNSIGNED_INT_VEC4:return GL_UNSIGNED_INT;
      case GL_BOOL:return GL_BOOL;
      case GL_BOOL_VEC2:return GL_BOOL;
      case GL_BOOL_VEC3:return GL_BOOL;
      case GL_BOOL_VEC4:return GL_BOOL;
      default:return GL_FALSE;
    }
  }

  GLint ComplexTypeToSize(GLenum Type){
    switch(Type){
      case GL_FLOAT:return 1;
      case GL_FLOAT_VEC2:return 2;
      case GL_FLOAT_VEC3:return 3;
      case GL_FLOAT_VEC4:return 4;
      case GL_DOUBLE:return 1;
      case GL_DOUBLE_VEC2:return 2;
      case GL_DOUBLE_VEC3:return 3;
      case GL_DOUBLE_VEC4:return 4;
      case GL_INT:return 1;
      case GL_INT_VEC2:return 2;
      case GL_INT_VEC3:return 3;
      case GL_INT_VEC4:return 4;
      case GL_UNSIGNED_INT:return 1;
      case GL_UNSIGNED_INT_VEC2:return 2;
      case GL_UNSIGNED_INT_VEC3:return 3;
      case GL_UNSIGNED_INT_VEC4:return 4;
      case GL_BOOL:return 1;
      case GL_BOOL_VEC2:return 2;
      case GL_BOOL_VEC3:return 3;
      case GL_BOOL_VEC4:return 4;
      default:return 0;
    }
  }

  }


