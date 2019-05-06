#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <fstream>
#include <vector>
#include <iostream>
#define F_PI (float)M_PI
#define cp1(r, a)     (r * sin(a))
#define cp2(r, a)     (r * cos(a))
#define ce1(r, a, b)  (r * cos(b) * sin(a))
#define ce2(r, b)     (r * sin(b))
#define ce3(r, a, b)  (r * cos(b) * cos(a))
#define norma(a,b,c)  ( sqrt(a*a + b*b + c*c) )
#define texX(a)       (a/(2.0*F_PI))
#define texY(b)       ((b/F_PI)+0.5)
using namespace std;


struct Ponto {
    float x;
    float y;
    float z;
};



void printSphere(float radius, int slices, int stacks, FILE* f){
   
    //numero de vertices
    fprintf(f,"%d\n", slices*(6+(stacks-2)*6)*3 );
   
    // variaveis que vem o numero da stack atual
    vector<float> vertices; 
    vector<float> normais ;
    vector<float> textura ;
    float stkd, slcd;
    float slc, stk, nslc, nstk;

    int j;

    
    // delta dos angulos por stack
    stkd = M_PI / stacks;

    // delta dos angulos por slice
    slcd = 2 * M_PI / slices;

    //base
    for(int i = 0; i < slices; ++i) {

        j = 1;
        slc = i * slcd;
        nslc = (i+1) * slcd;
        stk = -M_PI_2 + j * stkd;

        vertices.push_back(0.0);
        vertices.push_back(-radius);
        vertices.push_back(0.0);
        
        normais.push_back(0.0);
        normais.push_back(-1.0);
        normais.push_back(0.0);
        
        textura.push_back( 0.0 );
        textura.push_back( 0.0 );

        vertices.push_back(ce1(radius, nslc, stk));
        vertices.push_back(ce2(radius, stk));
        vertices.push_back(ce3(radius, nslc, stk));

        normais.push_back( ce1( 1.0, nslc, stk) );
        normais.push_back( ce2( 1.0, stk) );
        normais.push_back( ce3( 1.0, nslc, stk) );


        textura.push_back( texX(nslc) );
        textura.push_back( texY(stk) );
        
        vertices.push_back( ce1(radius, slc, stk));
        vertices.push_back( ce2(radius, stk));
        vertices.push_back( ce3(radius, slc, stk));

        normais.push_back( ce1(1.0, slc, stk) );
        normais.push_back( ce2(1.0, stk) );
        normais.push_back( ce3(1.0, slc, stk) );
        
        textura.push_back( texX(slc) );
        textura.push_back( texY(stk) );

        for(; j < stacks-1; ++j) {

            slc = i * slcd;
            nslc = (i+1) * slcd;
            stk = -M_PI_2 + j * stkd;
            nstk = -M_PI_2 + (j+1) * stkd;
            
            vertices.push_back( ce1(radius, nslc, nstk) );
            vertices.push_back( ce2(radius, nstk) );
            vertices.push_back( ce3(radius, nslc, nstk) );

            normais.push_back( ce1(1.0, nslc, nstk) );
            normais.push_back( ce2(1.0, nstk) );
            normais.push_back( ce3(1.0, nslc, nstk) );
        
            textura.push_back( texX(nslc) );
            textura.push_back( texY(nstk) );
           
            vertices.push_back( ce1(radius, slc, stk));
            vertices.push_back( ce2(radius, stk));
            vertices.push_back( ce3(radius, slc, stk));

            normais.push_back( ce1(1, slc, stk) );
            normais.push_back( ce2(1, stk));
            normais.push_back( ce3(1, slc, stk) );
        
            textura.push_back( texX(slc) );
            textura.push_back( texY(stk) );
            
            vertices.push_back( ce1(radius, nslc, stk));
            vertices.push_back( ce2(radius, stk));
            vertices.push_back( ce3(radius, nslc, stk));

            normais.push_back( ce1(1, nslc, stk) );
            normais.push_back( ce2(1, stk));
            normais.push_back( ce3(1, nslc, stk) );
        
            textura.push_back( texX(nslc) );
            textura.push_back( texY(stk) );

            vertices.push_back( ce1(radius, slc, nstk));
            vertices.push_back( ce2(radius, nstk));
            vertices.push_back( ce3(radius, slc, nstk));
            
            normais.push_back( ce1(1, slc, nstk) );
            normais.push_back( ce2(1, nstk) );
            normais.push_back( ce3(1, slc, nstk) );
        
            textura.push_back( texX(slc) );
            textura.push_back( texY(nstk) );
            
            vertices.push_back( ce1(radius, slc, stk));
            vertices.push_back( ce2(radius, stk));
            vertices.push_back( ce3(radius, slc, stk));

            normais.push_back( ce1(1, slc, stk));
            normais.push_back( ce2(1, stk));
            normais.push_back( ce3(1, slc, stk) );
        
            textura.push_back( texX(slc) );
            textura.push_back( texY(stk) );
            
            vertices.push_back( ce1(radius, nslc, nstk)) ;
            vertices.push_back( ce2(radius, nstk) );
            vertices.push_back( ce3(radius, nslc, nstk) );

            normais.push_back( ce1(1, nslc, nstk) );
            normais.push_back( ce2(1, nstk) );
            normais.push_back( ce3(1, nslc, nstk) );
        
            textura.push_back( texX(nslc) );
            textura.push_back( texY(nstk));

        }

        slc = i * slcd;
        nslc = (i+1) * slcd;
        stk = -M_PI / 2 + j * stkd;

        vertices.push_back(0.0);
        vertices.push_back(radius);
        vertices.push_back(0.0);

        normais.push_back(0.0);
        normais.push_back(1.0);
        normais.push_back(0.0);
        
        textura.push_back(1.0);
        textura.push_back(1.0);
        
        vertices.push_back( ce1(radius, slc, stk) );
        vertices.push_back( ce2(radius, stk) );
        vertices.push_back( ce3(radius, slc, stk) );

        normais.push_back( ce1(1, slc, stk) );
        normais.push_back( ce2(1, stk) );
        normais.push_back( ce3(1, slc, stk) );
        
        textura.push_back( texX(slc) );
        textura.push_back( texY(stk) );
        
        vertices.push_back( ce1(radius, nslc, stk) );
        vertices.push_back( ce2(radius, stk) );
        vertices.push_back( ce3(radius, nslc, stk) );

        normais.push_back( ce1(1, nslc, stk) );
        normais.push_back( ce2(1, stk) );
        normais.push_back( ce3(1, nslc, stk) );
        
        textura.push_back( texX(nslc) );
        textura.push_back( texY(stk) );

    }

     for(float i:vertices){
        fprintf(f,"%f\n",i);
    }

    for(float i:normais){
        fprintf(f,"%f\n",i);
    }

    for(float i:textura){
        fprintf(f,"%f\n",i);
    }

}

