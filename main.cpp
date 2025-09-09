#include <iostream>
#include <limits>

#include "Alumno.h"
#include "Curso.h"
#include "Inscripcion.h"

using namespace std;

void limpiarInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    ListaAlumnos listaA;
    ListaAlumnos listaC;
    ListaAlumnos listaI;
    int opcion;

    do {
        cout << "--- Sistema de Gestión Académica ---" << endl;
        cout << "1. Gestión de Alumnos" << endl;
        cout << "2. Gestión de Cursos" << endl;
        cout << "3. Inscripción de Alumno a Curso" << endl;
        cout << "4. Eliminar Inscripción" << endl;
        cout << "5. Registrar Nota" << endl;
        cout << "6. Consultas";
        cout << "7. Sair" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        if (cin.fail()) {
            limpiarInput();
            cout << "Entrada invalida, Intente nuevamente" << endl;
            continue;
        }

        switch (opcion) {
            case 1: {
                int opcionA;
                do {
                    cout << "--- Gestión de Alumnos ---" << endl;
                    cout << "1. Crear Alumno" << endl;
                    cout << "2. Buscar Alumno" << endl;
                    cout << "3. Eliminar Alumno" << endl;
                    cout << "4. Listar Alumnos por Carrera" << endl;
                    cout << "5. Mostrar todos los Alumnos" << endl;
                    cout << "6. Volver al menú principal" << endl;
                    cout << "Seleccione una opcion: " << endl;
                    cin >> opcionA;
                    if (cin.fail()) {limpiarInput(); cout << "Entrada invalida" << endl; continue;}

                    if (opcionA == 1) {
                        Alumno a;
                        cout << "Ingrese ID: "; cin >> a.id;
                        limpiarInput();
                        cout << "Ingrese Nombre: "; getline(cin, a.nombre);
                        cout << "Ingrese apellido: "; getline(cin, a.apellido);
                        cout << "Ingrese carrera: "; getline(cin, a.carrera);
                        cout << "Ingrese fecha de ingreso (dia/mes/año): "; getline(cin, a.fechaIngreso);
                        listaA.agregarAlumno(a);
                    } else if (opcionA == 2) {
                        int idBuscar;
                        cout << "Ingrese ID a buscar: "; cin >> idBuscar;
                        NodoAlumno* resultado = listaA.buscarPorId(idBuscar);
                        if (resultado) {
                            cout << "Alumno encontrado: " << resultado->alumno.id << " - "
                                 << resultado->alumno.nombre << " " << resultado->alumno.apellido
                                 << ", Carrera: " << resultado->alumno.carrera
                                 << ", Ingreso: " << resultado->alumno.fechaIngreso << endl;
                        } else {
                            cout << "Alumno con ID: " << idBuscar << " no existe." << endl;
                        }
                    } else if (opcionA == 3) {
                        int idEliminar;
                        cout << "Ingresar ID a eliminar: "; cin >> idEliminar;
                        listaA.eliminarPorId(idEliminar);
                    } else if (opcionA == 4) {
                        string carrera;
                        limpiarInput();
                        cout << "Ingrese carrera a filtrar: "; getline(cin, carrera);
                        listaA.listarPorCarrera(carrera);
                    } else if (opcionA == 5) {
                        listaA.MostrarTodos();
                    } else if (opcionA != 6) {
                        cout << "Opcion no valida" << endl;
                    }
                } while (opcionA != 6);
                break;
            }
            case 2: {
                int opcionC;
                do {
                    cout << "--- Gestión de Cursos ---" << endl;
                    cout << "1. Crear Curso" << endl;
                    cout << "2. Buscar Curso" << endl;
                    cout << "3. Eliminar Curso" << endl;
                    cout << "4. Mostrar todos los Cursos" << endl;
                    cout << "5. Volver al menu principal" << endl;
                    cout << "Seleccione una opcion: " << endl;
                    cin >> opcionC;
                } while (true);
            }
        }
    } while (true);

    return 0;
}