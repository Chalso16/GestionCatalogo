#include <iostream>
#include <vector>
#include <memory>
#include "Producto.h"
#include "Electronica.h"
#include "Ropa.h"
#include "CajaEnvio.h"
using namespace std;

int main() {
    try {
        vector<shared_ptr<Producto>> inventario;
        shared_ptr<Electronica> e1 = make_shared<Electronica>("1234ABC", "Iphone", 999.99, 1, 0.21);
        inventario.push_back(e1);
        shared_ptr<Electronica> e2 = make_shared<Electronica>("4321CBA", "Samsung", 899.99, 10, 0.21);
        --(*e2);
        inventario.push_back(e2);
        shared_ptr<Ropa> r1 = make_shared<Ropa>("9876XYZ", "Camiseta", 30.95, 10, "XL", 4.95);
        inventario.push_back(r1);
        shared_ptr<Ropa> r2 = make_shared<Ropa>("4545QRS", "Pantalon", 44.95, 12, "L", 9.95);
        inventario.push_back(r2);

        try {
            inventario.at(0)->vender(10);
        }catch (const runtime_error& error1) {
            cout << "ERROR, " << error1.what();
        }
        for (const auto x: inventario) {
            cout <<"Producto: " << x->getNombre()<<": "<< x->calcularPrecioFinal() << endl;
        }
        CajaEnvio<shared_ptr<Producto>> cajas;
        cajas.agregarElemento(e1);
        cajas.agregarElemento(e2);
        cajas.agregarElemento(r1);
        cajas.agregarElemento(r2);
        cajas.mostrarContenido();


    }catch (const invalid_argument& error2) {
        cout << "ERROR, " << error2.what();
    }
    return 0;
}

