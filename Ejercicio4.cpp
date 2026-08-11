#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CuentaBancaria {
private:
    int numeroCuenta;
    string titular;
    double saldo;

public:
    
    CuentaBancaria(int _numeroCuenta, string _titular, double _saldo) {
        numeroCuenta = _numeroCuenta;
        titular = _titular;
        saldo = _saldo;
    }

    // Getters
    int getNumeroCuenta() const { return numeroCuenta; }
    string getTitular() const { return titular; }
    double getSaldo() const { return saldo; }

    // Método para depositar
    void depositar(double monto) {
        if (monto > 0) {
            saldo += monto;
            cout << "Deposito realizado con exito. Nuevo saldo: $" << saldo << endl;
        } else {
            cout << "El monto a depositar debe ser mayor a cero." << endl;
        }
    }

    
    void retirar(double monto) {
        if (monto <= 0) {
            cout << "El monto a retirar debe ser mayor a cero." << endl;
        } else if (monto > saldo) {
            cout << "Fondos insuficientes. Saldo actual: $" << saldo << endl;
        } else {
            saldo -= monto;
            cout << "Retiro realizado con exito. Nuevo saldo: $" << saldo << endl;
        }
    }

    
    void mostrarInformacion() const {
        cout << "Nro Cuenta: " << numeroCuenta 
             << "Titular: " << titular 
             << "Saldo: $" << saldo << endl;
    }
};

int main() {
    vector<CuentaBancaria> cuentas;
    int cantidad;

    cout << "Ingrese la cantidad de cuentas bancarias a registrar: ";
    cin >> cantidad;

    
    for (int i = 0; i < cantidad; i++) {
        int num;
        string nom;
        double sal;

        cout << "\n--- Cuenta " << i + 1 << " ---" << endl;
        cout << "Ingrese numero de cuenta: ";
        cin >> num;
        cin.ignore(); 
        cout << "Ingrese nombre del titular: ";
        getline(cin, nom);
        cout << "Ingrese saldo inicial: ";
        cin >> sal;

        cuentas.push_back(CuentaBancaria(num, nom, sal));
    }

    cout<<"Todas las cuentas"
    for (size_t i = 0; i < cuentas.size(); i++) {
        cuentas[i].mostrarInformacion();
    }


    int opcion;
    do {
        
        cout << "1. Realizar Deposito" << endl;
        cout << "2. Realizar Retiro" << endl;
        cout << "3. Mostrar Estado de las Cuentas" << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        if (opcion == 1 || opcion == 2) {
            int numBuscado;
            cout << "Ingrese el numero de cuenta para operar: ";
            cin >> numBuscado;

            
            int indiceEncontrado = -1;
            for (size_t i = 0; i < cuentas.size(); i++) {
                if (cuentas[i].getNumeroCuenta() == numBuscado) {
                    indiceEncontrado = i;
                    break;
                }
            }

            if (indiceEncontrado != -1) {
                double monto;
                if (opcion == 1) {
                    cout << "Ingrese monto a depositar: ";
                    cin >> monto;
                    cuentas[indiceEncontrado].depositar(monto);
                } else {
                    cout << "Ingrese monto a retirar: ";
                    cin >> monto;
                    cuentas[indiceEncontrado].retirar(monto);
                }
            } else {
                cout << "Error: No se encontro ninguna cuenta con ese numero." << endl;
            }

        } else if (opcion == 3) {
            cout << "Cuentas:" << endl;
            for (size_t i = 0; i < cuentas.size(); i++) {
                cuentas[i].mostrarInformacion();
            }
        }

    } while (opcion != 0);

    cout << "\nPrograma finalizado." << endl;
    return 0;
}
