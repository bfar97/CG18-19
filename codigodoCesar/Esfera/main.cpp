#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#define _USE_MATH_DEFINES
#include <math.h>

#define GROWF 0.01
#define RAIOF 0.25

//  este codigo tambem vai ser usado para gerar imagens parciais para meter no relatorio
//  provavelmente normalizar os pontos para seguirem todos um standard


// coordenadas esfericas utilizadas no programa
#define ce1(r, a, b)  (r * cos(b) * sin(a))
#define ce2(r, b)     (r * sin(b))
#define ce3(r, a, b)  (r * cos(b) * cos(a))

// coordendas polares utilizadas no programa
#define cp1(r, a)     (r * sin(a))
#define cp2(r, a)     (r * cos(a))

// conversao de M_PI para um float
#define FLT_PI         ((float) M_PI)
#define FLT_PI_2       ((float) M_PI_2)

double alfa = M_PI_4;
double beta = M_PI_4;
float raio = 5.0f;

float altura = 2.0f;
float raioc = 1.0f;
int nslices = 5;

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


void drawSphere(float radius, int slices, int stacks) {

    // variaveis que vem o numero da stack atual
    GLfloat stkd, slcd;
    GLfloat slc, stk, nslc, nstk;

    int j;

    // delta dos angulos por stack
    stkd = FLT_PI / stacks;

    // delta dos angulos por slice
    slcd = 2 * FLT_PI / slices;


    glBegin(GL_TRIANGLES);

    for(int i = 0; i < slices; ++i) {

        j = 1;
        slc = i * slcd;
        nslc = (i+1) * slcd;
        stk = -FLT_PI_2 + j * stkd;


        glColor3f(0.5, 0.0, 0.5);
        glVertex3f(0.0, -radius, 0.0);
        glVertex3f(ce1(radius, nslc, stk), ce2(radius, stk), ce3(radius, nslc, stk));
        glVertex3f(ce1(radius, slc, stk), ce2(radius, stk), ce3(radius, slc, stk));



        for(; j < stacks-1; ++j) {

            slc = i * slcd;
            nslc = (i+1) * slcd;
            stk = -FLT_PI_2 + j * stkd;
            nstk = -FLT_PI_2 + (j+1) * stkd;


            glColor3f(0.70, 0.0, 0.25);
            glVertex3f(ce1(radius, nslc, nstk), ce2(radius, nstk), ce3(radius, nslc, nstk));
            glVertex3f(ce1(radius, slc, stk), ce2(radius, stk), ce3(radius, slc, stk));
            glVertex3f(ce1(radius, nslc, stk), ce2(radius, stk), ce3(radius, nslc, stk));



            glColor3f(1.0, 1.0, 1.0);
            glVertex3f(ce1(radius, slc, nstk), ce2(radius, nstk), ce3(radius, slc, nstk));
            glVertex3f(ce1(radius, slc, stk), ce2(radius, stk), ce3(radius, slc, stk));
            glVertex3f(ce1(radius, nslc, nstk), ce2(radius, nstk), ce3(radius, nslc, nstk));


        }

        slc = i * slcd;
        nslc = (i+1) * slcd;
        stk = -FLT_PI / 2 + j * stkd;

        glColor3f(0.7, 0.1, 0.7);
        glVertex3f(0.0, radius, 0.0);
        glVertex3f(ce1(radius, slc, stk), ce2(radius, stk), ce3(radius, slc, stk));
        glVertex3f(ce1(radius, nslc, stk), ce2(radius, stk), ce3(radius, nslc, stk));


    }

    glEnd();

}

// gera uma aproximacao de um cone
// algoritmo baseado em semelhanca de triangulos
void drawCone(float radius, float altura, int slices, int stacks) {

    GLfloat stkd, slcd, raiod;
    GLfloat stk, slc, nslc, nstk, nr, r;

    stkd = altura / stacks;
    slcd = 2 * FLT_PI / slices;
    raiod = radius / stacks;

    int j;

    glBegin(GL_TRIANGLES);

    for(int i = 0; i < slices; i++) {

        // codigo responsavel por gerar uma slice da base

        slc = i * slcd;
        nslc = (i+1) * slcd;

        glColor3f(0.2, 0.0, 0.6);
        glVertex3f(0.0, 0.0, 0.0);
        glVertex3f(cp1(radius, nslc),  0.0, cp2(radius, nslc));
        glVertex3f(cp1(radius, slc), 0.0, cp2(radius, slc));


        // codigo responsavel por gerar as slices laterais
        for(j = stacks ; j > 1; j--) {

            slc = i * slcd;
            nslc = (i+1) * slcd;
            stk = (stacks - j) * stkd;
            nstk = (stacks - (j-1)) * stkd;
            r = j * raiod;
            nr = (j - 1) * raiod;


            glColor3f(0.6, 0.0, 0.2);
            glVertex3f(cp1(nr, nslc), nstk, cp2(nr, nslc));
            glVertex3f(cp1(r, slc), stk, cp2(r, slc));
            glVertex3f(cp1(r, nslc), stk, cp2(r, nslc));



            glColor3f(0.2, 0.0, 0.6);
            glVertex3f(cp1(nr, slc), nstk, cp2(nr, slc));
            glVertex3f(cp1(r, slc), stk, cp2(r, slc));
            glVertex3f(cp1(nr, nslc), nstk, cp2(nr, nslc));

        }

        // codigo responsavel por gerar a slice do topo
        slc = i * slcd;
        nslc = (i+1) * slcd;
        stk = (stacks - j) * stkd;
        r = j * raiod;


        glColor3f(0.2, 0.0, 0.6);
        glVertex3f(0.0, altura, 0.0);
        glVertex3f(cp1(r, slc), stk, cp2(r, slc));
        glVertex3f(cp1(r, nslc), stk, cp2(r, nslc));

    }

    glEnd();

}


void renderScene(void) {

	// clear buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// set the camera
	glLoadIdentity();
	gluLookAt(raio * cos(beta) * cos(alfa), raio * sin(beta), raio * cos(beta) * sin(alfa),
		      0.0,0.0,0.0,
			  0.0f,1.0f,0.0f);


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

    // cilindro
	drawCone(1.5, 1.5, 31, 31);

	// End of frame
	glutSwapBuffers();

}


void processKeys(unsigned char c, int xx, int yy) {

    switch(c) {
        case 'i':
            raio += RAIOF;
            break;
        case 'k':
            raio -= RAIOF;
            break;
        case 'q':
            altura += GROWF;
            break;
        case 'a':
            altura -= GROWF;
            break;
        case 'w':
            raioc += GROWF;
            break;
        case 's':
            raioc -= GROWF;
            break;
        case 'e':
            nslices += 1;
            break;
        case 'd':
            nslices -= 1;
            break;
        default:
            ;
    }

    glutPostRedisplay();

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

// init GLUT and the window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH|GLUT_DOUBLE|GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,800);
	glutCreateWindow("MOTOR");
		
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
