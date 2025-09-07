//
// Created by sebab on 07-09-2025.
//

#ifndef TALLER1_CURSO_H
#define TALLER1_CURSO_H

#include <string>
using namespace std;

struct Curso {
    int codigo;
    string nombre;
    int maxAlumnos;
    string carrera;
    string profesor;
    int inscritos;
};

struct NodoCurso {
    Curso curso;
    NodoCurso* siguiente;
};

class ListaCursos {
private:
    NodoCurso* cabeza;
public:
    ListaCursos ();
    ~ListaCursos();
    void agregarCurso(const Curso &curso);
    NodoCurso* buscarPorCodigo(int codigo);
    NodoCurso* buscarPorNombre(const string &nombre);
    bool eliminarPorCodigo(int codigo);
    bool eliminarPorNombre(const string &nombre);
    void mostrarTodo();
};

#endif //TALLER1_CURSO_H