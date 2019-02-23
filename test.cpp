//include tinyxml header
#include <iostream>
#include "tinyxml2.h"
#include <string>
#include <vector>
#include <fstream>

using namespace tinyxml2;

std::vector<std::string> ficheiros;

void printPontos(std::string ficheiro) {
  std::ifstream file;
  file.open(ficheiro.c_str());
  float a,b,c;
  while(file >> a >> b >> c) {
    printf("%f %f %f\n",a,b,c);
  }
}

int main(int argc, char **argv) {

	tinyxml2::XMLDocument doc;

	doc.LoadFile("./conf.xml");

    tinyxml2::XMLNode *scene = doc.FirstChild();

    while(scene) {
        for(tinyxml2::XMLElement* model = scene->FirstChildElement(); model != NULL; model = model->NextSiblingElement()) {
            const char * file;
            file = model->Attribute("file");
            ficheiros.push_back(file);
        }
        scene = scene->NextSiblingElement();
    }

    for(int i = 0; i < ficheiros.size(); i++) {
      printf("%s\n", ficheiros[i].c_str());
      printPontos(ficheiros[i].c_str());
    }



	return 1;
}
