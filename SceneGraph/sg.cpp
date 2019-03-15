#include <vector>
#include <string>
#include <array>
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;


struct ponto {
	float a;
	float b;
	float c;
};

typedef struct ponto Ponto;

/*
 * Class principal para codificacao de um SceneGraph basico
 * para os arrays que codificam certas rotacoes, etc a posicao 0 simboliza a coordenada x,
 * a posicao 1 codifca a coordenada y, etc. No caso das rotacoes a posicao 3 codifica o angulo.
 *
 */
class SceneGraph {
	
	// variaveis
	array<float, 3> scale;
	array<float, 3> trans;
	array<float, 4> rot;
	vector<vector<Ponto>> modelos;
	vector<SceneGraph> filhos;
	
	public:
		// apresentacao de metodos
		SceneGraph();
		void draw();
		
		// metodos de implementacao direta
		void setScale( array<float, 3> escala) { this->scale = escala; }
		void setTrans( array<float, 3> transl) { this->trans = transl; }
		void setRot( array<float, 4> rota) { this->rot = rota; }
		array<float, 3> getScale() { return this->scale; } 
		array<float, 3> getTrans() { return this->trans; } 
		array<float, 4> getRot() { return this->rot; }
		vector<vector<Ponto>> getModelos() { return this-> modelos; }
		vector<SceneGraph> getFilhos() { return this->filhos; }
		void addFilho( SceneGraph c ) { this->filhos.push_back( c ); }
		void addModelo( vector<Ponto> c ) { this->modelos.push_back( c ); }
}; 

SceneGraph::SceneGraph() {

	scale.fill(1.0f);
	trans.fill(0.0f);
	rot.fill(0.0f);

}

void SceneGraph::draw() {

	glPushMatrix();
	// ordem ainda nao esta definida
	glRotatef(rot[3], rot[0], rot[1], rot[2]);
	glTranslatef(trans[0], trans[1], trans[2]);
	glScalef(scale[0], scale[1], scale[2]);
	// Instrucao para mostar os  valores
	
	for(SceneGraph tmp : this->filhos ) {
		tmp.draw();
	}
	glPopMatrix();
}


int main() {

	SceneGraph teste;
	SceneGraph teste2 = teste;
	SceneGraph teste3;
	
	array<float, 3> h2 = {1.0f, 2.0f, 3.0f};
	array<float, 3> h3 = {10.0f, 10.0f, 10.0f};

	cout << teste.getScale()[0] << '\n';
	teste.getScale()[0] = 3;
	cout << teste.getScale()[0] << '\n';
	teste.setScale(h2);
	teste.addFilho(teste3);
	teste3.setScale(h3);

	for( auto k : teste.getFilhos() ) {
		cout << k.getScale()[1] << ' ' << teste3.getScale()[1] << '\n';
	}

	h2[1] = 5.0f;
	cout << teste.getScale()[1] << '\n';
	cout << teste2.getScale()[1] << '\n';
	return 0;
}

