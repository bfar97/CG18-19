#ifndef SPOTLIGHT
#define SPOTLIGHT

#include <array>
#include <GL/glew.h>
#include <GL/glut.h>
#include "luz.h"

using namespace std;

class SLight: public Luz {
	
	array<float, 4> pos;
	array<float, 3> dir;
	float cutoff;
	GLenum luz;	

	public:
		SLight();
		void setPos( array<float, 3> );
		void setDir( array<float, 3> );
		void setCutoff( float );
		void setLight( GLenum );
		void aplica();

};

#endif
