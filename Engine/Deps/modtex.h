#ifndef __MOD_TEX__
#define __MOD_TEX__

#include <vector>
#include <array>
#include <GL/glew.h>
#include <GL/glut.h>

using namespace std;

class ModTex {

	vector<float> pontos;
	vector<float> normais;
	vector<float> textura;
	array<GLuint, 3> vbos;
	int nrpontos;
	GLuint texID;

	public:
		ModTex();
		void setPontos( vector<float> );
		void setNormais( vector<float> );
		void setTexturas( vector<float> );
		void setTexID( GLuint );
		void prep();
		void aplica();

};

#endif
