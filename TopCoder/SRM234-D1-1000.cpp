/*
    we'll solve this problem starting from the back
    for each index, we want to know the number of indices less that our current number 
    hence, we could do that using accumulation
    
    only problem is that the numbers are quite large, so we'll compress the numbers 
    to fit a maximum 1e5 numbers
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
#define mp(x, y, z) {x, {y, z}}

const int MX = 100005;
ll mod = ((1LL << 31) - 1);

ll arr[MX], tree[MX];

void update(int idx, int val)
{
	while(idx < MX)
	{
		tree[idx] += val;
		idx += (idx & -idx);
	}
}

ll query(int idx)
{
	ll ret = 0;

	while(idx > 0)
	{
		ret += tree[idx];
		idx -= (idx & -idx);
	}

	return ret;
}

class HowUnsorted
{
public:
	long long howMany(int m, int c, int n)
	{
		vll vec;
		vec.push_back(1);
		arr[1] = 1;
		erep(i, 2, n)
		{
			arr[i] = ((m * 1LL) * arr[i - 1] + c * 1LL) % mod;
			vec.push_back(arr[i]);
		}

		sort(all(vec));

		map<ll, int> mp;
		int t = 1;

		for(auto i : vec)
		{
			if (!mp[i]) mp[i] = t++;
		}

		ll ret = 0;

		for(int i = n; i>=1; i--)
		{
			ret += query(mp[arr[i]] - 1);
			update(mp[arr[i]], 1);
		}


		return ret;
	}
};