void printBox ( int ndivs, float xx , float yy , float zz , FILE *f ){
    
    fprintf(f,"%d\n", 6*6*ndivs*ndivs*3 );
    
    vector<float> vertices; 
    vector<float> normais ;
    vector<float> textura ;

    float xxdelta , yydelta , zzdelta ;
    xxdelta = xx /ndivs;
    yydelta = yy /ndivs;
    zzdelta = zz /ndivs;

    float texdelta = 1.0 / ndivs;
    //front
    for (int i = 0; i < ndivs; i++)
    {
        for (int j = 0; j < ndivs; j++)
        {
            vertices.push_back( i*xxdelta-xx/2);
            vertices.push_back( j*yydelta-yy/2);
            vertices.push_back( zz/2);
            
            normais.push_back(0.0);
            normais.push_back(0.0);
            normais.push_back(1.0);

            textura.push_back( i*texdelta );
            textura.push_back( j*texdelta );

            vertices.push_back( (i+1)*xxdelta-xx/2);
            vertices.push_back( (j+1)*yydelta-yy/2);
            vertices.push_back( zz/2);

            normais.push_back(0.0);
            normais.push_back(0.0);
            normais.push_back(1.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );
            
            vertices.push_back( i*xxdelta-xx/2);
            vertices.push_back( (j+1)*yydelta-yy/2);
            vertices.push_back( zz/2);

            normais.push_back(0.0);
            normais.push_back(0.0);
            normais.push_back(1.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );
            
            vertices.push_back(i*xxdelta-xx/2);
            vertices.push_back(  j*yydelta-yy/2);
            vertices.push_back( zz/2);

            normais.push_back(0.0);
            normais.push_back(0.0);
            normais.push_back(1.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );
            
            vertices.push_back((i+1)*xxdelta-xx/2);
            vertices.push_back( j*yydelta-yy/2);
            vertices.push_back( zz/2);

            normais.push_back(0.0);
            normais.push_back(0.0);
            normais.push_back(1.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );
            
            vertices.push_back( (i+1)*xxdelta-xx/2);
            vertices.push_back( (j+1)*yydelta-yy/2);
            vertices.push_back( zz/2);

            normais.push_back(0.0);
            normais.push_back(0.0);
            normais.push_back(1.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );

        }
    }
    //back
    for (int i = 0; i < ndivs; i++)
    {
        for (int j = 0; j < ndivs; j++)
        {   

            vertices.push_back( i*xxdelta-xx/2);
            vertices.push_back(  j*yydelta-yy/2);
            vertices.push_back( -zz/2);

            normais.push_back(0.0);
            normais.push_back(0.0);
            normais.push_back(-1.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );
            
            vertices.push_back( (i+1)*xxdelta-xx/2);
            vertices.push_back((j+1)*yydelta-yy/2);
            vertices.push_back( -zz/2); 

            normais.push_back(0.0);
            normais.push_back(0.0);
            normais.push_back(-1.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );          
            
            vertices.push_back( i*xxdelta-xx/2);            
            vertices.push_back( (j+1)*yydelta-yy/2);            
            vertices.push_back( -zz/2);  

            normais.push_back(0.0);
            normais.push_back(0.0);
            normais.push_back(-1.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );         
            
            vertices.push_back( i*xxdelta-xx/2);            
            vertices.push_back( j*yydelta-yy/2);            
            vertices.push_back( -zz/2); 

            normais.push_back(0.0);
            normais.push_back(0.0);
            normais.push_back(-1.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );          
            
            vertices.push_back( (i+1)*xxdelta-xx/2);            
            vertices.push_back( j*yydelta-yy/2);            
            vertices.push_back( -zz/2); 

            normais.push_back(0.0);
            normais.push_back(0.0);
            normais.push_back(-1.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );        
            
            vertices.push_back( (i+1)*xxdelta-xx/2);            
            vertices.push_back( (j+1)*yydelta-yy/2);            
            vertices.push_back( -zz/2); 

            normais.push_back(0.0);
            normais.push_back(0.0);
            normais.push_back(-1.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );       
            
        }
    }
    //top
    for (int i = 0; i < ndivs; i++)
    {
        for (int j = 0; j < ndivs; j++)
        {
            vertices.push_back( i*xxdelta-xx/2);            
            vertices.push_back( yy/2);            
            vertices.push_back( j*zzdelta-zz/2); 

            normais.push_back(0.0);
            normais.push_back(1.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );
            
            vertices.push_back( (i+1)*xxdelta-xx/2); 
            vertices.push_back( yy/2); 
            vertices.push_back( (j+1)*zzdelta-zz/2 ); 

            normais.push_back(0.0);
            normais.push_back(1.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );
            
            vertices.push_back( i*xxdelta-xx/2);
            vertices.push_back( yy/2);
            vertices.push_back((j+1)*zzdelta-zz/2);

            normais.push_back(0.0);
            normais.push_back(1.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );

            vertices.push_back( i*xxdelta-xx/2);
            vertices.push_back( yy/2);
            vertices.push_back( j*zzdelta-zz/2);

            normais.push_back(0.0);
            normais.push_back(1.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );
            
            vertices.push_back( (i+1)*xxdelta-xx/2);
            vertices.push_back( yy/2);
            vertices.push_back( j*zzdelta-zz/2);

            normais.push_back(0.0);
            normais.push_back(1.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );
            
            vertices.push_back( (i+1)*xxdelta-xx/2);
            vertices.push_back( yy/2);
            vertices.push_back( (j+1)*zzdelta-zz/2);

            normais.push_back(0.0);
            normais.push_back(1.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );


        }
    }

    //bottom
    for (int i = 0; i < ndivs; i++)
    {
        for (int j = 0; j < ndivs; j++)
        {   
            vertices.push_back(i*xxdelta-xx/2);
            vertices.push_back(-yy/2);
            vertices.push_back(j*zzdelta-zz/2);

            normais.push_back(0.0);
            normais.push_back(-1.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );
            
            vertices.push_back((i+1)*xxdelta-xx/2);
            vertices.push_back(-yy/2);
            vertices.push_back((j+1)*zzdelta-zz/2);

            normais.push_back(0.0);
            normais.push_back(-1.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );

            vertices.push_back(i*xxdelta-xx/2);
            vertices.push_back(-yy/2);
            vertices.push_back((j+1)*zzdelta-zz/2);

            normais.push_back(0.0);
            normais.push_back(-1.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );
           
            vertices.push_back(i*xxdelta-xx/2);
            vertices.push_back(-yy/2);
            vertices.push_back(j*zzdelta-zz/2);

            normais.push_back(0.0);
            normais.push_back(-1.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );

            vertices.push_back((i+1)*xxdelta-xx/2);
            vertices.push_back(-yy/2);
            vertices.push_back(j*zzdelta-zz/2);

            normais.push_back(0.0);
            normais.push_back(-1.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );

            vertices.push_back((i+1)*xxdelta-xx/2);
            vertices.push_back(-yy/2);
            vertices.push_back((j+1)*zzdelta-zz/2);

            normais.push_back(0.0);
            normais.push_back(-1.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );
            

        }
    }

    //righty
     for (int i = 0; i < ndivs; i++)
    {
        for (int j = 0; j < ndivs; j++)
        {   
            vertices.push_back(xx/2);
            vertices.push_back(i*yydelta-yy/2);
            vertices.push_back(j*zzdelta-zz/2);

            normais.push_back(1.0);
            normais.push_back(0.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );

            vertices.push_back(xx/2);
            vertices.push_back((i+1)*yydelta-yy/2);
            vertices.push_back((j+1)*zzdelta-zz/2);

            normais.push_back(1.0);
            normais.push_back(0.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );
            
            vertices.push_back(xx/2);
            vertices.push_back(i*yydelta-yy/2);
            vertices.push_back((j+1)*zzdelta-zz/2);

            normais.push_back(1.0);
            normais.push_back(0.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );
            
            vertices.push_back(xx/2);
            vertices.push_back(i*yydelta-yy/2);
            vertices.push_back(j*zzdelta-zz/2);

            normais.push_back(1.0);
            normais.push_back(0.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );

            vertices.push_back(xx/2);
            vertices.push_back((i+1)*yydelta-yy/2);
            vertices.push_back(j*zzdelta-zz/2 );

            normais.push_back(1.0);
            normais.push_back(0.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );

            vertices.push_back(xx/2);
            vertices.push_back((i+1)*yydelta-yy/2);
            vertices.push_back((j+1)*zzdelta-zz/2 );

            normais.push_back(1.0);
            normais.push_back(0.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );
        }
    }
    //lefty
     for (int i = 0; i < ndivs; i++)
    {
        for (int j = 0; j < ndivs; j++)
        {
            vertices.push_back(-xx/2);
            vertices.push_back(i*yydelta-yy/2);
            vertices.push_back(j*zzdelta-zz/2);

            normais.push_back(-1.0);
            normais.push_back(0.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );

            vertices.push_back(-xx/2);
            vertices.push_back((i+1)*yydelta-yy/2);
            vertices.push_back((j+1)*zzdelta-zz/2);

            normais.push_back(-1.0);
            normais.push_back(0.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );
            
            vertices.push_back(-xx/2);
            vertices.push_back(i*yydelta-yy/2);
            vertices.push_back((j+1)*zzdelta-zz/2);

            normais.push_back(-1.0);
            normais.push_back(0.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );
            
            vertices.push_back(-xx/2);
            vertices.push_back(i*yydelta-yy/2);
            vertices.push_back(j*zzdelta-zz/2);

            normais.push_back(-1.0);
            normais.push_back(0.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );

            vertices.push_back(-xx/2);
            vertices.push_back((i+1)*yydelta-yy/2);
            vertices.push_back(j*zzdelta-zz/2 );

            normais.push_back(-1.0);
            normais.push_back(0.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );

            vertices.push_back(-xx/2);
            vertices.push_back((i+1)*yydelta-yy/2);
            vertices.push_back((j+1)*zzdelta-zz/2 );

            normais.push_back(-1.0);
            normais.push_back(0.0);
            normais.push_back(0.0);

            textura.push_back(i*texdelta );
            textura.push_back(j*texdelta );

        }
    }

    for(float i:vertices){
        fprintf(f,"%f\n",i);
    }

    for(float i:normais){
        fprintf(f,"%f\n",i);
    }

    for(float i:textura){
        fprintf(f,"%f\n",i);
    }

}

