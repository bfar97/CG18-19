#include "sg.h"

using namespace std;


void SceneGraph::setScale( array<float, 3> escala) { 

	this->scale = escala; 

}

void SceneGraph::setTrans( array<float, 3> transl ) { 

	this->trans = transl; 

}
                
void SceneGraph::setRot( array<float, 4> rota) { 

	this->rot = rota; 

}
                
array<float, 3> SceneGraph::getScale() { 

	return this->scale; 

}
                
array<float, 3> SceneGraph::getTrans() {
       	
	return this->trans; 

}
                
array<float, 4> SceneGraph::getRot() { 
	
	return this->rot; 

}
               
vector<vector<Pontos>> SceneGraph::getModelos() { 
	
	return this-> modelos; 

}
                
vector<SceneGraph> SceneGraph::getFilhos() { 
	
	return this->filhos; 

}
                
void SceneGraph::addFilho( SceneGraph c ) { 
	
	this->filhos.push_back( c ); 

}
               
void SceneGraph::addModelo( vector<Pontos> c ) { 
	
	this->modelos.push_back( c ); 

}

SceneGraph::SceneGraph() {

	this->scale.fill(1.0f);
	this->trans.fill(0.0f);
	this->rot.fill(0.0f);

}

void SceneGraph::draw() const {

	glPushMatrix();
	// ordem ainda nao esta definida, ainda vai ser melhorado
	glRotatef(rot[3], rot[0], rot[1], rot[2]);
	glTranslatef(trans[0], trans[1], trans[2]);
	glScalef(scale[0], scale[1], scale[2]);
	
	glBegin(GL_TRIANGLES);
	
	for( vector<Pontos> pnts : this->modelos ) {		
		for( Pontos p : pnts ) {
        		glVertex3f(p.a, p.b, p.c);
    		}
	}

	glEnd();

	for( SceneGraph const &tmp : this->filhos ) {
		tmp.draw();
	}

	glPopMatrix();
}

void SceneGraph::setModelo(vector<vector<Pontos>> pontos) {
	this->modelos = pontos;
}

/*
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
*/

