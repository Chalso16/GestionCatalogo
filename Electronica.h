//
// Created by cbalb on 17/05/2026.
//

#ifndef GESTIONCATALOGO_ELECTRONICA_H
#define GESTIONCATALOGO_ELECTRONICA_H
#include "Producto.h"
#include <iostream>
using namespace std;

class Electronica : public Producto{
private:
    double impuesto;
public:
    //constructores
    Electronica();
    Electronica(const string& codigo, const string& nombre, const double& precioBase, const int& stock, const double& impuesto);
    Electronica(const Electronica& electronica);
    virtual ~Electronica();
    //getters
    double getImpuesto() const;
    //setters
    void setImpuesto(const double& impuesto);
    //sobrecarga
    Electronica operator--();
    Electronica operator--(int);
    //metodos
    double calcularPrecioFinal() const override;
    // void vender(int cantidad) override;
};


#endif //GESTIONCATALOGO_ELECTRONICA_H
