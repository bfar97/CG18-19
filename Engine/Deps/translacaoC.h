#ifndef TRANSLACAOC__H
#define TRANSLACAOC__H

#include <vector>
#include "ponto.h"
#include <GL/glew.h>
#include <GL/glut.h> 
#include "catmullmath.h"

using namespace std;

class TranslacaoC {

	vector<Pontos> pntsCurva;
	int voltas;
	
	public:
		TranslacaoC();
		void setCurva( vector<Pontos>, int);
		void aplica( bool );

};

#endif
