#include "tinyxml2.h"
#include <stdio.h>
#include <string.h>
#include "timedsg.h"
#include <fstream>
#include <iostream>
#include <memory>
#include "pointLight.h"
#include "spotLight.h"
#include "directionLight.h"


int nLights = -1;

GLenum pickLight() {
  nLights += 1;
  GLenum res;
  switch (nLights) {
    case 0: res = GL_LIGHT0; break;
    case 1: res = GL_LIGHT1; break;
    case 2: res = GL_LIGHT2; break;
    case 3: res = GL_LIGHT3; break;
    case 4: res = GL_LIGHT4; break;
    case 5: res = GL_LIGHT5; break;
    case 6: res = GL_LIGHT6; break;
    case 7: res = GL_LIGHT7; break;
    default: perror("Numero possivel de luzes excedido."); break;
  }
  return res;
}

std::vector<float> guardaPontos(std::string ficheiro) {

    std::vector<float> pontos;

    std::ifstream file;
    //change this to your folder's path.
    std::string s = "./";
    s.append(ficheiro.c_str());
    file.open(s.c_str());
    float a,b,c;
    while(file >> a >> b >> c) {
        pontos.push_back(a);
        pontos.push_back(b);
        pontos.push_back(c);
    }
    return pontos;
}

std::vector<float> doModels(tinyxml2::XMLElement* models) {
    std::vector<float> pPontos;
    std::vector<float> savedPoints;

    tinyxml2::XMLElement* novo = models->FirstChildElement();
    for(novo; novo != NULL; novo = novo->NextSiblingElement()) {
        const char * file;
        file = novo->Attribute("file");
        savedPoints = guardaPontos(file);
        pPontos.insert(pPontos.begin(), savedPoints.begin(), savedPoints.end());
    }
    return pPontos;
}

TranslacaoV doTranslate(tinyxml2::XMLElement* translate) {

    TranslacaoV transl;

    array<float, 3> trans;

    const char * x;
    const char * y;
    const char * z;
    x = translate->Attribute("x");
    y = translate->Attribute("y");
    z = translate->Attribute("z");

    x == nullptr ? trans[0] = 0 : trans[0] = atoi(x);
    y == nullptr ? trans[1] = 0 : trans[1] = atoi(y);
    z == nullptr ? trans[2] = 0 : trans[2] = atoi(z);

    transl.setTrans(trans);

    return transl;
}

RotacaoV doRotate(tinyxml2::XMLElement* rotate) {

    RotacaoV rotation;

    array<float,4> rot;

    const char * x;
    const char * y;
    const char * z;
    const char * ang;
    x = rotate->Attribute("x");
    y = rotate->Attribute("y");
    z = rotate->Attribute("z");
    ang = rotate->Attribute("angle");

    ang == nullptr ? rot[0] = 0.0f : rot[0] = atoi(ang);
    x == nullptr ? rot[1] = 0.0f : rot[1] = atof(x);
    y == nullptr ? rot[2] = 0.0f : rot[2] = atof(y);
    z == nullptr ? rot[3] = 0.0f : rot[3] = atof(z);

    rotation.setRot(rot);

    return rotation;
}

Escala doScale(tinyxml2::XMLElement* scale) {

    Escala escala;

    array<float,3> sca;

    const char * x;
    const char * y;
    const char * z;

    x = scale->Attribute("x");
    y = scale->Attribute("y");
    z = scale->Attribute("z");

    x == nullptr ? sca[0] = 1.0f : sca[0] = atof(x);
    y == nullptr ? sca[1] = 1.0f : sca[1] = atof(y);
    z == nullptr ? sca[2] = 1.0f : sca[2] = atof(z);

    escala.setAxis(sca);

    return escala;
}

TranslacaoC doTimeTranslate(tinyxml2::XMLElement* translate) {

    TranslacaoC t;

    int tempo;
    tempo = atoi(translate->Attribute("time"));

    std::vector<Pontos> pontos;

    tinyxml2::XMLElement* point = translate->FirstChildElement();
    for(point; point != NULL; point = point->NextSiblingElement()) {
        Pontos aux;
        aux.a = atof(point->Attribute("x"));
        aux.b = atof(point->Attribute("y"));
        aux.c = atof(point->Attribute("z"));
        pontos.push_back(aux);
    }
    if(pontos.size() < 4) {
        perror("Sao necessarios no minimo 4 pontos");
    } else {
        t.setCurva(pontos, tempo);
    }
    return t;
}

