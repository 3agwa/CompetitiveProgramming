/*
    sort the elements according to their positions
    run ternary search on starting position of the cars
    return minimum distance
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

class ConnectingCars
{
public:

    vector< pair< ll, ll > > vec;
    ll solve(ll mid)
    {
        ll sum = 0;
        rep(i, 0, sz(vec))
        {
            sum += abs(mid - vec[i].first);
            mid += vec[i].second;
        }
        return sum;
    }

    long long minimizeCost(vector <int> positions, vector <int> lengths)
    {
        vec.clear();
        rep(i, 0, sz(positions)) vec.push_back({positions[i], lengths[i]});
        sort(all(vec));
        ll st = vec[0].first-1, en = vec.back().first + 1;
        while(st < en)
        {
            ll mid = (st+en)/2;
            if (solve(mid) <= solve(mid+1))
            {
                en = mid;
            }
            else st = mid + 1;
        }
        return solve(st);
    }
};
