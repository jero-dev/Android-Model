#ifndef _ANDROID_H
#define _ANDROID_H

#include "objeto3d.h"
#include "revolucion.h"
#include "brazoand.h"
#include "cabezaand.h"
#include "piernaand.h"

using namespace std;

class Android : public Objeto3D{
  private:
    Revolucion cilind;
    Objeto3D objC;
    float highC, radC, gradeBrazo, gradePierna, gradeCabeza, translateCabeza;
    BrazoAnd brazoIzq, brazoDcho;
    PiernaAnd piernaIzq, piernaDcha;
    CabezaAnd cabeza;
    bool sentidoBrazo, sentidoPierna, sentidoCabeza;
  public:
    Android();
    void dibujar();
    void girarAnt();
    void girarBrazo();
    void girarPierna();
    void girarCabeza();
    void subirCabeza();
    void setMode(GLenum polygonMode);
};

#endif
