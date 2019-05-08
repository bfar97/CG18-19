#ifndef __MOD_MAT__
#define __MOD_MAT__

#include <vector>
#include <array>
#include <GL/glew.h>
#include <GL/glut.h>


using namespace std;

class ModMat {

	vector<float> pontos;
	vector<float> normais;
	array<GLuint, 2> vbos;
	array<float, 4> ambiente;
	array<float, 4> specular;
	array<float, 4> emissive;
	array<float, 4> difusa;
	int nrpontos;

	public:
		ModMat();
		void setPontos( vector<float> );
		void setNormais( vector<float> );
		void setAmbiente( array<float, 4> );
		void setSpecular( array<float, 4> );
		void setEmissive( array<float, 4> );
		void setDifusa( array<float, 4> );
		void prep();
		void aplica();



};

#endif
