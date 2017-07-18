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

int n, m, arr[1000001], memo[1001][1002];

bool solve(int i, int rem, int taken)
{
    if (!rem && taken) return true;
    if (i == n) return false;
    if (memo[i][rem] != -1) return memo[i][rem];
    bool ret = false;
    ret |= solve(i+1, rem, taken);
    ret |= solve(i+1, (rem+arr[i])%m, 1);
    return memo[i][rem] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, n) cin >> arr[i];
    if (n > m) cout << "YES";
    else
    {
        reset(memo, -1);
        int hoba = solve(0, 0, 0);
        if (hoba) cout << "YES";
        else cout << "NO";
    }
    return 0;
}
