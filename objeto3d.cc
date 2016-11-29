#include <vector>
#include <GL/gl.h>
#include <GL/glut.h>
#include "objeto3d.h"
#include <iostream>
#include <stdlib.h>

using namespace std;

void Objeto3D::dibujar()
{
  glEnable(GL_CULL_FACE);
  if(polygonMode==GL_POINT)
    glPointSize(3.0);

  glShadeModel(GL_SMOOTH);
  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);
  glPolygonMode(GL_FRONT, polygonMode);

  glVertexPointer(3, GL_FLOAT, 0, &vertices[0]);
  glColorPointer(3, GL_FLOAT, 0, &color[0]);
  glDrawElements(GL_TRIANGLES, caras.size(), GL_UNSIGNED_INT, &caras[0]);
}

void Objeto3D::setMode(GLenum mode){
  polygonMode= mode;

  if(polygonMode == GL_LINE)
    setColors(0.25, 0.5, 0.25);
  else
    setColors(0, 0.75, 0.25);
}

void Objeto3D::setObject(vector<float> &vert, vector<int> &faces){
  color.clear();
  vertices.clear();
  caras.clear();

  for(int i= 0; i < vert.size(); i++)
  {
    color.push_back((rand()%100)/100.0);
    vertices.push_back(vert[i]);
  }

  for(int i= 0; i < faces.size(); i++)
    caras.push_back(faces[i]);
}

void Objeto3D::setColors(float x, float y, float z){
  color.clear();
  for(int i= 0; i < vertices.size(); i+= 3){
    color.push_back(x);
    color.push_back(y);
    color.push_back(z);
  }
}
