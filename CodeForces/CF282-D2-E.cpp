/*
    we'll insert the numbers one by one in a trie
    we'll also have a number consisting of the remaining (uncut) xor of numbers
    we'll maximize over the bext solution of curr_uncut ^ (best match in trie)
    for the best match, we need to maximize the output
    hence if the uncut has a 1 in the ith bit, we want to move to a 0 bit (if it exists)
    same goes when the ith bit is 0, we want to move towards a 1 bit (if it exists)
    maximize between all available cuts of the array
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

struct Trie
{
	Trie* child[2];

	Trie()
	{
		reset(child, 0);
	}

	void insert(ll num, int idx)
	{
		if (idx == -1) return;

		bool next = ((num & (1LL << idx)) != 0);
		if (child[next] == 0) child[next] = new Trie();
		child[next]->insert(num, idx - 1);
	}

	ll retrieve(ll num, int idx)
	{
		if (idx == -1) return 0;

		bool next = (num & (1LL << idx));
		next = !next;
		if (!child[next]) next = !next;

		if (next) return child[next]->retrieve(num, idx-1) + (1LL << idx);
		else return child[next]->retrieve(num, idx-1);
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vll arr(n);
	ll l = 0, r = 0;
	rep(i, 0, n) cin >> arr[i], l^=arr[i];

	Trie* root = new Trie();
	ll mx = l;
	root->insert(0, 40);

	rep(i, 0, n)
	{
		l^=arr[i], r^=arr[i];
		root->insert(r, 40);
		mx = max(mx, l ^ root->retrieve(l, 40));
	}

	cout << mx;
	return 0;
}

