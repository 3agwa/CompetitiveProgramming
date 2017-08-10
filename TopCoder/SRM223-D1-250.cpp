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

class QuizShow
{
public:
    int wager(vector <int> scores, int wager1, int wager2)
    {
        int ret = 0, best = 0;
        erep(i, 0, scores[0])
        {
            int odds = 0;
            for(int a = -1; a <= 1; a+=2)
            {
                for(int b = -1; b <= 1; b+=2)
                {
                    for(int c = -1; c <= 1; c+=2)
                    {
                        int f = a*i + scores[0], s = b*wager1 + scores[1], t = c*wager2 + scores[2];
                        if (f > s && f > t) odds++;
                        if (odds > best)
                        {
                            ret = i;
                            best = odds;
                        }
                    }
                }
            }
        }
        return ret;
    }
};
