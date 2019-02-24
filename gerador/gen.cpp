#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define cp1(r, a)     (r * sin(a))
#define cp2(r, a)     (r * cos(a))


#define ce1(r, a, b)  (r * cos(b) * sin(a))
#define ce2(r, b)     (r * sin(b))
#define ce3(r, a, b)  (r * cos(b) * cos(a))

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
    fprintf(f,"%f %f %f \n",0.0,0.0,zz );
    fprintf(f,"%f %f %f \n",xx,0.0,zz);
    fprintf(f,"%f %f %f \n",xx,yy,zz);
    fprintf(f,"%f %f %f \n",xx,yy,zz);
    fprintf(f,"%f %f %f \n",0.0,yy,zz);
    fprintf(f,"%f %f %f \n",0.0,0.0,zz);
    fprintf(f,"%f %f %f \n",0.0,0.0,0.0);
    fprintf(f,"%f %f %f \n",xx,yy,0.0);
    fprintf(f,"%f %f %f \n",xx,0.0,0.0);
    fprintf(f,"%f %f %f \n",xx,yy,0.0);
    fprintf(f,"%f %f %f \n",0.0,0.0,0.0);
    fprintf(f,"%f %f %f \n",0.0,yy,0.0);
    fprintf(f,"%f %f %f \n",xx,yy,zz);
    fprintf(f,"%f %f %f \n",xx,yy,0.0);
    fprintf(f,"%f %f %f \n",0.0,yy,0.0);
    fprintf(f,"%f %f %f \n",xx,yy,zz);
    fprintf(f,"%f %f %f \n",0.0,yy,0.0);
    fprintf(f,"%f %f %f \n",0.0,yy,zz);
    fprintf(f,"%f %f %f \n",xx,0.0,zz);
    fprintf(f,"%f %f %f \n",0.0,0.0,0.0);
    fprintf(f,"%f %f %f \n",xx,0.0,0.0);
    fprintf(f,"%f %f %f \n",0.0,0.0,0.0);
    fprintf(f,"%f %f %f \n",xx,0.0,zz);
    fprintf(f,"%f %f %f \n",0.0,0.0,zz);
    fprintf(f,"%f %f %f \n",xx,0.0,zz);
    fprintf(f,"%f %f %f \n",xx,0.0,0.0);
    fprintf(f,"%f %f %f \n",xx,yy,0.0);
    fprintf(f,"%f %f %f \n",xx,yy,0.0);
    fprintf(f,"%f %f %f \n",xx,yy,zz);
    fprintf(f,"%f %f %f \n",xx,0.0,zz);
    fprintf(f,"%f %f %f \n",0.0,0.0,zz);
    fprintf(f,"%f %f %f \n",0.0,yy,0.0);
    fprintf(f,"%f %f %f \n",0.0,0.0,0.0);
    fprintf(f,"%f %f %f \n",0.0,0.0,zz);
    fprintf(f,"%f %f %f \n",0.0,yy,zz);
    fprintf(f,"%f %f %f \n",0.0,yy,0.0);
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
    fprintf(f,"%f %f %f \n",tam/2,tam/2, 0.0);
    fprintf(f,"%f %f %f \n",-tam/2,tam/2, 0.0);
    fprintf(f,"%f %f %f \n",tam/2,-tam/2, 0.0);

    fprintf(f,"%f %f %f \n",tam/2,tam/2, 0.0);
    fprintf(f,"%f %f %f \n",tam/2,-tam/2, 0.0);
    fprintf(f,"%f %f %f \n",-tam/2,tam/2, 0.0);

    fprintf(f,"%f %f %f \n",tam/2,-tam/2, 0.0);
    fprintf(f,"%f %f %f \n",-tam/2,tam/2, 0.0);
    fprintf(f,"%f %f %f \n",-tam/2,-tam/2, 0.0);

    fprintf(f,"%f %f %f \n",tam/2,-tam/2, 0.0);
    fprintf(f,"%f %f %f \n",-tam/2,-tam/2, 0.0);
    fprintf(f,"%f %f %f \n",-tam/2,tam/2, 0.0);
}

int main( int i ,char *args[] ) {
    FILE *f = fopen( "pontos.txt","w");
    
    if ( !strcmp("cone", args[1]) ){
        
        printCone( atof(args[2]), atof(args[3]), atof(args[4]), atof(args[5]), f);
    }
    else {
        if ( !strcmp("caixa", args[1]) ){
            
            printBox( atof(args[2]), atof(args[3]), atof(args[4]), f);
        }
        else{
            if ( !strcmp("esfera", args[1]) ){
                
                printSphere( atof( args[2] ), atof( args[3] ), atof( args[4] ), f);
            }
            else {
                if ( !strcmp("plano", args[1]) ){

                    printPlano( atof( args[2] ),f );
                }
            }
        }
    }
    fclose(f);
    return 0;
}







