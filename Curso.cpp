//
// Created by sebab on 07-09-2025.
//

#include "Curso.h"
#include <iostream>

// Constructor
ListaCursos::ListaCursos() : cabeza(nullptr) {}

// Destructor
ListaCursos::~ListaCursos() {
    NodoCurso* actual = cabeza;
    while (actual) {
        NodoCurso* aux = actual;
        actual = actual->siguiente;
        delete aux;
    }
}
