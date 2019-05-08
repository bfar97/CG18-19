#include "modmat.h"


ModMat::ModMat() {

	this->ambiente.fill(0.0f);
	this->specular.fill(0.0f);
	this->emissive.fill(0.0f);
	this->difusa.fill(0.0f);

}

void ModMat::setPontos( vector<float> vec ) { 

	this->pontos = vec;

}

void ModMat::setNormais( vector<float> vec ) {

	this->normais = vec;

}

void ModMat::setAmbiente( array<float, 4> amb ) {

	this->ambiente = amb;

}

void ModMat::setSpecular( array<float, 4> sp ) {

	this->specular = sp;

}

void ModMat::setEmissive( array<float, 4> emi ) {

	this->emissive = emi;

}

void ModMat::setDifusa( array<float, 4> dif ) {

	this->difusa = dif;

}

void ModMat::prep() {
        
	this->nrpontos = this->pontos.size() / 3;
        
        glGenBuffers(1, &(this->vbos[0]));
        glBindBuffer(GL_ARRAY_BUFFER, this->vbos[0]); 
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->pontos.size(), this->pontos.data(), GL_STATIC_DRAW);

        glGenBuffers(1, &(this->vbos[1]));
        glBindBuffer(GL_ARRAY_BUFFER, this->vbos[1]);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->normais.size(), this->normais.data(), GL_STATIC_DRAW);
        
        vector<float>().swap(this->pontos);
        vector<float>().swap(this->normais);

}

void ModMat::aplica() {

	float black[4] = {0,0,0,0};

	glMaterialfv(GL_FRONT, GL_AMBIENT, this->ambiente.data());
	glMaterialfv(GL_FRONT, GL_SPECULAR, this->specular.data());
	glMaterialfv(GL_FRONT, GL_EMISSION, this->emissive.data());
	glMaterialfv(GL_FRONT, GL_DIFFUSE, this->difusa.data());

	glBindBuffer(GL_ARRAY_BUFFER, this->vbos[0]);
        glVertexPointer(3, GL_FLOAT, 0, 0);

        glBindBuffer(GL_ARRAY_BUFFER, this->vbos[1]);
        glNormalPointer(GL_FLOAT, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, this->nrpontos);

	glMaterialfv(GL_FRONT, GL_AMBIENT, black);
	glMaterialfv(GL_FRONT, GL_SPECULAR, black);
	glMaterialfv(GL_FRONT, GL_EMISSION, black);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, black);

}
