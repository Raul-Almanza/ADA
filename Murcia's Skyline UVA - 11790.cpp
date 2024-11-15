#include <bits/stdc++.h>

#define agregar push_back
#define todos(x) x.begin(), x.end()
#define llenar(a, v) memset(a, v, sizeof a)
#define primero first
#define segundo second
#define emparejar make_pair
#define leerCaracter getchar
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long Long;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<Long> vl;
typedef pair<int, int> parEntero;
typedef pair<string, int> parStringEntero;
typedef pair<Long, Long> parLong;
typedef pair<double, double> parDouble;

#define paraDesdeHasta(i, desde, hasta) for (__typeof(hasta) i = (desde); i <= hasta; ++i)
#define repetir(i, n) paraDesdeHasta(i, 0, (n) - 1)
#define desdeUno(i, n) paraDesdeHasta(i, 1, n)
#define desdeHastaReverso(i, desde, hasta) for (__typeof(hasta)i = (hasta); i >= desde; --i)
#define repetirReverso(i, n) desdeHastaReverso(i, 0, (n) - 1)
#define desdeUnoReverso(i, n) desdeHastaReverso(i, 1, n)
#define paraCadaElemento(i, s) for (__typeof((s).end()) i = (s).begin(); i != (s).end(); ++i)

// Funciones para leer entrada
int leerInt() { int a; scanf("%d", &a); return a; }
Long leerLong() { Long a; scanf("%lld", &a); return a; }
double leerDouble() { double a; scanf("%lf", &a); return a; }

const int MAX = 1e5 + 7;
int numCasos, alturas[MAX], pesos[MAX], lis[MAX], lds[MAX];

int main() {
    int pruebas = leerInt();
    desdeUno(caso, pruebas) {
        numCasos = leerInt();
        repetir(i, numCasos) alturas[i] = leerInt();
        repetir(i, numCasos) pesos[i] = leerInt();
        repetir(i, numCasos) {
            lis[i] = lds[i] = pesos[i];
            repetir(j, i) {
                if (alturas[i] > alturas[j]) lis[i] = max(lis[i], lis[j] + pesos[i]);
                if (alturas[i] < alturas[j]) lds[i] = max(lds[i], lds[j] + pesos[i]);
            }
        }
        int creciente = 0, decreciente = 0;
        repetir(i, numCasos) {
            creciente = max(creciente, lis[i]);
            decreciente = max(decreciente, lds[i]);
        }
        if (creciente >= decreciente)
            printf("Case %d. Increasing (%d). Decreasing (%d).\n", caso, creciente, decreciente);
        else
            printf("Case %d. Decreasing (%d). Increasing (%d).\n", caso, decreciente, creciente);
    }
}