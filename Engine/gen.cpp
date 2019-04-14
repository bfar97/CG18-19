#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <iostream>

#define cp1(r, a)     (r * sin(a))
#define cp2(r, a)     (r * cos(a))

#define ce1(r, a, b)  (r * cos(b) * sin(a))
#define ce2(r, b)     (r * sin(b))
#define ce3(r, a, b)  (r * cos(b) * cos(a))

#define B0(u) ((1-u))^3
#define B1(u) (3*u*(1-u)^3)
#define B2(u) ((3*(u^2))*(1-u))
#define B3(u) ((u)^3)

struct Ponto {
    float x;
    float y;
    float z;
};

// para usar estes vetores dar include a "parseBezier.h" e usar
// extern std::vector< std::vector<int> > patchesIndx;
// extern std::vector< Ponto > pontos;

std::vector< std::vector<int> > patchesIndx;
std::vector< Ponto > pontos;


void printSphere(float radius, int slices, int stacks, FILE* f){
    // variaveis que vem o numero da stack atual
    float stkd, slcd;
    float slc, stk, nslc, nstk;

    int j;

    // delta dos angulos por stack
    stkd = M_PI / stacks;

    // delta dos angulos por slice
    slcd = 2 * M_PI / slices;


    for(int i = 0; i < slices; ++i) {

        j = 1;
        slc = i * slcd;
        nslc = (i+1) * slcd;
        stk = -M_PI_2 + j * stkd;


        fprintf(f,"%f %f %f \n",0.0, -radius, 0.0);
        fprintf(f,"%f %f %f \n",ce1(radius, nslc, stk), ce2(radius, stk), ce3(radius, nslc, stk));
        fprintf(f,"%f %f %f \n",ce1(radius, slc, stk), ce2(radius, stk), ce3(radius, slc, stk));



        for(; j < stacks-1; ++j) {

            slc = i * slcd;
            nslc = (i+1) * slcd;
            stk = -M_PI_2 + j * stkd;
            nstk = -M_PI_2 + (j+1) * stkd;

            fprintf(f,"%f %f %f \n",ce1(radius, nslc, nstk), ce2(radius, nstk), ce3(radius, nslc, nstk));
            fprintf(f,"%f %f %f \n",ce1(radius, slc, stk), ce2(radius, stk), ce3(radius, slc, stk));
            fprintf(f,"%f %f %f \n",ce1(radius, nslc, stk), ce2(radius, stk), ce3(radius, nslc, stk));



            
            fprintf(f,"%f %f %f \n",ce1(radius, slc, nstk), ce2(radius, nstk), ce3(radius, slc, nstk));
            fprintf(f,"%f %f %f \n",ce1(radius, slc, stk), ce2(radius, stk), ce3(radius, slc, stk));
            fprintf(f,"%f %f %f \n",ce1(radius, nslc, nstk), ce2(radius, nstk), ce3(radius, nslc, nstk));


        }

        slc = i * slcd;
        nslc = (i+1) * slcd;
        stk = -M_PI / 2 + j * stkd;

        
        fprintf(f,"%f %f %f \n",0.0, radius, 0.0);
        fprintf(f,"%f %f %f \n",ce1(radius, slc, stk), ce2(radius, stk), ce3(radius, slc, stk));
        fprintf(f,"%f %f %f \n",ce1(radius, nslc, stk), ce2(radius, stk), ce3(radius, nslc, stk));


    }

    


}

