#ifndef _MEDIAPIERNA_H
#define _MEDIAPIERNA_H

#include "objeto3d.h"
#include "revolucion.h"
#include <cmath>


using namespace std;

class MediaPierna : public Objeto3D{
  private:
    float rad, high;
    Revolucion sphere, cilind;
    Objeto3D objE, objC;
  public:
    MediaPierna();
    void dibujar();
    void setMode(GLenum polygonMode);
    float getLength();
};

#endif
