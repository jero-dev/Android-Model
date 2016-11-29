#ifndef _PIERNAAND_H
#define _PIERNAAND_H

#include "objeto3d.h"
#include "revolucion.h"

using namespace std;

class PiernaAnd : public Objeto3D{
  private:
    float rad, high;
    Revolucion sphere, cilind;
    Objeto3D objE, objC;
  public:
    PiernaAnd();
    void dibujar();
    void setMode(GLenum polygonMode);
    float getLength();
};

#endif
