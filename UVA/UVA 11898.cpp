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
#define mp(x, y, z) {{x, y}, z}

int arr[200001], cnt[200001], temp[200001];

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int tc, n, a, b, q, idx;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d", &n);
        rep(i, 0, n) scanf("%d", &arr[i]);
        scanf("%d", &q);
        while(q--)
        {
            scanf("%d%d", &a,& b);
            a--, b--;
            int mn = INT_MAX, mx = 0;
            if (b - a + 1 > 10000)
            {
                mn = 0;
                goto barra;
            }
            erep(i, a, b) cnt[arr[i]]++, mn = min(mn, arr[i]), mx = max(mx, arr[i]);
            idx = 0;
            erep(i, mn, mx)
            {
                while(cnt[i] > 0) cnt[i]--, temp[idx++] = i;
            }
            mn = INT_MAX;
            if (idx == 1) mn = 0;
            else rep(i, 1, idx) mn = min(mn, temp[i]-temp[i-1]);
barra:
            printf("%d\n", mn);
        }
    }

    return 0;
}
