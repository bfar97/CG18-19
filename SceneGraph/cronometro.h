#ifndef CRONOMETRO__H
#define CRONOMETRO__H

#include <GL/glew.h>
#include <GL/glut.h>

class Cronometro {

	int basetime;

	public:
		Cronometro();
		bool updateTime();
};

#endif
