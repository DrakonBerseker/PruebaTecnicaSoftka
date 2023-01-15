#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include "Nave.cpp"
#include <fstream>
#include <string>
#include<array>

class Principal {
    private:
    Sonda SondaGenerica;
    Cohete CoheteGenerico;
    EstacionEspacial EEGenerica;
    fstream BaseDatos;

    public:
    Principal();
    void Selector(int);
    Sonda getSonda();
    Cohete getCohete();
    EstacionEspacial getEstacionEspacial();
    void NaveABase(int, string);
    void Filtro_Por_Tipo(int);
    void Busqueda_Por_Nombre(string);
    std::array<string,14> ExtraccionCaracteristicas(string);
    void MonstarBaseDatos();
    void BorrarBaseDatos();

};
#endif