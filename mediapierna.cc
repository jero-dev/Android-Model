#include "mediapierna.h"

MediaPierna::MediaPierna()
{
  rad= 10; high= 25;

  Revolucion cilind({rad, high, 0.0, rad, 0.0, 0.0}, 300, 'y');

  vector<float> vert;

  vert.push_back(0.0);
  vert.push_back(0.0);
  vert.push_back(0.0);

  vert.push_back(rad);
  vert.push_back(0.0);
  vert.push_back(0.0);

  float grade= (M_PI/2) / 20;
  float angle= grade;

  while(grade < M_PI/2)
  {
    vert.push_back(rad * cos(grade));
    vert.push_back(rad * sin(grade));
    vert.push_back(0.0);
    grade+= angle;
  }

  vert.push_back(0.0);
  vert.push_back(rad);
  vert.push_back(0.0);

  Revolucion sphere(vert, 300, 'y');

  objE= sphere;
  objC= cilind;

  objE.setColors(0.0, 0.75, 0.25);
  objC.setColors(0.0, 0.75, 0.25);
}

void MediaPierna::dibujar()
{
  glPushMatrix();
    glPushMatrix();
      glTranslatef(0.0, -high, 0.0);
      glRotatef(180, 0.0, 0.0, 1.0);
      objE.dibujar();
    glPopMatrix();
    glPushMatrix();
      glTranslatef(0.0, -high, 0.0);
      objC.dibujar();
    glPopMatrix();
  glPopMatrix();
}

void MediaPierna::setMode(GLenum polygonMode)
{
  objE.setMode(polygonMode);
  objC.setMode(polygonMode);
}

float MediaPierna::getLength()
{
  return high + rad;
}
