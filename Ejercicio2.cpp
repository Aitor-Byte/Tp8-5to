#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Persona{
	private: 
	string nombre;
	int edad; 
	
	public:
	Persona (string _nombre, int _edad){
		nombre = _nombre;
		edad = _edad;
	}
	
	int getEdad() const{
	return edad;
	} 
	
	string getNombre() const{
	return nombre;
	}
};

bool compararEdad(const Persona& p1, const Persona& p2){
	return p1.getEdad() < p2.getEdad();
}

int main(){
	vector<Persona> lista;
	lista.push_back(Persona("Juan", 25));
	lista.push_back(Persona("Maria", 18));
    lista.push_back(Persona("Lucas", 30));
    lista.push_back(Persona("Sofia", 15));

    
    sort(lista.begin(), lista.end(), compararEdad);

    
    cout << "--- Listado ordenado por edad ---" << endl;
    for (size_t i = 0; i < lista.size(); i++) {
        cout << "Nombre: " << lista[i].getNombre() 
             << " | Edad: " << lista[i].getEdad() << endl;
    }

    return 0;
	
}



