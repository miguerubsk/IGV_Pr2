#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif

class igvEscena3D {
    public:
        const int EscenaA = 1;
		const int EscenaB = 2;
		const int EscenaC = 3;

		const char *Nombre_EscenaA = "Escena A";
		const char *Nombre_EscenaB = "Escena B";
		const char* Nombre_EscenaC = "Escena C";

	protected:
		// Atributos
		bool ejes;
        // Declarar variables para manejar las transformaciones para la escena B


	public:
		// Constructores por defecto y destructor
		igvEscena3D();
		~igvEscena3D();

		// M�todos
		// m�todo con las llamadas OpenGL para visualizar la escena
        void visualizar(int escena);

		bool get_ejes() {return ejes;};
		void set_ejes(bool _ejes){ejes = _ejes;};

    protected:
        void renderEscenaA();
        void renderEscenaB();
		void renderEscenaC();

};

#endif
