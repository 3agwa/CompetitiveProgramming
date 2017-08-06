#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define vll vector<ll>
#define pii pair<int, int>
#define vii vector<pii>
#define vb vector<bool>
#define vi vector<int>
#define vvi vector< vector<int> >
#define vvii vector< vector< pii > >
#define mapii map<int, int>
#define ld long double
#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pi acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
// brain lag :)
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vll vec(n);
    ll sum = 0, sub = 0;
    rep(i, 0, n) cin >> vec[i];
    vec.push_back(0);
    rep(i, 0, n+1)
    {
        if (vec[i] > vec[i+1])
        {
            sum += vec[i];
            sub += vec[i+1];
        }
    }
    cout << sum - sub;

    return 0;
}
