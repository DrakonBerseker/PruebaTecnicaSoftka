#include "Principal.h"

Principal::Principal(){
    SondaGenerica = Sonda();
    CoheteGenerico =Cohete();
    EEGenerica = EstacionEspacial();
}

//Esto permite llenar cualquiera de los 3 atributos con la data de la nave seleccionada
void Principal::Selector(int Seleccion){
    //DatosNaveGenerica();
    //Datos del constructor
    string Nombre = "Nombre";
    string Agencia = "Agencia";
    string Funcion = "Funcion";
    string Combustible = "Combustible";
    unsigned short int Peso;
    unsigned short int VelocidadMaxima;
    unsigned short int Empuje;
    //Unicos de la SONDA
    string Destino = "Destino";
    //Unicos de los cohetes
    unsigned short int CargaMaxima;
    unsigned short int Potencia;
    unsigned short int Tamano;
    //Unicos de las estaciones espaciales
    unsigned short int Distancia_Orbita;
    unsigned short int Capacidad;

    cout<<"Introduzca el nombre de la nave ";cin>>Nombre;
    cout<<"Introduzca la agencia ";cin>>Agencia;
    cout<<"Introduzca la funcion ";cin>>Funcion;
    cout<<"Introduzca el combustible ";cin>>Combustible;
    cout<<"Introduzca el peso aproximado ";cin>>Peso;
    cout<<"Introduzca la velocidad maxima ";cin>>VelocidadMaxima;
    cout<<"Introduzca el empuje aproximado ";cin>>Empuje;
    switch (Seleccion)
    {
    case 1://Sonda
        cout<<"Introduzca el destino de la Sonda ";cin>>Destino;
        SondaGenerica = Sonda(Peso, VelocidadMaxima, Empuje, Combustible, Nombre, Agencia, Funcion, Destino);
        break;
    case 2://Cohete
        cout<<"Introduzca el tamano del cohete ";cin>>Tamano;
        cout<<"Introduzca la carga maxima del cohete ";cin>>CargaMaxima;
        cout<<"Introduzca la potencia del cohete ";cin>>Potencia;
        CoheteGenerico = Cohete(Peso, VelocidadMaxima, Empuje, Combustible, Nombre, Agencia, Funcion, Tamano, CargaMaxima, Potencia);
        break;
    case 3://Estacion Espacial
        //DatosEE(Info);
        cout<<"Introduzca la distancia de la estacion espacial respecto a la superficie ";cin>>Distancia_Orbita;
        cout<<"Introduzca la cantidad de personas que pueden estar en la estacion ";cin>>Capacidad;
        EEGenerica = EstacionEspacial(Peso, VelocidadMaxima, Empuje, Combustible, Nombre, Agencia, Funcion, Capacidad, Distancia_Orbita);
        break;
    default:
        break;
    }
    NaveABase(Seleccion,"Base_Datos.csv");
}

//Funciones para base de datos

void Principal::NaveABase (int Seleccion, string file_name){
    //Abrir la base de datos
    BaseDatos.open(file_name,ios::out | ios::app);
    //Llenar la informacion de la fila en funcion del tipo de nave seleccionada
    switch (Seleccion)
    {
    case 1:
        BaseDatos<<"Sonda"<<","<<SondaGenerica.getNombre()<<","<<SondaGenerica.getAgencia()<<","
        <<SondaGenerica.getFuncion()<<","<<SondaGenerica.getCombustible()<<","
        <<SondaGenerica.getpeso()<<","<<SondaGenerica.getMaxvel()<<","<<SondaGenerica.getEmpuje()<<","
        <<SondaGenerica.getDestino()<<","<<"***"<<","<<"***"<<","<<"***"<<","<<"***"<<","<<"***"<<";\n";
        break;
    case 2:
        BaseDatos<<"Cohete"<<","<<CoheteGenerico.getNombre()<<","<<CoheteGenerico.getAgencia()<<","
        <<CoheteGenerico.getFuncion()<<","<<CoheteGenerico.getCombustible()<<","
        <<CoheteGenerico.getpeso()<<","<<CoheteGenerico.getMaxvel()<<","<<CoheteGenerico.getEmpuje()<<","
        <<"***"<<","<<CoheteGenerico.getTamano()<<","<<CoheteGenerico.getCargaMaxima()<<","
        <<CoheteGenerico.getPotencia()<<","<<"***"<<","<<"***"<<";\n";
        break;
    case 3:
        BaseDatos<<"Estacion Espacial"<<","<<EEGenerica.getNombre()<<","<<EEGenerica.getAgencia()<<","
        <<EEGenerica.getFuncion()<<","<<EEGenerica.getCombustible()<<","
        <<EEGenerica.getpeso()<<","<<EEGenerica.getMaxvel()<<","
        <<EEGenerica.getEmpuje()<<","<<"***"<<","<<"***"<<","<<"***"<<","
        <<"***"<<","<<EEGenerica.getCapacidad()<<","<<EEGenerica.getDistancia_Orbita()<<";\n";
        break;
    default:
        break;
    }
    //Cerrar la base de datos
    BaseDatos.close();
}

