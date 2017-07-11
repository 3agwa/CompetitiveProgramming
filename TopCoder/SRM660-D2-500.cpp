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
#define eps (1e-6)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

class PrivateD2party
{
public:
    int getsz(vector <int> a)
    {
        vvi node(100);
        int arr[100] = {};
        rep(i, 0, sz(a))
        {
            if (a[i] != i)
            {
                node[a[i]].push_back(i);
                arr[a[i]]++;
            }
        }
        mapii visited;
        mapii hoba;
        int cnt = 0, sol = 0;
        while(true)
        {
            int mn = INT_MAX, pos;
            rep(i, 0, sz(a))
            {
                if (visited[i] || hoba[i]) continue;
                if (arr[i] < mn)
                {
                    mn = arr[i];
                    pos = i;
                }
            }
            cnt++;
            visited[pos] = true;
            arr[a[pos]]--;
            for(auto i : node[pos])
            {
                if (!visited[i] && !hoba[i])
                {
                    cout << pos << " " << i << endl;
                    hoba[i] = true;
                    sol++;
                }
            }
            if (sol + cnt == sz(a)) break;
        }
        return cnt;
    }
};
