#include <cstdlib>
#include <cstdio>

#include "igvEscena3D.h"

// M�todos constructores -----------------------------------

// M�todos p�blicos ----------------------------------------

/**
 * M�todo para pintar los ejes coordenados llamando a funciones de OpenGL
 */
void igvEscena3D::pintar_ejes() {
    constexpr GLfloat rojo[] = {1, 0, 0, 1.0};
    constexpr GLfloat verde[] = {0, 1, 0, 1.0};
    constexpr GLfloat azul[] = {0, 0, 1, 1.0};

    glBegin(GL_LINES);
    glMaterialfv(GL_FRONT, GL_EMISSION, rojo);
    glVertex3f(1000, 0, 0);
    glVertex3f(-1000, 0, 0);

    glMaterialfv(GL_FRONT, GL_EMISSION, verde);
    glVertex3f(0, 1000, 0);
    glVertex3f(0, -1000, 0);

    glMaterialfv(GL_FRONT, GL_EMISSION, azul);
    glVertex3f(0, 0, 1000);
    glVertex3f(0, 0, -1000);
    glEnd();
}

/**
 * M�todo con las llamadas OpenGL para visualizar la escena
 * @param escena Identificador del tipo de escena a dibujar
 * @pre Se asume que el valor del par�metro es correcto
 */
void igvEscena3D::visualizar(int escena) {
    // borra la ventana y el Z-buffer
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Luces
    constexpr GLfloat light0[] = {10, 8, 9, 1}; // point light source
    glLightfv(GL_LIGHT0, GL_POSITION, light0);
    glEnable(GL_LIGHT0);

    glPushMatrix(); // guarda la matriz de modelado

    // se pintan los ejes
    if (ejes) {
        pintar_ejes();
    }

    // Escena seleccionada a trav�s del men� (clic bot�n derecho)

    if (escena == EscenaA) {
        renderEscenaA();
    }
    if (escena == EscenaB) {
        renderEscenaB();
    }
    if (escena == EscenaC) {
        renderEscenaC();
    }


    glPopMatrix(); // restaura la matriz de modelado
    glutSwapBuffers(); // se utiliza, en vez de glFlush(), para evitar el parpadeo
}

/**
 * Pinta la escena A llamando a las funciones de OpenGL
 */
void igvEscena3D::renderEscenaA() {
    GLfloat color_pieza[] = {0, 0.25, 0};

    // TODO: Practica 2a. Parte A.
    glMaterialfv(GL_FRONT, GL_EMISSION, color_pieza);

    glPushMatrix();
    pintarCaja();
    glPopMatrix();
}

/**
 * Pinta la escena B llamando a las funciones de OpenGL
 */
void igvEscena3D::renderEscenaB() const {
    constexpr GLfloat color_pieza[] = {0, 0, 0.5};

    glMaterialfv(GL_FRONT, GL_EMISSION, color_pieza);

    for (int i = 0; i < yMax; i++) {
        glPushMatrix();
        glTranslatef(0, i, 0);
        pintarCaja();
        glPopMatrix();
    }
}

/**
 * Pinta la escena C llamando a las funciones de OpenGL
 */
void igvEscena3D::renderEscenaC() const {
    constexpr GLfloat color_pieza[] = {0.5, 0, 0};

    // TODO: Practica 2a. Parte C.
    glMaterialfv(GL_FRONT, GL_EMISSION, color_pieza);

    for (int i = 0; i < yMax; i++) {
        for (int j = 0; j < xMax; j++) {
            for (int k = 0; k < zMax; k++) {
                glPushMatrix();
                glTranslatef(j * 1.5, 0 + i, k * 2.5);
                pintarCaja();
                glPopMatrix();
            }
        }
    }
}

/**
 * M�todo para consultar si hay que dibujar los ejes o no
 * @retval true Si hay que dibujar los ejes
 * @retval false Si no hay que dibujar los ejes
 */
bool igvEscena3D::get_ejes() const {
    return ejes;
}

/**
 * M�todo para activar o desactivar el dibujado de los ejes
 * @param _ejes Indica si hay que dibujar los ejes (true) o no (false)
 * @post El estado del objeto cambia en lo que respecta al dibujado de ejes,
 *       de acuerdo al valor pasado como par�metro
 */
void igvEscena3D::set_ejes(const bool _ejes) {
    ejes = _ejes;
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
