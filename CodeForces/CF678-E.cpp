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
#define mp(x, y, z) {{x, y}, z}

int n;
double arr[19][19], memo[(1<<19)+1][19];
bool visited[(1<<18)+5][19];

double solve(int mask, int idx)
{
    if (mask == (1<<n)-1) return idx == 0; // Jedi's index is 0, check if he is the winner or not

    if (visited[mask][idx]) return memo[mask][idx];
    visited[mask][idx] = true;
    double ret = 0.0;
    rep(j, 0, n)
    {
        if (mask & (1<<j)) continue;
        ret = max(ret, solve(mask | (1<<j), idx) * arr[idx][j] + solve(mask | (1<<j), j) * arr[j][idx]); // idx win, j-win
    }

    return memo[mask][idx] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    reset(memo, -1);
    rep(i, 0, n) rep(j, 0, n) cin >> arr[i][j];
    double mx = 0.0;
    rep(i, 0, n) mx = max(mx, solve((1<<i), i)); // pick player 1
    cout << fixed << setprecision(9) << mx;

    return 0;
}
