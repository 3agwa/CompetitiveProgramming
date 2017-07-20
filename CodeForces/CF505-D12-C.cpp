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

int arr[60005], n, d, mx, memo[60005][350];

int solve(int curr, int prev)
{
    if (prev >= curr || curr <= 0 || curr > 2*mx) return 0;

    if (memo[curr][curr - prev] != -1) return memo[curr][curr - prev];

    int ret = 0;

    ret = max(ret, arr[curr] + solve(2*curr - prev - 1, curr));
    ret = max(ret, arr[curr] + solve(2*curr - prev, curr));
    ret = max(ret, arr[curr] + solve(2*curr - prev + 1, curr));

    return memo[curr][curr - prev] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> d;
    reset(memo, -1);
    int input;
    rep(i, 0, n)
    {
        cin >> input;
        mx = max(mx, input);
        arr[input]++;
    }

    cout << solve(d, 0);

    return 0;
}