void printCone(float radius, float altura, int slices, int stacks, FILE *f) {
    
     //numero de vertices
    fprintf(f,"%d\n", slices*(6+(stacks-1)*6)*3 );

    vector<float> vertices; 
    vector<float> normais ;
    vector<float> textura ;

    float stkd, slcd, raiod;
    float stk, slc, nslc, nstk, nr, r;

    stkd = altura / stacks;
    slcd = 2 * M_PI / slices;
    raiod = radius / stacks;

    float n[6];
    int j;

    for(int i = 0; i < slices; i++) {

        // codigo responsavel por gerar uma slice da base

        slc = i * slcd;
        nslc = (i+1) * slcd;

        vertices.push_back(0.0);       
        vertices.push_back(0.0);       
        vertices.push_back(0.0);

        normais.push_back(0.0);
        normais.push_back(-1.0);
        normais.push_back(0.0);

        //textura.push_back();
        //textura.push_back();

        vertices.push_back(cp1(radius, nslc));
        vertices.push_back(0.0);
        vertices.push_back(cp2(radius, nslc));

        normais.push_back( 0.0  );
        normais.push_back( -1.0 );
        normais.push_back( 0.0 );

        //textura.push_back();
        //textura.push_back();

        vertices.push_back( cp1(radius, slc) );
        vertices.push_back( 0.0 );
        vertices.push_back( cp2(radius, slc) );

        normais.push_back( 0.0 );
        normais.push_back( -1.0 );
        normais.push_back( 0.0 );

        //textura.push_back();
        //textura.push_back();

        // codigo responsavel por gerar as slices laterais
        for(j = stacks ; j > 1; j--) {

            slc = i * slcd;
            nslc = (i+1) * slcd;
            stk = (stacks - j) * stkd;
            nstk = (stacks - (j-1)) * stkd;
            r = j * raiod;
            nr = (j - 1) * raiod;
            
            n[0] = norma(cp1(nr, nslc),nstk,cp2(nr, nslc) );
            n[1] = norma(cp1(r, slc), stk, cp2(r, slc) );
            n[2] = norma(cp1(r, nslc), stk ,cp2(r, nslc));
            n[3] = norma(cp1(nr, slc), nstk, cp2(nr, slc) );
            n[4] = norma(cp1(r,slc) , stk, cp2(r, slc) );
            n[5] = norma(cp1(nr, nslc), nstk, cp2(nr, nslc));

            vertices.push_back(cp1(nr, nslc));
            vertices.push_back(nstk);
            vertices.push_back(cp2(nr, nslc));

            normais.push_back( cp1(nr,nslc) /n[0] );
            normais.push_back( nstk/n[0] );
            normais.push_back( cp2(nr, nslc) /n[0] );

           //  textura.push_back();
           // textura.push_back();

            vertices.push_back(cp1(r, slc));
            vertices.push_back(stk);
            vertices.push_back( cp2(r, slc));
            
            normais.push_back(cp1(r, slc) /n[1]);
            normais.push_back(stk/n[1]);
            normais.push_back(cp2(r, slc)/n[1]);

            //textura.push_back();
            //textura.push_back();

            vertices.push_back(cp1(r, nslc));
            vertices.push_back(stk);
            vertices.push_back(cp2(r, nslc));

            normais.push_back(cp1(r, nslc) /n[2]);
            normais.push_back(stk/n[2]);
            normais.push_back(cp2(r, nslc)/n[2]);

            //textura.push_back();
            //textura.push_back();

            vertices.push_back(cp1(nr, slc));
            vertices.push_back(nstk);
            vertices.push_back(cp2(nr, slc));

            normais.push_back(cp1(nr, slc) /n[3]);
            normais.push_back(nstk/n[3]);
            normais.push_back(cp2(nr, slc)/n[3]);

            //textura.push_back();
            //textura.push_back();
            
            vertices.push_back(cp1(r, slc));
            vertices.push_back(stk);
            vertices.push_back(cp2(r, slc));

            normais.push_back(cp1(r, slc) /n[4]);
            normais.push_back(stk/n[4]);
            normais.push_back(cp2(r, slc)/n[4]);

            //textura.push_back();
            //textura.push_back();
            
            vertices.push_back(cp1(nr, nslc));
            vertices.push_back(nstk);
            vertices.push_back(cp2(nr, nslc));

            normais.push_back(cp1(nr, nslc) /n[5]);
            normais.push_back(nstk/n[5]);
            normais.push_back(cp2(nr, nslc) /n[5]);

            //textura.push_back();
            //textura.push_back();

        }
        // codigo responsavel por gerar a slice do topo
        slc = i * slcd;
        nslc = (i+1) * slcd;
        stk = (stacks - j) * stkd;
        r = j * raiod;

        vertices.push_back(0.0);
        vertices.push_back(altura);
        vertices.push_back(0.0);
        
        vertices.push_back(cp1(r, slc));
        vertices.push_back(stk);
        vertices.push_back( cp2(r, slc));
        
        vertices.push_back(cp1(r, nslc));
        vertices.push_back(stk);
        vertices.push_back(cp2(r, nslc));
    }

}

