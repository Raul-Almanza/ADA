#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

static const int MAXIMO_VALOR = 300;

typedef unsigned long long ull_t;
unordered_map<string, ull_t> memo; // Memorización para evitar recalcular subproblemas

// Función recursiva con memorización para contar las maneras de pagar
ull_t contarManeras(int cantidad, int maxMoneda) {
    if (cantidad == 0) return 1; // Caso base: hay una sola forma de pagar 0, no usar ninguna moneda
    if (maxMoneda == 0) return 0; // No hay formas si no tenemos monedas
    string clave = to_string(cantidad) + "," + to_string(maxMoneda); // Clave única para cada subproblema
    
    // Si el subproblema ya fue calculado, devolver el resultado memorizado
    if (memo.find(clave) != memo.end()) {
        return memo[clave];
    }
    
    // Recursión: contar las maneras de pagar la cantidad con monedas hasta maxMoneda
    ull_t resultado = contarManeras(cantidad, maxMoneda - 1) + (cantidad >= maxMoneda ? contarManeras(cantidad - maxMoneda, maxMoneda) : 0);
    
    // Memorizamos el resultado antes de devolverlo
    memo[clave] = resultado;
    return resultado;
}

int main()
{  
    string s;
    while (getline(cin, s))
    {
        vector<int> numerosEntrada;
        stringstream ss(s);
        int valor;
        while (ss >> valor)
            numerosEntrada.push_back(valor);

        int limiteInferior, limiteSuperior;
        switch(numerosEntrada.size())
        {
        case 1:
            limiteInferior = 0;
            limiteSuperior = numerosEntrada[0];
            break;
        case 2:
            limiteInferior = 0;
            limiteSuperior = numerosEntrada[1];
            break;
        default:
            limiteInferior = numerosEntrada[1];
            limiteSuperior = numerosEntrada[2];
        }
        
        // Casos especiales cuando la cantidad es 0
        if (numerosEntrada[0] == 0)
            cout << "1" << endl;
        else
            cout << contarManeras(numerosEntrada[0], min(300, limiteSuperior)) - contarManeras(numerosEntrada[0], min(300, max(0, limiteInferior - 1))) << endl;
    }
    return 0;
}
