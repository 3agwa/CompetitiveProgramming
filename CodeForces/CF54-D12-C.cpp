/*
    initially, we have to get the probability of ones in each interval
    afterwards, dp on the indices with their possible values of K
    the base case would be if current K is >= desired K we return true
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

double prob[1001], memo[1001][1001];
int n, k;
bool visited[1001][1001];

double solve(int idx, int hoba)
{
    if (idx == n) return 1LL*hoba*100 >= 1LL*n*k;
    if (visited[idx][hoba]) return memo[idx][hoba];
    visited[idx][hoba] = true;
    double ret = solve(idx+1, hoba) * (1.0 - prob[idx]) + solve(idx+1, hoba+1) * prob[idx];
    return memo[idx][hoba] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n)
    {
        ull l, r;
        cin >> l >> r;
        ull curr = 0;
        for(ull j = 1; j<=r; j*=10)
        {
            ll st = max(l, j);
            ll en = min(r, 2*j - 1);
            if (st <= en) curr += (en-st+1);
        }
        prob[i] = 1.0 * curr / (r-l+1);
    }
    cin >> k;
    cout << fixed << setprecision(9) << solve(0, 0);

    return 0;
}
