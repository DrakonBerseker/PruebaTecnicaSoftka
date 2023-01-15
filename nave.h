#ifndef NAVE_H
#define NAVE_H
#include <iostream>
#include <stdio.h>
using namespace std;

class Nave{
//Atributos de las naves
private:
    unsigned short int Peso;//Toneladas
    unsigned short int VelocidadMaxima;//km/h
    unsigned short int Empuje;//Toneladas
    string Combustible;
    string Nombre;
    string Agencia;
    string Funcion;

//Metodos
public:
    //Constructor
    Nave(unsigned short int, unsigned short int, unsigned short int, string, string, string, string);

    //Gets
    unsigned short int getpeso();
    unsigned short int getMaxvel();
    unsigned short int getEmpuje();
    string getCombustible();
    string getNombre();
    string getFuncion();
    string getAgencia();
    //Sets
    void setpeso(unsigned short int);
    void setvelocidad(unsigned short int);
    void setEmpuje(unsigned short int);
    void setCombustible(string);
    void setNombre(string);
    void setFuncion(string);
    void setAgencia(string);
};

class Sonda : public Nave{
    private:
    string Destino;//Hace referencia al planeta o dispositivo (en el caso de la EEI) que orbita
    public:
    Sonda(unsigned short int, unsigned short int, unsigned short int, string, string, string, string, string);
    //Gets
    string getDestino();
    //Sets 
    void setDestino(string);
};

class Cohete : public Nave{
    private:
    unsigned short int Tamano;
    unsigned short int CargaMaxima;
    unsigned short int Potencia;
   
    public:
    Cohete(unsigned short int, unsigned short int, unsigned short int, string, string, string, string, unsigned short int, unsigned short int, unsigned short int);
    //Gets
    unsigned short int getTamano();
    unsigned short int getCargaMaxima();
    unsigned short int getPotencia();
    //Sets
    void setTamano(unsigned short int);
    void setCargaMaxima(unsigned short int);
    void setPotencia(unsigned short int);
};

class EstacionEspacial : public Nave{
    private:
    unsigned short int Capacidad;
    unsigned short int Distancia_Orbita;

    public:
    EstacionEspacial(unsigned short int, unsigned short int, unsigned short int, string, string, string, string, unsigned short int, unsigned short int);
    //Gets
    unsigned short int getCapacidad();
    unsigned short int getDistancia_Orbita();
    //Sets
    void setCapacidad(unsigned short int);
    void setDistancia_Orbita(unsigned short int);
};

#endif