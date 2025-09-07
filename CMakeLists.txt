cmake_minimum_required(VERSION 4.0)
project(Taller1)

set(CMAKE_CXX_STANDARD 26)

add_executable(Taller1 main.cpp
        Alumno.h
        Alumno.cpp
        Curso.h
        Curso.cpp
        Inscripcion.h
        Inscripcion.cpp)
