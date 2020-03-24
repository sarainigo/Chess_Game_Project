//
//  casilla.hpp
//  trabajo ajedrez prueba
//
//  Created by Sara Íñigo on 10/5/16.
//  Copyright © 2016 Sara Íñigo. All rights reserved.
//

#ifndef casilla_hpp
#define casilla_hpp

#include <stdio.h>

#endif /* casilla_hpp */

#include "pieza.hpp"

class Casilla{
    Pieza * pieza; //puntero a clase Pieza en cada casilla. Void si no hay pieza en la casilla
    
public:
    Casilla(void);
    ~Casilla(void);
    void setpieza(Pieza*);
    Pieza* getpieza();
};

//aunque pieza sea un puntero a un objeto de la clase Pieza, si tuviesemos: Peon* pieza1
//podría hacer pieza=&pieza1 (si hacemos funciones virtuales)