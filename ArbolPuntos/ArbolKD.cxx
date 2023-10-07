#include "ArbolKD.h"


ArbolKD::ArbolKD() {
    this->raiz = NULL;
}


ArbolKD::~ArbolKD() {
    if (this->raiz != NULL) {
        delete this->raiz;
        this->raiz = NULL;
    }
}


bool ArbolKD::isVacio() {
    return this->raiz == NULL;
}


Punto ArbolKD::datoRaiz() {
    return (this->raiz)->getDato();
}


void ArbolKD::setRaiz(NodoKD* nodo) {
    this->raiz = nodo;
}


NodoKD* ArbolKD::getRaiz() {
    return this->raiz;
}


bool ArbolKD::insertar(Punto val) {
    if(this->isVacio()) {
        NodoKD* nodo = new NodoKD(val);
        this->raiz = nodo;
        return true;
    }
    
    bool insertado = false;
    bool duplicado = false;
    NodoKD* nodo = this->raiz;
    int contador = 0;
    
    while(!insertado && !duplicado) {
        contador++;
        if(nodo->getDato() == val) {
            duplicado = true;
            break;
        }
        
        int x1 = nodo->getDato().x;
        int y1 = nodo->getDato().y;
        int x2 = val.x;
        int y2 = val.y;
        NodoKD* hijo;
        
        if(contador%2 == 1) {
            
            if(x2 <= x1) {
                hijo = nodo->getIzq();
            } else {
                hijo = nodo->getDer();
            }
            
            
            if(hijo == NULL) {
                
                if(x2 <= x1) {
                    nodo->setIzq(new NodoKD(val));
                } else {
                    nodo->setDer(new NodoKD(val));
                }
                
                insertado = true;
                
            } else {
                nodo = hijo;
            }
                
        } else {
            
            if(y2 <= y1) {
                hijo = nodo->getIzq();
            } else {
                hijo = nodo->getDer();
            }
            
            
            if(hijo == NULL) {
                
                if(y2 <= y1) {
                    nodo->setIzq(new NodoKD(val));
                } else {
                    nodo->setDer(new NodoKD(val));
                }
                
                insertado = true;
                
            } else {
                nodo = hijo;
            }
        }
        
    }
    
    return insertado;
}


void ArbolKD::preOrden() {
    if(!this->isVacio()) {
        this->preOrden(this->raiz);
    }
}


void ArbolKD::preOrden(NodoKD* nodo) {
    std::cout << nodo->getDato() << " ";

    if (nodo->getIzq() != NULL) {
        this->preOrden(nodo->getIzq());
    }

    if (nodo->getDer() != NULL) {
        this->preOrden(nodo->getDer());
    }
}


void ArbolKD::inOrden() {
    if (!this->isVacio()) {
        this->inOrden(this->raiz);
    }
}


void ArbolKD::inOrden(NodoKD *nodo) {
    if (nodo != NULL) {
        this->inOrden(nodo->getIzq());
        std::cout << nodo->getDato() << " ";
        this->inOrden(nodo->getDer());
    }
}


void ArbolKD::posOrden() {
    if(!this->isVacio()) {
        this->posOrden(this->raiz);
    }
}


void ArbolKD::posOrden(NodoKD *nodo) {
    if (nodo->getIzq() != NULL) {
        this->posOrden(nodo->getIzq());
    }

    if (nodo->getDer() != NULL) {
        this->posOrden(nodo->getDer());
    }

    std::cout << nodo->getDato() << " ";
}


void ArbolKD::nivelOrden() {
    if (!this->isVacio()) {
        std::queue<NodoKD*> cola;
        cola.push(this->raiz);
        NodoKD* nodo;

        while(!cola.empty()) {
            nodo = cola.front();
            cola.pop();
            std::cout << nodo->getDato() << " ";

            if (nodo->getIzq() != NULL) {
                cola.push(nodo->getIzq());
            }

            if (nodo->getDer() != NULL) {
                cola.push(nodo->getDer());
            }

        }

    }
}
