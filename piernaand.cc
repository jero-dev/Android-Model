#include "piernaand.h"
#include <iostream>
#include <cmath>

PiernaAnd::PiernaAnd():Objeto3D()
{
  rad= 10; high= 25; gradeMp= 0;

  Revolucion cilind({rad, high, 0.0, rad, 0.0, 0.0}, 300, 'y');

  objC= cilind;
  objC.setColors(0.0, 0.75, 0.25);
}

void PiernaAnd::dibujar()
{
  glPushMatrix();
    glPushMatrix();
      glTranslatef(0.0, -high, 0.0);
      glRotatef(gradeMp, 1.0, 0.0, 0.0);
      mp.dibujar();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0.0, -high, 0.0);
      objC.dibujar();
    glPopMatrix();
  glPopMatrix();
}

void PiernaAnd::setMode(GLenum polygonMode)
{
  mp.setMode(polygonMode);
  objC.setMode(polygonMode);
}

float PiernaAnd::getLength()
{
  return high + rad + mp.getLength();
}

void PiernaAnd::girarPiernaBaja(float grade)
{
  gradeMp= grade;
}
