//
// Created by sebab on 07-09-2025.
//

#include "Inscripcion.h"
#include <iostream>

// Constructor
ListaInscripciones::ListaInscripciones(): cabeza(nullptr) {}

// Destructor
ListaInscripciones::~ListaInscripciones() {
    Inscripcion* actual = cabeza;
    while (actual) {
        Nota* nota = actual->notas;
        while (nota) {
            Nota* auxN = nota;
            nota = nota->siguiente;
            delete auxN;
        }
        Inscripcion* aux = actual;
        actual = actual->siguiente;
        delete aux;
    }
}

//Inscribir alumno en un curso
bool ListaInscripciones::inscribir(int idAlumno, int codigoCurso, ListaAlumnos &listaA, ListaCursos &listaC) {
    NodoAlumno* nodoA = listaA.buscarPorId(idAlumno);
    if (!nodoA) {
        cout << "Alumno con ID " << idAlumno << " no encontrado." << endl;
        return false;
    }
    NodoCurso* nodoC = listaC.buscarPorCodigo(codigoCurso);
    if (!nodoC) {
        cout << "Curso con codigo " << codigoCurso << " no encontrado." << endl;
        return false;
    }

    if (nodoA->alumno.carrera != nodoC->curso.carrera) {
        cout << "La carrera del alumno y del curso no coinciden." << endl;
        return false;
    }

    if (nodoC->curso.inscritos >= nodoC->curso.maxAlumnos) {
        cout << "Cupo del curso lleno" << endl;
        return false;
    }

    Inscripcion* actual = cabeza;
    while (actual) {
        if (actual->idAlumno == idAlumno && actual->codigoCurso == codigoCurso) {
            cout << "El alumno ya esta inscrito en este curso." << endl;
            return false;
        }
        actual = actual->siguiente;
    }

    Inscripcion* nueva = new Inscripcion{idAlumno, codigoCurso, nullptr, cabeza};
    cabeza = nueva;
    nodoC->curso.inscritos++;
    cout << "Alumno " << idAlumno << " inscrito en curso " << codigoCurso << "." << endl;
    return true;
}

// Eliminar inscripcion de un alumno en un curso
bool ListaInscripciones::eliminarInscripcion(int idAlumno, int codigoCurso, ListaCursos &listaC) {
    Inscripcion* actual = cabeza;
    Inscripcion* anterior = nullptr;
    while (actual) {
        if (actual->idAlumno == idAlumno && actual->codigoCurso == codigoCurso) {
            if (anterior) anterior->siguiente = actual->siguiente;
            else cabeza = actual->siguiente;
            NodoCurso* nodoC = listaC.buscarPorCodigo(codigoCurso);
            if (nodoC) {
                nodoC->curso.inscritos--;
            }
            cout << "Inscripcion de alumno" << idAlumno << " en curso " << codigoCurso << " eliminado." << endl;
            delete actual;
            return true;
        }
        anterior = actual;
        actual = actual->siguiente;
    }
    cout << "Inscripcion no encontrada." << endl;
    return false;
}

// elimina la inscripcion de un alumno por curso
void ListaInscripciones::eliminarInscripcionesPorCurso(int codigoCurso, ListaCursos &listaC) {
    Inscripcion* actual = cabeza;
    Inscripcion* anterior = nullptr;
    bool any = false;

    NodoCurso* nodoCurso = listaC.buscarPorCodigo(codigoCurso);

    while(actual) {
        if(actual->codigoCurso == codigoCurso) {
            Inscripcion* aEliminar = actual;
            actual = actual->siguiente;

            if(anterior) anterior->siguiente = aEliminar->siguiente;
            else cabeza = aEliminar->siguiente;

            Nota* n = aEliminar->notas;
            while(n) {
                Nota* auxN = n;
                n = n->siguiente;
                delete auxN;
            }

            delete aEliminar;
            any = true;
        } else {
            anterior = actual;
            actual = actual->siguiente;
        }
    }

    if(nodoCurso) {
        nodoCurso->curso.inscritos = 0;
    }

    if(any) {
        cout << "Se eliminaron todas las inscripciones del curso " << codigoCurso << ".\n";
    } else {
        cout << "No se encontraron inscripciones para el curso " << codigoCurso << ".\n";
    }
}

