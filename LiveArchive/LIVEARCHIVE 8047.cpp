/*
    for every a[i] != b[i], run bfs from a[i] to get all the letters it could reach
    if letter b[i] was not found, output no
    repeat till the string ends
    if the 2 lengths are not the same, answer is no
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


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int m, n;
    while(cin >> m >> n)
    {
        map<char, vector<char> > mp;
        rep(i, 0, m)
        {
            char a, b;
            cin >> a >> b;
            mp[a].push_back(b);
        }
        while(n--)
        {
            string a, b;
            cin >> a >> b;
            if (sz(a) != sz(b))
            {
                cout << "no\n";
                goto barra;
            }

            rep(i, 0, sz(a))
            {
                if (a[i] != b[i])
                {
                    queue<char> Q;
                    Q.push(a[i]);
                    bool flag = false;
                    bool visited[200] = {};
                    while(!Q.empty())
                    {
                        char hoba = Q.front();
                        Q.pop();
                        if (hoba == b[i])
                        {
                            flag = true;
                            break;
                        }
                        if (visited[hoba]) continue;
                        visited[hoba] = true;
                        rep(j, 0, sz(mp[hoba]))
                        {
                            if (!visited[mp[hoba][j]]) Q.push(mp[hoba][j]);
                        }
                    }
                    if (!flag)
                    {
                        cout << "no\n";
                        goto barra;
                    }
                }
            }
            cout << "yes\n";
            barra:;
        }
    }
    return 0;
}
