#include "freeglut.h"
#include <math.h>
#include "Esfera.h"
#include "Mundo.h"


//
// struct Esfera {
//	float radio= 2.0f;
//	float x = 0.0f;
//	float y = 0.0f;
//	float z= 0.0f;
//	unsigned char rojo= 255;
//	unsigned char verde= 255;
//	unsigned char azul= 255;
//};
//
 /*struct Plano {
	 unsigned char V1_rojo;
	 unsigned char V1_verde;
	 unsigned char V1_azul;

	 unsigned char V2_rojo;
	 unsigned char V2_verde;
	 unsigned char V2_azul;

	 unsigned char V3_rojo;
	 unsigned char V3_verde;
	 unsigned char V3_azul;

	 unsigned char V4_rojo;
	 unsigned char V4_verde;
	 unsigned char V4_azul;

	 float v1_x, v1_y, v1_z;
	 float v2_x, v2_y, v2_z;
	 float v3_x, v3_y, v3_z;
	 float v4_x, v4_y, v4_z; 
 };*/
//
// struct Mundo {
//
//	 //gluLookAt(0, 10, 30,  // posicion del ojo
//		// 0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
//		// 0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  
//
//	 float ojo_x, ojo_y, ojo_z;
//	 float pto_vista_x, pto_vista_y, pto_vista_z;
//	 float eje_x, eje_y, eje_z;
//	 
//
// };
//
// struct Torus
// {
//	 float innerRadius, outerRadius,sides,rings;
//
//
// };
//
// void Mueve(Mundo* m)
// {
//	 float dist = sqrt(m->ojo_x* m->ojo_x + m->ojo_z* m->ojo_z);
//	 float theta = atan2(m->ojo_z, m->ojo_x);
//	 theta += 0.01f;
//	 m->ojo_x = dist * cos(theta);
//	 m->ojo_z = dist * sin(theta);
//
//  }
//
// void Dibuja(const Torus& torus)
// {
//	 glutWireTorus(torus.innerRadius, torus.outerRadius, torus.sides , torus.rings );
// }
//
 /*void Dibuja(const Plano& plano)
 {
	 glDisable(GL_LIGHTING);
	 glBegin(GL_POLYGON);
	 glColor3ub(plano.V1_rojo, plano.V1_verde, plano.V1_azul);
	 glVertex3f(plano.v1_x, plano.v1_y, plano.v1_z);
	 glColor3ub(plano.V2_rojo, plano.V2_verde, plano.V2_azul);
	 glVertex3f(plano.v2_x, plano.v2_y, plano.v2_z);
	 glColor3ub(plano.V3_rojo, plano.V3_verde, plano.V3_azul);
	 glVertex3f(plano.v3_x, plano.v3_y, plano.v3_z);
	 glColor3ub(plano.V4_rojo, plano.V4_verde, plano.V4_azul);
	 glVertex3f(plano.v4_x, plano.v4_y, plano.v4_z);
	 glEnd();
	 glEnable(GL_LIGHTING);
 }

*/



 

 //float radio = 2.0f;
 //float x = 0.0f;
 //float y = 0.0f;
 //float z = 0.0f;
 //unsigned char rojo = 255;
 //unsigned char verde = 255;
 //unsigned char azul = 255;



	 //gluLookAt(0, 10, 30,  // posicion del ojo
		// 0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		// 0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)  

 // Mundo mundo = { 0.0f,10.0f,30.0f, 0.0f,0.0f,0.0f, 0.0f, 1.0f,0.0f };
// Esfera esfera = { 2.0f,3.0f,0.0f,0.0f,255,0,255 };
// Esfera esfera2 = { 2.0f,0.0f,0.0f,0.0f,255,255,255 };
 //Plano plano = { 255,0,0, 255,255,0, 255,255,255, 0,255,255, 5.0f,0.0f,5.0f, -5.0f,0.0f,5.0f, -5.0f,0.0f,-5.0f, 5.0f,0.0f,-5.0f };
 //Torus torus = { 2.5f,5.0f,10.0f,10.0f };

	 //glBegin(GL_POLYGON);
	 //glColor3ub(255, 0, 0);
	 //glVertex3f(-5.0f, -5.0f, 0.0f);
	 //glColor3ub(255, 255, 0);
	 //glVertex3f(-5.0f, 5.0f, 0.0f);
	 //glColor3ub(255, 255, 255);
	 //glVertex3f(5.0f, 5.0f, 0.0f);
	 //glColor3ub(0, 255, 255);
	 //glVertex3f(5.0f, -5.0f, 0.0f);
	 //glEnd();


Mundo mundo;


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
	
	////////////////////////////////////////////


	////////////////////////////////////////////
	
	
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
	
	gluLookAt(mundo.getOjo_x(), mundo.getOjo_y(), mundo.getOjo_z(),  // posicion del ojo
		mundo.getPtoVista_x(), mundo.getPtoVista_y(), mundo.getPtoVista_z(),      // hacia que punto mira  (0,0,0) 
		mundo.getEjex(), mundo.getEjey(), mundo.getEjez());      // definimos hacia arriba (eje Y)    

	//aqui es donde hay que poner el código de dibujo
	//Dibuja(esfera);

	mundo.dibuja();
	//glColor3ub(0, 255, 0);
	//Dibuja(torus);

	//glColor3ub(0, 255, 255);
	//Dibuja(esfera2);

	/*glTranslatef(-x_esfera, 0, 0);*/

	//no borrar esta linea ni poner nada despues
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{

	mundo.tecla(key);


	



	glutPostRedisplay();

}

void OnTimer(int value)
{
	mundo.rotarOjo();
	//esfera.mueve();
	//Mueve(&esfera);
	//Mueve(&mundo);

	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();

}

