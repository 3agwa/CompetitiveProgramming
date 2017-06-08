/*
    using circle equation (x*x + y*y = r*r)
    then, y = sqrt(r*r - x*x)
    we iterate over all Xs (till sqrt(D)) and find the corresponding Ys
    if found, increment the counter by 4 as this points exists in all quadrants with different signs
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
#define INF  LLONG_MAX
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
    int tc;
    cin >> tc;
    int d, k;
    while(tc--)
    {
        cin >> d >> k;
        int cnt = 0;
        for(int i = 1; i*i <= d; i++)
        {
            int temp = sqrt(d-(i*i));
            if ((i*i) + (temp*temp) == d)
            {
                cnt += 4;
            }
            if (cnt > k) break;
        }
        if (cnt <= k) cout << "possible\n";
        else cout << "impossible\n";
    }


    return 0;
}
