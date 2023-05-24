#pragma once
#include "freeglut.h"
class Esfera
{
float radio;
float x;
float y;
float z;
unsigned char rojo;
unsigned char verde;
unsigned char azul;
public:

	Esfera();

	void mueve();
	void dibuja();

	void setColor(float r=255.0f,float g = 255.0f, float b=255.0f);
	void setRadio(float);
	void setPos(float, float, float);

	
};
