#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define pol1(r, a, b)  (r * cos(b) * cos(a))
#define pol2(r, a, b)  (r * cos(b) * sin(a))
#define pol3(r, b)     (r * sin(b))

void printSphere(float radius, int slices, int stacks, FILE* f){
    // variaveis que vem o numero da stack atual
    float stkd, slcd;
    int j;
    // delta dos angulos por stack
    stkd = M_PI / stacks;
    // delta dos angulos por slice
    slcd = 2 * M_PI / slices;

    for(int i = 0; i < slices; ++i) {

        j = -(stacks / 2) + 1;

        fprintf(f,"%f %f %f \n",pol1(radius, (i+1)*slcd, j*stkd), pol2(radius, (i+1)*slcd, j*stkd),
                   pol3(radius, j * stkd));
        fprintf(f,"%f %f %f \n",pol1(radius, i*slcd, j*stkd), pol2(radius, i*slcd, j*stkd),
                pol3(radius, j * stkd));
        fprintf(f,"%f %f %f \n",0.0, 0.0, -radius);

        for(; j < stacks / 2 - 1; ++j) {
            
            fprintf(f,"%f %f %f \n",pol1(radius, i*slcd, j*stkd), pol2(radius, i*slcd, j*stkd), pol3(radius, j*stkd));
            fprintf(f,"%f %f %f \n",pol1(radius, (i+1) * slcd, j*stkd), pol2(radius, (i+1)*slcd, j*stkd),
                    pol3(radius, j*stkd));
            fprintf(f,"%f %f %f \n",pol1(radius, (i+1)*slcd, (j+1) * stkd), pol2(radius, (i+1)*slcd, (j+1) * stkd),
                    pol3(radius, (j+1) * stkd));
            
            fprintf(f,"%f %f %f \n",pol1(radius, (i+1)*slcd, (j+1)*stkd), pol2(radius, (i+1)*slcd, (j+1)*stkd),
                    pol3(radius, (j+1)*stkd));
            fprintf(f,"%f %f %f \n",pol1(radius, i*slcd, (j+1)*stkd), pol2(radius, i*slcd, (j+1)*stkd),
                    pol3(radius, (j+1)*stkd));
            fprintf(f,"%f %f %f \n",pol1(radius, i*slcd, j*stkd), pol2(radius, i*slcd, j*stkd), pol3(radius, j*stkd));

        }
        
        fprintf(f,"%f %f %f \n",0.0, 0.0, radius);
        fprintf(f,"%f %f %f \n",pol1(radius, i*slcd, j*stkd), pol2(radius, i*slcd, j*stkd),
                pol3(radius, j * stkd));
        fprintf(f,"%f %f %f \n",pol1(radius, (i+1)*slcd, j*stkd), pol2(radius, (i+1)*slcd, j*stkd),
                   pol3(radius, j * stkd));
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

    stkd = altura / stacks;
    slcd = 2 * M_PI / slices;
    raiod = radius / stacks;

    int j;

   

    for(int i = 0; i < slices; i++) {

       
        fprintf(f,"%f %f %f \n",0.0, 0.0, 0.0);
        fprintf(f,"%f %f %f \n",radius * cos((i+1)*slcd), radius * sin((i+1)*slcd), 0.0);
        fprintf(f,"%f %f %f \n",radius * cos(i*slcd), radius * sin(i*slcd), 0.0);

        for(j = stacks; j > 1; j--) {

           
            fprintf(f,"%f %f %f \n",j * raiod * cos(i * slcd), j * raiod * sin(i * slcd), (stacks-j)*stkd);
            fprintf(f,"%f %f %f \n",j * raiod * cos((i + 1) * slcd), j * raiod * sin((i + 1) * slcd), (stacks-j)*stkd);
            fprintf(f,"%f %f %f \n",(j-1) * raiod * cos((i + 1) * slcd), (j-1) * raiod * sin((i + 1) * slcd),
                    (stacks-(j-1)) * stkd);


            
            fprintf(f,"%f %f %f \n",(j-1) * raiod * cos((i + 1) * slcd), (j-1) * raiod * sin((i + 1) * slcd),
                    (stacks-(j - 1))*stkd);
            fprintf(f,"%f %f %f \n",(j-1) * raiod * cos(i * slcd), (j-1) * raiod * sin(i * slcd),
                    (stacks-(j - 1))*stkd);
            fprintf(f,"%f %f %f \n",j * raiod * cos(i * slcd), j * raiod * sin(i * slcd), (stacks-j)*stkd);

        }


        
        fprintf(f,"%f %f %f \n",j * raiod * cos(i * slcd), j * raiod * sin(i * slcd), (stacks-j)*stkd);
        fprintf(f,"%f %f %f \n",j * raiod * cos((i + 1) * slcd), j * raiod * sin((i + 1) * slcd), (stacks-j)*stkd);
        fprintf(f,"%f %f %f \n",0.0, 0.0, altura);

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







