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

int prime[5000001];
int hoba[5000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i = 2; i<= 5000001; i++)
    {
        if (!prime[i])
        {
            for(int j = i; j<=5000001; j+=i)
            {
                prime[j] = true;
                int jj = j, cnt = 0;
                while(jj%i == 0)
                {
                    jj /= i;
                    cnt++;
                }
                hoba[j] += cnt;
            }
        }
    }

    erep(i, 1, 5000001) hoba[i] += hoba[i-1];
    int tc;
    cin >> tc;
    while(tc--)
    {
        int a, b;
        cin >> a >> b;
        cout << hoba[a] - hoba[b] << endl;
    }

    return 0;
}