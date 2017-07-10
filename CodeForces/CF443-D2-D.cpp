/*
    we want to multiply all previous (1-prob[j]) by prob[j]
    we sort to maximize over the values
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

vd arr;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    arr = vd(n);
    rep(i, 0, n) cin >> arr[i];
    sort(all(arr));
    ld ret = 0.0;
    rep(i, 0, n)
    {
        ld sum = 0.0, prob = 1.0;
        rep(j, i, n)
        {
            sum *= (1 - arr[j]);
            sum += (prob * arr[j]);
            prob *= (1 - arr[j]);
        }
        if (sum > ret) ret = sum;
    }
    cout << fixed << setprecision(9) << ret;

    return 0;
}
