#include "piernaand.h"
#include <iostream>
#include <cmath>

PiernaAnd::PiernaAnd():Objeto3D(){
  Revolucion cilind({10.0, 50.0, 0.0, 10.0, 0.0, 0.0}, 300, 'y');

  vector<float> vert;

  vert.push_back(0.0);
  vert.push_back(0.0);
  vert.push_back(0.0);

  vert.push_back(10.0);
  vert.push_back(0.0);
  vert.push_back(0.0);

  float grade= (M_PI/2) / 20;
  float angle= grade;

  while(grade < M_PI/2){
    vert.push_back(10.0 * cos(grade));
    vert.push_back(10.0 * sin(grade));
    vert.push_back(0.0);
    grade+= angle;
  }

  vert.push_back(0.0);
  vert.push_back(10.0);
  vert.push_back(0.0);

  Revolucion sphere(vert, 300, 'y');

  objE= sphere;
  objC= cilind;

  objE.setColors(0.0, 0.5, 0.5);
  objC.setColors(0.0, 0.5, 0.5);
}

void PiernaAnd::dibujar(){
  glPushMatrix();
    glPushMatrix();
      glTranslatef(0.0, -50.0, 0.0);
      glRotatef(180, 0.0, 0.0, 1.0);
      objE.dibujar();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0.0, -50.0, 0.0);
      objC.dibujar();
    glPopMatrix();
  glPopMatrix();
}

void PiernaAnd::setMode(GLenum polygonMode){
  objE.setMode(polygonMode);
  objC.setMode(polygonMode);
}
