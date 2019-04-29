#include "android.h"
#include <iostream>
#include <cmath>

Android::Android():Objeto3D()
{
  radC= 50; highC= 85; gradeBrazo= 0; gradePierna= 0; gradeCabeza= 0, translateCabeza= 0; scale= 0.75; velocidadC= 1; velocidadO= 3;
  Revolucion cilind({radC, highC, 0.0, radC, 0.0, 0.0}, 100, 'y');

  objC= cilind;

  objC.setColors(0.0, 0.75, 0.25);

  sentidoBrazo= sentidoPierna=  sentidoCabeza= sentidoMP= true;
}

void Android::dibujar()
{
  glPushMatrix();
    glTranslatef(0.0, piernaIzq.getLength()*scale - highC*0.2, 0.0);
    glScalef(scale, scale, scale);

    glPushMatrix();
      objC.dibujar();
    glPopMatrix();

    glPushMatrix();
      glTranslatef(radC + 10, highC/2.0 + highC/3.0, 0);
      glRotatef(gradeBrazo, 1, 0, 0);
      brazoIzq.dibujar();
    glPopMatrix();

    glPushMatrix();
      glScalef(-1, 1, -1);
      glTranslatef(radC + 10, highC/2.0 + highC/3.0, 0);
      glRotatef(gradeBrazo, 1, 0, 0);
      brazoDcho.dibujar();
    glPopMatrix();

    glPushMatrix();
      glTranslatef(-radC/2.0, highC*1.2 - highC, 0);
      glRotatef(gradePierna, 1, 0, 0);
      piernaIzq.dibujar();
    glPopMatrix();

    glPushMatrix();
      glScalef(-1, 1, -1);
      glTranslatef(-radC/2.0, highC*1.2 - highC, 0);
      glRotatef(gradePierna, 1, 0, 0);
      piernaDcha.dibujar();
    glPopMatrix();

    glPushMatrix();
      glTranslatef(0, translateCabeza + highC + 2, 0);
      glRotatef(gradeCabeza, 0, 1, 0);
      cabeza.dibujar();
    glPopMatrix();

  glPopMatrix();
}

void Android::girarAnt()
{
  cabeza.girarAnt();
}

void Android::girarCabeza()
{
  gradeCabeza+= velocidadC;

  if(gradeCabeza == 360)
    gradeCabeza= 0;
}

void Android::girarBrazo()
{
  if(sentidoBrazo)
    gradeBrazo+= velocidadO;
  else
    gradeBrazo= gradeBrazo - velocidadO;

  if(gradeBrazo > 45)
    sentidoBrazo= false;
  if(gradeBrazo < -45)
    sentidoBrazo= true;
}

void Android::subirCabeza()
{
  if(sentidoCabeza)
    translateCabeza+= velocidadC;
  else
    translateCabeza= translateCabeza - velocidadC;

  if(translateCabeza > 20)
    sentidoCabeza= false;
  if(translateCabeza < 0)
    sentidoCabeza= true;
}

void Android::girarPierna()
{
  if(sentidoPierna)
    gradePierna+= velocidadO;
  else
    gradePierna= gradePierna - velocidadO;

  if(gradePierna > 45)
    sentidoPierna= false;
  if(gradePierna < -45)
    sentidoPierna= true;

  if(sentidoMP)
  {
    piernaIzq.girarPiernaBaja(gradePierna/1.2);
    piernaDcha.girarPiernaBaja(-gradePierna/1.2);
  }
  else
  {
    piernaIzq.girarPiernaBaja(-gradePierna/1.2);
    piernaDcha.girarPiernaBaja(gradePierna/1.2);
  }

  if(gradePierna==0)
    sentidoMP= !sentidoMP;
}

void Android::setMode(GLenum polygonMode)
{
  objC.setMode(polygonMode);
  brazoIzq.setMode(polygonMode);
  brazoDcho.setMode(polygonMode);
  piernaIzq.setMode(polygonMode);
  piernaDcha.setMode(polygonMode);
  cabeza.setMode(polygonMode);
}

void Android::aumentarVelocidad(float vel)
{
  if(velocidadO < 48 && velocidadC < 16)
  {
    velocidadO *= vel;
    velocidadC *= vel;
    cabeza.aumentarVelocidad(vel);
  }
}

void Android::disminuirVelocidad(float vel)
{
  if(velocidadO > 3 && velocidadC > 1)
  {
    velocidadO /= vel;
    velocidadC /= vel;
    cabeza.disminuirVelocidad(vel);
  }
}
