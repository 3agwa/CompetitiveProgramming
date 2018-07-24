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
int arr[N], cnt[N], block, res[N];
vector<pair<int, pii>> query;
int n, q;

bool cmp(pair<int, pii> &a, pair<int, pii> &b)
{
	if (a.first / block != b.first / block)
		return a.first / block < b.first / block;
	return a.second.first < b.second.first;
}

inline void remove(int idx, int &ans)
{
	if (arr[idx] > n)
		return;
	if (cnt[arr[idx]] == arr[idx])
		ans--;
	cnt[arr[idx]]--;
	if (cnt[arr[idx]] == arr[idx])
		ans++;
}

inline void add(int idx, int & ans)
{
	if (arr[idx] > n)
		return;
	if (cnt[arr[idx]] == arr[idx])
		ans--;
	cnt[arr[idx]]++;
	if (cnt[arr[idx]] == arr[idx])
		ans++;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;
	block = sqrt(q) + 1;
	query.resize(q);
	rep(i, 0, n)
		cin >> arr[i];
	rep(i, 0, q)
	{
		int l, r;
		cin >> l >> r;
		l--, r--;
		query[i] = mp(l, r, i);
	}
	sort(all(query), cmp);
	int moL = 0, moR = -1, ans = 0;
	rep(i, 0, q)
	{
		int l = query[i].first, r = query[i].second.first, idx =
				query[i].second.second;

		while (moL < l) remove(moL++, ans);
		while (moL > l) add(--moL, ans);
		while (moR < r) add(++moR, ans);
		while (moR > r) remove(moR--, ans);

		res[idx] = ans;
	}

	rep(i, 0, q) cout << res[i] << '\n';

	return 0;
}
