#include <bits/stdc++.h>
#define agregar push_back
#define todos(x) x.begin(), x.end()
#define inicializar(a, v) memset(a, v, sizeof a)
#define leerInt ({int a; scanf("%d", &a); a;})
#define leerLong ({Long a; scanf("%lld", &a); a;})
#define leerDouble ({double a; scanf("%lf", &a); a;})
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long Long;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef set<int> si;
typedef vector<Long> vl;
typedef pair<int, int> pii;
typedef pair<Long, Long> pll;
typedef pair<double, double> pdd;

#define forab(i, a, b)	for (__typeof(b) i = (a); i <= b; ++i)
#define rep(i, n)		forab(i, 0, (n) - 1)
#define For(i, n)		forab(i, 1, n)
#define rofba(i, a, b)	for (__typeof(b)i = (b); i >= a; --i)
#define per(i, n)		rofba(i, 0, (n) - 1)
#define rof(i, n)		rofba(i, 1, n)
#define forstl(i, s)	for (__typeof((s).end()) i = (s).begin(); i != (s).end(); ++i)

const int MAX = 307;
const int INF = 1e8 + 7;
int Suma, Limite1, Limite2;
Long dp1[MAX];
Long dp2[MAX][MAX];
int Monedas[MAX];
int Indice;

Long aEntero(string s) {
    Long r = 0;
    istringstream sin(s); sin >> r;
    return r;
}

vector<string> dividir(string s) {
    vector<string> resultado;
    istringstream ss(s);
    string token;
    while (ss >> token) resultado.agregar(token);
    return resultado;
}

char Cadena[MAX];

void inicializarValores() {
    vector<string> resultado = dividir(Cadena);
    Indice = resultado.size();
    if (Indice == 1) {
        Suma = aEntero(resultado[0]);
    }
    else if (Indice == 2) {
        Suma = aEntero(resultado[0]);
        Limite1 = aEntero(resultado[1]);
    } else {
        Suma = aEntero(resultado[0]);
        Limite1 = aEntero(resultado[1]);
        Limite2 = aEntero(resultado[2]);
    }
}

void preparar() {
    For(i, MAX - 7) Monedas[i] = i;
    inicializar(dp1, 0);
    dp1[0] = 1;
    for (int i = 1; i <= MAX - 7; i++)
        for (int j = 0; j + Monedas[i] < MAX; j++)
            if (dp1[j]) dp1[j + Monedas[i]] += dp1[j];

    inicializar(dp2, 0);
    dp2[0][0] = 1;
    for (int s = 0; s <= MAX - 7; s++) {
        for (int j = 1; j <= MAX - 7; j++) {
            dp2[s][j] += dp2[s][j - 1];
            if (s - Monedas[j] >= 0)
                dp2[s][j] += dp2[s - Monedas[j]][j];
        }
    }
}

int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
    #endif
    preparar();
    while (gets(Cadena)) {
        inicializarValores();
        if (Indice == 1) printf("%lld\n", dp1[Suma]);
        else if (Indice == 2) {
            Limite1 = min(Limite1, 300);
            printf("%lld\n", dp2[Suma][Limite1]);
        } else {
            Limite1 = min(Limite1, 300);
            Limite2 = min(Limite2, 300);
            printf("%lld\n", dp2[Suma][Limite2] - dp2[Suma][Limite1 - 1]);
        }
    }
}