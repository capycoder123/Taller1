//
// Created by sebab on 07-09-2025.
//

#ifndef TALLER1_INSCRIPCION_H
#define TALLER1_INSCRIPCION_H

#include <string>
#include "Alumno.h"
#include "Curso.h"

// Nodo de lista enlazada para notas
struct Nota {
    double valor;
    Nota* siguiente;
};

// Estructura para inscripcion de alumno en curso
struct Inscripcion {
    int idAlumno;
    int codigoCurso;
    Nota* notas;
    Inscripcion* siguiente;
};

// Lista enlazada de inscripciones
class ListaInscripciones {
private:
    Inscripcion* cabeza;
public:
    ListaInscripciones();
    ~ListaInscripciones();
    bool inscribir(int idAlumno, int codigoCurso, ListaAlumnos &listaA, ListaCursos &listaC);
    bool eliminarInscripcion(int idAlumno, int codigoCurso, ListaCursos &listaC);
    bool agregarNota(int idAlumno, int codigoCurso, double nota);
    void mostrarCursosPorAlumno(int idAlumno, ListaCursos &listaC);
    void mostrarPromedio(int idAlumno, int codigoCurso);
    void mostrarPromediosTotales(int idAlumno);
};

#endif //TALLER1_INSCRIPCION_H