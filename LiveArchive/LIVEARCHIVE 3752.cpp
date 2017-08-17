/*
    it's basic dp, just maximize over the elements that appeared before you that you're greater than
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

string x;
int memo[1001][1001];

int solve(int i, int j)
{
    if (i == sz(x)) return 0;
    if (memo[i][j] != -1) return memo[i][j];
    int ret = 0;
    ret = max(ret, solve(i+1, j));
    if (x[i] > x[j]) ret = max(ret, 1 + solve(i+1, i));
    return memo[i][j] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 0;
    while(cin >> x && x != "end")
    {
        reset(memo, -1);
        cout << "Case " << ++t << ": " << solve(0, sz(x)) << endl;
    }
    return 0;
}
