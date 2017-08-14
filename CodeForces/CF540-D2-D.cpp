/*
    accumulate the pairs taken in the current state, we'll divide the solution by that number before returning
    simulate the process stated in the statement and memoize over the values
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

double memo[101][101][101];
bool visited[101][101][101];
int id;

double solve(int a, int b, int c)
{
    if (a && !b && !c) return 1.;
    if (a <= 0) return 0;
    if (visited[a][b][c]) return memo[a][b][c];
    visited[a][b][c] = true;
    double deno = 0.0;
    double ret = 0.0;
    if (a && b)
    {
        deno += (a*b);
        ret += a*b*solve(a, b-1, c);
    }
    if (a && c)
    {
        deno += (a*c);
        ret += a*c*solve(a-1, b, c);
    }
    if (b && c)
    {
        deno += (b*c);
        ret += b*c*solve(a, b, c-1);
    }
    return memo[a][b][c] = ret / deno;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    cout << fixed << setprecision(9);
    reset(visited, false);
    cout << solve(a, b, c) << " ";
    reset(visited, false);
    cout << solve(b, c, a) << " ";
    reset(visited, false);
    cout << solve(c, a, b) << endl;


    return 0;
}
