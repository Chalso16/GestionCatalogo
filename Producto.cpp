//
// Created by cbalb on 17/05/2026.
//

#include "Producto.h"

//constructores
Producto::Producto():codigo("0000xxx"), nombre("Null"), precioBase(0.0), stock(0) {
}

Producto::Producto(const string &codigo, const string &nombre, const double &precioBase, const int &stock):codigo(codigo),nombre(nombre),precioBase(precioBase),stock(stock) {
    if (precioBase<0) {
        throw invalid_argument("Precio base menor a 0");
    }
    if (stock<0) {
        throw invalid_argument("Stock menor a 0");
    }
}

Producto::Producto(const Producto &producto) : codigo(producto.codigo), nombre(producto.nombre), precioBase(producto.precioBase), stock(producto.stock){
}

Producto::~Producto() {
    cout << "Producto eliminado" << endl;
}

//getters
string Producto::getCodigo() const {
    return codigo;
}

string Producto::getNombre() const {
    return nombre;
}

double Producto::getPrecioBase() const {
    return precioBase;
}

int Producto::getStock() const {
    return stock;
}

//setters
void Producto::setCodigo(const string &codigo) {
    this->codigo=codigo;
}

void Producto::setNombre(const string &nombre) {
    this->nombre=nombre;
}

void Producto::setPrecioBase(const double &precioBase) {
    if (precioBase<0) {
        throw invalid_argument("Precio base menor a 0");
    }
    this->precioBase=precioBase;
}

void Producto::setStock(const int &stock) {
    if (stock<0) {
        throw invalid_argument("Stock menor a 0");
    }
    this->stock=stock;
}

//sobrecarga
ostream &operator<<(ostream &os, const Producto &producto) {
    os << "-->Nombre: "<< producto.nombre << endl;
    os << "-->Codigo: "<< producto.codigo << endl;
    os << "-->PrecioBase: "<< producto.precioBase << endl;
    os << "-->Stock: "<< producto.stock << endl;
    return os;
}

//metodos
void Producto::vender(int cantidad) {
    if (stock<cantidad) {
        throw runtime_error("Stock menor a cantidad a vender");
    }
    setStock(getStock() - cantidad);
}

