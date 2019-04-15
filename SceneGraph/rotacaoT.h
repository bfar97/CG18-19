#ifndef ROTACAOT__H
#define ROTACAOT__H

#include <array>
#include <GL/glew.h>
#include <GL/glut.h>

using namespace std;

class RotacaoT {
	
	array<float, 4> rot;
	int segundos;
	int voltas;

	public:
		RotacaoT();
		void setRot( array<float, 3> );
		void setGraus( int );
		void aplica( bool );

};

#endif
