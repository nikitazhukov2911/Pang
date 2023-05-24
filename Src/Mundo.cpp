#include "Mundo.h"

Mundo::Mundo()
{
	//gluLookAt(0, 10, 30,  // posicion del ojo
	//	 0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
	//	 0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

	ojo_x = 0; ojo_y = 10; ojo_z = 30;
	pto_vista_x = 0.0; pto_vista_y = 0.0; pto_vista_z = 0.0f;
	eje_x = 0.0; eje_y = 1.0; eje_z = 0.0f;

	esfera = new Esfera();
}
Mundo::~Mundo() 
{
	delete esfera;
}

void Mundo::dibuja()
{
	this->esfera->dibuja();
}
void Mundo::tecla(unsigned char k)
{
	//switch (key)
//{
//case 'r':
//case 'R':
//	break;
//case 'G':
//case 'g':
//	break;
//case 'B':
//case 'b':
//	break;
//case 'D':
//case 'd':
//	//esfera2.x += 1.0f;
//	break;
//

//	//esfera2.rojo = 0;
//	//esfera2.verde = 255;
//	//esfera2.azul = 0;
//	break;
//default:

//	break;
//}
}

void Mundo::rotarOjo()
 {
	 float dist = sqrt(this->ojo_x* this->ojo_x + this->ojo_z* this->ojo_z);
	 float theta = atan2(this->ojo_z, this->ojo_x);
	 theta += 0.01f;
	 this->ojo_x = dist * cos(theta);
	 this->ojo_z = dist * sin(theta);

  }

void Mundo::setOjo_x(float var)
{
	this->ojo_x = var;
}
void Mundo::setOjo_y(float var)
{
	this->ojo_y = var;
}
void Mundo::setOjo_z(float var)
{
	this->ojo_z = var;
}
void Mundo::setPtoVista_x(float var)
{
	this->ojo_x = var;
}
void Mundo::setPtoVista_y(float var)
{
	this->ojo_y = var;
}
void Mundo::setPtoVista_z(float var)
{
	this->ojo_z = var;
}
float Mundo::getOjo_x()
{
	return this->ojo_x;
}
float Mundo::getOjo_y()
{
	return this->ojo_y;
}
float Mundo::getOjo_z()
{
	return this->ojo_z;
}
float Mundo::getPtoVista_x()
{
	return this->pto_vista_x;
}
float Mundo::getPtoVista_y()
{
	return this->pto_vista_y;
}
float Mundo::getPtoVista_z()
{
	return this->pto_vista_z;
}
void Mundo::setEjex(float var)
{
	this->eje_x = var;
}
void Mundo::setEjey(float var)
{
	this->eje_y = var;
}
void Mundo::setEjez(float var)
{
	this->eje_z = var;
}
float Mundo::getEjex()
{
	return this->eje_x;
}
float Mundo::getEjey()
{
	return this->eje_y;
}
float Mundo::getEjez()
{
	return this->eje_z;
}