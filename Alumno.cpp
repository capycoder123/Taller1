//
// Created by sebab on 07-09-2025.
//

#include "Alumno.h"
#include <iostream>
using namespace std;

// Constructor
ListaAlumnos::ListaAlumnos() : cabeza(nullptr) {}

// Destructor
ListaAlumnos::~ListaAlumnos() {
    NodoAlumno *actual = cabeza;
    while (actual) {
        NodoAlumno *aux = actual;
        actual = actual->siguiente;
        delete aux;
    }
}

// Agrega un alumno a la lista
void ListaAlumnos::agregarAlumno(const Alumno &alumno) {
    NodoAlumno* nuevo = new NodoAlumno(alumno, cabeza);
    cabeza = nuevo;
    cout << "Alumno agregado: ID= " << alumno.id << ", Nombre= " << alumno.nombre << " " << alumno.apellido << endl;
}

// Busca un alumno por id
NodoAlumno* ListaAlumnos::buscarPorId(int id) {
    NodoAlumno *actual = cabeza;
    while (actual) {
        if (actual->alumno.id == id) return actual;
        actual = actual->siguiente;
    }
    return nullptr;
}

// Busca alumno por nombre
NodoAlumno *ListaAlumnos::buscarPorNombre(const string &nombre) {
    NodoAlumno* actual = cabeza;
    while (actual) {
        if (actual->alumno.nombre == nombre) return actual;
        actual = actual->siguiente;
    }
    return nullptr;
}

// Elimina un alumno por id
bool ListaAlumnos::eliminarPorId(int id) {
    NodoAlumno* actual = cabeza;
    NodoAlumno* anterior = nullptr;
    while (actual) {
        if (actual->alumno.id == id) {
            if (anterior) anterior->siguiente = actual->siguiente;
            else cabeza = actual->siguiente;
            delete actual;
            cout << "Alumno con ID=" << id << "eliminado." << endl;
            return true;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    cout << "Alumno con ID=" << id << " no existe." << endl;
    return false;
}

// Elimina alumno por nombre
bool ListaAlumnos::eliminarPorNombre(const string &nombre) {
    NodoAlumno* actual = cabeza;
    NodoAlumno* anterior = nullptr;
    while (actual) {
        if (actual->alumno.nombre == nombre) {
            if (anterior) anterior->siguiente = actual->siguiente;
            else cabeza = actual->siguiente;
            delete actual;
            cout << "Alumno " << nombre << " eliminado." << endl;
            return true;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    cout << "Alumno con ID=" << nombre << " no existe." << endl;
    return false;
}

// Lista los alumnos de una carrera
void ListaAlumnos::listarPorCarrera(const string &carrera) {
    NodoAlumno* actual = cabeza;
    cout << "Alumno en la carrera " << carrera << endl;
    bool encontrado = false;
    while (actual) {
        if (actual->alumno.carrera == carrera) {
            cout << "ID: " << actual->alumno.id << ", Nombre: " << actual->alumno.nombre << " " << actual->alumno.apellido << ", Ingreso: " << actual->alumno.fechaIngreso << endl;
            encontrado = true;
        }
        actual = actual->siguiente;
    }
    if (!encontrado) {
        cout << "No hay alumnos en la carrera" << endl;
    }
}

// Muestra todos los alumnos
void ListaAlumnos::MostrarTodos() {
    NodoAlumno* actual = cabeza;
    cout << "Listado de todos los alumnos." << endl;
    while (actual) {
        cout << "ID: " << actual->alumno.id << ", Nombre: " << actual->alumno.nombre << " " << actual->alumno.apellido << ", Ingreso: " << actual->alumno.fechaIngreso << endl;
        actual = actual->siguiente;
    }
}







