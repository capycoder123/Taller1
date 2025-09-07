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

// Agrega un curso a la lista
void ListaCursos::agregarCurso(const Curso &curso) {
    NodoCurso* nuevo = new NodoCurso(curso, cabeza);
    nuevo->curso.inscritos = 0;
    cabeza = nuevo;
    cout << "Curso agregado: Codigo= " << curso.codigo << ", Nombre= " << curso.nombre <<endl;
}

// Busca curso por codigo
NodoCurso* ListaCursos::buscarPorCodigo(int codigo) {
    NodoCurso* actual = cabeza;
    while (actual) {
        if (actual->curso.codigo ==  codigo) return actual;
        actual = actual->siguiente;
    }
    return nullptr;
}

// Busca curso por nombre
NodoCurso* ListaCursos::buscarPorNombre(const string &nombre) {
    NodoCurso* actual = cabeza;
    while (actual) {
        if (actual->curso.nombre == nombre) return actual;
        actual = actual->siguiente;
    }
    return nullptr;
}

// Elimina un curso por codigo
bool ListaCursos::eliminarPorCodigo(int codigo) {
    NodoCurso* actual = cabeza;
    NodoCurso* anterior = nullptr;
    while (actual) {
        if (actual->curso.codigo == codigo) {
            if (anterior) anterior->siguiente = actual->siguiente;
            else cabeza = actual->siguiente;
            delete actual;
            cout << "Curso por codigo= " << codigo << " Eliminado" << endl;
            return true;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    cout << "Curso con codigo= " << codigo << " no encontrado" << endl;
    return false;
}

// Elimina curso por nombre
bool ListaCursos::eliminarPorNombre(const string &nombre) {
    NodoCurso* actual = cabeza;
    NodoCurso* anterior = nullptr;
    while (actual) {
        if (actual->curso.nombre == nombre) {
            if (anterior) anterior->siguiente = actual->siguiente;
            else cabeza = actual->siguiente;
            delete actual;
            cout << "Curso " << nombre << " Eliminado" << endl;
            return true;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    cout << "Curso " << nombre << " no encontrado" << endl;
    return false;
}

void ListaCursos::mostrarTodo() {
    NodoCurso* actual = cabeza;
    cout << "Listado de todos los curos " << endl;
    while (actual) {
        cout << "Codigo. " << actual->curso.codigo << ", Nombre: " << actual->curso.nombre
        << ", Carrera: " << actual->curso.carrera << ", Profesor: " << actual->curso.profesor
        << ", Max Alumnos: " << actual->curso.maxAlumnos << ", Inscritos: " << actual->curso.inscritos << endl;
        actual = actual->siguiente;
    }
}
