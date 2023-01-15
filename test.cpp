//#include "Nave.cpp"
#include "Principal.cpp"


void printSonda(Sonda SondaGenerica){
    std::cout<<"Los parametros de la Cassini son: "<<endl;
    std::cout<<"Nombre: "<<SondaGenerica.getNombre()<<endl;
    std::cout<<"Funcion: "<<SondaGenerica.getFuncion()<<endl;
    std::cout<<"Combustible: "<<SondaGenerica.getCombustible()<<endl;
    std::cout<<"Peso: "<<SondaGenerica.getpeso()<<endl;
    std::cout<<"Velocidad Maxima: "<<SondaGenerica.getMaxvel()<<endl;
    std::cout<<"Empuje: "<<SondaGenerica.getEmpuje()<<endl;
    std::cout<<"Destino: "<<SondaGenerica.getDestino()<<endl;
    std::cout<<"\n\n\n\n\n\n\n";
}

void printCohete(Cohete CoheteGenerico){
    std::cout<<"Los parametros de la MARS son: "<<endl;
    std::cout<<"Nombre: "<<CoheteGenerico.getNombre()<<endl;
    std::cout<<"Funcion: "<<CoheteGenerico.getFuncion()<<endl;
    std::cout<<"Combustible: "<<CoheteGenerico.getCombustible()<<endl;
    std::cout<<"Peso: "<<CoheteGenerico.getpeso()<<endl;
    std::cout<<"Velocidad Maxima: "<<CoheteGenerico.getMaxvel()<<endl;
    std::cout<<"Empuje: "<<CoheteGenerico.getEmpuje()<<endl;
    std::cout<<"Carga Maxima: "<<CoheteGenerico.getCargaMaxima()<<endl;
    std::cout<<"Potencia: "<<CoheteGenerico.getPotencia()<<endl;
    std::cout<<"Tamano: "<<CoheteGenerico.getTamano()<<endl;
    std::cout<<"\n\n\n\n\n\n\n";

}

void printEstacionEspacial(EstacionEspacial EEGenerica){
    std::cout<<"Los parametros de la EE son: "<<endl;
    std::cout<<"Nombre: "<<EEGenerica.getNombre()<<endl;
    std::cout<<"Funcion: "<<EEGenerica.getFuncion()<<endl;
    std::cout<<"Combustible: "<<EEGenerica.getCombustible()<<endl;
    std::cout<<"Peso: "<<EEGenerica.getpeso()<<endl;
    std::cout<<"Velocidad Maxima: "<<EEGenerica.getMaxvel()<<endl;
    std::cout<<"Empuje: "<<EEGenerica.getEmpuje()<<endl;
    std::cout<<"Capacidad: "<<EEGenerica.getCapacidad()<<endl;
    std::cout<<"Distancia de orbita: "<<EEGenerica.getDistancia_Orbita()<<endl;
    std::cout<<"\n\n\n\n\n\n\n";
}

int main(){
    //Prueba Constructores por default
    /*Nave NaveGenerica;
    Sonda Cassini;
    EstacionEspacial EEI;
    Cohete Mars;
    
    //Pruebas Sonda
    Cassini.setNombre("Cassini");
    Cassini.setFuncion("Explorar Saturno y sus Lunas");
    Cassini.setCombustible("H20");
    Cassini.setpeso(58);
    Cassini.setvelocidad(75);
    Cassini.setEmpuje(80);
    Cassini.setDestino("Saturno");

    //Pruebas Cohete
    Mars.setNombre("Mars");
    Mars.setFuncion("Volar siempre arriba");
    Mars.setCombustible("Anabolicos");
    Mars.setpeso(456);
    Mars.setvelocidad(654);
    Mars.setEmpuje(1000);
    Mars.setCargaMaxima(5789);
    Mars.setPotencia(6325);
    Mars.setTamano(2754);

    //Pruebas Estacion Espacial
    EEI.setNombre("EEI");
    EEI.setFuncion("Experimentos");
    EEI.setCombustible("Azufre");
    EEI.setpeso(2);
    EEI.setvelocidad(3);
    EEI.setEmpuje(5);
    EEI.setCapacidad(9);
    EEI.setDistancia_Orbita(123);*/

    //Prueba Principal
    Principal NaveGenerica;
    bool Continuar = true;
    int Seleccion;
    //fstream BaseDeDatos;
    while(Continuar){
        cout<<"0.Salir\n1.Sonda\n2.Cohete\n3.Estacion Espacial\n4.Buscar una nave especifica\n5.Filtrar Naves por tipo"<<endl;
        cin>>Seleccion;
        switch (Seleccion)
        {
        case 0:
            Continuar = false;
            break;
        case 1:
            NaveGenerica.Selector(Seleccion);
            printSonda(NaveGenerica.getSonda());
            NaveGenerica.MonstarBaseDatos();
            break;
        case 2:
            NaveGenerica.Selector(Seleccion);
            printCohete(NaveGenerica.getCohete());
            NaveGenerica.MonstarBaseDatos();
            break;
        case 3:
            NaveGenerica.Selector(Seleccion);
            printEstacionEspacial(NaveGenerica.getEstacionEspacial());
            NaveGenerica.MonstarBaseDatos();
            break;
        case 4:
            cout<<"\n\n\n\n";
            NaveGenerica.Busqueda_Por_Nombre("cas");
            cout<<"\n\n\n\n";
            break;
        case 5:
            cout<<"\n\n\n\n";
            NaveGenerica.Filtro_Por_Tipo(1);
            cout<<"\n\n\n\n";
            break;
        default:
            break;
        }
    }

    system("pause");
    return 0;
}