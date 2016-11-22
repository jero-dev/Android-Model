#include "cabezaand.h"
#include <iostream>
#include <cmath>

CabezaAnd::CabezaAnd():Objeto3D(){
  vector<float> vert;
  sentido= true;

  radE= 50; gradeAnt= 45;

  vert.push_back(0.0);
  vert.push_back(0.0);
  vert.push_back(0.0);

  vert.push_back(radE);
  vert.push_back(0.0);
  vert.push_back(0.0);

  float grade= (M_PI/2) / 20;
  float angle= grade;

  while(grade < M_PI/2){
    vert.push_back(radE * cos(grade));
    vert.push_back(radE * sin(grade));
    vert.push_back(0.0);
    grade+= angle;
  }

  vert.push_back(0.0);
  vert.push_back(radE);
  vert.push_back(0.0);

  Revolucion sphere(vert, 300, 'y');

  objE= sphere;

  objE.setColors(0.0, 0.5, 0.5);
}

void CabezaAnd::dibujar(){
  glPushMatrix();
    glPushMatrix();
      objE.dibujar();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(-(radE/2.0), radE/2.0 + radE/5.0, 0.0);
      glRotatef(gradeAnt, 0.0, 0.0, 1.0);
      antenaDcha.dibujar();
    glPopMatrix();
    glPushMatrix();
      glScalef(-1, 1, 1);
      glTranslatef(-(radE/2.0), radE/2.0 + radE/5.0, 0.0);
      glRotatef(gradeAnt, 0.0, 0.0, 1.0);
      antenaIzq.dibujar();
    glPopMatrix();
  glPopMatrix();
}

void CabezaAnd::girarAnt(){
  if(sentido)
    gradeAnt--;
  else
    gradeAnt++;

  if(gradeAnt == 0)
    sentido= false;
  if(gradeAnt == 45)
    sentido= true;
}

void CabezaAnd::setMode(GLenum polygonMode){
  objE.setMode(polygonMode);
  antenaIzq.setMode(polygonMode);
  antenaDcha.setMode(polygonMode);
}
