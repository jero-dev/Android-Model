#include "android.h"
#include <iostream>
#include <cmath>

Android::Android():Objeto3D(){
  radC= 50; highC= 85; gradeBrazo= 0; gradePierna= 0; gradeCabeza= 0, translateCabeza= 0;
  Revolucion cilind({radC, highC, 0.0, radC, 0.0, 0.0}, 100, 'y');

  objC= cilind;

  objC.setColors(0.0, 0.5, 0.5);

  sentidoBrazo= sentidoPierna=  sentidoCabeza= true;
}

void Android::dibujar(){
  glPushMatrix();

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
      glTranslatef(radC/2.0, highC*1.2 - highC, 0);
      glRotatef(gradePierna, 1, 0, 0);
      piernaIzq.dibujar();
    glPopMatrix();

    glPushMatrix();
      glScalef(-1, 1, -1);
      glTranslatef(radC/2.0, highC*1.2 - highC, 0);
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

void Android::girarAnt(){
  cabeza.girarAnt();
}

void Android::girarCabeza(){
  gradeCabeza++;

  if(gradeCabeza == 360)
    gradeCabeza= 0;
}

void Android::girarBrazo(){
  if(sentidoBrazo)
    gradeBrazo++;
  else
    gradeBrazo--;

  if(gradeBrazo==45)
    sentidoBrazo= false;
  if(gradeBrazo== -45)
    sentidoBrazo= true;
}

void Android::subirCabeza(){
  if(sentidoCabeza)
    translateCabeza++;
  else
    translateCabeza--;

  if(translateCabeza==10)
    sentidoCabeza= false;
  if(translateCabeza== 0)
    sentidoCabeza= true;
}

void Android::girarPierna(){
  if(sentidoPierna)
    gradePierna++;
  else
    gradePierna--;

  if(gradePierna== 45)
    sentidoPierna= false;
  if(gradePierna== -45)
    sentidoPierna= true;
}

void Android::setMode(GLenum polygonMode){
  objC.setMode(polygonMode);
  brazoIzq.setMode(polygonMode);
  brazoDcho.setMode(polygonMode);
  piernaIzq.setMode(polygonMode);
  piernaDcha.setMode(polygonMode);
  cabeza.setMode(polygonMode);
}
