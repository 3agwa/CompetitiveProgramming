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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi v1(n);
    vi v2(n);
    vi res(n);
    mapii mp;
    vi temp;
    rep(i, 0, n) cin >> v1[i];
    rep(i, 0, n) cin >> v2[i];
    rep(i, 0, n)
    {
        if (v1[i] == v2[i]) res[i] = v1[i], mp[v1[i]] = 1;
        else temp.push_back(i);
    }
    if (sz(temp) == 1)
    {
        erep(i, 1, n)
        {
            if (!mp[i])
            {
                res[temp[0]] = i;
                break;
            }
        }
    }
    else
    {
        int x = temp[0], y = temp[1];
        if (!mp[v1[x]] && !mp[v2[y]] && v1[x] != v1[x] != v2[y])
        {
            res[x] = v1[x];
            res[y] = v2[y];
        }
        else
        {
            res[x] = v2[x];
            res[y] = v1[y];
        }
    }
    rep(i, 0, n) cout << res[i] << " ";


    return 0;
}
