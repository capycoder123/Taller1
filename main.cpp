#include <iostream>
#include <string>
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
    ListaCursos listaC;
    ListaInscripciones listaI;
    int opcion;

    do {
        cout << "\n--- Sistema de Gestión Académica ---\n";
        cout << "1. Gestión de Alumnos\n";
        cout << "2. Gestión de Cursos\n";
        cout << "3. Inscripción de Alumno a Curso\n";
        cout << "4. Eliminar Inscripción\n";
        cout << "5. Registrar Nota\n";
        cout << "6. Consultas\n";
        cout << "7. Salir\n";
        cout << "Seleccione una opción: ";
        if(!(cin >> opcion)) {
            limpiarInput();
            cout << "Entrada inválida. Intente nuevamente.\n";
            continue;
        }

        switch(opcion) {
            case 1: {
                int opA;
                do {
                    cout << "\n--- Gestión de Alumnos ---\n";
                    cout << "1. Crear Alumno\n";
                    cout << "2. Buscar Alumno\n";
                    cout << "3. Eliminar Alumno\n";
                    cout << "4. Listar Alumnos por Carrera\n";
                    cout << "5. Mostrar todos los Alumnos\n";
                    cout << "6. Volver al menú principal\n";
                    cout << "Seleccione una opción: ";
                    if(!(cin >> opA)) { limpiarInput(); cout << "Entrada inválida.\n"; continue; }

                    if(opA == 1) {
                        Alumno a;
                        cout << "Ingrese ID: ";
                        while(!(cin >> a.id)) { limpiarInput(); cout << "ID inválido. Ingrese un número: "; }
                        limpiarInput();
                        cout << "Ingrese nombre: "; getline(cin, a.nombre);
                        cout << "Ingrese apellido: "; getline(cin, a.apellido);
                        cout << "Ingrese carrera: "; getline(cin, a.carrera);
                        cout << "Ingrese fecha de ingreso (dd/mm/aaaa): "; getline(cin, a.fechaIngreso);
                        listaA.agregarAlumno(a);
                    } else if(opA == 2) {
                        cout << "Buscar Alumno:\n1. Por ID\n2. Por Nombre\nSeleccione: ";
                        int buscarOp;
                        if(!(cin >> buscarOp)) { limpiarInput(); cout << "Entrada inválida.\n"; continue; }
                        if(buscarOp == 1) {
                            int idBus;
                            cout << "Ingrese ID a buscar: ";
                            if(!(cin >> idBus)) { limpiarInput(); cout << "ID inválido.\n"; continue; }
                            NodoAlumno* alumnoNodo = listaA.buscarPorId(idBus);
                            if(alumnoNodo) {
                                cout << "Alumno encontrado: " << alumnoNodo->alumno.id << " - "
                                     << alumnoNodo->alumno.nombre << " " << alumnoNodo->alumno.apellido
                                     << ", Carrera: " << alumnoNodo->alumno.carrera
                                     << ", Ingreso: " << alumnoNodo->alumno.fechaIngreso << endl;
                            } else {
                                cout << "Alumno con ID " << idBus << " no existe.\n";
                            }
                        } else if(buscarOp == 2) {
                            limpiarInput();
                            string nombreBusqueda;
                            cout << "Ingrese nombre a buscar: "; getline(cin, nombreBusqueda);
                            listaA.listarPorNombre(nombreBusqueda);
                        } else {
                            cout << "Opción inválida.\n";
                        }
                    } else if(opA == 3) {
                        cout << "Eliminar Alumno - Ingrese ID a eliminar: ";
                        int idE;
                        if(!(cin >> idE)) { limpiarInput(); cout << "ID inválido.\n"; continue; }

                        NodoAlumno* alumnoNodo = listaA.buscarPorId(idE);
                        if(!alumnoNodo) {
                            cout << "No existe alumno con ID " << idE << ".\n";
                            continue;
                        }
                        cout << "Confirma eliminar al alumno: " << alumnoNodo->alumno.id << " - "
                             << alumnoNodo->alumno.nombre << " " << alumnoNodo->alumno.apellido
                             << " ? (s/n): ";
                        char conf; cin >> conf; limpiarInput();
                        if(conf == 's' || conf == 'S') {
                            listaA.eliminarPorId(idE);
                        } else {
                            cout << "Operación cancelada.\n";
                        }
                    } else if(opA == 4) {
                        string carrera;
                        limpiarInput();
                        cout << "Ingrese carrera a filtrar: "; getline(cin, carrera);
                        listaA.listarPorCarrera(carrera);
                    } else if(opA == 5) {
                        listaA.MostrarTodos();
                    } else if(opA != 6) {
                        cout << "Opción inválida.\n";
                    }
                } while(opA != 6);
                break;
            }
            case 2: {
                int opC;
                do {
                    cout << "\n--- Gestión de Cursos ---\n";
                    cout << "1. Crear Curso\n";
                    cout << "2. Buscar Curso\n";
                    cout << "3. Eliminar Curso\n";
                    cout << "4. Mostrar todos los Cursos\n";
                    cout << "5. Volver al menú principal\n";
                    cout << "Seleccione una opción: ";
                    if(!(cin >> opC)) { limpiarInput(); cout << "Entrada inválida.\n"; continue; }

                    if(opC == 1) {
                        Curso c;
                        cout << "Ingrese código: ";
                        while(!(cin >> c.codigo)) { limpiarInput(); cout << "Código inválido. Reintente: "; }
                        limpiarInput();
                        cout << "Ingrese nombre: "; getline(cin, c.nombre);
                        cout << "Ingrese carrera: "; getline(cin, c.carrera);
                        cout << "Ingrese profesor: "; getline(cin, c.profesor);
                        cout << "Ingrese cupo máximo de alumnos: ";
                        while(!(cin >> c.maxAlumnos)) { limpiarInput(); cout << "Cupo inválido. Reintente: "; }
                        limpiarInput();
                        listaC.agregarCurso(c);
                    } else if(opC == 2) {
                        cout << "Buscar Curso:\n1. Por Código\n2. Por Nombre\nSeleccione: ";
                        int buscarOp;
                        if(!(cin >> buscarOp)) { limpiarInput(); cout << "Entrada inválida.\n"; continue; }
                        if(buscarOp == 1) {
                            int cod;
                            cout << "Ingrese código: ";
                            if(!(cin >> cod)) { limpiarInput(); cout << "Código inválido.\n"; continue; }
                            NodoCurso* res = listaC.buscarPorCodigo(cod);
                            if(res) {
                                cout << "Curso encontrado: " << res->curso.codigo << " - "
                                     << res->curso.nombre << ", Carrera: " << res->curso.carrera
                                     << ", Profesor: " << res->curso.profesor
                                     << ", Inscritos: " << res->curso.inscritos << "/" << res->curso.maxAlumnos << endl;
                            } else {
                                cout << "Curso con código " << cod << " no existe.\n";
                            }
                        } else if(buscarOp == 2) {
                            limpiarInput();
                            string nombreC;
                            cout << "Ingrese nombre: "; getline(cin, nombreC);
                            listaC.listarPorNombre(nombreC);
                        } else {
                            cout << "Opción inválida.\n";
                        }
                    } else if(opC == 3) {
                        int metodo;
                        cout << "\nEliminar Curso - Elija método:\n";
                        cout << "1. Por Código\n";
                        cout << "2. Por Nombre\n";
                        cout << "Seleccione: ";
                        if(!(cin >> metodo)) {
                            limpiarInput();
                            cout << "Entrada inválida.\n";
                            continue;
                        }

                        if(metodo == 1) {
                            int codE;
                            cout << "Ingrese código a eliminar: ";
                            if(!(cin >> codE)) { limpiarInput(); cout << "Código inválido.\n"; continue; }

                            NodoCurso* curso = listaC.buscarPorCodigo(codE);
                            if(!curso) {
                                cout << "No existe curso con código " << codE << ".\n";
                                continue;
                            }
                            cout << "Confirma eliminar el curso: " << curso->curso.codigo << " - " << curso->curso.nombre
                                 << " ? (s/n): ";
                            char conf; cin >> conf; limpiarInput();
                            if(conf == 's' || conf == 'S') {
                                listaI.eliminarInscripcionesPorCurso(codE, listaC);
                                listaC.eliminarPorCodigo(codE);
                            } else {
                                cout << "Operación cancelada.\n";
                            }

                        } else if(metodo == 2) {
                            limpiarInput();
                            string nombreEliminar;
                            cout << "Ingrese nombre del curso a eliminar: ";
                            getline(cin, nombreEliminar);

                            listaC.listarPorNombre(nombreEliminar);

                            cout << "Ingrese el CÓDIGO del curso que desea eliminar (0 para cancelar): ";
                            int codE;
                            if(!(cin >> codE)) { limpiarInput(); cout << "Código inválido.\n"; continue; }

                            if(codE == 0) {
                                cout << "Operación cancelada.\n";
                                continue;
                            }

                            NodoCurso* curso = listaC.buscarPorCodigo(codE);
                            if(!curso) {
                                cout << "No existe curso con código " << codE << ". Operación abortada.\n";
                                continue;
                            }

                            if(curso->curso.nombre != nombreEliminar) {
                                cout << "El curso seleccionado (codigo " << codE << ") no coincide con el nombre '"
                                     << nombreEliminar << "'.\n";
                                cout << "Si quieres, vuelve a intentar con el código correcto.\n";
                                continue;
                            }

                            cout << "Confirma eliminar el curso: " << curso->curso.codigo << " - " << curso->curso.nombre
                                 << " ? (s/n): ";
                            char conf; cin >> conf; limpiarInput();
                            if(conf == 's' || conf == 'S') {
                                listaI.eliminarInscripcionesPorCurso(codE, listaC);
                                listaC.eliminarPorCodigo(codE);
                            } else {
                                cout << "Operación cancelada.\n";
                            }

                        } else {
                            cout << "Método inválido.\n";
                        }
                    } else if(opC == 4) {
                        listaC.mostrarTodo();
                    } else if(opC != 5) {
                        cout << "Opción inválida.\n";
                    }
                } while(opC != 5);
                break;
            }
            case 3: {
                int idA, codC;
                cout << "Inscribir Alumno a Curso\n";
                cout << "Ingrese ID del alumno: ";
                if(!(cin >> idA)) { limpiarInput(); cout << "ID inválido.\n"; continue; }
                cout << "Ingrese Código del curso: ";
                if(!(cin >> codC)) { limpiarInput(); cout << "Código inválido.\n"; continue; }
                listaI.inscribir(idA, codC, listaA, listaC);
                break;
            }
            case 4: {
                int idA, codC;
                cout << "Eliminar Inscripción\n";
                cout << "Ingrese ID del alumno: ";
                if(!(cin >> idA)) { limpiarInput(); cout << "ID inválido.\n"; continue; }
                cout << "Ingrese Código del curso: ";
                if(!(cin >> codC)) { limpiarInput(); cout << "Código inválido.\n"; continue; }
                listaI.eliminarInscripcion(idA, codC, listaC);
                break;
            }
            case 5: {
                int idA, codC;
                double nota;
                cout << "Registrar Nota\n";
                cout << "Ingrese ID del alumno: ";
                if(!(cin >> idA)) { limpiarInput(); cout << "ID inválido.\n"; continue; }
                cout << "Ingrese Código del curso: ";
                if(!(cin >> codC)) { limpiarInput(); cout << "Código inválido.\n"; continue; }
                cout << "Ingrese nota (1.0 - 7.0): ";
                if(!(cin >> nota)) { limpiarInput(); cout << "Nota inválida.\n"; continue; }
                listaI.agregarNota(idA, codC, nota);
                break;
            }
            case 6: {
                int opQ;
                do {
                    cout << "\n--- Consultas ---\n";
                    cout << "1. Cursos inscritos de un alumno\n";
                    cout << "2. Promedios de un alumno\n";
                    cout << "3. Alumnos por carrera\n";
                    cout << "4. Volver al menú principal\n";
                    cout << "Seleccione una opción: ";
                    if(!(cin >> opQ)) { limpiarInput(); cout << "Entrada inválida.\n"; continue; }

                    if(opQ == 1) {
                        int id;
                        cout << "Ingrese ID del alumno: ";
                        if(!(cin >> id)) { limpiarInput(); cout << "ID inválido.\n"; continue; }
                        listaI.mostrarCursosPorAlumno(id, listaC);
                    } else if(opQ == 2) {
                        int id;
                        cout << "Ingrese ID del alumno: ";
                        if(!(cin >> id)) { limpiarInput(); cout << "ID inválido.\n"; continue; }
                        listaI.mostrarPromediosTotales(id);
                    } else if(opQ == 3) {
                        string carrera;
                        limpiarInput();
                        cout << "Ingrese carrera: "; getline(cin, carrera);
                        listaA.listarPorCarrera(carrera);
                    } else if(opQ != 4) {
                        cout << "Opción inválida.\n";
                    }
                } while(opQ != 4);
                break;
            }
            case 7:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }

    } while(opcion != 7);

    return 0;
}