void printBox ( float xx , float yy , float zz , FILE *f ){
    // front e back
    fprintf(f,"%f %f %f \n",-xx/2,-yy/2,zz/2 );
    fprintf(f,"%f %f %f \n",xx/2,-yy/2,zz/2);
    fprintf(f,"%f %f %f \n",xx/2,yy/2,zz/2);

    fprintf(f,"%f %f %f \n",-xx/2,-yy/2,zz/2);
    fprintf(f,"%f %f %f \n",xx/2,yy/2,zz/2);
    fprintf(f,"%f %f %f \n",-xx/2,yy/2,zz/2);

    fprintf(f,"%f %f %f \n",-xx/2,-yy/2,-zz/2);
    fprintf(f,"%f %f %f \n",xx/2,yy/2,-zz/2);
    fprintf(f,"%f %f %f \n",xx/2,-yy/2,-zz/2);

    fprintf(f,"%f %f %f \n",xx/2,yy/2,-zz/2);
    fprintf(f,"%f %f %f \n",-xx/2,-yy/2,-zz/2);
    fprintf(f,"%f %f %f \n",-xx/2,yy/2,-zz/2);
    // top e bot
    fprintf(f,"%f %f %f \n",xx/2,yy/2,zz/2);
    fprintf(f,"%f %f %f \n",xx/2,yy/2,-zz/2);
    fprintf(f,"%f %f %f \n",-xx/2,yy/2,-zz/2);

    fprintf(f,"%f %f %f \n",xx/2,yy/2,zz/2);
    fprintf(f,"%f %f %f \n",-xx/2,yy/2,-zz/2);
    fprintf(f,"%f %f %f \n",-xx/2,yy/2,zz/2);

    fprintf(f,"%f %f %f \n",xx/2,-yy/2,zz/2);
    fprintf(f,"%f %f %f \n",-xx/2,-yy/2,-zz/2);
    fprintf(f,"%f %f %f \n",xx/2,-yy/2,-zz/2);

    fprintf(f,"%f %f %f \n",-xx/2,-yy/2,-zz/2);
    fprintf(f,"%f %f %f \n",xx/2,-yy/2,zz/2);
    fprintf(f,"%f %f %f \n",-xx/2,-yy/2,zz/2);
    //sides
    fprintf(f,"%f %f %f \n",xx/2,-yy/2,zz/2);
    fprintf(f,"%f %f %f \n",xx/2,-yy/2,-zz/2);
    fprintf(f,"%f %f %f \n",xx/2,yy/2,-zz/2);

    fprintf(f,"%f %f %f \n",xx/2,yy/2,-zz/2);
    fprintf(f,"%f %f %f \n",xx/2,yy/2,zz/2);
    fprintf(f,"%f %f %f \n",xx/2,-yy/2,zz/2);

    fprintf(f,"%f %f %f \n",-xx/2,-yy/2,zz/2);
    fprintf(f,"%f %f %f \n",-xx/2,yy/2,-zz/2);
    fprintf(f,"%f %f %f \n",-xx/2,-yy/2,-zz/2);

    fprintf(f,"%f %f %f \n",-xx/2,-yy/2,zz/2);
    fprintf(f,"%f %f %f \n",-xx/2,yy/2,zz/2);
    fprintf(f,"%f %f %f \n",-xx/2,yy/2,-zz/2);
}

void printCone(float radius, float altura, int slices, int stacks, FILE *f) {
 
    float stkd, slcd, raiod;
    float stk, slc, nslc, nstk, nr, r;

    stkd = altura / stacks;
    slcd = 2 * M_PI / slices;
    raiod = radius / stacks;

    int j;


    for(int i = 0; i < slices; i++) {

        // codigo responsavel por gerar uma slice da base

        slc = i * slcd;
        nslc = (i+1) * slcd;

       
        fprintf(f,"%f %f %f \n",0.0, 0.0, 0.0);
        fprintf(f,"%f %f %f \n",cp1(radius, nslc),  0.0, cp2(radius, nslc));
        fprintf(f,"%f %f %f \n",cp1(radius, slc), 0.0, cp2(radius, slc));


        // codigo responsavel por gerar as slices laterais
        for(j = stacks ; j > 1; j--) {

            slc = i * slcd;
            nslc = (i+1) * slcd;
            stk = (stacks - j) * stkd;
            nstk = (stacks - (j-1)) * stkd;
            r = j * raiod;
            nr = (j - 1) * raiod;


           
            fprintf(f,"%f %f %f \n",cp1(nr, nslc), nstk, cp2(nr, nslc));
            fprintf(f,"%f %f %f \n",cp1(r, slc), stk, cp2(r, slc));
            fprintf(f,"%f %f %f \n",cp1(r, nslc), stk, cp2(r, nslc));



            
            fprintf(f,"%f %f %f \n",cp1(nr, slc), nstk, cp2(nr, slc));
            fprintf(f,"%f %f %f \n",cp1(r, slc), stk, cp2(r, slc));
            fprintf(f,"%f %f %f \n",cp1(nr, nslc), nstk, cp2(nr, nslc));

        }

        // codigo responsavel por gerar a slice do topo
        slc = i * slcd;
        nslc = (i+1) * slcd;
        stk = (stacks - j) * stkd;
        r = j * raiod;


       
        fprintf(f,"%f %f %f \n",0.0, altura, 0.0);
        fprintf(f,"%f %f %f \n",cp1(r, slc), stk, cp2(r, slc));
        fprintf(f,"%f %f %f \n",cp1(r, nslc), stk, cp2(r, nslc));

    }

   

}

