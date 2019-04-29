#include "revolucion.h"
#include "math.h"
#include <iostream>

using namespace std;

# define M_PI           3.14159265358979323846  /* pi */

Revolucion::Revolucion(vector<float> vert, int numerodiv, char ej):Objeto3D()
{
	division = numerodiv;
	eje = ej;
	for(int i =0; i < vert.size(); i++)
	{
		inicial.push_back(vert[i]);
	}
	creaObjeto();
}

void Revolucion::creaObjeto()
{
	int tam = inicial.size();
	calculaPuntos(tam);
	carasLaterales();
	for(int i = 0; i < v_tapa.size(); i++)
	{
		caras.push_back(v_tapa[i]);
	}
	for(int i = 0; i < v_base.size(); i++)
	{
		caras.push_back(v_base[i]);
	}
}

void Revolucion::calculaPuntos(int tam)
{
	//Declaramos el angulo y el vector auxiliar
	float alpha = 2*M_PI/division;
	float aux[3];

	//Comprobamos si el vector inicial esta en el orden correcto.
	bool normal;
	switch(eje)
	{
		case 'y':
			normal = inicial[inicial.size()-2] > inicial[1];break;
		case 'x':
			normal = inicial[inicial.size()-3] < inicial[0];break;
		case 'z':
			normal = inicial[inicial.size()-1] < inicial[2];break;
	}

	if(!normal)
	{
		vector<float> vert;
		for(int i = inicial.size()-1; i >= 0; i-=3)
		{
			aux[0] = inicial[i-2];
			aux[1] = inicial[i-1];
			aux[2] = inicial[i];
			vert.push_back(aux[0]);
			vert.push_back(aux[1]);
			vert.push_back(aux[2]);
		}
		inicial.clear();
		for(int i = 0; i < vert.size(); i++)
		{
			inicial.push_back(vert[i]);
		}
	}

	//Calculamos la posicion inicial

	switch (eje)
	{
		case 'y':
			aux[0] = 0;
			aux[1] = inicial[1];
			aux[2] = 0;
			break;
		case 'x':
			aux[0] = inicial[0];
			aux[1] = 0;
			aux[2] = 0;
			break;
		case 'z':
			aux[0] = 0;
			aux[1] = 0;
			aux[2] = inicial[2];
			break;
	}


	if(necesitoBase())
	{
		vertices.push_back(aux[0]);
		vertices.push_back(aux[1]);
		vertices.push_back(aux[2]);
	}
	int ini=0;
	int res = 0;
	if(!necesitoBase())
	{
		ini = 3;
		vertices.push_back(inicial[0]);
		vertices.push_back(inicial[1]);
		vertices.push_back(inicial[2]);
	}
	if(!necesitoTapa())
		res = 3;


	for(int i = ini; i < tam-res; i+=3)
	{
		for(int j = 0; j <= division; j++)
		{
			switch (eje)
			{
				case 'y':
					aux[0] = cos(alpha*j)*inicial[i] + sin(alpha*j)*inicial[i+2];
					aux[1] = inicial[i+1];
					aux[2] = -sin(alpha*j)*inicial[i] + cos(alpha*j)*inicial[i+2];
					break;
				case 'x':
					aux[0] = inicial[i];
					aux[1] = cos(alpha*j)*inicial[i+1] + sin(alpha*j)*inicial[i+2];
					aux[2] = -sin(alpha*j)*inicial[i+1] + cos(alpha*j)*inicial[i+2];
					break;
				case 'z':
					aux[0] = cos(alpha*j)*inicial[i] + sin(alpha*j)*inicial[i+1];
					aux[1] = -sin(alpha*j)*inicial[i] + cos(alpha*j)*inicial[i+1];
					aux[2] = inicial[i+2];
					break;
			}
			vertices.push_back(aux[0]);
			vertices.push_back(aux[1]);
			vertices.push_back(aux[2]);
		}
	}

	switch (eje)
	{
		case 'y':
			aux[0] = 0;
			aux[1] = inicial[tam-2];
			aux[2] = 0;
			break;
		case 'x':
			aux[0] = inicial[tam-3];
			aux[1] = 0;
			aux[2] = 0;
			break;
		case 'z':
			aux[0] = 0;
			aux[1] = 0;
			aux[2] = inicial[tam-1];
			break;
	}

	if(necesitoTapa())
	{
		vertices.push_back(aux[0]);
		vertices.push_back(aux[1]);
		vertices.push_back(aux[2]);
	}
	else if(!necesitoTapa())
	{
		vertices.push_back(inicial[inicial.size()-3]);
		vertices.push_back(inicial[inicial.size()-2]);
		vertices.push_back(inicial[inicial.size()-1]);
	}

	// glScalef(40,40,40);
	// for(int i = 0; i < vertices.size(); i++){
	// 	vertices[i] *= 40;
	// }

	// if(NecesitoBase())
		base();
	// if(NecesitoTapa())
		tapa();

}