void Principal::MonstarBaseDatos(){
    string line;
    std::array <string,14> Caracteristicas;
    BaseDatos.open("Base_Datos.csv", ios::in);
    while(getline(BaseDatos,line)){
        Caracteristicas = ExtraccionCaracteristicas(line);
        for(int i=0;i<14;i++){
            cout<<Caracteristicas[i]<<" ";
        }
        cout<<endl;
    }
    BaseDatos.close();
}

void Principal::BorrarBaseDatos(){
    BaseDatos.open("Base_Datos.csv", ios::out);
    BaseDatos<<"Tipo,Nombre,Agencia,Funcion,Combustible,Peso,VelocidadMaxima,Empuje,Destino,Tamano,CargaMaxima,Potencia,Capacidad,DistanciaOrbita;\n";
    BaseDatos.close();
}

std::array<string,14> Principal::ExtraccionCaracteristicas(string line){
    std::string Delimitador =",",Caracteristica,Copia_line=line;
    std::array<string,14> Caracteristicas={{}};
    //https://cplusplus.com/reference/string/string/find/
    size_t IndexDelimitador = Copia_line.find(Delimitador),IndexDelimitadorPrevio=0;
    int IndexCaracteristica=0;
    while(IndexDelimitador != std::string::npos){
        IndexDelimitador = Copia_line.find(Delimitador);
        Caracteristica = Copia_line.substr(0,IndexDelimitador);
        Caracteristicas[IndexCaracteristica]=Caracteristica;
        IndexDelimitadorPrevio=IndexDelimitador;   
        Copia_line=Copia_line.substr(IndexDelimitadorPrevio+1,string::npos);
        IndexCaracteristica++;
    }
    return Caracteristicas;
}

void Principal::Busqueda_Por_Nombre(string Nombre){
    string line;
    std::array <string,14> Caracteristicas;
    BaseDatos.open("Base_Datos.csv", ios::in);
    while(getline(BaseDatos,line)){
        Caracteristicas = ExtraccionCaracteristicas(line);
        if(Nombre==Caracteristicas[1]){
            for(int i=0;i<14;i++){
                cout<<Caracteristicas[i]<<" ";
            }
            cout<<endl;
        }
    }
    BaseDatos.close();
}

void Principal::Filtro_Por_Tipo(int tipo){
    string line;
    string Tipo=(tipo==1)?"Sonda":(tipo==2)?"Cohete":"Estacion espacial";
    std::array <string,14> Caracteristicas;
    BaseDatos.open("Base_Datos.csv", ios::in);
    while(getline(BaseDatos,line)){
        Caracteristicas = ExtraccionCaracteristicas(line);
        if(Tipo==Caracteristicas[0]){
            for(int i=0;i<14;i++){
                cout<<Caracteristicas[i]<<" ";
            }
            cout<<endl;
        }
    }
    BaseDatos.close();
}

Sonda Principal::getSonda(){return SondaGenerica;}

Cohete Principal::getCohete(){return CoheteGenerico;}

EstacionEspacial Principal::getEstacionEspacial(){return EEGenerica;}