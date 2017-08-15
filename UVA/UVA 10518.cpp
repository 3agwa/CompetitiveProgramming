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

//const int mod = 987654321;

int mod;

#define vvll vector< vector< ll > >

vvll matrixUnit(int n)
{
    vvll res(n, vll(n));
    for (int i = 0; i < n; i++)
        res[i][i] = 1;
    return res;
}

vvll matrixAdd(const vvll &a, const vvll &b)
{
    int n = a.size();
    int m = a[0].size();
    vvll res(n, vll(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res[i][j] = (a[i][j] + b[i][j]) % mod;
    return res;
}

vvll matrixMul(const vvll &a, const vvll &b)
{
    int n = a.size();
    int m = a[0].size();
    int k = b[0].size();
    vvll res(n, vll(k));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
            for (int p = 0; p < m; p++)
                res[i][j] = (res[i][j]%mod + ((long long) a[i][p] * b[p][j])%mod) % mod;
    return res;
}

vvll matrixPow(const vvll &a, ll p)
{
    if (p == 0)
        return matrixUnit(a.size());
    if (p & 1)
        return matrixMul(a, matrixPow(a, p - 1));
    return matrixPow(matrixMul(a, a), p / 2);
}

vvll matrixPowSum(const vvll &a, ll p)
{
    int n = a.size();
    if (p == 0)
        return vvll(n, vll(n));
    if (p % 2 == 0)
        return matrixMul(matrixPowSum(a, p / 2), matrixAdd(matrixUnit(n), matrixPow(a, p / 2)));
    return matrixAdd(a, matrixMul(matrixPowSum(a, p - 1), a));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, b, tc = 0;
    while(cin >> n >> b)
    {
        if (!n && !b) break;
        tc++;
        cout << "Case " << tc << ": ";
        cout << n << " " << b << " ";
        if (!n) cout << 1%b << endl;
        else
        {
            vvll mat(2, vll(2));
            mat[0][0] = 0;
            mat[0][1] = 1;
            mat[1][0] = 1;
            mat[1][1] = 1;
            mod = b;

            vvll hoba = matrixPow(mat, n+1);
            cout << mod(2*hoba[0][1] - 1, b) << endl;
        }
    }

    return 0;
}
