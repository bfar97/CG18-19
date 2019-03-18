#include <vector>
#include <string>
#include <array>
//#include <iostream>

#include <GL/glut.h>
//#include <GL/glew.h>
//#include <stdio.h>
//#include <stdlib.h>

using namespace std;

struct ponto {
	float a;
	float b;
	float c;
};

typedef struct ponto Pontos;

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
        vector<vector<Pontos>> modelos;
        vector<SceneGraph> filhos;
        
        public:
                // apresentacao de metodos
                SceneGraph();
                void setScale( array<float, 3> a ); 
                void setTrans( array<float, 3> b );
                void setRot( array<float, 4> c ); 
                array<float, 3> getScale(); 
                array<float, 3> getTrans();
                array<float, 4> getRot();
                vector<vector<Pontos>> getModelos();
                vector<SceneGraph> getFilhos();
                void addFilho( SceneGraph c ); 
                void addModelo( vector<Pontos> c );
                void setModelo(vector<vector<Pontos>> p);
                void draw() const;
};


