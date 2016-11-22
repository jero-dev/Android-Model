#ifndef _OBJETO3D_H
#define _OBJETO3D_H
#include <vector>
#include <GL/gl.h>
#include <GL/glut.h>

using namespace std;

class Objeto3D
{
  protected:
    vector<float> vertices;
    vector<float> color;
    vector<float> colorChess;
    vector<int> caras;
    GLenum polygonMode;
  public:
    Objeto3D(){}
    void setMode(GLenum mode);
    void dibujar();
    void setObject(vector<float> &vert, vector<int> &faces);
    void setColors(float x, float y, float z);
};
#endif