void Revolucion::carasLaterales()
{
	int parada = vertices.size()/3;
	int sum = 1;
	int res = 2;

	if(!necesitoBase())
		sum = 0;
	if(!necesitoTapa())
		res = 1;
	
	for(int i = sum; i+division < parada-res; i++)
	{
		caras.push_back(i);
		caras.push_back(i+1);
		caras.push_back(i+division+1);

		caras.push_back(i);
		caras.push_back(i+division+1);
		caras.push_back(i+division);

	}
}

void Revolucion::base()
{
	for(int i =1; i <= division; i++)
	{
		v_base.push_back(i);
		v_base.push_back(0);
		v_base.push_back(i+1);

	}
}

void Revolucion::tapa()
{
	int tamanio = vertices.size()/3;

	for(int i = tamanio -division-2; i < tamanio-1; i++)
	{
		v_tapa.push_back(i);
		v_tapa.push_back(i+1);
		v_tapa.push_back(tamanio-1);
	}
}

bool Revolucion::necesitoTapa()
{
	switch(eje)
	{
		case 'y':
			if(inicial[inicial.size()-3] == 0 and inicial[inicial.size()-1] == 0 and inicial[inicial.size()-2] != 0)
			{
				return false;
			}
			break;
		case 'x':
			if(inicial[inicial.size()-2] == 0 and inicial[inicial.size()-1] == 0 and inicial[inicial.size()-3] != 0)
			{
				return false;
			}
			break;
		case 'z':
			if(inicial[inicial.size()-2] == 0 and inicial[inicial.size()-3] == 0 and inicial[inicial.size()-1] != 0)
			{
				return false;
			}
			break;
			// for(int i = inicial.size()-2; i >= 0; i-=3)
			// {
			//	 if(inicial[i-1] == 0 and inicial[i+1] == 0 and inicial[i] != 0)
			//   {
			// 		 return false;
			// 	 }
			// }
	}
	return true;
}
bool Revolucion::necesitoBase()
{
	switch(eje)
	{
		case 'y':
			if(inicial[0] == 0 and inicial[2] == 0 and inicial[1] != 0)
			{
				return false;
			}
			break;
		case 'x':
			if(inicial[1] == 0 and inicial[2] == 0 and inicial[0] != 0)
			{
				return false;
			}
			break;
		case 'z':
			if(inicial[1] == 0 and inicial[0] == 0 and inicial[2] != 0)
			{
				return false;
			}
			break;

			// for(int i = 1; i < inicial.size(); i+=3)
			// {
			// 	 if(inicial[i-1] == 0 and inicial[i+1] == 0 and inicial[i] != 0)
			//   {
			// 		 return false;
			// 	 }
			// }
	}
	return true;
}

void Revolucion::resize(int value)
{
	cout << "Voy a redividir" << endl;

	vertices.clear();
	caras.clear();
	v_tapa.clear();
	v_base.clear();

	if(value == 0)
		division -= 10;
	else
		division+=10;
	
	creaObjeto();
}

void Revolucion::conSinTapa(int cond)
{
	if(necesitoTapa())
	{
		if(cond == 0)
		{
			caras.clear();
			carasLaterales();
			for(int i = 0; i < v_base.size(); i++)
			{
				caras.push_back(v_base[i]);
			}
		}
		else
		{
			for(int i = 0; i < v_tapa.size(); i++)
			{
				caras.push_back(v_tapa[i]);
			}
		}
	}
}
void Revolucion::conSinBase(int cond)
{
	if(necesitoBase())
	{
		if(cond == 0)
		{
			caras.clear();
			carasLaterales();
			for(int i = 0; i < v_tapa.size(); i++)
			{
				caras.push_back(v_tapa[i]);
			}
		}
		else
		{
			for(int i = 0; i < v_base.size(); i++)
			{
				caras.push_back(v_base[i]);
			}
		}
	}
}
