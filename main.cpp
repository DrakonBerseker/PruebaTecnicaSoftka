#include "Principal.cpp"
#include <conio.h>

int main(){
    bool continuar=true;
    Principal NaveGenerica;
    string Nombre_Nave;
    int opcion,seleccionTipo;
    while(continuar){
        std::cout<<"¿Que desea hacer?\n1.Agregar una nave a la base de datos\n2.Visualizar la base de datos completa\n3.Filtrar las naves\n4.Buscar una nave en especifico\n5.Borrar la base de datos\n0.Salir"<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 0:
            cout<<"Ha decidido salir"<<endl;
            continuar = false;
            break;
        case 1:
            cout<<"Ha elegido agregar una nueva nave a la base de datos.\n\n¿Que tipo de nave desea agregar?\n\n1.Sonda\n2.Cohete\n3.Estacion Espacial"<<endl;cin>>seleccionTipo;
            if(seleccionTipo==0){
                break;
            }
            NaveGenerica.Selector(seleccionTipo);
            cout<<"\n\n\n\n\n\n\n";
            break;
        case 2:
            cout<<"Ha decidido visualizar toda la base de datos"<<endl;
            NaveGenerica.MonstarBaseDatos();
            cout<<"\n\n\n\n\n\n\n";
            break;
        case 3:
            cout<<"Ha decidido filtrar las naves por tipo\n¿Que tipo de nave desea fitrar?\n1.Sonda\n2.Cohete\n3.Estacion Espacial"<<endl;cin>>seleccionTipo;
            NaveGenerica.Filtro_Por_Tipo(seleccionTipo);
            break;
        case 4:
            cout<<"Ha decidido buscar una nave en especifico\nIntroduzca el nombre de la nave: "<<endl;cin>>Nombre_Nave;
            NaveGenerica.Busqueda_Por_Nombre(Nombre_Nave);
            cout<<"\n\n\n\n\n\n\n";
            break;
        case 5:
            cout<<"Ha decidido borrar las naves de la base de datos"<<endl;
            NaveGenerica.BorrarBaseDatos();
            cout<<"\n\n\n\n\n\n\n";
            break;
        default:
            break;
        }       
    }
    
    return 0;
}