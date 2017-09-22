/*
 *  for a given number, we want to match it with m - 1 - x, this way we'll reach m - 1 which is the greatest value
 *  but for that to happen we need to make sure that the left hand side matches with the right hand side
 *  hence, we'll get the best match for our left, then we'll get the best match for that (currently right) in our left
 *  add this match to our vector, sort it in descending order and output the value
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

multiset<int, greater<int> > up, down;

int n, m;

int match(bool type, int x)
{
	multiset<int, greater<int> > :: iterator i;
	if (type)
	{
		i = down.lower_bound(m - 1 - x);
		if (i != down.end()) return *i;
		return *down.begin();
	}
	else
	{
		i = up.lower_bound(m - 1 - x);
		if (i != up.end()) return *i;
		return *up.begin();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int x;
	rep(i, 0, n)
	{
		cin >> x;
		up.insert(x);
	}

	rep(i, 0, n)
	{
		cin >> x;
		down.insert(x);
	}


	vi yay;

	while(n--)
	{
		int temp = *up.begin();

		int ta7t = match(1, temp);
		int foo2 = match(0, ta7t);

		yay.push_back((foo2 + ta7t) % m);

		up.erase(up.find(foo2));
		down.erase(down.find(ta7t));
	}

	sort(yay.rbegin(), yay.rend());
	rep(i, 0, sz(yay)) cout << yay[i] << " ";

	return 0;
}
