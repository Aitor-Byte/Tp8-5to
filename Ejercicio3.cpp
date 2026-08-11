#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class rectangulo{
	private:
		double base;
		double altura;
	public:
		rectangulo(int _base, int _altura){
			base=_base;
			altura=_altura;
		}
		
	double calcularArea() const{
	return base*altura;
	}
	double calcularPerimetro() const{
	return 2*(base + altura);
	}
	
	double getBase() const { return base; }
    double getAltura() const { return altura; }
};

int main() {
    vector<rectangulo> rectangulos;
    int cantidad;

    cout << "Ingrese la cantidad de rectangulos: ";
    cin >> cantidad;

    
    for (int i = 0; i < cantidad; i++) {
        double b, h;
        cout << "Rectangulo " << i + 1 << endl;
        cout << "Ingrese la base: ";
        cin >> b;
        cout << "Ingrese la altura: ";
        cin >> h;

        
        rectangulos.push_back(rectangulo(b, h));
    }

    cout<<"Resultados: " <<endl;

    for (size_t i = 0; i < rectangulos.size(); i++) {
        cout << "Rectangulo " << i + 1 << ":" << endl;
        cout << "  Base: " << rectangulos[i].getBase() << endl;
        cout << "  Altura: " << rectangulos[i].getAltura() << endl;
        cout << "  Area: " << rectangulos[i].calcularArea() << endl;
        cout << "  Perimetro: " << rectangulos[i].calcularPerimetro() << endl;
    }

    return 0;
}
