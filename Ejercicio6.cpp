#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    int anioPublicacion;

public:
    // Constructor
    Libro(string _titulo, string _autor, int _anioPublicacion) {
        titulo = _titulo;
        autor = _autor;
        anioPublicacion = _anioPublicacion;
    }

    // Getters
    string getTitulo() const { return titulo; }
    string getAutor() const { return autor; }
    int getAnioPublicacion() const { return anioPublicacion; }

    // Método para mostrar la información del libro
    void mostrarInformacion() const {
        cout << "Titulo: " << titulo 
             << " | Autor: " << autor 
             << " | Anio: " << anioPublicacion << endl;
    }
};

int main() {
    vector<Libro> biblioteca;
    int cantidad;

    cout << "Ingrese la cantidad de libros a registrar: ";
    cin >> cantidad;

    
    for (int i = 0; i < cantidad; i++) {
        string tit, aut;
        int anio;

        cout << "Libro " << i + 1 << " ---" << endl;
        cout << "Ingrese titulo: ";
        cin.ignore(); 
        getline(cin, tit);
        cout << "Ingrese autor: ";
        getline(cin, aut);
        cout << "Ingrese año de publicacion: ";
        cin >> anio;

        biblioteca.push_back(Libro(tit, aut, anio));
    }

    
    for (int i = 0; i < biblioteca.size(); i++) {
        for (int j = 0; j < biblioteca.size() - 1; j++) {
            
            if (biblioteca[j].getAnioPublicacion() > biblioteca[j + 1].getAnioPublicacion()) {
                Libro aux = biblioteca[j];
                biblioteca[j] = biblioteca[j + 1];
                biblioteca[j + 1] = aux;
            }
        }
    }
cout<<"Libros ordenados: ";

    for (int i = 0; i < biblioteca.size(); i++) {
        biblioteca[i].mostrarInformacion();
    }

    return 0;
}
