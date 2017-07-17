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

int n, total;
vi vec;

bool check(int mask, int pos)
{
    return !(mask & (1<<pos));
}

int memo[(1<<20)];

int solve(int mask)
{
    if (mask == (1<<n)-1) return 0;
    if (memo[mask] != -1) return memo[mask];
    int ret = INT_MAX, val = 0;
    rep(j, 0, n)
    {
        if (check(mask, j)) val += vec[j];
    }
    rep(i, 0, n)
    {
        int temp = mask, xval = 0;
        if (check(mask, i)) temp |= (1<<i), xval += vec[i];
        if (check(mask, (i+1)%n)) temp |= (1<<((i+1)%n)), xval += vec[(i+1)%n];
        if (check(mask, (i+2)%n)) temp |= (1<<((i+2)%n)), xval += vec[(i+2)%n];
        if (temp == mask) continue;
        ret = min(ret, solve(temp) + val - xval);
    }

    return memo[mask] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    reset(memo, -1);
    cin >> n;
    vec = vi(n);
    rep(i, 0, n)
    {
        cin >> vec[i];
        total += vec[i];
    }
    cout << solve(0);

    return 0;
}
