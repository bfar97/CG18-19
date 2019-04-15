#include "sg.h"

using namespace std;

// SceneGraph
// Construtor

SceneGraph::SceneGraph() {

}

// Setters 

void SceneGraph::setScale( Escala novaesc ) { 

	this->scale = novaesc; 

}

void SceneGraph::setTrans( TranslacaoV novatrans ) { 

	this->trans = novatrans; 

}
                
void SceneGraph::setRot( RotacaoV novorot ) { 

	this->rot = novorot; 

}

void SceneGraph::setModelo( vector<float> pontos ) {
	
	this->modelos = pontos;

}

void SceneGraph::setCurva( TranslacaoC novacurva ) {
	
	this->curva = novacurva;


}

void SceneGraph::setEixo( RotacaoT novoeixo ) {
	
	this->eixo = novoeixo;
}

// Funcoes Adicionais
                
void SceneGraph::addFilho( SceneGraph c ) { 
	
	this->filhos.push_back( c ); 

}
               
void SceneGraph::prep() {

	glGenBuffers(1, &(this->vbo));
	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->modelos.size(), this->modelos.data(), GL_STATIC_DRAW);

	for( SceneGraph &tmp : this->filhos ) {
		tmp.prep();
	}
}

// Funcao responsavel por desenhar a estrutra
void SceneGraph::draw( bool updt ) {

	glPushMatrix();

	this->scale.aplica();
	this->rot.aplica();
	this->trans.aplica();

	this->curva.aplica( updt );
	this->eixo.aplica( updt );

	glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
	glVertexPointer(3,GL_FLOAT, 0, 0);

	glDrawArrays(GL_TRIANGLES, 0, this->modelos.size() / 3);

	for( SceneGraph &tmp : this->filhos ) {
		tmp.draw( updt );
	}

	glPopMatrix();

}
