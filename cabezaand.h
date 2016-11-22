#ifndef _CABEZAAND_H
#define _CABEZAAND_H

#include "objeto3d.h"
#include "revolucion.h"
#include "antenaand.h"

using namespace std;

class CabezaAnd : public Objeto3D{
  private:
    Revolucion sphere;
    float radE, gradeAnt;
    AntenaAnd antenaIzq, antenaDcha;
    Objeto3D objE;
    bool sentido;
  public:
    CabezaAnd();
    void dibujar();
    void girarAnt();
    void setMode(GLenum polygonMode);
};

#endif
