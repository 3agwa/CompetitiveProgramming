/*
    for each string, get the smallest lexicographical one ans add it to the map
    this will save us a lot of insertions and time
    "solve" transfroms the string as required in the problem
    "fix" gets the lexicographically smallest string among the rotations
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
#define eps (1e-6)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}


class CircleBugs
{
public:

    deque<char> solve(deque<char> dq)
    {
        deque<char> ret;
        rep(i, 0, sz(dq))
        {
            char c = dq[i], d = dq[(i+1)%sz(dq)];
            if (c == d) ret.push_back('R');
            else ret.push_back('G');
        }
        return ret;
    }

    deque<char> fix(deque<char> dq)
    {
        deque<char> ret;
        ret = dq;
        rep(i, 0, sz(dq))
        {
            dq.push_front(dq.back());
            dq.pop_back();
            if (dq < ret) ret = dq;
        }
        return ret;
    }

    int cycleLength(string formation)
    {
        deque<char> dq;
        rep(i, 0, sz(formation)) dq.push_back(formation[i]);
        queue< pair< deque<char>, int > > Q;
        map< deque<char>, int > mp;

        dq = fix(dq);


        Q.push({dq, 1});

        while(!Q.empty())
        {
            deque<char> x = Q.front().first;
            int level = Q.front().second;
            Q.pop();
            if (mp[x]) return level - mp[x];
            mp[x] = level;

            x = solve(x);
            x = fix(x);
            Q.push({x, level+1});
        }
    }
};
