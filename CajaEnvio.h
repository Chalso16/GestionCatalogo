//
// Created by cbalb on 17/05/2026.
//

#ifndef GESTIONCATALOGO_CAJAENVIO_H
#define GESTIONCATALOGO_CAJAENVIO_H
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class CajaEnvio {
private:
    vector<T> caja;
public:
    //contructores
    CajaEnvio(){}
    CajaEnvio(const vector<T>& caja):caja(caja){}
    CajaEnvio(const CajaEnvio& cajaEnvio): caja(cajaEnvio){}
    ~CajaEnvio() {
        cout << "CajaEnvio destruida" << endl;
    }
    //getters
    vector<T> getCaja() const {
        return caja;
    }
    //setters
    void setCaja(const vector<T>& caja) {
        this->caja=caja;
    }
    //metodos
    void agregarElemento(const T& elemento) {
        this->caja.push_back(elemento);
    }

    void mostrarContenido() const {
        cout << "Contenido de la caja: "<< endl;
        for (T elemento : caja) {
            cout << *elemento << endl;
        }
    }
};


#endif //GESTIONCATALOGO_CAJAENVIO_H
