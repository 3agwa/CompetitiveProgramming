/*
 *  we could conclude which part does our current index belong to
 *  if it belongs to one of the parts in the current level, return its character
 *  else recurse to the lower level and repeat those steps
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

string x = "What are you doing at the end of the world? Are you busy? Will you save us?";
string a = "What are you doing while sending \"";
string b = "\"? Are you busy? Will you send \"";
string c = "\"?";

ull arr[100001];

char solve(int n, ull k)
{
	if (!n)
	{
		if (k < sz(x))
			return x[k];
		return '.';
	}

	if (k >= arr[n])
		return '.';

	if (!arr[n])
		return solve(n-1, k - 34);

	// first part
	if (k < sz(a))
		return a[k];

	// last part
	if (arr[n] - 2 <= k)
		return c[k - arr[n] + 2];


	ull l1 = sz(a) + arr[n-1], r1 = l1 + sz(b);

	//cerr << n << " " << k << " " << l1 << " " << r1 << endl;
	if (l1 <= k && k < r1)
		return b[k - l1];

	if (k >= r1)
		return solve(n-1, k - r1);

	return solve(n-1, k - sz(a));
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	arr[0] = sz(x);
	rep(i, 1, 100001)
	{
		arr[i] = sz(a) + arr[i-1] + sz(b) + arr[i-1] + sz(c);
	}

	string ret = "";
	int q;
	cin >> q;
	while(q--)
	{
		int n; ll k;
		cin >> n >> k;
		ret += solve(n, k-1);
	}
	cout << ret << endl;

	return 0;
}
