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
#define mp(x, y, z) {{x, y}, z}

ll modulo;

struct matrix
{
    int row, col;
    ll arr[2][2];
};

matrix multiply(matrix a, matrix b)
{
    matrix ret;
    ret.row = a.row;
    ret.col = b.col;

    rep(i, 0, ret.row)
    {
        rep(j, 0, ret.col)
        {
            ll sum = 0;
            rep(k, 0, a.col)
            {
                sum += a.arr[i][k] * b.arr[k][j];
                sum %= modulo;
            }
            ret.arr[i][j] = sum;
        }
    }
    return ret;
}

matrix fast_pow(matrix b, int p)
{
    if (p == 1) return b;
    if (p%2 == 0)
    {
        matrix ret = fast_pow(b, p/2);
        return multiply(ret, ret);
    }
    else return multiply(b, fast_pow(b, p-1));
}

int main()
{
    //output;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    while(cin >> n >> m)
    {
        modulo = (1<<m);
        if (n == 0) cout << 0 << endl;
        else if (n <= 2) cout << 1 << endl;
        else
        {
            matrix hoba;
            hoba.row = hoba.col = 2;
            hoba.arr[0][0] = hoba.arr[0][1] = hoba.arr[1][0] = 1;
            hoba.arr[1][1] = 0;

            matrix ret = fast_pow(hoba, n-2);

            matrix hela;
            hela.row = 2, hela.col = 1;
            hela.arr[0][0] = hela.arr[1][0] = 1;

            matrix res = multiply(ret, hela);
            ll ans = res.arr[0][0] % modulo;
            cout << ans << endl;
        }
    }
    return 0;
}
