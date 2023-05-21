#include "freeglut.h"


 struct Esfera {
	float radio= 2.0f;
	float x = 0.0f;
	float y = 0.0f;
	float z= 0.0f;
	unsigned char rojo= 255;
	unsigned char verde= 255;
	unsigned char azul= 255;
};

 void Dibuja(const Esfera& e)
 {
	 glColor3ub(e.rojo, e.verde, e.azul);
	 glTranslatef(e.x, e.y, 0);
	 glutSolidSphere(e.radio, 20, 20);
	 glTranslatef(-e.x, -e.y, 0);
 }

 void Mueve(Esfera* e)
 {
	 e->radio += 0.1f;
	 if (e->radio > 3)
	 {
		 e->radio = 0.5f;

	 }
	
 }

 float var_x = 0.0f,var_y;

 



 Esfera esfera = { 2.0f,0.0f,0.0f,0.0f,255,255,255 };
 Esfera esfera2 = { 2.0f,0.0f,0.0f,0.0f,255,255,255 };

//los callback, funciones que seran llamadas automaticamente por la glut
//cuando sucedan eventos
//NO HACE FALTA LLAMARLAS EXPLICITAMENTE
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	

int main(int argc,char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800,600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("MiJuego");

	//habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);	
	glMatrixMode(GL_PROJECTION);
	gluPerspective( 40.0, 800/600.0f, 0.1, 150);

	//Registrar los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25,OnTimer,0);//le decimos que dentro de 25ms llame 1 vez a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	
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
	
	gluLookAt(var_x, 10, 20,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el código de dibujo
	Dibuja(esfera);
	Dibuja(esfera2);
	glBegin(GL_POLYGON);
	glColor3ub(255, 0, 0);
	glVertex3f(-5.0f, -5.0f, 0.0f);
	glColor3ub(255, 255, 0);
	glVertex3f(-5.0f, 5.0f, 0.0f);
	glColor3ub(255, 255, 255);
	glVertex3f(5.0f, 5.0f, 0.0f);
	glColor3ub(0, 255, 255);
	glVertex3f(5.0f, -5.0f, 0.0f);
	glEnd();

	/*glTranslatef(-x_esfera, 0, 0);*/

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	if (key == '1' && esfera.radio< 3) { esfera.radio+= 0.1f; }
	if (key == '2' && esfera.radio> 1) { esfera.radio-= 0.1f; }
	if (key == 'r')
	{
		esfera.rojo= 255;
		esfera.verde= 0;
		esfera.azul= 0;
	}
	if (key == 'g')
	{
		esfera.rojo= 0;
		esfera.verde= 255;
		esfera.azul= 0;
	}
	if (key == 'b')
	{
		esfera.rojo= 0;
		esfera.verde= 0;
		esfera.azul= 255;
	}
	if (key == 'a')//izq, X negativo
		esfera.x-= 0.1f;
	if (key == 'd')//izq, X negativo
		esfera.x+= 0.1f;
	if (key == 'w')//izq, X negativo
		esfera.y+= 0.1f;
	if (key == 's')//izq, X negativo
		esfera.y-= 0.1f;
	if (key == 'j')//izq, X negativo
		var_x += 0.1f;
	var_y += 0.1f;
	glutPostRedisplay();

}

void OnTimer(int value)
{

	Mueve(&esfera);
	Mueve(&esfera2);
	var_x += 0.1f;
	var_y += 0.1f;
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();

}

