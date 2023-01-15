#include "Nave.h"

//Constructores
Nave::Nave(unsigned short int _Peso = 0, unsigned short int _VelocidadMaxima = 0, unsigned short int _Empuje=0, string _Combustible="ND", string _Nombre="ND", string _Agencia ="ND",string _Funcion="ND"){
    Peso = _Peso;
    VelocidadMaxima = _VelocidadMaxima;
    Empuje = _Empuje;
    Combustible = _Combustible;
    Nombre = _Nombre;
    Funcion = _Funcion;
    Agencia = _Agencia;
}

Sonda::Sonda(unsigned short int _Peso = 0, unsigned short int _VelocidadMaxima = 0, unsigned short int _Empuje=0, string _Combustible="ND", string _Nombre="ND", string _Agencia = "ND", string _Funcion = "ND", string _Destino = "ND") : Nave(_Peso, _VelocidadMaxima, _Empuje, _Combustible, _Nombre, _Agencia, _Funcion){
    Destino = _Destino;//A que orbita
}

Cohete::Cohete(unsigned short int _Peso = 0, unsigned short int _VelocidadMaxima = 0, unsigned short int _Empuje=0, string _Combustible="ND", string _Nombre="ND", string _Agencia="ND",string _Funcion="ND", unsigned short int _Tamano = 0, unsigned short int _CargaMaxima = 0, unsigned short int _Potencia = 0) : Nave(_Peso, _VelocidadMaxima, _Empuje, _Combustible, _Nombre, _Agencia,_Funcion){
    Tamano = _Tamano;//Cuando mide
    CargaMaxima = _CargaMaxima;//Cuanto peso puede transportar
    Potencia = _Potencia;//Potencia
}

EstacionEspacial::EstacionEspacial(unsigned short int _Peso = 0, unsigned short int _VelocidadMaxima = 0, unsigned short int _Empuje=0, string _Combustible="ND", string _Agencia="ND", string _Nombre="ND", string _Funcion = "ND", unsigned short int _Capacidad = 0, unsigned short int _Distancia_Orbita = 0) : Nave(_Peso, _VelocidadMaxima, _Empuje, _Combustible, _Nombre, _Agencia,_Funcion){
    Capacidad = _Capacidad;//Cuantas personas puede transportar
    Distancia_Orbita = _Distancia_Orbita;//A que distancia esta de la superficie
}

//Gets
unsigned short int Nave::getpeso(){return Peso;}
unsigned short int Nave::getMaxvel(){return VelocidadMaxima;}
unsigned short int Nave::getEmpuje(){return Empuje;}
string Nave::getCombustible(){return Combustible;}
string Nave::getNombre(){return Nombre;}
string Nave::getFuncion(){return Funcion;}
string Nave::getAgencia(){return Agencia;}
string Sonda::getDestino(){return Destino;}
unsigned short int Cohete::getTamano(){return Tamano;}
unsigned short int Cohete::getPotencia(){return Potencia;}
unsigned short int Cohete::getCargaMaxima(){return CargaMaxima;}
unsigned short int EstacionEspacial::getCapacidad(){return Capacidad;}
unsigned short int EstacionEspacial::getDistancia_Orbita(){return Distancia_Orbita;}
//Sets
void Nave::setpeso(unsigned short int _Peso){Peso = _Peso;}
void Nave::setvelocidad(unsigned short int _VelocidadMaxima){VelocidadMaxima = _VelocidadMaxima;}
void Nave::setEmpuje(unsigned short int _Empuje){Empuje = _Empuje;}
void Nave::setCombustible(string _Combustible){Combustible = _Combustible;}
void Nave::setNombre(string _Nombre){Nombre = _Nombre;}
void Nave::setFuncion(string _Funcion){Funcion = _Funcion;}
void Nave::setAgencia(string _Agencia){Agencia =  _Agencia;}
void Sonda::setDestino(string _Destino){Destino = _Destino;}
void Cohete::setTamano(unsigned short int _Tamano){Tamano = _Tamano;}
void Cohete::setPotencia(unsigned short int _Potencia){Potencia = _Potencia;}
void Cohete::setCargaMaxima(unsigned short int _CargaMaxima){CargaMaxima = _CargaMaxima;}
void EstacionEspacial::setCapacidad(unsigned short int _Capacidad){Capacidad = _Capacidad;}
void EstacionEspacial::setDistancia_Orbita(unsigned short int _Distancia_Orbita){Distancia_Orbita = _Distancia_Orbita;}
