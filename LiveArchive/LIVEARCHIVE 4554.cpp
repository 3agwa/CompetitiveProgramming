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

int a, b, f, memo[51][1001], visited[51][1001], id;

int solve(int ball, int floor)
{
    if (ball == 1) return floor;
    if (!floor) return 0;
    if (visited[ball][floor] == id) return memo[ball][floor];
    visited[ball][floor] = id;
    int ret = INT_MAX;
    //cout << ball << " " << floor << endl;
    erep(i, 1, floor)
    {
        ret = min(ret, 1 + max(solve(ball-1, i-1), solve(ball, floor-i)));
    }

    return memo[ball][floor] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    erep(t, 1, tc)
    {
        id = t;
        cin >> a >> b >> f;
        cout << a << " " << solve(b, f) << endl;
    }

    return 0;
}
