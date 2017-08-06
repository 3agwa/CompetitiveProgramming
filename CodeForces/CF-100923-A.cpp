#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define pii pair<int, int>
#define vii vector<pii>
#define vb vector<bool>
#define vi vector<int>
#define vvi vector< vector<int> >
#define vvii vector< vector< pii > >
#define mapii map<int, int>
#define ld long double
#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pi acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

/*int n, memo[1000001][3];
vi vec;

int solve(int i, int even, int taken)
{
    if (i == n) return (!(even&1) && taken);
    //if (memo[i][even] != -1) return memo[i][even];
    int ret = 0;
    ret += solve(i+1, even, taken);
    ret += solve(i+1, even + vec[i], taken ? taken : taken + 1);
    /*if (even == 2)
    {
        ret += solve(i+1, even);
        ret += solve(i+1, vec[i]);
    }
    else
    {
        ret += solve(i+1, even);
        if (!even && !vec[i]) ret += solve(i+1, 0);
        else if (even && vec[i]) ret += solve(i+1, 1);
    }
    return memo[i][even] = ret;
}*/

int n, modulo = 1000000007;
vi vec;

ll fast_pow(int b, int p)
{
    if (!p) return 1;

    ll ret = fast_pow(b, p/2) % modulo;
    ret = (ret*ret)%modulo;
    if (p&1) ret = (ret*b)%modulo;
    return ret;
}

int main()
{
    freopen("azerah.in", "r", stdin);
    freopen("azerah.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int even = 0, odd = 0;
        cin >> n;
        rep(i, 0, n)
        {
            int x;
            cin >> x;
            if (x%2 == 0) even++;
            else odd++;
        }

        ll a = fast_pow(2, even)-1, b = fast_pow(2, odd-1)-1;
        if (!odd) cout << a << endl;
        else if (!even) cout << b << endl;
        else
        {
            ll sol = ((a%modulo)*(b%modulo))%modulo;
            sol = (sol + a + b)%modulo;
            cout << sol << endl;
        }
    }

    return 0;
}
