//
// Created by cbalb on 17/05/2026.
//

#ifndef GESTIONCATALOGO_PRODUCTO_H
#define GESTIONCATALOGO_PRODUCTO_H
#include <iostream>
#include <stdexcept>
using namespace std;

class Producto {
protected:
    string codigo;
    string nombre;
    double precioBase;
    int stock;
public:
    //Constructores
    Producto();
    Producto(const string& codigo, const string& nombre, const double& precioBase, const int& stock);
    Producto(const Producto& producto);
    virtual ~Producto();
    //getters
    string getCodigo() const;
    string getNombre() const;
    double getPrecioBase() const;
    int getStock() const;
    //setters
    void setCodigo(const string& codigo);
    void setNombre(const string& nombre);
    void setPrecioBase(const double& precioBase);
    void setStock(const int& stock);
    //sobrecargas
    friend ostream& operator<< (ostream& os, const Producto& producto);
    //metodos
    virtual double calcularPrecioFinal() const = 0;
    virtual void vender(int cantidad);
};

#endif //GESTIONCATALOGO_PRODUCTO_H
