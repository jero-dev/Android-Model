#ifndef _BRAZOAND_H
#define _BRAZOAND_H

#include "objeto3d.h"
#include "revolucion.h"

using namespace std;

class BrazoAnd : public Objeto3D{
  private:
    Revolucion sphere, cilind;
    Objeto3D objE1, objC, objE2;
  public:
    BrazoAnd();
    void dibujar();
    void setMode(GLenum polygonMode);
};

#endif
