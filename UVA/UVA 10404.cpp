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

int total, n;
bool memo[1000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin >> total >> n)
    {
        reset(memo, 0);
        vi vec(n);
        rep(i, 0, n) cin >> vec[i];
        erep(i, 1, total)
        {
            memo[i] = 0;
            rep(j, 0, n)
            {
                if (i - vec[j] >= 0 && !memo[i - vec[j]])
                {
                    memo[i] = true;
                    break;
                }
            }
        }
        if (memo[total]) cout << "Stan wins\n";
        else cout << "Ollie wins\n";
    }
    return 0;
}
