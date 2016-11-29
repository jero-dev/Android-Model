#include "antenaand.h"
#include <iostream>
#include <cmath>

AntenaAnd::AntenaAnd():Objeto3D(){
  Revolucion cilind({2.5, 20.0, 0.0, 2.5, 0.0, 0.0}, 300, 'y');

  vector<float> vert;

  vert.push_back(0.0);
  vert.push_back(0.0);
  vert.push_back(0.0);

  vert.push_back(2.5);
  vert.push_back(0.0);
  vert.push_back(0.0);

  float grade= (M_PI/2) / 20;
  float angle= grade;

  while(grade < M_PI/2){
    vert.push_back(2.5 * cos(grade));
    vert.push_back(2.5 * sin(grade));
    vert.push_back(0.0);
    grade+= angle;
  }

  vert.push_back(0.0);
  vert.push_back(2.5);
  vert.push_back(0.0);

  Revolucion sphere(vert, 300, 'y');

  objE= sphere;
  objC= cilind;

  objE.setColors(0.0, 0.75, 0.25);
  objC.setColors(0.0, 0.75, 0.25);
}

void AntenaAnd::dibujar(){
  glPushMatrix();
    glPushMatrix();
      glTranslatef(0.0, 20.0, 0.0);
      objE.dibujar();
    glPopMatrix();
    glPushMatrix();
      objC.dibujar();
    glPopMatrix();
  glPopMatrix();
}

void AntenaAnd::setMode(GLenum polygonMode){
  objE.setMode(polygonMode);
  objC.setMode(polygonMode);
}
