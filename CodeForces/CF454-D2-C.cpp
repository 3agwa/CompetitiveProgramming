/*
    after brute forcing some solutions, you'll be able to spot a pattern
    index i will be maximum exactly i^m - (i-1)^m times
    since we divide the final answer by N, hence we could write it as (i/N)^m 
    multiply the above by i and accumulate it over the solution variable
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


int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    double n, m;
    cin >> n >> m;
    double ret = 0;
    erep(i, 1, n)
    {
        ret += i*(powl(i/n, m) - powl((i-1)/n, m));
    }
    cout << fixed << setprecision(9) << ret << endl;

    return 0;
}
