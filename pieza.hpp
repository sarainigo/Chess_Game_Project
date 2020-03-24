
//  pieza.hpp
//  trabajo ajedrez prueba
//
//  Created by Sara Íñigo on 10/5/16.
//  Copyright © 2016 Sara Íñigo. All rights reserved.
//

#ifndef pieza_hpp
#define pieza_hpp

#include <stdio.h>
class Casilla;

 /* pieza_hpp */

#include<string>
#include <stdlib.h>
#include <stdio.h>
#include<iostream>

using namespace std;


class Pieza{
    
protected:
    
    int jugador;
    static int turno;
    
    Casilla** tablero;
    
public:
    
    Pieza(int,Casilla**); //constructor
    
    virtual ~Pieza(void);
    
    virtual char tipo();
    
    int getjugador();//1-blancas 2-negras
    
    virtual bool mover(int, int, int, int);
    
    virtual bool comer(int, int, int, int);
    
    virtual bool puedoMover(int, int, int, int);
    
    virtual bool puedoComer(int, int, int, int);
    
    virtual int * posicionposible(int, int);
    
    
    
};

int Pieza::turno=0;


class Rey: public Pieza{
    
    bool hamovido;
    
public:
    
    Rey(int,Casilla**);
    
    ~Rey(void);
    
    char tipo(){return 'k';}
    
    bool mover(int, int, int, int);
    bool puedoComer(int, int, int, int);
    bool comer(int, int, int, int);
    bool puedoMover(int, int, int, int);
    int * posicionposible(int, int);
    
    
    bool getmovido();
    
    void enrocar(bool);
    
    
    
};




class Reina: public Pieza{
    
public:
    
    Reina(int,Casilla**);
    
    ~Reina(void);
    
    char tipo(){return 'q';}
    
    bool mover(int, int, int, int);
    bool puedoMover(int, int, int, int);
    bool comer(int, int, int, int);
    bool puedoComer(int, int, int, int);
    int * posicionposible(int, int);
};




class Torre: public Pieza{
    
    bool hamovido;
    
public:
    
    Torre(int,Casilla**);
    
    ~Torre(void);
    
    char tipo(){return 't';}
    
    bool mover(int, int, int, int);
    bool puedoMover(int, int, int, int);
    bool comer(int, int, int, int);
    bool puedoComer(int, int, int, int);
    int * posicionposible(int, int);
    
    
    bool getmovido();
    
    void enrocar();
};




class Alfil: public Pieza{
    
public:
    
    Alfil(int,Casilla**);
    
    ~Alfil(void);
    
    char tipo(){return 'a';}
    bool puedoMover(int, int, int, int);
    bool mover(int, int, int, int);
    bool puedoComer(int, int, int, int);
    bool comer(int, int, int, int);
    
    int * posicionposible(int, int);
    
};




class Caballo: public Pieza{
    
public:
    
    Caballo(int,Casilla**);
    
    ~Caballo(void);
    
    char tipo(){return 'c';}
    
    bool mover(int, int, int, int);
    bool puedoComer(int, int, int, int);
    bool comer(int, int, int, int);
    bool puedoMover(int, int, int, int);
    int * posicionposible(int, int);
    
};




class Peon: public Pieza{
    
    int haavanzado;
    
public:
    
    Peon(int,Casilla**);
    
    ~Peon(void);
    
    char tipo(){return 'p';}
    
    bool mover(int, int, int, int);
    bool puedoComer(int, int, int, int);
    bool comer(int, int, int, int);
    bool puedoMover(int, int, int, int);
    int * posicionposible(int, int);
    
    
    //Pieza promocion(char);
    
    int getavanzado();
};

#endif



