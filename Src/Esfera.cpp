
#include"Esfera.h"

void Esfera::dibuja()
{
	 glColor3ub(this->rojo, this->verde, this->azul);
	 glTranslatef(this->x, this->y, 0);
	 glutSolidSphere(this->radio, 20, 20);
	 glTranslatef(-this->x, -this->y, 0);
 } 

void Esfera::mueve()
{
	this->radio += 0.1f;
	if (this->radio > 3)
	{
		this->radio = 0.5f;

	}
}

Esfera::Esfera()
{
	this->radio = 2.0f;
	this->x = 0.0f;
	this->y = 0.0f;
	this->z = 0.0f;
	this->rojo = 255;
	this->verde = 255;
	this->azul = 255;
}

void Esfera::setColor(float r, float g, float b)
{
	this->rojo = r;
	this->verde = g;
	this->azul = b;
}

void Esfera::setRadio(float var)
{
	if (var < 0.1f)
	{
		this->radio = 0.1f;
	}
	this->radio = var;
}

void Esfera::setPos(float _x, float _y, float _z)
{
	this->x = _x;
	this->y = _y;
	this->z = _z;
}
