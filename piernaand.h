#ifndef _PIERNAAND_H
#define _PIERNAAND_H

#include "objeto3d.h"
#include "revolucion.h"
#include "mediapierna.h"

using namespace std;

class PiernaAnd : public Objeto3D{
  private:
    float rad, high, gradeMp;
    Revolucion cilind;
    MediaPierna mp;
    Objeto3D objC;
  public:
    PiernaAnd();
    void dibujar();
    void setMode(GLenum polygonMode);
    float getLength();
    void girarPiernaBaja(float grade);
};

#endif
