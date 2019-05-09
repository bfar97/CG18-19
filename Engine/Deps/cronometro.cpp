#include "cronometro.h"

Cronometro::Cronometro() {
	this->basetime = 0;
}

bool Cronometro::updateTime() {

	int aux = glutGet(GLUT_ELAPSED_TIME);
	
	if(aux - this->basetime >= 300) {
		this->basetime = aux;
		return true;
	}

	return false;

}
