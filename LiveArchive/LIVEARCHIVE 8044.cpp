#include <bits/stdc++.h>
#include <chrono>

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

int n, m;

ll memo[300][300];
ll dp[257][257];
vll val;
vi vec;

ll fn(int i, int j)
{
    ll mn = INF;
    erep(a, i, j)
    {
        ll sum = 0;
        rep(b, 0, sz(vec))
        {
            if (i <= vec[b] && vec[b] <= j)
            {
                sum += (abs(vec[b] - a))*(abs(vec[b] - a)) * val[b];
            }
        }
        mn = min(mn, sum);
    }
    return mn;
}

ll solve(int i, int rem)
{
    if (i > vec.back()) return 0;
    ll &ret = memo[i][rem];
    if (ret != -1) return ret;
    ret = 1e16;
    erep(j, i, vec.back())
    {
        if (rem-1 >= 0)
            ret = min(ret, dp[i][j] + solve(j+1, rem-1));
        else break;
    }
    return memo[i][rem] = ret;
}

int main()
{
    freopen("input.txt", "r", stdin);
    auto start = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n >> m)
    {
        vec = vi(n);
        val = vll(n);
        reset(memo, -1);
        rep(i, 0, n) cin >> vec[i] >> val[i];
        erep(i, vec.front(), vec.back())
        {
            erep(j, i, vec.back())
            {
                dp[i][j] = fn(i, j);
            }
        }
        cout << solve(vec.front(), m) << endl;
    }
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
    return 0;
}
