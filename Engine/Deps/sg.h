#ifndef __SG__H
#define __SG__H

#include <vector>
#include <string>
#include <array>
#include <memory>
#include <GL/glew.h>
#include <GL/glut.h>
#include "ponto.h"
#include "escala.h"
#include "rotacaoT.h"
#include "rotacaoV.h"
#include "translacaoC.h"
#include "translacaoV.h"
#include "cronometro.h"
#include "luz.h"

using namespace std;

class SceneGraph {

        // variaveis
	// transformacoes nao baseadas em tempo
        Escala scale;
        TranslacaoV trans;
        RotacaoV rot;

	//transformacoes baseadas em tempo
	TranslacaoC curva;
	RotacaoT eixo;

	// modelos guardados na scenegraph
        vector<float> modelos;

	//luzes na cena
	vector<shared_ptr<Luz>> luzes;

	// inteiro responsavel pelos VBOS
	GLuint vbo;

	// Descendencia do SceneGraph
        vector<SceneGraph> filhos;
        
        public:
                // Construtores 
                SceneGraph();

		// Setters
                void setScale( Escala ); 
                void setTrans( TranslacaoV );
                void setRot( RotacaoV ); 
                void setModelo( vector<float> );
		void setCurva( TranslacaoC );
		void setEixo( RotacaoT );

		// Funcoes adicionais
                void addFilho( SceneGraph ); 
		void setLuzes( vector<shared_ptr<Luz>> );

		// Funcao que trata de inicializar os VBOS
		void prep();

		// Funcao responsavel por desenhar a estrutura
                void draw( bool );
};

#endif
