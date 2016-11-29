#include "brazoand.h"
#include <iostream>
#include <cmath>

BrazoAnd::BrazoAnd():Objeto3D(){
  Revolucion cilind({10.0, 50.0, 0.0, 10.0, 0.0, 0.0}, 150, 'y');

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

  Revolucion sphere(vert, 150, 'y');

  objE1= sphere;
  objC= cilind;
  objE2= sphere;

  objE1.setColors(0.0, 0.75, 0.25);
  objC.setColors(0.0, 0.75, 0.25);
  objE2.setColors(0.0, 0.75, 0.25);
}

void BrazoAnd::dibujar(){
  glPushMatrix();
    glPushMatrix();
      objE1.dibujar();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0.0, -50.0, 0.0);
      objC.dibujar();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0.0, -50, 0.0);
      glRotatef(180, 0.0, 0.0, 1.0);
      objE2.dibujar();
    glPopMatrix();
  glPopMatrix();
}

void BrazoAnd::setMode(GLenum polygonMode){
  objE1.setMode(polygonMode);
  objC.setMode(polygonMode);
  objE2.setMode(polygonMode);
}
