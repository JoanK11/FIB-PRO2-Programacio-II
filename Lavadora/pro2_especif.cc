/**
 * @mainpage Ejemplo de diseño modular:  Gestión de una lavadora.
 
En este ejemplo se construye un programa modular que ofrece un menú de opciones para gestionar una lavadora. Se introducen las clases <em>Lavadora</em>, <em>Cubeta</em> y <em>Prenda</em>.

Sólo se documentan elementos públicos. En una próxima sesión se verá un ejemplo
de proyecto completamente documentado, incluyendo los elementos privados.
*/

/** @file pro2_s8.cc
    @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/

// para que el diagrama modular quede bien se han escrito includes redundantes;
// en los ficheros .hh de la documentación de las clases ocurre lo mismo.
#include "Prenda.hh"
#include "Lavadora.hh"
#include "Cubeta.hh"
#ifndef NO_DIAGRAM // explicado en Prenda.hh
#include "readbool.hh"
#endif

/** @brief Programa principal para el ejercicio <em>Gestión de una lavadora</em>.
*/

int main ()
{
    // Inicialitcem els parametres
    Lavadora lav;
    Cubeta cub;
    
    int op;
    cin >> op;
    while (op != -8) {
        if (op == -1) {
            int pes;
            cin >> pes;
            bool color = readbool();
            if (pes > 0 and not lav.esta_inicializada()) lav.inicializar(pes, color);
        }
        
        else if (op == -2) {
            int pes;
            cin >> pes;
            bool color = readbool();
            Prenda pren(pes, color);
            if (lav.esta_inicializada() and color == lav.consultar_color() 
                and pes + lav.consultar_peso() <= lav.consultar_peso_maximo()) lav.anadir_prenda(pren);
        }
        
        else if (op == -3) {
            int pes;
            cin >> pes;
            bool color = readbool();
            Prenda pren(pes, color);
            cub.anadir_prenda(pren);
        }
        
        else if (op == -4) {
            if (lav.esta_inicializada()) cub.completar_lavadora(lav);
        }
        
        else if (op == -5) {
            if (lav.esta_inicializada()) lav.lavado();
        }
        
        else if (op == -6) {
            cout << "   Cubeta: " << endl;
            cub.escribir();
        }
        
        else if (op == -7) {
            cout << "   Lavadora: " << endl;
            if (lav.esta_inicializada()) lav.escribir();
            else cout << "Lavadora no inicializada" << endl << endl;
        }
        
        cin >> op;
    }
}
