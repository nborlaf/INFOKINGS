#include "Pared.h"
#include"freeglut.h"
Pared::Pared()
{
	
}
Pared::~Pared()
{

}
void Pared::Dibuja()
{
	glDisable(GL_LIGHTING);
	color.ponColor();
	glBegin(GL_POLYGON);
	glVertex3d(limite1.x, limite1.y,0);
	glVertex3d(limite2.x, limite2.y,-1);
	glVertex3d(limite2.x, limite2.y,0);
	glVertex3d(limite1.x, limite1.y,-1);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Pared::setColor(unsigned char r, unsigned char g, unsigned char b)
{
	color.set(r, g, b);
}

void Pared::setPos(float x1, float y1, float x2, float y2)
{
	limite1.x = x1;
	limite1.y = y1;
	limite2.x = x2;
	limite2.y = y2;
}
//Calculo de distancia de una pared a un punto, adicionalmente
//se modifica el valor de un vector direccion opcional que contendr�
//el vector unitario saliente que indica la direccion de la
//recta m�s corta entre el punto y la pared.
float Pared::distancia(Vector2D punto, Vector2D* direccion)
{
	Vector2D u = (punto - limite1);
	Vector2D v = (limite2 - limite1).unitario();
	float longitud = (limite1 - limite2).modulo();
	Vector2D dir;
	float valor = u * v;
	float distancia = 0;
	if (valor < 0)
		dir = u;
	else if (valor > longitud)
		dir = (punto - limite2);
	else
		dir = u - v * valor;
	distancia = dir.modulo();
	if (direccion != 0) //si nos dan un vector�
		*direccion = dir.unitario();
	return distancia;
}