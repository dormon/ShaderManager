#ifndef _CSHADERPROGRAMMACRO_HPP_
#define _CSHADERPROGRAMMACRO_HPP_

#define DEF_GLUNIFORM(a,b) DEF_GLUNIFORM_##b(a)
#define DEF_GLUNIFORM_boolean(a) glUniform##a##i
#define DEF_GLUNIFORM_i(a) glUniform##a##i
#define DEF_GLUNIFORM_f(a) glUniform##a##f
#define DEF_GLUNIFORM_ui(a) glUniform##a##ui
#define DEF_GLUNIFORM_d(a) glUniform##a##d

#define DEF_GLUNIFORMV(a,b) DEF_GLUNIFORMV_##b(a)
#define DEF_GLUNIFORMV_boolean(a) glUniform##a##iv
#define DEF_GLUNIFORMV_i(a) glUniform##a##iv
#define DEF_GLUNIFORMV_f(a) glUniform##a##fv
#define DEF_GLUNIFORMV_ui(a) glUniform##a##uiv
#define DEF_GLUNIFORMV_d(a) glUniform##a##dv

#define DEF_GLTYPE(b_const) DEF_GLTYPE_##b_const
#define DEF_GLTYPE_b GLbyte
#define DEF_GLTYPE_s GLshort
#define DEF_GLTYPE_i GLint
#define DEF_GLTYPE_i64 GLint64
#define DEF_GLTYPE_f GLfloat
#define DEF_GLTYPE_ub GLubyte
#define DEF_GLTYPE_us GLushort
#define DEF_GLTYPE_ui GLuint
#define DEF_GLTYPE_ui64 GLuint64
#define DEF_GLTYPE_d GLdouble
#define DEF_GLTYPE_boolean GLboolean
#define DEF_GLTYPE_x

#define DEF_GLTYPETRANS(b_const) DEF_GLTYPETRANS_##b_const
#define DEF_GLTYPETRANS_b GLbyte
#define DEF_GLTYPETRANS_s GLshort
#define DEF_GLTYPETRANS_i GLint
#define DEF_GLTYPETRANS_i64 GLint64
#define DEF_GLTYPETRANS_f GLfloat
#define DEF_GLTYPETRANS_ub GLubyte
#define DEF_GLTYPETRANS_us GLushort
#define DEF_GLTYPETRANS_ui GLuint
#define DEF_GLTYPETRANS_ui64 GLuint64
#define DEF_GLTYPETRANS_d GLdouble
#define DEF_GLTYPETRANS_boolean GLint

#define DEF_GLTYPECONST(a,b) DEF_GLTYPECONST_##a##b
#define DEF_GLTYPECONST_1f GL_FLOAT
#define DEF_GLTYPECONST_2f GL_FLOAT_VEC2
#define DEF_GLTYPECONST_3f GL_FLOAT_VEC3
#define DEF_GLTYPECONST_4f GL_FLOAT_VEC4
#define DEF_GLTYPECONST_1d GL_DOUBLE
#define DEF_GLTYPECONST_2d GL_DOUBLE_VEC2
#define DEF_GLTYPECONST_3d GL_DOUBLE_VEC3
#define DEF_GLTYPECONST_4d GL_DOUBLE_VEC4
#define DEF_GLTYPECONST_1i GL_INT
#define DEF_GLTYPECONST_2i GL_INT_VEC2
#define DEF_GLTYPECONST_3i GL_INT_VEC3
#define DEF_GLTYPECONST_4i GL_INT_VEC4
#define DEF_GLTYPECONST_1ui GL_UNSIGNED_INT
#define DEF_GLTYPECONST_2ui GL_UNSIGNED_INT_VEC2
#define DEF_GLTYPECONST_3ui GL_UNSIGNED_INT_VEC3
#define DEF_GLTYPECONST_4ui GL_UNSIGNED_INT_VEC4
#define DEF_GLTYPECONST_1boolean GL_BOOL
#define DEF_GLTYPECONST_2boolean GL_BOOL_VEC2
#define DEF_GLTYPECONST_3boolean GL_BOOL_VEC3
#define DEF_GLTYPECONST_4boolean GL_BOOL_VEC4

#define DEF_GLTYPEPAR(b_num,type) DEF_GLTYPEPAR_##b_num(type)
#define DEF_GLTYPEPAR_1(type) DEF_GLTYPE(type) v0
#define DEF_GLTYPEPAR_2(type) DEF_GLTYPE(type) v0,DEF_GLTYPE(type) v1
#define DEF_GLTYPEPAR_3(type) DEF_GLTYPE(type) v0,DEF_GLTYPE(type) v1,DEF_GLTYPE(type) v2
#define DEF_GLTYPEPAR_4(type) DEF_GLTYPE(type) v0,DEF_GLTYPE(type) v1,DEF_GLTYPE(type) v2,DEF_GLTYPE(type) v3

#define DEFDEFFCE(a,b)\
	void Set(std::string UniformName,DEF_GLTYPEPAR(a,b));

#define DEFFCE(a,b)\
	void CShaderProgram::Set(std::string UniformName,DEF_GLTYPEPAR(a,b)){\
		DEF_GLUNIFORM(a,b)(this->UniformList[UniformName].Location,DEF_GLTYPEPAR(a,x));\
	}

#define DEFDEFFCEV(type)\
	void Set(std::string UniformName,GLsizei Count,\
			DEF_GLTYPE(type) *Value);

#define DEFFCEV(type)\
	void CShaderProgram::Set(\
			std::string UniformName,\
			GLsizei Count,\
			DEF_GLTYPE(type) *Value){\
		CShaderParameter Param=this->UniformList[UniformName];\
		switch(Param.Type){\
			case DEF_GLTYPECONST(1,type):\
				DEF_GLUNIFORMV(1,type)(Param.Location,Count,(const DEF_GLTYPETRANS(type)*)Value);\
				break;\
			case DEF_GLTYPECONST(2,type):\
				DEF_GLUNIFORMV(2,type)(Param.Location,Count,(const DEF_GLTYPETRANS(type)*)Value);\
				break;\
			case DEF_GLTYPECONST(3,type):\
				DEF_GLUNIFORMV(3,type)(Param.Location,Count,(const DEF_GLTYPETRANS(type)*)Value);\
				break;\
			case DEF_GLTYPECONST(4,type):\
				DEF_GLUNIFORMV(4,type)(Param.Location,Count,(const DEF_GLTYPETRANS(type)*)Value);\
				break;\
			default:\
				break;\
		}\
	}


#endif//_CSHADERPROGRAMMACRO_HPP_
