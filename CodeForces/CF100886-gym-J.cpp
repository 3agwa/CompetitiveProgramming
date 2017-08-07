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

vi sockets, resistance;
int n, m;

bool solve(int mid)
{
    if (!mid) return true;
    if (resistance[mid] == 0) return false;
    int res = sockets[0], idx = 0, curr = mid, val = 1;
    while(true)
    {
        while(resistance[curr] == val && res && curr >= 0)
        {
            res--, curr--;
        }
        if (curr < 0) return true;
        if (!res && curr >= 0) return false;

        int total = 0;
        while(res)
        {
            if (idx == n-1) break;
            total += sockets[++idx];
            res--;
        }
        val++;
        res += total;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    sockets = vi(n+1);
    resistance = vi(m+1);
    rep(i, 0, n) cin >> sockets[i];
    rep(i, 0, m) cin >> resistance[i];
    sort(sockets.rbegin(), sockets.rend());
    sort(resistance.rbegin(), resistance.rend());
    int st = 0, en = m, mid, ret = -1;
    while(st <= en)
    {
        mid = (st+en)/2;
        if (solve(mid)) st = mid + 1, ret = mid;
        else en = mid - 1;
    }
    cout << ret + 1 << endl;

    return 0;
}
