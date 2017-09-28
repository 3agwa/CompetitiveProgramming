/*
 * since S is <= 20, we can try all different combinations using bitmasking, add the values in a set and get the set's MEX
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

class NumbersChallenge
{
public:
	int MinNumber(vector<int> S)
	{
		int n = sz(S);
		
		set<ll> st;
		
		rep(i, 0, (1<<n))
		{
			ll sum = 0;
			rep(j, 0, n)
			{
				if (i & (1<<j)) sum += S[j];
			}
			if (!sum) continue;
			st.insert(sum);
		}
		
		for(int i = 1; ; i++)
		{
			if (!st.count(i))
				return i;
		}
	}
};

