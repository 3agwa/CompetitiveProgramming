#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define vll vector<ll>
#define pii pair<int, int>
#define vii vector<pii>
#define vs vector<string>
#define vb vector<bool>
#define vi vector<int>
#define vd vector<double>
#define vvi vector< vector<int> >
#define vvii vector< vector< pii > >
#define ld long double
#define mapii map<int, int>
#define mapsi map<string, int>
#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
//#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pie  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

double memo[(1<<18) + 1];
double arr[18][18];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    rep(i, 0, n) rep(j, 0, n) cin >> arr[i][j];
    memo[(1<<n)-1] = 1.;

    for(int mask = (1<<n)-1; mask>=0; mask--)
    {
        rep(i, 0, n)
        {
            if (mask & (1<<i))
            {
                rep(j, i+1, n)
                {
                    if (mask & (1<<j))
                    {
                        double x = __builtin_popcount(mask);
                        double hoba = (x*(x-1)) / 2.0;
                        memo[mask - (1<<i)] += memo[mask] * arr[j][i] / hoba; // ith eaten
                        memo[mask - (1<<j)] += memo[mask] * arr[i][j] / hoba; // jth eaten
                    }
                }
            }
        }
    }
    cout << fixed << setprecision(9);
    rep(i, 0, n) cout << memo[(1<<i)] << " ";
    return 0;
}
