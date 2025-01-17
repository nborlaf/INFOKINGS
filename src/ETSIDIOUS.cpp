#include "freeglut.h"
#include"CoordinadorEtsidious.h"
CoordinadorEtsidious etsidious;

//CALLBACKS LIBRER�A FREEGLUT
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void onSpecialKeyboardDown(int key, int x, int y); //Declaraci�n funciones teclas especiales
void OnSpecialKeyboardUp(int key, int x, int y); //Detecci�n flanco negativo teclas especiales

int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(750, 650);
	glutInitWindowPosition(400, 50);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("ETSIDIOUS");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutSpecialFunc(onSpecialKeyboardDown); //gestion de los cursores
	glutSpecialUpFunc(OnSpecialKeyboardUp); //flancos negativos de las teclas especiales

	etsidious.Inicializa();

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}

void OnDraw(void)
{
	//Borrado de la pantalla	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Para definir el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	etsidious.Dibuja();

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	etsidious.Tecla(key);
	glutPostRedisplay();
}
void onSpecialKeyboardDown(int key, int x, int y)
{
	etsidious.teclaEspecial(key);
}
void OnSpecialKeyboardUp(int key, int x, int y)
{
	etsidious.teclaEspecialUp(key);
}

void OnTimer(int value)
{
	//poner aqui el c�digo de animacion
	etsidious.Mueve(0.025f);

	//no borrar estas lineas
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}


