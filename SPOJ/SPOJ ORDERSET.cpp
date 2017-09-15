/*
      first off, since the values could grow rather large,
      we'll use a map to compress the data and a reverse map as we'll be using it later
      
      for query I, we check if the interval of [val-1, val] has a value or not, if not then we update
      
      for query D, we do the same except we update if there is a value
      
      for query K, we'll lower bound on our BIT and use query as check function
      since we're accumulating, the array is monotonic increasing
      if the value fits, we output the reverse of the index (that's why we needed a reverse map earlier)
      
      for query C, we just print the accumulative sum excluding our value
      
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

vi bit;
int n;

void update(int idx, int val)
{
	while(idx < n+5)
	{
		bit[idx] += val;
		idx += (idx & -idx);
	}
}

int query(int idx)
{
	int ret = 0;

	while(idx > 0)
	{
		ret += bit[idx];
		idx -= (idx & -idx);
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	bit = vi(n+1);
	vi vec(n);
	vector<char> x(n);
	vi y(n);

	rep(i, 0, n) cin >> x[i] >> y[i], vec[i] = y[i];
	sort(all(vec));

	mapii mp;
	mapii rev;
	int t = 2;

	for(auto i : vec)
		if (!mp[i]) rev[t] = i, mp[i] = t++;

	rep(i, 0, n)
	{
		if (x[i] == 'I')
		{
			int hoba = query(mp[y[i]]) - query(mp[y[i]]-1);
			if (!hoba)
			{
				update(mp[y[i]], 1);
			}
		}
		else if (x[i] == 'D')
		{
			int hoba = query(mp[y[i]]) - query(mp[y[i]]-1);
			if (hoba)
			{
				update(mp[y[i]], -1);
			}
		}
		else if (x[i] == 'K')
		{
			int st = 1, en = n, mid, ret = -1;

			while(st <= en)
			{
				mid = (st+en) / 2;

				if (query(mid) < y[i]) st = mid + 1;
				else en = mid - 1, ret = mid;
			}

			if (query(ret) == y[i]) cout << rev[ret] << endl;
			else cout << "invalid\n";
		}
		else
		{
			cout << query(mp[y[i]] - 1) << endl;
		}
	}
	return 0;
}

