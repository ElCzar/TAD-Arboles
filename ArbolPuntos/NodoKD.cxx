#include "NodoKD.h"


NodoKD::NodoKD(){
    Punto p;
    p.x = 0;
    p.y = 0;

    this->dato = p;
    izq = der = nullptr;
}

NodoKD::NodoKD(Punto p) {
    this->dato = p;
    izq = der = nullptr;
}


NodoKD::~NodoKD(){
    if (izq != NULL) {
        delete izq;
    }
    if (der != NULL) {
        delete der;
    }
}


Punto NodoKD::getDato(){
    return dato;
}


void NodoKD::setDato(Punto val){
    dato = val;
}


NodoKD* NodoKD::getIzq(){
    return izq;
}


void NodoKD::setIzq(NodoKD* izq){
    this->izq = izq;
}


NodoKD* NodoKD::getDer(){
    return der;
}


void NodoKD::setDer(NodoKD* der){
    this->der = der;
}


bool NodoKD::isHoja() {
    return (this->der == NULL) && (this->izq == NULL);
}
