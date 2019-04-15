#ifndef ESCALA__H
#define ESCALA__H

#include <array>
#include <GL/glew.h>
#include <GL/glut.h>

using namespace std;

class Escala {

	array<float, 3> escala;

	public:
		Escala();
		void setAxis( array<float, 3> );
		void aplica();
};

#endif
