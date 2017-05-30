/*

    the idea is to disect the problem, cutting off the leaf nodes level by level.
    first, push the leaf nodes into the queue
    find the xor value of the leaf node, TEMP, then decrease TEMP's degree by 1, and xor TEMP with the leaf node
    save the solution and output it after exiting the loop

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
    int n;
    cin >> n;
    mapii xorr;
    int cnt = 0;
    mapii deg;
    queue<int> Q;
    rep(i, 0, n)
    {
        int a, b;
        cin >> a >> b;
        deg[i] = a;
        if (a == 1) Q.push(i);
        xorr[i] = b;
    }
    vii vec;
    while(!Q.empty())
    {
        int idx = Q.front();
        Q.pop();
        if (deg[idx] != 1) continue;
        int temp = xorr[idx];
        xorr[idx] ^= temp;
        deg[idx]--;
        deg[temp]--;
        xorr[temp]^=idx;
        if (deg[temp] == 1)
        Q.push(temp);
        vec.push_back({idx, temp});
    }
    cout << sz(vec) << endl;
    rep(i, 0, sz(vec)) cout << vec[i].first << " " << vec[i].second << endl;


    return 0;
}
