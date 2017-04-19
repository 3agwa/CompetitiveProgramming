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
#define input freopen("input.txt", "r", stdin)
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

int main()
{
    //input;
    //output;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, c;
    string x, hoba;
    while(cin >> n >> m)
    {
        map<string, vii > mp;
        string arr[10001][11];
        set< string > st;
        rep(i, 0, n)
        {
            c = 0;
            if (!i) cin.ignore();
            getline(cin, x);
            if (m == 1) continue;
            x += ',';
            hoba = "";
            rep(j, 0, sz(x))
            {
                if (x[j] == ',')
                {
                    arr[i][c] = hoba;
                    mp[hoba].push_back({i, c++});
                    if (sz(mp[hoba]) > 1)
                    {
                        st.insert(hoba);
                    }
                    hoba = "";
                    continue;
                }
                hoba += x[j];
            }
        }
        if (m == 1) goto here;
        while(!st.empty())
        {
            hoba = *st.begin();
            st.erase(st.begin());
            //cout << hoba << endl;
            rep(i, 0, sz(mp[hoba]))
            {
                int r = mp[hoba][i].first, c = mp[hoba][i].second;
                rep(j, i+1, sz(mp[hoba]))
                {
                    int r2 = mp[hoba][j].first, c2 = mp[hoba][j].second;
                    if (c == c2)
                    {
                        rep(a, 0, m)
                        {
                            rep(b, 0, m)
                            {
                                if (a != c && b != c2 && arr[r][a] == arr[r2][b])
                                {
                                    if (arr[r][c] == arr[r2][c] && arr[r][b] == arr[r2][b])
                                    {
                                        cout << "NO\n";
                                        cout << r+1 << " " << r2+1 << endl;
                                        cout << c+1 << " " << b+1 << endl;
                                        goto barra;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
here:
        cout << "YES\n";
barra:;
    }


    return 0;
}
