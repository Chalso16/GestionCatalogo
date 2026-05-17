//
// Created by cbalb on 17/05/2026.
//

#include "Ropa.h"

//constructores
Ropa::Ropa():Producto(), talla("M"), descuento(0) {
}

Ropa::Ropa(const string &codigo, const string &nombre, const double &precioBase, const int &stock, const string &talla, const double &descuento)
    : Producto(codigo, nombre, precioBase, stock), talla(talla), descuento(descuento){
    if (descuento<0 || descuento > precioBase) {
        throw invalid_argument("Descuento no valido");
    }
    if (talla!="XS" && talla!="S" && talla!="M" && talla!="L" && talla!="XL" && talla!="XXL") {
        throw invalid_argument("Talla no valida (XS-S-M-L-XL-XXL)");
    }
}

Ropa::Ropa(const Ropa &ropa):Producto(ropa), talla(ropa.talla), descuento(ropa.descuento) {
}

Ropa::~Ropa() {
    cout << "Ropa destruida" << endl;
}

//getters
string Ropa::getTalla() const {
    return talla;
}

double Ropa::getDescuento() const {
    return descuento;
}

//setters
void Ropa::setTalla(const string &talla) {
    if (talla!="XS" || talla!="S" || talla!="M" || talla!="L" || talla!="XL" || talla!="XXL") {
        throw invalid_argument("Talla no valida (XS-S-M-L-XL-XXL)");
    }
    this->talla=talla;
}

void Ropa::setDescuento(const double &descuento) {
    if (descuento<0 || descuento > precioBase) {
        throw invalid_argument("Descuento no valido");
    }
    this->descuento=descuento;
}

//metodos
double Ropa::calcularPrecioFinal() const {
    return getPrecioBase()-descuento;
}

void Ropa::vender(int cantidad) {
    Producto::vender(cantidad);
    if (getStock()==0) {
        cout << "Rotura de stock" << endl;
    }
}
