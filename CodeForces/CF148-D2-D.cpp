/*
    we divide the problem into two parts, the princess's turn and the dragon's turn
    if the princess is now playing, she could either win in this turn or pick a black mouse
    if it's the dragon's turn, he could pick a black one and another black mouse escapes
    or he could pick a black mouse and a white mouse escapes
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

double memo[1010][1010][2];

double solve(int w, int b, bool turn)
{
    if (b <= 0) return (w && !turn);
    if (!w) return 0;
    if (fabs(memo[w][b][turn] + 1) > 1e-9) return memo[w][b][turn];
    double ret = 0;
    if (!turn)
    {
        ret = w*1.0 / (w+b);
        ret += solve(w, b-1, !turn) * (b *1.0 / (b+w));
    }
    else
    {
        ret = solve(w, b-2, !turn) * b *1.0 * (b-1)*1.0 / (b+w) / (b+w-1);
        ret += solve(w-1, b-1, !turn) * w*1.0 * b*1.0 / (w+b-1) / (w+b);
    }
    return memo[w][b][turn] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int w, b;
    cin >> w >> b;
    reset(memo, -1);
    cout << fixed << setprecision(9) << solve(w, b, 0);
    return 0;
}
