/*
    we have (n-k) positions that can't go to 1, hence we have (n-k) options
    in each index, we could place any of the (n-k) options
    therefore, we have (n-k)^(n-k) places that can't go to house #1
    we have to multiply that by a factor
    i deduced that factor from dividing the given answer / (n-k)^(n-k)
    factor equals k^(k-1)
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

ll modulo = 1000000007;

ll fast_pow(int b, int p)
{
    if (!p) return 1;
    ll temp = fast_pow(b, p/2)%modulo;
    temp = (temp*temp)%modulo;
    if (p&1) temp = (temp*b)%modulo;
    return temp;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    ll sum = ((fast_pow(n-k, n-k)%modulo)*fast_pow(k, k-1)%modulo)%modulo;
    cout << sum;
    return 0;
}
