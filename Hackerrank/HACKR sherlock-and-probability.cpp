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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        ll n, m;
        cin >> n >> m;
        vi vec(n+1);
        string x;
        cin >> x;
        rep(i, 0, sz(x))
        {
            vec[i+1] = x[i] - '0';
            vec[i+1] += vec[i];
        }
        ll ret = 0;
        erep(i, 1, n)
        {
            if (vec[i] - vec[i-1])
            {
                int t = min(n, i + m);
                ret += vec[t] - vec[i-1];
                t = max(0LL, i - m);
                ret--;
                if (t) ret += vec[i] - vec[t-1];
                else ret += vec[i];
            }
        }
        if (!ret) cout << "0/1\n";
        else
        {
            ll deno = n*n;
            ll gcd = __gcd(ret, deno);
            ret /= gcd, deno /= gcd;
            cout << ret << "/" << deno << endl;
        }
    }

    return 0;
}
