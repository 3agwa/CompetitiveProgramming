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
#define eps (1e-9)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {{x, y}, z}

int idx;
string good, x, y;
map<char, int > mp;

bool solve()
{
    if (idx == -1)
    {
        if (sz(y) != sz(x)) return false;

        rep(i, 0, sz(x))
        {
            if (x[i] == '?')
            {
                if (!mp[y[i]]) return false;
            }
            else if (x[i] != y[i]) return false;
        }
        return true;
    }

    rep(i, 0, idx)
    {
        if (i >= sz(y)) return false;

        if (x[i] == '?')
        {
            if (!mp[y[i]]) return false;
        }
        else if (x[i] != y[i]) return false;
    }

    int pos = sz(y)-1;

    for(int i = sz(x)-1; i>idx; i--)
    {
        if (pos < idx) return false;
        if (x[i] == '?')
        {
            if (!mp[y[pos]]) return false;
        }
        else if (x[i] != y[pos]) return false;
        pos--;
    }

    erep(i, idx, pos) if (mp[y[i]]) return false;

    return true;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> good;


    rep(i, 0, sz(good)) mp[good[i]]++;

    cin >> x;
    idx = -1;

    rep(i, 0, sz(x))
    {
        if (x[i] == '*')
        {
            idx = i;
            break;
        }
    }

    int q;
    cin >> q;
    while(q--)
    {
        cin >> y;
        if (solve()) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
