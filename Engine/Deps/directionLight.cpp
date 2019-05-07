#include "directionLight.h"

DLight::DLight() {
	this->dLight.fill(0.0f);
}

void DLight::setDirectionLight( array<float, 3> axs ) {
	this->dLight = axs;
}

void DLight::setLight( GLenum luz ) {
	this->luz = luz;
}
void DLight::aplica() {
	float pos[4] = {this->dLight[0], this->dLight[1], this->dLight[2], 1.0f};
	glLightfv(this->luz, GL_POSITION, pos);
}
