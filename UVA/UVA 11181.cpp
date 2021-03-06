/*
    consider all masks with # of bits turned on = m
    for each of those, calculate the probability that it occurs
    for turned on bits, multiply its probability 
    for turned off bits, multiply 1-its probability
    accumulate all probabilities
    for each i, output its probability / total sum of probabilities
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
    int t = 0, n, m;
    while(cin >> n >> m)
    {
        if (!n && !m) break;
        t++;
        vd vec(n);
        rep(i, 0, n) cin >> vec[i];
        int mask = (1<<n);
        double total = 0;
        vd memo(n);
        rep(i, 0, mask)
        {
            if (__builtin_popcount(i) == m)
            {
                double prob = 1.;
                rep(j, 0, n)
                {
                    if (i & (1<<j)) prob *= vec[j];
                    else prob *= (1. - vec[j]);
                }
                total += prob;
                rep(j, 0, n)
                {
                    if (i & (1<<j)) memo[j] += prob;
                }
            }
        }
        cout << "Case " << t << ":\n";
        cout << fixed << setprecision(6);
        rep(i, 0, n) cout << memo[i] / total << endl;
    }
    return 0;
}
