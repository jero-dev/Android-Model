#ifndef _ANTENAAND_H
#define _ANTENAAND_H

#include "objeto3d.h"
#include "revolucion.h"

using namespace std;

class AntenaAnd : public Objeto3D{
  private:
    Revolucion sphere, cilind;
    Objeto3D objE, objC;
  public:
    AntenaAnd();
    void dibujar();
    void setMode(GLenum polygonMode);
};

#endif
