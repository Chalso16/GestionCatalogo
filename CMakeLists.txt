cmake_minimum_required(VERSION 4.2)
project(GestionCatalogo)

set(CMAKE_CXX_STANDARD 20)

add_executable(GestionCatalogo main.cpp
        Producto.cpp
        Producto.h
        Electronica.cpp
        Electronica.h
        Ropa.cpp
        Ropa.h
        CajaEnvio.cpp
        CajaEnvio.h)
