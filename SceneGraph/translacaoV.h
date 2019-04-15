#include <array>
#include <GL/glew.h>
#include <GL/glut.h>

#ifndef TRANSLACAOV__H
#define TRANSLACAOV__H

using namespace std;

class TranslacaoV {

	array<float, 3> trans;

	public:
		TranslacaoV();
		void setTrans( array<float, 3> );
		void aplica();
        
};

#endif
