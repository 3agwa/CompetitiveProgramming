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

double p[17][17], memo[18][18];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 4;
    int m = (1<<n);
    vs vec(m);
    rep(i, 0, m)
    {
        cin >> vec[i];
        erep(j, sz(vec[i]), 10) vec[i] += " ";
    }
    for(int i = 0; i<m; i++) for(int j = 0; j<m; j++) cin >> p[i][j], p[i][j]/=(double)100.0;
    for(int i = 0; i<m; i++) memo[0][i] = 1; // base case
    for(int i = 1; i<=n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            for(int k = 0; k<m; k++)
            {
                if((j>>(i-1)^1)==(k>>(i-1))) // two bits are not the same
                {
                    memo[i][j] += memo[i-1][j]*memo[i-1][k]*p[j][k];
                }
            }
        }
    }
    cout << fixed << setprecision(2);
    rep(i, 0, 16) cout << vec[i] << "p=" << memo[n][i]*100.0 << "%\n";

    return 0;
}
