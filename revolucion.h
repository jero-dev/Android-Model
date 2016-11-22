#ifndef _REVOLUCION_H
#define _REVOLUCION_H
#include <iostream>
#include "objeto3d.h"

using namespace std;

class Revolucion : public Objeto3D{ //hereda de Objeto3D
private:
	int division;
	vector<float> inicial;
	vector<int> v_tapa;
	vector<int> v_base;
	char eje;
public:
	Revolucion(){};
	Revolucion(vector<float> vertices, int numerodiv, char eje);
	// ObjetoDeRevolucion(Objeto3D & otro, int divi, char ej){
	// 	division = divi;
	// 	eje = ej;
	// 	CopiarDatos(otro);
	// }
	int cubo();
	void creaObjeto();
	void calculaPuntos(int tam);
	void carasLaterales();
	// void Tapas();
	void base();
	void tapa();
	bool necesitoTapa();
	bool necesitoBase();
	void resize(int value);
	void conSinTapa(int cond);
	void conSinBase(int cond);

	// void Redivide(int value, char ej, int division);
	//
	// ObjetoDeRevolucion & operator = (const ObjetoDeRevolucion & otro);
	//
	// void CopiarDatos (const Objeto3D & otro);
};
#endif
