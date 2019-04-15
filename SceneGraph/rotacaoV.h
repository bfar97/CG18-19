#include <array>
#include <GL/glew.h>
#include <GL/glut.h>

#ifndef ROTACAOV__H
#define ROTACAOV__H

using namespace std;

class RotacaoV {
	
	array<float, 4> rot;

	public:
		RotacaoV();
		void setRot( array<float, 4> );
		void aplica(); 
}; 

#endif
