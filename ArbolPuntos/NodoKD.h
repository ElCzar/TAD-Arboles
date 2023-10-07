#ifndef __NODOKD_H__
#define __NODOKD_H__

#include "Punto.h"

class NodoKD {
protected:
    Punto dato;
    NodoKD* izq;
    NodoKD* der;
public:
    NodoKD();
    NodoKD(Punto p);
    ~NodoKD();

    Punto getDato();
    void setDato(Punto val);

    NodoKD* getIzq();
    NodoKD* getDer();

    void setIzq(NodoKD* izq);
    void setDer(NodoKD* der);

    bool isHoja();
};

#endif
