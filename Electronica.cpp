//
// Created by cbalb on 17/05/2026.
//

#include "Electronica.h"

//constructores
Electronica::Electronica(): Producto(), impuesto(0) {
}

Electronica::Electronica(const string &codigo, const string &nombre, const double &precioBase, const int &stock, const double &impuesto)
    : Producto(codigo, nombre, precioBase, stock), impuesto(impuesto){
    if (impuesto<0 || impuesto>1) {
        throw invalid_argument("Impuesto fuera de rango (0-1)");
    }
}

Electronica::Electronica(const Electronica &electronica): Producto(electronica), impuesto(electronica.impuesto) {
}

Electronica::~Electronica() {
    cout << "Electronica destruida" << endl;
}

//getters
double Electronica::getImpuesto() const {
    return impuesto;
}

//setters
void Electronica::setImpuesto(const double &impuesto) {
    if (impuesto<0 || impuesto>1) {
        throw invalid_argument("Impuesto fuera de rango (0-1)");
    }
    this->impuesto=impuesto;
}

//sobrecarga
Electronica& Electronica::operator--() {
    setStock(getStock()-1);
    return *this;
}

//Post decremento
Electronica& Electronica::operator--(int) {
    Electronica obj = *this;
    setStock(getStock()-1);
    return obj;
}

//metodos
double Electronica::calcularPrecioFinal() const {
    return getPrecioBase()* (1+impuesto);
}

