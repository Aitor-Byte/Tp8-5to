#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Empleado {
private:
    string nombre;
    double salario;
    string departamento;

public:
    
    Empleado(string _nombre, double _salario, string _departamento) {
        nombre = _nombre;
        salario = _salario;
        departamento = _departamento;
    }

    
    string getNombre() const { return nombre; }
    double getSalario() const { return salario; }
    string getDepartamento() const { return departamento; }

    
    void mostrarInformacion() const {
        cout << "Nombre: " << nombre 
             << " | Salario: $" << salario 
             << " | Departamento: " << departamento << endl;
    }
    
    
};

bool compararSalarioMayorAMenor(const Empleado& e1, const Empleado& e2) {
    return e1.getSalario() > e2.getSalario();
}

int main() {
    vector<Empleado> empleados;
    int cantidad;

    cout << "Ingrese la cantidad de empleados a registrar: ";
    cin >> cantidad;

    
    for (int i = 0; i < cantidad; i++) {
        string nom, dep;
        double sal;

        cout << "\n--- Empleado " << i + 1 << " ---" << endl;
        cout << "Ingrese nombre: ";
        cin.ignore(); 
        getline(cin, nom);
        cout << "Ingrese salario: $";
        cin >> sal;
        cout << "Ingrese departamento: ";
        cin.ignore();
        getline(cin, dep);

        empleados.push_back(Empleado(nom, sal, dep));
    }

    sort(empleados.begin(), empleados.end(), compararSalarioMayorAMenor);

    cout<<"Empleados: ";

    for (int i = 0; i < empleados.size(); i++) {
        empleados[i].mostrarInformacion();
    }

    return 0;
}
