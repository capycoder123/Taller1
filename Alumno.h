//
// Created by sebab on 07-09-2025.
//

#ifndef TALLER1_ALUMNO_H
#define TALLER1_ALUMNO_H

#include <iostream>
using namespace std;

struct Alumno {
    int id;
    string nombre;
    string apellido;
    string carrera;
    string fechaIngreso;
};

struct NodoAlumno {
    Alumno alumno;
    NodoAlumno* siguiente;
};

class ListaAlumnos {
private:
    NodoAlumno* cabeza;
public:
    ListaAlumnos();
    ~ListaAlumnos();
    void agregarAlumno(const Alumno &alumno);
    NodoAlumno* buscarPorId(int id);
    NodoAlumno* buscarPorNombre(const string &nombre);
    bool eliminarPorId(int id);
    bool eliminarPorNombre(const string &nombre);
    void listarPorCarrera(const string &carrera);
    void MostrarTodos();
};

#endif //TALLER1_ALUMNO_H