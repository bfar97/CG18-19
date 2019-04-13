#include <fstream>
#include <vector>
#include <iostream>

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
