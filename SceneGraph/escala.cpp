#include "escala.h"

using namespace std;

Escala::Escala() {
	this->escala.fill(1.0f);
}

void Escala::setAxis( array<float, 3> newAxs ) {
	this->escala = newAxs;
}

void Escala::aplica() {
	glScalef(this->escala[0], this->escala[1], this->escala[2]);
}
