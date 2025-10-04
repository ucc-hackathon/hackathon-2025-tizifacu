#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// -------------------------
// Clase Equipo
// -------------------------
class Equipo {
private:
    string nombre;
    int puntos;

public:
    Equipo(string n) {
        nombre = n;
        puntos = 0;
    }

    string getNombre() const { return nombre; }
    int getPuntos() const { return puntos; }

    void sumarPuntos(int p) { puntos += p; }
};

// -------------------------
// Clase Partido
// -------------------------
class Partido {
private:
    Equipo equipo1;
    Equipo equipo2;
    int golesEquipo1;
    int golesEquipo2;

public:
    Partido(Equipo eq1, Equipo eq2, int g1, int g2)
        : equipo1(eq1), equipo2(eq2), golesEquipo1(g1), golesEquipo2(g2) {}

    Equipo getEquipo1() const { return equipo1; }
    Equipo getEquipo2() const { return equipo2; }
    int getGolesEquipo1() const { return golesEquipo1; }
    int getGolesEquipo2() const { return golesEquipo2; }

    int totalGoles() const { return golesEquipo1 + golesEquipo2; }
};

// -------------------------
// Programa principal
// -------------------------
int main() {
    // Creamos los equipos
    vector<Equipo> equipos = {
        Equipo("UCC"),
        Equipo("UNC"),
        Equipo("UTN"),
        Equipo("UNRC"),
        Equipo("UBP"),
        Equipo("UES21")
    };

    // Lista de partidos (15 en total)
    vector<Partido> partidos = {
        Partido(equipos[3], equipos[4], 0, 0),
        Partido(equipos[0], equipos[3], 2, 2),
        Partido(equipos[2], equipos[4], 3, 1),
        Partido(equipos[1], equipos[5], 3, 1),
        Partido(equipos[4], equipos[5], 2, 1),
        Partido(equipos[1], equipos[3], 2, 2),
        Partido(equipos[0], equipos[4], 0, 0),
        Partido(equipos[1], equipos[2], 0, 1),
        Partido(equipos[2], equipos[3], 0, 0),
        Partido(equipos[0], equipos[1], 2, 1),
        Partido(equipos[0], equipos[5], 2, 2),
        Partido(equipos[1], equipos[4], 1, 3),
        Partido(equipos[2], equipos[5], 1, 0),
        Partido(equipos[3], equipos[5], 2, 3)
    };

    // -------------------------
    // Mostrar partidos ordenados por total de goles
    // -------------------------
    sort(partidos.begin(), partidos.end(), [](Partido a, Partido b) {
        return a.totalGoles() > b.totalGoles(); // de mayor a menor
    });

    cout << "=== PARTIDOS ORDENADOS POR TOTAL DE GOLES ===\n";
    for (auto &p : partidos) {
        cout << p.getEquipo1().getNombre() << " " << p.getGolesEquipo1()
             << " - " << p.getGolesEquipo2() << " " << p.getEquipo2().getNombre()
             << " (Total: " << p.totalGoles() << " goles)" << endl;
    }

    // -------------------------
    // Calcular puntos por equipo
    // -------------------------
    for (auto &p : partidos) {
        string e1 = p.getEquipo1().getNombre();
        string e2 = p.getEquipo2().getNombre();
        int g1 = p.getGolesEquipo1();
        int g2 = p.getGolesEquipo2();

        // Buscar los equipos en el vector principal
        for (auto &eq : equipos) {
            if (eq.getNombre() == e1) {
                if (g1 > g2) eq.sumarPuntos(3);
                else if (g1 == g2) eq.sumarPuntos(1);
            }
            if (eq.getNombre() == e2) {
                if (g2 > g1) eq.sumarPuntos(3);
                else if (g2 == g1) eq.sumarPuntos(1);
            }
        }
    }

    // -------------------------
    // Ordenar equipos por puntos
    // -------------------------
    sort(equipos.begin(), equipos.end(), [](Equipo a, Equipo b) {
        return a.getPuntos() > b.getPuntos();
    });

    cout << "\n=== TABLA FINAL DEL TORNEO ===\n";
    for (auto &e : equipos) {
        cout << e.getNombre() << " - " << e.getPuntos() << " puntos\n";
    }

    cout << "\n Ganadores \n";
    cout << "1° " << equipos[0].getNombre() << endl;
    cout << "2° " << equipos[1].getNombre() << endl;
    cout << "3° " << equipos[2].getNombre() << endl;

    return 0;
}

