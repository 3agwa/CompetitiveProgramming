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
#define mp(x, y, z) {{x, y}, z}

bool visited[25][25];
int st, en, n, x, y;

int solve(int i, int j, int cnt)
{
    if (cnt == n) return abs(i-st) + abs(j-en);
    int mn = 1e8;
    erep(a, 1, x)
    {
        erep(b, 1, y)
        {
            if (visited[a][b])
            {
                visited[a][b] = false;
                mn = min(mn, solve(a, b, 1 + cnt) + abs(i-a) + abs(b-j));
                visited[a][b] = true;
            }
        }
    }
    return mn;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        cin >> x >> y;
        cin >> st >> en;
        cin >> n;
        reset(visited, false);
        rep(i, 0, n)
        {
            int a, b;
            cin >> a >> b;
            visited[a][b] = true;
        }
        cout << "The shortest path has length " << solve(st, en, 0) << endl;
    }
    return 0;
}
