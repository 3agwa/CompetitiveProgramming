/*
    modified bfs, if the current value is not visited, mark it as visited and continue
    else keep running bfs to reach all multiples of starting node
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
#define eps (1e-6)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

class IncrementingSequence
{
public:
    string canItBeDone(int k, vector <int> A)
    {
        mapii visited;
        queue<int> Q;
        int x = 0;
        rep(i, 0, sz(A))
        {
            Q.push(A[i]);
        }
        while(!Q.empty())
        {
            int hoba = Q.front();
            Q.pop();
            if (hoba > sz(A)) continue;
            if (!visited[hoba])
            {
                visited[hoba] = true;
                continue;
            }
            Q.push(hoba + k);
        }
        int cnt = 0;
        erep(i, 1, sz(A)) if (visited[i]) cnt++;
        return ((cnt == sz(A)) ? "POSSIBLE" : "IMPOSSIBLE");
    }
};