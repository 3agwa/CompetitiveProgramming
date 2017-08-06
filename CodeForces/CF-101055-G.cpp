#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define vll vector<ll>
#define pii pair<int, int>
#define vii vector<pii>
#define vb vector<bool>
#define vi vector<int>
#define vvi vector< vector<int> >
#define vvii vector< vector< pii > >
#define ld long double
#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pi acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

int n, x[16], y[16], z[16], memo[(1<<16) + 5][3][3][16], sum[16];

int solve(int mask, int l1, int l2, int idx)
{
    if (mask == (1<<n)-1) return 0;

    if (memo[mask][l1][l2][idx] != -1) return memo[mask][l1][l2][idx];

    int ret = 0;

    rep(i, 0, n)
    {
        if (!(mask & (1<<i)))
        {
            int _mask = mask | (1<<i);
            if (idx == n)
            {
                ret = max(ret, sum[i] - x[i] - y[i] + solve(_mask, 0, 1, i));
                ret = max(ret, sum[i] - x[i] - z[i] + solve(_mask, 0, 2, i));
                ret = max(ret, sum[i] - y[i] - z[i] + solve(_mask, 1, 2, i));
                ret = max(ret, sum[i] - y[i] - x[i] + solve(_mask, 1, 0, i));
                ret = max(ret, sum[i] - z[i] - x[i] + solve(_mask, 2, 0, i));
                ret = max(ret, sum[i] - z[i] - y[i] + solve(_mask, 2, 1, i));
            }
            else
            {
                int a, b;
                if (l1 == 0) a = x[idx];
                if (l1 == 1) a = y[idx];
                if (l1 == 2) a = z[idx];
                if (l2 == 0) b = x[idx];
                if (l2 == 1) b = y[idx];
                if (l2 == 2) b = z[idx];
                if (a >= x[i] && b >= y[i]) ret = max(ret, sum[i] - x[i] - y[i] + solve(_mask, 0, 1, i));
                if (a >= x[i] && b >= z[i]) ret = max(ret, sum[i] - x[i] - z[i] + solve(_mask, 0, 2, i));
                if (a >= y[i] && b >= z[i]) ret = max(ret, sum[i] - y[i] - z[i] + solve(_mask, 1, 2, i));
                if (a >= y[i] && b >= x[i]) ret = max(ret, sum[i] - y[i] - x[i] + solve(_mask, 1, 0, i));
                if (a >= z[i] && b >= x[i]) ret = max(ret, sum[i] - z[i] - x[i] + solve(_mask, 2, 0, i));
                if (a >= z[i] && b >= y[i]) ret = max(ret, sum[i] - z[i] - y[i] + solve(_mask, 2, 1, i));
            }
        }
    }
    return memo[mask][l1][l2][idx] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    reset(memo, -1);
    cin >> n;
    rep(i, 0, n)
    {
        cin >> x[i] >> y[i] >> z[i];
        sum[i] = x[i] + y[i] + z[i];
    }

    cout << solve(0, n, n, n);


    return 0;
}
