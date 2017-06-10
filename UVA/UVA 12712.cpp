/*
    solution is summation of NpR such that R[min, max], N = size of grid ^2
*/
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
#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pie  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

ll modulo = 10000000000007;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    erep(t, 1, tc)
    {
        int a, b, c;
        cin >> a >> b >> c;
        ll hoba = 1;
        for(ll i = a*a; i>(a*a - b); i--)
        {
            hoba = (hoba*i)%modulo;
        }
        ll sum = hoba;
        for(ll i = (a*a - b); i>(a*a-c); i--)
        {
            hoba = (hoba*i)%modulo;
            sum = (sum + hoba)%modulo;
        }
        cout << "Case " << t << ": " << sum << endl;
    }
    return 0;
}
