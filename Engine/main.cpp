#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>

//include tinyxml header
#include <iostream>
#include "tinyxml2.h"
#include <string>
#include <vector>
#include <fstream>



using namespace tinyxml2;

std::vector<std::string> ficheiros;


#define GROWF 0.01

double alfa = M_PI / 4;
double beta = M_PI / 4;
float raio = 5.0f;


void changeSize(int w, int h) {

	// Prevent a divide by zero, when window is too short
	// (you cant make a window with zero width).
	if(h == 0)
		h = 1;

	// compute window's aspect ratio 
	float ratio = w * 1.0 / h;

	// Set the projection matrix as current
	glMatrixMode(GL_PROJECTION);
	// Load Identity Matrix
	glLoadIdentity();
	
	// Set the viewport to be the entire window
    glViewport(0, 0, w, h);

	// Set perspective
	gluPerspective(45.0f ,ratio, 1.0f ,1000.0f);

	// return to the model view matrix mode
	glMatrixMode(GL_MODELVIEW);
}


void printPontos(std::string ficheiro) {
    std::ifstream file;
    //change this to your folder's path.
    std::string s = "/home/bernardo/Desktop/Generator/Engine/";
    s.append(ficheiro.c_str());
    file.open(s.c_str());
    float a,b,c;
    while(file >> a >> b >> c) {
        glVertex3f(a,b,c);
    }
}



void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
    glLoadIdentity();
    gluLookAt(raio * cos(beta) * cos(alfa), raio * cos(beta) * sin(alfa), raio * sin(beta),
              0.0,0.0,0.0,
              0.0f,0.0f,1.0f);

    // x y z linhas

    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0, 0, 0);
    glVertex3f(5, 0, 0);

    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 5, 0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 5);

    glEnd();

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glBegin(GL_TRIANGLES);
    glColor3f(0.5,0.5,0.5);
	for(int i = 0; i < ficheiros.size(); i++) {
        printPontos(ficheiros[i].c_str());
	}
    glEnd();

	// End of frame
	glutSwapBuffers();
}


void processKeys(unsigned char c, int xx, int yy) {



}


void processSpecialKeys(int key, int xx, int yy) {


// put code to process special keys in here
    switch(key) {
        case GLUT_KEY_LEFT:
            alfa += GROWF;
            break;
        case GLUT_KEY_RIGHT:
            alfa -= GROWF;
            break;
        case GLUT_KEY_UP:
            beta += GROWF;
            break;
        case GLUT_KEY_DOWN:
            beta -= GROWF;
            break;
        default:
            ;
    }

    glutPostRedisplay();


}


int main(int argc, char **argv) {

    tinyxml2::XMLDocument doc;

    doc.LoadFile("/home/bernardo/Desktop/Generator/Engine/conf.xml");

    tinyxml2::XMLNode *scene = doc.FirstChild();

    while(scene) {
        for(tinyxml2::XMLElement* model = scene->FirstChildElement(); model != NULL; model = model->NextSiblingElement()) {
            const char * file;
            file = model->Attribute("file");
            ficheiros.push_back(file);
        }
        scene = scene->NextSiblingElement();
    }


// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("CG@DI-UM");
		
// Required callback registry 
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	
// Callback registration for keyboard processing
	glutKeyboardFunc(processKeys);
	glutSpecialFunc(processSpecialKeys);

//  OpenGL settings
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	
// enter GLUT's main cycle
	glutMainLoop();
	
	return 1;
}
