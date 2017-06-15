/*
	after sorting the input, count for each element the # of times it will appear in the permutations
	memoize over the index and the current element value (before incrementing it)
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

class DiceGames {
public:

    ll memo[35][35];
    int n;
    vi hoba;
    ll solve(int i, int element)
    {
        if (i == n) return 1;
        if (memo[i][element] != -1) return memo[i][element];
        ll ret = 0;
        int temp = element;

        while(element <= hoba[i])
        {
            ret += solve(i+1, element);
            element++;
        }
        return memo[i][temp] = ret;
    }

	long long countFormations(vector <int> sides) {
	    reset(memo, -1);
		n = sz(sides);
        hoba = sides;
        sort(all(hoba));
        ll ret = solve(0, 1);
        return ret;
	}
};
