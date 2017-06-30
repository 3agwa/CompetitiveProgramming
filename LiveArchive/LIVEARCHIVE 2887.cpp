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

int arr[1000001];
int freq[26];

void solve(int n, bool hoba)
{
    erep(i, 2, n)
    {
        int x = i;
        for(int j = 2; j*j <= x; j++)
        {
            while(x%j == 0)
            {
                x/=j;
                if (hoba) arr[j]++;
                else arr[j]--;
            }
        }
        if (x > 1)
        {
            if (hoba) arr[x]++;
            else arr[x]--;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string x;
    while(cin >> x)
    {
        reset(freq, 0);
        rep(i, 0, sz(x)) freq[x[i] - 'a']++;
        solve(sz(x), 1);
        rep(i, 0, 26)
        {
            if (freq[i] > 1) solve(freq[i], 0);
        }
        if (arr[5] >= arr[2])
        {
            arr[5] -= arr[2];
            arr[2] = 0;
        }
        else
        {
            arr[2] -= arr[5];
            arr[5] = 0;
        }
        int ans = 1;
        erep(i, 1, sz(x))
        {
            while(arr[i])
            {
                ans *= i;
                arr[i]--;
                ans %= 10;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
