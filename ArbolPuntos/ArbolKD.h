#ifndef __ARBOLKD_H__
#define __ARBOLKD_H__

#include "NodoKD.h"
#include "Punto.h"
#include <queue>


class ArbolKD {
private:
    NodoKD* raiz;

public:
    ArbolKD();
    ~ArbolKD();
    bool isVacio();

    Punto datoRaiz();
    void setRaiz(NodoKD* nodo);
    NodoKD* getRaiz();

    bool insert(Punto val);

    void preOrden();
    void preOrden(NodoKD* nodo);

    void inOrden();
    void inOrden(NodoKD* nodo);

    void posOrden();
    void posOrden(NodoKD* nodo);

    void nivelOrden();
};

#endif // ARBOLKD_H
