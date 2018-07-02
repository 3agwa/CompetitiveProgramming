/*
 *  This problem could be solved using persistent segment tree
 *  Since the operations are equivalent to turn on, turn off and flip, we could use bitset inside our node
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<vector<int> > vvi;
typedef vector<pii> vii;
typedef vector<vector<pii> > vvii;
typedef long double ld;
typedef map<int, int> mapii;
typedef map<string, int> mapsi;

#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pi  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) { x, {y, z} }

const int N = 1e5 + 5;

int n, m, arr[N], q;

struct shelf
{
	bitset<1024> bs;
	int cnt = 0;
	// el X shayla el value beta3 el change eli haye7sal
	int on(int idx)
	{
		int x = 1 - bs[idx];
		cnt += x;
		bs[idx] = 1;
		return x;
	}

	int off(int idx)
	{
		int x = -bs[idx];
		cnt += x;
		bs[idx] = 0;
		return x;
	}

	int flip()
	{
		int x = (m - cnt) - cnt;
		cnt = m - cnt;
		bs.flip();
		return x;
	}
};

struct node
{
	shelf x;
	int sum = 1;
	node * l = 0;
	node * r = 0;

	node()
	{

	}

	node(node* old)
	{
		*this = *old;
	}

	void merge()
	{
		sum = 1;
		sum += (l ? l->sum : 0);
		sum += (r ? r->sum : 0);
	}
};

int qt, qi, qj, idx;

node* roots[N];

void get(node *curr)
{
	int ret = 0;
	if (qt == 1)
		ret = curr->x.on(qj);
	else if (qt == 2)
		ret = curr->x.off(qj);
	else
		ret = curr->x.flip();
	arr[idx] = arr[idx - 1] + ret;
}

node* build(int st, int en)
{
	if (st > en)
		return nullptr;
	if (st == en)
		return new node();

	int mid = (st + en) / 2;

	auto p = new node();
	p->l = build(st, mid);
	p->r = build(mid + 1, en);
	p->merge();
	return p;
}

node* update(int idx, node *p)
{
	int ls = p->l ? p->l->sum : 0;
	auto temp = new node(p);
	if (idx == ls)
	{
		get(temp);
	}
	else if (idx < ls)
		temp->l = update(idx, temp->l);
	else
		temp->r = update(idx - ls - 1, temp->r);
	return temp;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> q;

	roots[0] = build(0, n);

	erep(i, 1, q)
	{
		idx = i;
		cin >> qt >> qi;
		if (qt <= 2) cin >> qj;
		if (qt == 4)
		{
			arr[idx] = arr[qi];
			roots[idx] = roots[qi];
		}
		else
			roots[idx] = update(qi, roots[idx-1]);

		cout << arr[idx] << endl;
	}

	return 0;
}