// Agrega nota a una inscripcion existente
bool ListaInscripciones::agregarNota(int idAlumno, int codigoCurso, double nota) {
    if (nota < 1.0 || nota > 7.0) {
        cout << "Nota fuera de rango (1.0 a 7.0)." << endl;
        return false;
    }
    Inscripcion* actual = cabeza;
    while (actual) {
        if (actual->idAlumno == idAlumno && actual->codigoCurso == codigoCurso) {
            Nota* nuevaNota = new Nota(nota,nullptr);
            if (!actual->notas) {
                actual->notas = nuevaNota;
            } else {
                Nota* temp = actual->notas;
                while (temp->siguiente) temp = temp->siguiente;
                temp->siguiente = nuevaNota;
            }
            cout << "Nota " << nota << " agregada a alumno " << idAlumno << " en curso " << codigoCurso << "." << endl;
            return true;
        }
        actual = actual->siguiente;
    }
    cout << "Inscripcion no encontrada para agregar nota." << endl;
    return false;
}

// Mostrar cursos inscritos de un alumno
void ListaInscripciones::mostrarCursosPorAlumno(int idAlumno, ListaCursos &listaC) {
    Inscripcion* actual = cabeza;
    bool encontrado = false;
    cout << "Cursos inscritos por el alumno " << idAlumno << "." << endl;
    while (actual) {
        if (actual->idAlumno == idAlumno) {
            NodoCurso* curso = listaC.buscarPorCodigo(actual->codigoCurso);
            if (curso) {
                cout << "Codigo: " << curso->curso.codigo << ", Nombre: " << curso->curso.nombre << endl;
                encontrado = true;
            }
        }
        actual = actual->siguiente;
    }
    if (!encontrado) {
        cout << "El alumno no esta inscrito en ningun curso." << endl;
    }
}

// Mostrar promedio de notas de un alumno en un curso específico
void ListaInscripciones::mostrarPromedio(int idAlumno, int codigoCurso) {
    Inscripcion* actual = cabeza;
    while (actual) {
        if (actual->idAlumno == idAlumno && actual->codigoCurso == codigoCurso) {
            if (!actual->notas) {
                cout << "No hay notas registradas para este curso." << endl;
                return;
            }
            double suma = 0;
            int cont = 0;
            Nota* n = actual->notas;
            while (n) {
                suma+=n->valor;
                cont++;
                n = n->siguiente;
            }
            double promedio = suma/cont;
            cout << "Promedio del alumno " << idAlumno << " en curso " << codigoCurso << ": " << promedio << endl;
            return;
        }
        actual = actual->siguiente;
    }
    cout << "Inscripcion no encontrada para calcular promedio." << endl;
}

// Mostrar promedios totales de un alumno (por curso y general)
void ListaInscripciones::mostrarPromediosTotales(int idAlumno) {
    Inscripcion* actual = cabeza;
    double sumaGeneral = 0;
    int totalNotas = 0;
    bool encontrado = false;
    cout << "Promedios para el alumno " << idAlumno << "." << endl;
    while (actual) {
        if (actual->idAlumno == idAlumno) {
            if (!actual->notas) {actual = actual->siguiente; continue; }
            double suma = 0;
            int cont = 0;
            Nota* n = actual->notas;
            while (n) {
                suma += n->valor;
                cont++;
                n = n->siguiente;
            }
            double promedio = suma/cont;
            cout << "Curso " << actual->codigoCurso << " promedio: " << promedio << endl;
            sumaGeneral += suma;
            totalNotas += cont;
            encontrado = true;
        }
        actual = actual->siguiente;
    }
    if (encontrado) {
        double promedioGeneral = sumaGeneral/totalNotas;
        cout << "Promedio general: " << promedioGeneral << endl;
    } else {
        cout << "El alumno no tiene cursos con notas registradas";
    }
}
