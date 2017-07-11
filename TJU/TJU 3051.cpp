/*
    calculate win/draw/lose ratio
    each match we will either win/draw/lose, recurse an subtract the points according 
    to the current transition and multiply by the transition's probability
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

double n, pts, total, w, d, l, win, lose, draw;

double memo[500][500];

double solve(int i, int p)
{
    if (p <= 0) return 100.0;
    if (!i) return 0.0;
    if (fabs(memo[i][p] + 1) > 1e-9) return memo[i][p];
    double ret = solve(i-1, p-3) * win + draw * solve(i-1, p-1) + solve(i-1, p) * lose;
    return memo[i][p] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n >> pts)
    {
        if (!n && !pts) break;
        reset(memo, -1);
        cin >> w >> d >> l;
        win = w / (w+d+l);
        lose = l / (w+d+l);
        draw = d / (w+d+l);
        cout << fixed << setprecision(1) << solve(n, pts) << endl;
    }
    return 0;
}
