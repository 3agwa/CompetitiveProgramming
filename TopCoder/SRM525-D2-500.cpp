/*
    try to form a rectangle with K coins
    then calculate the minimum # of steps 
    needed to get rid of the extra rows/cols 
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
#define eps (1e-9)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {{x, y}, z}

class DropCoins
{
public:
    int getMinimum(vector <string> board, int K)
    {
        int w = sz(board), h = sz(board[0]);
        int ret = INT_MAX;

        rep(i, 0, w)
        {
            rep(j, i, w)
            {
                rep(k, 0, h)
                {
                    int current = 0;
                    rep(l, k, h)
                    {
                        erep(m, i, j)
                        {
                            if (board[m][l] == 'o')
                                current++;
                        }
                        if (current == K)
                        {
                            ret = min(ret, i + w - j - 1 + min(i, w - j - 1) + k + h - l - 1 + min(k, h - l - 1));
                        }
                    }
                }
            }
        }
        if (ret == INT_MAX) return -1;
        return ret;
    }
};
