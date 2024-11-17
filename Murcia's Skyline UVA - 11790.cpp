#include <bits/stdc++.h>

#define todos(x) x.begin(), x.end()
#define llenar(a, v) memset(a, v, sizeof a)
using namespace std;

typedef long long Long;
typedef vector<int> vi;

const int MAX = 1e5 + 7;
int alturas[MAX], pesos[MAX];
int memLIS[MAX], memLDS[MAX];

// Función recursiva con memoización para LIS
int LIS(int i) {
    if (memLIS[i] != -1) return memLIS[i]; // Si ya se calculó, devolver el valor almacenado
    int mejor = pesos[i]; // Base: la suma incluye al menos el peso actual
    for (int j = 0; j < i; ++j) {
        if (alturas[j] < alturas[i]) { // Subsecuencia creciente
            mejor = max(mejor, LIS(j) + pesos[i]);
        }
    }
    return memLIS[i] = mejor;
}

// Función recursiva con memoización para LDS
int LDS(int i) {
    if (memLDS[i] != -1) return memLDS[i]; // Si ya se calculó, devolver el valor almacenado
    int mejor = pesos[i]; // Base: la suma incluye al menos el peso actual
    for (int j = 0; j < i; ++j) {
        if (alturas[j] > alturas[i]) { // Subsecuencia decreciente
            mejor = max(mejor, LDS(j) + pesos[i]);
        }
    }
    return memLDS[i] = mejor;
}

int main() {
    int pruebas;
    cin >> pruebas;
    for (int caso = 1; caso <= pruebas; ++caso) {
        int numCasos;
        cin >> numCasos;
        
        for (int i = 0; i < numCasos; ++i) cin >> alturas[i];
        for (int i = 0; i < numCasos; ++i) cin >> pesos[i];
        
        llenar(memLIS, -1); // Inicializamos la memoización para LIS
        llenar(memLDS, -1); // Inicializamos la memoización para LDS

        int creciente = 0, decreciente = 0;
        for (int i = 0; i < numCasos; ++i) {
            creciente = max(creciente, LIS(i));
            decreciente = max(decreciente, LDS(i));
        }

        if (creciente >= decreciente)
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", caso, creciente, decreciente);
        else
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", caso, decreciente, creciente);
    }
    return 0;
}
