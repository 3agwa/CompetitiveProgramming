/*
    for each value, we need to keep track the time when it was inserted or deleted
    hence, we'll maintain a segment tree for each value
    we have to compress the values in order to fit (1e9 --> 1e5)
    
    now for each value, add the time it appears at in an array
    we'll have to introduce a vector of map<int, int> to hold the compressed time for each segment tree
    
    compressing the values is independent on its order, but compressing the time differs
    we'll have to sort the vector carrying all times of the current value to compress it successfully
    
    now for each compressed value, tree size would be vec[new_val].size*4 
    where new_val is the compressed value, and the size of the vector represents the number of "times" in the vector
    
    after compression, update/query on the input in the same order after getting the compressed values
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

vvi tree;

void update(int node, int st, int en, int pos, int val, int idx)
{
	if (st > en || st > pos || en < pos) return;

	if (st == en)
	{
		tree[idx][node] += val;
		return;
	}

	int mid = (st+en)/2;

	update(2*node, st, mid, pos, val, idx);
	update(2*node + 1, mid + 1, en, pos, val, idx);

	tree[idx][node] = tree[idx][2*node] + tree[idx][2*node + 1];
}

int query(int node, int st, int en, int shemal, int yemeen, int idx)
{
	if (st > en || st > yemeen || en < shemal) return 0;

	if (shemal <= st && en <= yemeen) return tree[idx][node];

	int mid = (st+en)/2;

	return query(2*node, st, mid, shemal, yemeen, idx) + query(2*node + 1, mid + 1, en, shemal, yemeen, idx);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, t = 1;
	cin >> n;
	tree = vvi(n+5);
	vi op(n), time(n), val(n);
	vvi vec(n);
	mapii c;
	rep(i, 0, n)
	{
		cin >> op[i] >> time[i] >> val[i];
		if (!c[val[i]]) c[val[i]] = t++; // compress value
	}
	rep(i, 0, n) vec[c[val[i]]].push_back(time[i]); // for each value, get the time it appears at
	vector<mapii> compress(n); // compression map for each tree
	rep(i, 1, t)
	{
		int x = sz(vec[i]);
		tree[i] = vi(4*x);
		vi temp = vec[i];
		sort(all(temp)); // sort time to compress
		int y = 1;
		rep(j, 0, sz(temp))
		{
			if (!compress[i][temp[j]]) compress[i][temp[j]] = y++;
		}
	}

	rep(i, 0, n)
	{
		int idx = c[val[i]], tim = compress[idx][time[i]];
		//cerr << i << " " << idx << " " << tim << endl;
		if (op[i] == 1)
		{
			update(1, 0, sz(vec[idx]), tim, 1, idx);
		}
		else if (op[i] == 2)
		{
			update(1, 0, sz(vec[idx]), tim, -1, idx);
		}
		else
		{
			cout << query(1, 0, sz(vec[idx]), 0, tim ,idx) << endl;
		}
	}

	return 0;
}

