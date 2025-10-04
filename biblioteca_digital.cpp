#include <iostream>
#include <vector>
#include <string>
using namespace std;


// Clase LIBRO

class Libro {
private:
    string codigo;
    string titulo;
    string autor;
    int anio;
    string categoria;
    bool prestado;

public:
    Libro(string c, string t, string a, int an, string cat) {
        codigo = c;
        titulo = t;
        autor = a;
        anio = an;
        categoria = cat;
        prestado = false;
    }

    string getCodigo() { return codigo; }
    string getTitulo() { return titulo; }
    string getAutor() { return autor; }
    string getCategoria() { return categoria; }
    bool estaPrestado() { return prestado; }

    void prestar() { prestado = true; }
    void devolver() { prestado = false; }

    void mostrarInfo() {
        cout << "Codigo: " << codigo << " | Titulo: " << titulo
             << " | Autor: " << autor << " | Año: " << anio
             << " | Categoria: " << categoria
             << " | Estado: " << (prestado ? "Prestado" : "Disponible") << endl;
    }
};


// Clase USUARIO

class Usuario {
protected:
    string nombre;
    int legajo;

public:
    Usuario(string n, int l) {
        nombre = n;
        legajo = l;
    }

    virtual void mostrarInfo() {
        cout << "Nombre: " << nombre << " | Legajo: " << legajo << endl;
    }

    string getNombre() { return nombre; }
};

// Subclase ALUMNO
class Alumno : public Usuario {
private:
    int anio;

public:
    Alumno(string n, int l, int a) : Usuario(n, l) {
        anio = a;
    }

    void mostrarInfo() override {
        cout << "Alumno - Nombre: " << nombre << " | Legajo: " << legajo
             << " | Año: " << anio << endl;
    }
};

// Subclase PROFESOR
class Profesor : public Usuario {
private:
    string especialidad;

public:
    Profesor(string n, int l, string e) : Usuario(n, l) {
        especialidad = e;
    }

    void mostrarInfo() override {
        cout << "Profesor - Nombre: " << nombre << " | Legajo: " << legajo
             << " | Especialidad: " << especialidad << endl;
    }
};


// Clase BIBLIOTECA

class Biblioteca {
private:
    vector<Libro> libros;

public:
    void agregarLibro(Libro libro) {
        libros.push_back(libro);
    }

    void listarLibros() {
        cout << "\n--- Lista de Libros ---\n";
        for (auto &libro : libros) {
            libro.mostrarInfo();
        }
    }

    void prestarLibro(string codigo) {
        for (auto &libro : libros) {
            if (libro.getCodigo() == codigo) {
                if (!libro.estaPrestado()) {
                    libro.prestar();
                    cout << " Libro prestado con exito.\n";
                } else {
                    cout << " El libro ya está prestado.\n";
                }
                return;
            }
        }
        cout << " No se encontró el libro.\n";
    }

    void devolverLibro(string codigo) {
        for (auto &libro : libros) {
            if (libro.getCodigo() == codigo) {
                if (libro.estaPrestado()) {
                    libro.devolver();
                    cout << " Libro devuelto con exito.\n";
                } else {
                    cout << " El libro no estaba prestado.\n";
                }
                return;
            }
        }
        cout << " No se encontró el libro.\n";
    }
};


// PROGRAMA PRINCIPAL (main)

int main() {
    Biblioteca biblioteca;
    int opcion;

    // Agregamos algunos libros de ejemplo
    biblioteca.agregarLibro(Libro("001", "C++ Basico", "Bjarne Stroustrup", 1985, "Programacion"));
    biblioteca.agregarLibro(Libro("002", "Fisica I", "Isaac Newton", 1687, "Fisica"));
    biblioteca.agregarLibro(Libro("003", "Matematicas Avanzadas", "Euler", 1750, "Matematicas"));

    do {
        cout << "\n=== MENU BIBLIOTECA DIGITAL ===\n";
        cout << "1. Listar libros\n";
        cout << "2. Prestar libro\n";
        cout << "3. Devolver libro\n";
        cout << "0. Salir\n";
        cout << "Elija una opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            biblioteca.listarLibros();
        } else if (opcion == 2) {
            string codigo;
            cout << "Ingrese el codigo del libro: ";
            cin >> codigo;
            biblioteca.prestarLibro(codigo);
        } else if (opcion == 3) {
            string codigo;
            cout << "Ingrese el codigo del libro: ";
            cin >> codigo;
            biblioteca.devolverLibro(codigo);
        } else if (opcion == 0) {
            cout << "Saliendo del sistema...\n";
        } else {
            cout << "Opcion invalida.\n";
        }
    } while (opcion != 0);

    return 0;
}