void printPlano(float tam,FILE *f){

    fprintf(f,"%f %f %f \n",tam/2,0.0,tam/2);
    fprintf(f,"%f %f %f \n",-tam/2,0.0,tam/2);
    fprintf(f,"%f %f %f \n",tam/2,0.0,-tam/2);

    fprintf(f,"%f %f %f \n",tam/2,0.0,tam/2);
    fprintf(f,"%f %f %f \n",tam/2,0.0,-tam/2);
    fprintf(f,"%f %f %f \n",-tam/2,0.0,tam/2);

    fprintf(f,"%f %f %f \n",tam/2,0.0,-tam/2);
    fprintf(f,"%f %f %f \n",-tam/2,0.0,tam/2);
    fprintf(f,"%f %f %f \n",-tam/2,0.0,-tam/2);

    fprintf(f,"%f %f %f \n",tam/2,0.0,-tam/2);
    fprintf(f,"%f %f %f \n",-tam/2,0.0,-tam/2);
    fprintf(f,"%f %f %f \n",-tam/2,0.0,tam/2);
}

float* cb (  float* p0 , float* p1 ,float* p2 ,float* p3 ,int u ){
    float* r=(float*) malloc(sizeof(float)*3);
    float b0 = B0(u);
    float b1 = B1(u);
    float b2 = B2(u);
    float b3 = B3(u);
    r[0] = b0 * p0[0] + b1 * p1[0] + b2 * p2[0] + b3 * p3[0];
    r[1] = b0 * p0[1] + b1 * p1[1] + b2 * p2[1] + b3 * p3[1];
    r[2] = b0 * p0[2] + b1 * p1[2] + b2 * p2[2] + b3 * p3[2];
    return r;
} 


float* bezierSurfPoint (float u , float v , float pts[4][4][4]){
    
    float* p0 = cb(pts[0][0], pts[0][1], pts[0][2], pts[0][3], u );
    float* p1 = cb(pts[1][0], pts[1][1], pts[1][2], pts[1][3], u );
    float* p2 = cb(pts[2][0], pts[2][1], pts[2][2], pts[2][3], u );
    float* p3 = cb(pts[3][0], pts[3][1], pts[3][2], pts[3][3], u );
    
    float* r=  cb(p0,p1,p2,p3,v) ;
    
    return r;
}


void parsePatches(std::string ficheiro) {

    std::ifstream file;
    std::string s = "./";
    s.append(ficheiro.c_str());
    file.open(s.c_str());
    std::vector< std::vector<int> > patchesIndx;
    std::vector< Ponto > pontos;
    int nrPatches;

    file >> nrPatches;

    for(int k = 0; k < nrPatches; k++) {
        std::vector<int> indices;
        int inx;
        for(int i = 0; i < 16; i++) {
            file >> inx;
            indices.push_back(inx);
            if(file.peek() == ',') {
                file.ignore();
            }
        }
        patchesIndx.push_back(indices);
    }

    int nrPoints;

    file >> nrPoints;

    for(int k = 0; k < nrPoints; k++) {
        Ponto i;
        file >> i.x; 
        if(file.peek() == ',') {
            file.ignore();
        }
        file >> i.y;
        if(file.peek() == ',') {
            file.ignore();
        }
        file >> i.z;
        pontos.push_back(i);
    }
}

//void printBezierSurf(std::string ficheiro ,int tess, FILE *out){
void printBezierSurf(int tess, FILE *out){
    //parsePatches(ficheiro);
    float pts[4][4][4] = { {{4,2,3,0}, {1,2,0,0}, {2,2,2,0}, {3,1,2,0}},
                           {{2,2,2,0}, {3,2,1,0}, {4,2,3,0}, {3,2,1,0}},
                           {{1,1,1,0}, {3,2,1,0}, {4,2,3,0}, {3,2,1,0}},
                           {{2,1,3,0}, {7,1,2,0}, {9,1,3,0}, {2,6,3,0}},
                        };
    float* x = bezierSurfPoint(1,1,pts);
    printf("\n%f\n%f\n%f\n", x[0],  x[1] , x[2] );
}

int main( int i ,char *args[] ) {

    if ( !strcmp("cone", args[1]) ){
        FILE *f = fopen( args[6],"w");
        printCone( atof(args[2]), atof(args[3]), atof(args[4]), atof(args[5]), f);
        fclose(f);
    }
    else if ( !strcmp("caixa", args[1]) ){
        FILE *f = fopen( args[5],"w");
        printBox( atof(args[2]), atof(args[3]), atof(args[4]), f);
        fclose(f);
    }
    else if ( !strcmp("esfera", args[1]) ){
        FILE *f = fopen( args[5],"w");
        printSphere( atof( args[2] ), atof( args[3] ), atof( args[4] ), f);
        fclose(f);
    }
    else if ( !strcmp("plano", args[1]) ){
        FILE *f = fopen( args[3],"w");
        printPlano( atof( args[2] ),f );
        fclose(f);
    }
    else if ( !strcmp("bezier", args[1]) ){
        FILE *f = fopen( args[2],"w");
        printBezierSurf( atoi( args[2]), f );
        fclose(f);
    }
    
    return 0;
}







