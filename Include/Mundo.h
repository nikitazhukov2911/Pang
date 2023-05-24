#pragma once
#include <math.h>
#include "Esfera.h"

class Mundo
{
	//gluLookAt(0, 10, 30,  // posicion del ojo
	//	 0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
	//	 0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

	 float ojo_x, ojo_y, ojo_z;
	 float pto_vista_x, pto_vista_y, pto_vista_z;
	 float eje_x, eje_y, eje_z;

	 Esfera* esfera;

public:
	Mundo();
	~Mundo();

	void dibuja();
	void tecla(unsigned char key);

	void rotarOjo();

	void setOjo_x(float);
	void setOjo_y(float);
	void setOjo_z(float);

	void setPtoVista_x(float);
	void setPtoVista_y(float);
	void setPtoVista_z(float);

	float getOjo_x();
	float getOjo_y();
	float getOjo_z();

	float getPtoVista_x();
	float getPtoVista_y();
	float getPtoVista_z();

	void setEjex(float);
	void setEjey(float);
	void setEjez(float);

	float getEjex();
	float getEjey();
	float getEjez();
	

	

	 

};

