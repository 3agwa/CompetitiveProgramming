/*
    check if there are more that 1 occurance of the sequence, if so check which elements don't fit
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


class ColorfulCards
{
public:
    bool primes[1002];
    void sieve(int n)
    {
        reset(primes, 0);
        vb visited(n+1);
        visited[0] = visited[1] = true;
        for(int i = 2; i*i <= n; i++)
        {
            if (!visited[i])
            {
                for(int j = 2*i; j<=n; j+=i) visited[j] = true;
            }
        }
        erep(i, 1, n) if (!visited[i]) primes[i] = true;
    }

    string x;
    vi ret;
    void solve(int st, int en)
    {
        int pos = 0;
        vi vec;
        erep(i, st, en)
        {
            if (x[pos] == 'R' && primes[i]) vec.push_back(i), pos++;
            else if (x[pos] == 'B' && !primes[i]) vec.push_back(i), pos++;
            if (pos == sz(x)) break;
        }

        if (sz(vec) == sz(x))
        {
            rep(i, 0, sz(ret))
            {
                if (!ret[i]) ret[i] = vec[i];
                else if (vec[i] != ret[i]) ret[i] = -1;
            }
        }

        deque<int> dq;
        pos = sz(x)-1;
        for(int i = en; i>=st; i--)
        {
            if (x[pos] == 'R' && primes[i]) dq.push_front(i), pos--;
            else if (x[pos] == 'B' && !primes[i]) dq.push_front(i), pos--;
            if (pos == -1) break;
        }
        if (sz(dq) == sz(x))
        {
            rep(i, 0, sz(ret))
            {
                if (!ret[i]) ret[i] = dq[i];
                else if (dq[i] != ret[i]) ret[i] = -1;
            }
        }
    }

    vector <int> theCards(int N, string colors)
    {
        sieve(N);
        x = colors;
        ret.clear();
        rep(i, 0, sz(colors)) ret.push_back(0);

        solve(1, N);

        return ret;
    }
};
