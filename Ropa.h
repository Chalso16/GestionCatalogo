//
// Created by cbalb on 17/05/2026.
//

#ifndef GESTIONCATALOGO_ROPA_H
#define GESTIONCATALOGO_ROPA_H
#include "Producto.h"
#include <iostream>
using namespace std;

class Ropa : public Producto{
private:
    string talla;
    double descuento;
public:
    //constructores
    Ropa();
    Ropa(const string& codigo, const string& nombre, const double& precioBase, const int& stock, const string& talla, const double& descuento);
    Ropa(const Ropa& ropa);
    virtual ~Ropa();
    //getters
    string getTalla() const;
    double getDescuento() const;
    //setters
    void setTalla(const string& talla);
    void setDescuento(const double& descuento);
    //sobrecarga
    //metodos
    double calcularPrecioFinal() const override;
    void vender(int cantidad) override;
};


#endif //GESTIONCATALOGO_ROPA_H
