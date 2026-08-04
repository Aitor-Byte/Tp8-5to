#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Alumno {
	private: 
	string nombre;
	double nota1;
	double nota2;
	double nota3;
	
	public:
		Alumno(string _nombre, float _nota1, float _nota2, float _nota3){
			nombre = _nombre;
			nota1 = _nota1;
			nota2 = _nota2;
			nota3 = _nota3;
		}
		
		void mostrarDatos() const{
		cout << "Nombre: " << nombre << endl;
		cout << "Nota 1: " << nota1 << endl;
		cout << "Nota 2: " << nota2 << endl;
		cout << "Nota 3: " << nota3 << endl;
		}
};

int main(){
	vector<Alumno> listaAlumnos; 
    
    char continuar;
    string nombreTemp;
    float n1, n2, n3;

    cout << "--- Sistema de Registro de Alumnos ---" << endl;

    
    do {
        cout << "\nIngrese el nombre del alumno: ";
        
        getline(cin >> ws, nombreTemp); 

        cout << "Ingrese la nota 1: ";
        cin >> n1;
        cout << "Ingrese la nota 2: ";
        cin >> n2;
        cout << "Ingrese la nota 3: ";
        cin >> n3;

        
        Alumno nuevoAlumno(nombreTemp, n1, n2, n3);

        
        listaAlumnos.push_back(nuevoAlumno);

        
        cout << "\n¿Desea ingresar otro alumno? (s/n): ";
        cin >> continuar;

    } while (continuar == 's' || continuar == 'S');

    
    cout << "\n=== DATOS DE TODOS LOS ALUMNOS ===" << endl;
    
    
    for (size_t i = 0; i < listaAlumnos.size(); i++) {
        cout << "Alumno #" << (i + 1) << ":" << endl;
        listaAlumnos[i].mostrarDatos(); 
    }

    return 0;
}
