#include <bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(),x.end()
#define ms(a,v) memset(a,v,sizeof a)
#define II ({int a; scanf("%d", &a); a;})
#define LL ({Longo a; scanf("%lld", &a); a;})
#define DD ({double a; scanf("%lf", &a); a;})
#define EPS 1e-10
#define pi 3.1415926535897932384626433832795
using namespace std;

typedef long long Longo;
typedef unsigned long long ull;
typedef vector<int> vi ;
typedef set<int> si;
typedef vector<Longo> vl;
typedef pair<int,int> pii;
typedef pair<Longo,Longo> pll;
typedef pair<double,double> pdd;

#define forab(i, a, b) for (__typeof (b) i = (a) ; i <= b ; ++i)
#define rep(i, n)      forab (i, 0, (n) - 1)
#define For(i, n)      forab (i, 1, n)
#define rofba(i, a, b) for (__typeof (b)i = (b) ; i >= a ; --i)
#define per(i, n)      rofba (i, 0, (n) - 1)
#define rof(i, n)      rofba (i, 1, n)
#define forstl(i, s)   for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)

const int MX = 507;
const int INF = 1e8 + 7;

Longo dp[MX][27];
bool Visitado[MX][27];
int tamano, valor;

Longo resolver(int i, int j) {
    if (i == tamano && j == 1) return valor;
    Longo &retorno = dp[i][j];
    if (Visitado[i][j]) return retorno;
    Visitado[i][j] = true;
    retorno = 0;
    if (i < j) {
        for (int k = i; k < j; k++)
            retorno = max(retorno, resolver(i, k) + resolver(k + 1, j));
    } else {
        Longo r1 = 0, r2 = 0;
        if (i < tamano) {
            for (int k = i + 1; k <= tamano; k++)
                r1 = max(r1, resolver(k, 1) + resolver(k, j));
        }
        if (j > 0) {
            for (int k = 1; k < j; k++)
                r2 = max(r2, resolver(i, k) + resolver(tamano, k));
        }
        retorno = r1 + r2;
    }
    return retorno;
}

int main() {
    #ifdef LOCAL
        freopen("in.txt", "r", stdin);
    #endif
    while (scanf("%d %d", &tamano, &valor) != EOF) {
        ms(Visitado, false);
        printf("%lld\n", resolver(1, tamano));
    }
}
