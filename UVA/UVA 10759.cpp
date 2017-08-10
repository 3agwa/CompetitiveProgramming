/*
    for each cube, select a number [1, 6] and move to the next cube
    when finishing all cubes, check if the current sum is >= target sum
    after that, get the gcd between dp and 6^n (all possible combinations)
    divide dp value and 6^n by their gcd
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

int n, x;

ull memo[25][160];

ull solve(int idx, int sum)
{
    if (idx == n) return (sum >= x);
    if (memo[idx][sum] != -1) return memo[idx][sum];
    ull ret = 0;
    erep(i, 1, 6) ret += solve(idx+1, sum + i);

    return memo[idx][sum] = ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> n >> x)
    {
        if (!n && !x) break;
        reset(memo, -1);
        ull ret = solve(0, 0);
        ull temp = powl(6, n);
        ull gcd = __gcd(ret, temp);
        ret /= gcd, temp /= gcd;
        if (!ret) cout << 0 << endl;
        else if (ret == temp) cout << 1 << endl;
        else cout << ret << "/" << temp << endl;
    }
    return 0;
}
