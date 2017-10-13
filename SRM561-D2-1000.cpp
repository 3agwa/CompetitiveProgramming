/*
 *  for each road, we'll calculate the expected number of times the each city passes by it
 *  expected sum is the sum of expectations for each road
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

class FoxAndTouristFamilies
{
public:
	vi A;
	vi B;
	vi F;

	int dfs(int v, int p, int road, bool yay)
	{
		int ret = yay;

		rep(i, 0, sz(A))
		{
			if ((A[i] == v) || (B[i] == v))
			{
				int child = (A[i] == v ? B[i] : A[i]);
				if (child != p)
					ret += dfs(child, v, road, yay || (i == road));
			}
		}

		return ret;
	}

	double expectedLength(vector<int> A, vector<int> B, vector<int> f)
	{
		this->A = A;
		this->B = B;
		this->F = F;

		double ret = 0., n = sz(A);

		rep(i, 0, n)
		{
			double p = 1.;

			rep(j, 0, sz(f))
			{
				p *= (dfs(f[j], -1, i, 0) / n);
			}
			ret += p;
		}

		return ret;
	}
};

