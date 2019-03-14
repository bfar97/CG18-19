#include <vector>
#include <string>
#include <array>
#include <iostream>
#include <GL/glew.h>
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>


using namespace std;

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
	vector<string> modelos;
	vector<SceneGraph> filhos;
	// variavel do pai e funcoes que as usam
	// para ja ficam apesar de achar que nao sao precisas
	SceneGraph *pai;
	
	public:
		// apresentacao de metodos
		SceneGraph();
		void setScale( array<float, 3> );
		void setTrans( array<float, 3> );
		void setRot( array<float, 4> );
		void draw();
		
		// metodos de implementacao direta
		array<float, 3> getScale() { return this->scale; } 
		array<float, 3> getTrans() { return this->trans; } 
		array<float, 4> getRot() { return this->rot; }
	        SceneGraph getParent() { return *(this->pai); }
		void setParent( SceneGraph c ) { this->pai = &c; }
		void addFilho( SceneGraph c ) { this->filhos.push_back( c ); }
		void addModelo( string c ) { this->modelos.push_back( c ); }
}; 

SceneGraph::SceneGraph() {

	scale.fill(1.0f);
	trans.fill(0.0f);
	rot.fill(0.0f);
	pai = nullptr;

}

void SceneGraph::setScale(array<float, 3> escala) {

	array<float, 3> aux = escala;
	this->scale = aux;

}

void SceneGraph::setTrans(array<float, 3> escala) {

	array<float, 3> aux = escala;
	this->trans = aux;

}

void SceneGraph::setRot(array<float, 4> escala) {

	array<float, 4> aux = escala;
	this->rot = aux;

}

void SceneGraph::draw() {

	glPushMatrix();
	// ordem ainda nao esta definida
	glRotatef(rot[3], rot[0], rot[1], rot[2]);
	glTranslatef(trans[0], trans[1], trans[2]);
	glScalef(scale[0], scale[1], scale[2]);
	for(SceneGraph tmp : this->filhos ) {
		tmp.draw();
	}
	glPopMatrix();
}

/*
int main() {

	SceneGraph teste;
	SceneGraph teste2;
	array<float, 3> h2 = {1.0f, 2.0f, 3.0f};
	
	teste2.setParent(teste);
	cout << teste.getScale()[0] << '\n';
	teste.getScale()[0] = 3;
	cout << teste.getScale()[0] << '\n';
	teste.setScale(h2);
	h2[1] = 5.0f;
	cout << teste.getScale()[1] << '\n';
	cout << teste2.getParent().getScale()[1] << '\n';
	return 0;
}
*/