void printPlano(float tam,FILE *f){

    vector<float> vertices; 
    vector<float> normais ;
    vector<float> textura ;

    
    fprintf(f,"36\n");

    vertices.push_back(tam/2);
    vertices.push_back(0.0);
    vertices.push_back(tam/2);
    
    normais.push_back(0.0);
    normais.push_back(1.0);
    normais.push_back(0.0);

    textura.push_back(1.0);
    textura.push_back(0.0);

    vertices.push_back(-tam/2);
    vertices.push_back(0.0);
    vertices.push_back(tam/2);
    
    normais.push_back(0.0);
    normais.push_back(1.0);
    normais.push_back(0.0);

    textura.push_back(0.0);
    textura.push_back(0.0);

    vertices.push_back(tam/2);
    vertices.push_back(0.0);
    vertices.push_back(-tam/2);
    
    normais.push_back(0.0);
    normais.push_back(1.0);
    normais.push_back(0.0);

    textura.push_back(1.0);
    textura.push_back(1.0);

    vertices.push_back(tam/2);
    vertices.push_back(0.0);
    vertices.push_back(tam/2);
    
    normais.push_back(0.0);
    normais.push_back(1.0);
    normais.push_back(0.0);

    textura.push_back(1.0);
    textura.push_back(0.0);

    vertices.push_back(tam/2);
    vertices.push_back(0.0);
    vertices.push_back(-tam/2);
    
    normais.push_back(0.0);
    normais.push_back(1.0);
    normais.push_back(0.0);

    textura.push_back(1.0);
    textura.push_back(1.0);

    vertices.push_back(-tam/2);
    vertices.push_back(0.0);
    vertices.push_back(tam/2);
    
    normais.push_back(0.0);
    normais.push_back(1.0);
    normais.push_back(0.0);
    
    textura.push_back(0.0);
    textura.push_back(0.0);

    vertices.push_back(tam/2);
    vertices.push_back(0.0);
    vertices.push_back(-tam/2);

    normais.push_back(0.0);
    normais.push_back(1.0);
    normais.push_back(0.0);

    textura.push_back(1.0);
    textura.push_back(1.0);

    vertices.push_back(-tam/2);
    vertices.push_back(0.0);
    vertices.push_back(tam/2);
    
    normais.push_back(0.0);
    normais.push_back(1.0);
    normais.push_back(0.0);

    textura.push_back(0.0);
    textura.push_back(0.0);

    vertices.push_back(-tam/2);
    vertices.push_back(0.0);
    vertices.push_back(-tam/2);
    
    normais.push_back(0.0);
    normais.push_back(1.0);
    normais.push_back(0.0);

    textura.push_back(0.0);
    textura.push_back(1.0);

    vertices.push_back(tam/2);
    vertices.push_back(0.0);
    vertices.push_back(-tam/2);
    
    normais.push_back(0.0);
    normais.push_back(1.0);
    normais.push_back(0.0);

    textura.push_back(1.0);
    textura.push_back(1.0);

    vertices.push_back(-tam/2);
    vertices.push_back(0.0);
    vertices.push_back(-tam/2);
    
    normais.push_back(0.0);
    normais.push_back(1.0);
    normais.push_back(0.0);

    textura.push_back(1.0);
    textura.push_back(0.0);

    vertices.push_back(-tam/2);
    vertices.push_back(0.0);
    vertices.push_back(tam/2);
    
    normais.push_back(0.0);
    normais.push_back(1.0);
    normais.push_back(0.0);

    textura.push_back(0.0);
    textura.push_back(0.0);

    for( float i: vertices ){
        fprintf(f,"%f\n", i);
    }

    for( float i: normais ){
        fprintf(f,"%f\n", i);
    }

    for( float i: textura ){
        fprintf(f,"%f\n", i);
    }

}

int main( int i ,char *args[] ) {

    if ( !strcmp("cone", args[1]) ){
        FILE *f = fopen( args[6],"w");
        printCone( atof(args[2]), atof(args[3]), atof(args[4]), atof(args[5]), f);
        fclose(f);
    }
    else if ( !strcmp("caixa", args[1]) ){
        FILE *f = fopen( args[6],"w");
        printBox( atof(args[2]), atof(args[3]), atof(args[4]), atof(args[5]), f);
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
    
    return 0;
}