RotacaoT doTimeRotate(tinyxml2::XMLElement* rotate) {

    RotacaoT rotation;

    std::array<float, 3> xyz;

    int tempo;

    xyz[0] = atof(rotate->Attribute("x"));
    xyz[1] = atof(rotate->Attribute("y"));
    xyz[2] = atof(rotate->Attribute("z"));

    tempo = atoi(rotate->Attribute("time"));

    rotation.setRot(xyz);
    rotation.setGraus(tempo);

    return rotation;
}

std::vector<std::shared_ptr<Luz>> doLights(tinyxml2::XMLElement* lights) {
  std::array<float, 3> pontos;
  std::array<float, 3> direction;
  float cutoff;
  const char * x;
  const char * y;
  const char * z;
  std::vector<std::shared_ptr<Luz>> res;
  //Sacar o First Element do bloco de luzes
  tinyxml2::XMLElement* light = lights->FirstChildElement();
  // percorrer todos os elementos do bloco LIGHTS
  for(light; light != NULL; light = light->NextSiblingElement()) {
    // Verificar se o tipo de luz é POINT LIGHT
    if(strcmp((light->Attribute("type")), "POINT")) {
      //DO POINT LIGHT
      x = light->Attribute("posX");
      y = light->Attribute("posY");
      z = light->Attribute("posZ");

      x == nullptr ? pontos[0] = 0.0f : pontos[0] = atof(x);
      y == nullptr ? pontos[1] = 0.0f : pontos[1] = atof(y);
      z == nullptr ? pontos[2] = 0.0f : pontos[2] = atof(z);

      std::shared_ptr<Luz> pL(new PLight(pontos, pickLight()));

      res.push_back(pL);
    // Verificar se o tipo de luz é DIRECTIONAL LIGHT
  } else if(strcmp((light->Attribute("type")), "SPOT")) {
      //DO DIRECTIONAL LIGHT
      
      x = light->Attribute("posX");
      y = light->Attribute("posY");
      z = light->Attribute("posZ");

      x == nullptr ? pontos[0] = 0.0f : pontos[0] = atof(x);
      y == nullptr ? pontos[1] = 0.0f : pontos[1] = atof(y);
      z == nullptr ? pontos[2] = 0.0f : pontos[2] = atof(z);


      x = light->Attribute("dirX");
      y = light->Attribute("dirY");
      z = light->Attribute("dirZ");

      x == nullptr ? direction[0] = 0.0f : direction[0] = atof(x);
      y == nullptr ? direction[1] = 0.0f : direction[1] = atof(y);
      z == nullptr ? direction[2] = 0.0f : direction[2] = atof(z);

      x = light->Attribute("cutoff");

      x == nullptr ? cutoff = 0.0f : cutoff = atof(x);

      std::shared_ptr<Luz> sL(new SLight(pontos, direction, cutoff, pickLight()));

      res.push_back(sL);

    // Verificar se o tipo de luz é SPOT LIGHT
  } else if(strcmp((light->Attribute("type")), "DIRECTIONAL")) {
      //DO SPOT LIGHT
      
      x = light->Attribute("dirX");
      y = light->Attribute("dirY");
      z = light->Attribute("dirZ");

      x == nullptr ? direction[0] = 0.0f : direction[0] = atof(x);
      y == nullptr ? direction[1] = 0.0f : direction[1] = atof(y);
      z == nullptr ? direction[2] = 0.0f : direction[2] = atof(z);
      
      std::shared_ptr<Luz> dL(new DLight(pontos, pickLight()));
      res.push_back(dL);
    }
  }
  return res;
}

SceneGraph doGroup(tinyxml2::XMLElement* group) {
    SceneGraph s_g;
    tinyxml2::XMLElement* novo = group->FirstChildElement();
    for(novo; novo != NULL; novo = novo->NextSiblingElement()) {
        //printf("%s\n", novo->Name());
        if(!strcmp(novo->Name(), "group")) {
            s_g.addFilho(doGroup(novo));
        } else if(!strcmp(novo->Name(), "models")) {
            s_g.setModelo(doModels(novo));
        } else if(!strcmp(novo->Name(), "translate")) {
            if(novo->Attribute("time") == nullptr) {
                s_g.setTrans(doTranslate(novo));
            } else {
                s_g.setCurva(doTimeTranslate(novo));
            }
        } else if(!strcmp(novo->Name(), "rotate")) {
            if(novo->Attribute("time") == nullptr) {
                s_g.setRot(doRotate(novo));
            } else {
                s_g.setEixo(doTimeRotate(novo));
            }
        } else if(!strcmp(novo->Name(), "scale")) {
            s_g.setScale(doScale(novo));
        } else {
            perror("Formato XML Incorreto.\n");
        }
    }
    return s_g;
}
