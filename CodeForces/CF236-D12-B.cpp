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

int solve(int num)
{
    int cnt = 0;
    for(int i = 1; i*i <= num; i++)
    {
        if (num%i == 0)
        {
            cnt++;
            if (i*i != num) cnt++;
        }
    }
    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    ll sum = 0;
    erep(i, 1, a)
    {
        erep(j, 1, b)
        {
            erep(k, 1, c)
            {
                if (!arr[i*j*k])
                {
                    int temp = solve(i*j*k);
                    arr[i*j*k] = temp;
                    sum += solve(i*j*k);
                    if (sum >= (1<<30)) sum %= (1<<30);
                }
                else
                {
                    sum += arr[i*j*k];
                    if (sum >= (1<<30)) sum %= (1<<30);
                }
            }
        }
    }
    cout << sum;


    return 0;
}
