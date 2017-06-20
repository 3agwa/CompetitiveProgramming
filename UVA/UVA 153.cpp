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


ull gcd(ll a, ll b)
{
    if (a % b == 0)   return b;
    else   return gcd(b, a % b);
}
void Divbygcd(ull& a, ull& b)
{
    ull g = gcd(a, b);
    a /= g;
    b /= g;
}
ull C(ull n, ull k)
{
    if (n < k)   return 0;
    ull numerator = 1, denominator = 1, toMul, toDiv, i;
    if (k > n / 2)   k = n - k; // use smaller k
    for (i = k; i; i--)
    {
        toMul = n - k + i;
        toDiv = i;
        Divbygcd(toMul, toDiv); // always divide before multiply
        Divbygcd(numerator, toDiv);
        Divbygcd(toMul, denominator);
        numerator *= toMul;
        denominator *= toDiv;
    }
    return numerator / denominator;
}

ull solve(ull n, ull arr[])
{
    vector< ull >  coeff;
    erep(i, 'a', 'z') if (arr[i]) coeff.push_back(arr[i]);
    ull ret = 1;
    rep(i, 0, sz(coeff))
    {
        ret *= C(n, coeff[i]);
        n-=coeff[i];
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string x;
    while(cin >> x && x != "#")
    {
        ull arr[130] = {};
        rep(i, 0, sz(x)) arr[x[i]]++;
        ull hoba = 1;
        rep(i, 0, sz(x))
        {
            double val = (double)solve(sz(x)-i, arr) / (double)(sz(x)-i);
            //cout << solve(sz(x)-i, arr) << " " << val << endl;
            rep(j, 'a', x[i]) if (arr[j]) hoba += (arr[j]*val);
            arr[x[i]]--;
        }
        cout << setw(10) << hoba << endl;
    }

    return 0;
}
