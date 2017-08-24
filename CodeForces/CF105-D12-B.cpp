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
#define mp(x, y, z) {x, {y, z}}

int b[8], l[8], n, k, A;
int arr[8];

double check()
{
    double ret = 0, rat;
    int sum = 0, cnt = 0;
    rep(mask, 0, (1<<n))
    {
        rat = 1, sum = cnt = 0;
        rep(i, 0, n)
        {
            if (mask & (1<<i))
            {
                cnt++;
                rat *= (arr[i]) / 100.0;
            }
            else
            {
                rat *= (100.0 - arr[i]) / 100.0;
                sum += b[i];
            }
        }
        if (cnt > n/2) ret += rat;
        else ret += rat*(A / (double)(A+sum));
    }
    return ret;
}

double solve(int idx, int rem)
{
    if (idx == n)
    {
        if (!rem) return check();
        return 0;
    }
    double ret = 0.;
    erep(i, 0, rem)
    {
        arr[idx] = min(100, l[idx] + i*10);
        ret = max(ret, solve(idx+1, rem - i));
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k >> A;
    rep(i, 0, n) cin >> b[i] >> l[i];
    cout << fixed << setprecision(9) << solve(0, k) << endl;
    return 0;
}
