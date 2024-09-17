#include <cstdlib>
#include <stdio.h>

#include "igvEscena3D.h"

//Constantes -----------------------------------------------
static GLfloat color_pieza_verde[] = { 0,0.25,0 };
static GLfloat color_pieza_rojo[] = { 0.5,0,0 };
static GLfloat color_pieza_azul[] = { 0,0,0.5 };

// Metodos constructores -----------------------------------

igvEscena3D::igvEscena3D() { ejes = true; }

igvEscena3D::~igvEscena3D() {}


// Metodos publicos ----------------------------------------

void pintar_ejes(void) {
	GLfloat rojo[] = { 1,0,0,1.0 };
	GLfloat verde[] = { 0,1,0,1.0 };
	GLfloat azul[] = { 0,0,1,1.0 };

	glMaterialfv(GL_FRONT, GL_EMISSION, rojo);
	glBegin(GL_LINES);
	glVertex3f(1000, 0, 0);
	glVertex3f(-1000, 0, 0);
	glEnd();

	glMaterialfv(GL_FRONT, GL_EMISSION, verde);
	glBegin(GL_LINES);
	glVertex3f(0, 1000, 0);
	glVertex3f(0, -1000, 0);
	glEnd();

	glMaterialfv(GL_FRONT, GL_EMISSION, azul);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 1000);
	glVertex3f(0, 0, -1000);
	glEnd();
}

void igvEscena3D::visualizar(int escena) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // borra la ventana y el z-buffer

	//Luces
	GLfloat light0[] = { 10,8,9,1 }; // point light source
	glLightfv(GL_LIGHT0, GL_POSITION, light0);
	glEnable(GL_LIGHT0);

	glPushMatrix(); // guarda la matriz de modelado

	  // se pintan los ejes
	if (ejes) pintar_ejes();

	// Escena seleccionada a través del menú (click botón derecho)
	if (escena == EscenaA) renderEscenaA();
	else if (escena == EscenaB) renderEscenaB();
	else if (escena == EscenaC) renderEscenaC();

	glPopMatrix(); // restaura la matriz de modelado
	glutSwapBuffers(); // se utiliza, en vez de glFlush(), para evitar el parpadeo
}

void igvEscena3D::renderEscenaA() {
	//GLfloat color_pieza[]

	// Practica 2a. Parte A.
	glMaterialfv(GL_FRONT, GL_EMISSION, color_pieza_verde);

	

	glPushMatrix();
	pintarCaja();
	glPopMatrix();
}

void igvEscena3D::renderEscenaB() {
	/*GLfloat color_pieza[] = { 0,0,0.5 };*/

	// Practica 2a. Parte B.
	glMaterialfv(GL_FRONT, GL_EMISSION, color_pieza_azul);

	for (int i = 0; i < yMax; i++) {
		glPushMatrix();
		glTranslatef(0, i, 0);
		pintarCaja();
		glPopMatrix();
	}

}


void igvEscena3D::renderEscenaC() {
	//GLfloat color_pieza[] = { 0.5,0,0 };

	// Practica 2a. Parte C.
	glMaterialfv(GL_FRONT, GL_EMISSION, color_pieza_rojo);

	for (int i = 0; i < yMax; i++) {
		for (int j = 0; j < xMax; j++) {
			for (int k = 0; k < zMax; k++) {
				glPushMatrix();
				glTranslatef(j * 1.5, 0 + i, k * 2.5);
				pintarCaja();
				glPopMatrix();

				/*glPushMatrix();
				glTranslatef(j*1.5, 0, 0);
				pintarCaja();
				glPopMatrix();

				glPushMatrix();
				glTranslatef(0, 0, k*2.5);
				pintarCaja();
				glPopMatrix();*/
			}
		}
	}
	
}

void igvEscena3D::pintarCaja() {
	//glMaterialfv(GL_FRONT, GL_EMISSION, color_pieza_verde);

	glPushMatrix();

	glScalef(1, 1, 2);
	glutSolidCube(1);

	glPopMatrix();

	//glMaterialfv(GL_FRONT, GL_EMISSION, color_pieza_verde);

	glPushMatrix();
	
	glScalef(1.3, 0.2, 2.3);
	glTranslatef(0, 2.1, 0);
	glutSolidCube(1);
	glPopMatrix();
}


