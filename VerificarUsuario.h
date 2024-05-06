#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

struct User {
    string cod;
    string contra;
    string nombre;
};

bool verificar(const string& cod_ingresado, const string& contra_ingresado, const vector<User>& users) {
    for (int i = 0; i < users.size(); ++i) {
        if (users[i].cod == cod_ingresado && users[i].contra == contra_ingresado) {
            return true;
        }
    }
    return false;
}

void guardardatos(const vector<User>& users){
    ofstream archivoSalida("datos.txt");
    
    for (int i = 0; i < users.size(); ++i) {
    	archivoSalida << users[i].cod << " " << users[i].contra << "" << users[i].nombre << endl;
    }
    
    archivoSalida.close();
}

bool verificarnuevo(const string& cod_ingresado, const vector<User>& users){
    for (int i = 0; i < users.size(); ++i) {
        if (users[i].cod == cod_ingresado) {
        	if (users[i].contra == "ODNCXASODXASLO15533"){
        		return true;
			}
        }
    }
    return false;
}

bool vericarmatricula(const string& cod_ingresado, const vector<User>& users){
    for (int i = 0; i < users.size(); ++i) {
        if (users[i].cod == cod_ingresado) {
            return true;
        }
    }
    return false;
}

void escribir(string n){
	int lenght=n.length();
	
	cout<<"\n\n\n\t\t+-----------------------";
	for(int i=0; i<lenght; i++){
		cout<<"-";
	}
	cout<<"+"<<endl;
	
	cout<<"\t\t| Bienvenido al sistema"<<n<<" |"<<endl;
	
	cout<<"\t\t+-----------------------";
	for(int i=0; i<lenght; i++){
		cout<<"-";
	}
	cout<<"+"<<endl;
	cout<<"\t\tDale ENTER para continuar"<<endl;
}


int VerificarUsuario(string cod_ingresado, string contra_ingresado) {
	vector<User> users;

    ifstream archivo("datos.txt");

    string line;
    while (getline(archivo, line)) {
        istringstream iss(line);
        User u;
        iss >> u.cod >> u.contra;

        getline(iss, u.nombre);

        users.push_back(u);
    }
    archivo.close();
    

    int aux;
    int aux2=1;
    bool ingresa = false;

	
    if (verificar(cod_ingresado, contra_ingresado, users)) {
    	for (int i = 0; i < users.size(); ++i){
			if (users[i].cod == cod_ingresado) {
			    aux = i;
			}
		}
		
		escribir(users[aux].nombre);
		
        aux2=1;
        ingresa = true;
    } else {
    	if (verificarnuevo(cod_ingresado, users)){
    		for (int i = 0; i < users.size(); ++i){
			    if (users[i].cod == cod_ingresado) {
			            aux = i;
			    }
			}
			
			users[aux].contra = contra_ingresado;
			
			guardardatos(users);
			
			cout <<"\n\tCUENTA CREADA";
			aux2=1;
			
			ingresa = true;
		}else{
			if (vericarmatricula(cod_ingresado, users)){
				cout << "\n\tCREDENCIALES INCORRECTAS" << endl;
				aux2=0;
				
			}
			else{
				cout << "\n\tNO ESTA MATRICULADO" << endl;
				aux2=0;
				
			}
		}
    }

    return aux2;
}
