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
#define rep(i, x, n) for(int i = x; i<(ll)(n); i++)
#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pi  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-9)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

const int N = 1e5 + 5;
int n;
int before[N], after[N], mn[N][18], mx[N][18], lg[N], arr[N];

void build()
{
	erep(j, 1, 17)
		for (int i = 0; i <= n - (1 << j); i++)
		{
			mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
			mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
		}
}

int qmin(int l, int r)
{
	if (l > r)
		swap(l, r);
	int j = lg[r - l + 1];

	if (mn[l][j] <= mn[r - (1 << j) + 1][j])
		return mn[l][j];
	return mn[r - (1 << j) + 1][j];
}

int qmax(int l, int r)
{
	if (l > r)
		swap(l, r);
	int j = lg[r - l + 1];

	if (mx[l][j] >= mx[r - (1 << j) + 1][j])
		return mx[l][j];
	return mx[r - (1 << j) + 1][j];
}

int af(int i)
{
	int st = i + 1, en = n - 1, mid, ret = -1;

	while (st <= en)
	{
		mid = (st + en) / 2;
		if (qmax(i + 1, mid) > arr[i])
			en = mid - 1, ret = mid;
		else
			st = mid + 1;
	}

	return ret;
}

int bf(int i)
{
	int st = 0, en = i - 1, mid, ret = -1;

	while (st <= en)
	{
		mid = (st + en) / 2;
		if (qmax(mid, i - 1) > arr[i])
			st = mid + 1, ret = mid;
		else
			en = mid - 1;
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	rep(i, 0, N)
		lg[i] = log2(i);

	while (cin >> n)
	{
		reset(before, -1);
		reset(after, -1);
		reset(mx, 0);
		rep(i, 0, N)
			rep(j, 0, 18)
				mn[i][j] = 1e9;
		rep(i, 0, n)
			cin >> arr[i], mn[i][0] = arr[i], mx[i][0] = arr[i];
		build();

		rep(i, 0, n)
		{
			before[i] = bf(i);
			after[i] = af(i);
		}

		vi vec;

		rep(i, 0, n)
		{
			if (before[i] == -1 && after[i] == -1)
				vec.push_back(i + 1);
			else if (before[i] == -1)
			{
				if (arr[i] - qmin(i, after[i]) >= 150000)
					vec.push_back(i + 1);
			}
			else if (after[i] == -1)
			{
				if (arr[i] - qmin(before[i], i) >= 150000)
					vec.push_back(i + 1);
			}
			else
			{
				int mx = max(qmin(i, after[i]), qmin(before[i], i));
				if (arr[i] - mx >= 150000)
					vec.push_back(i + 1);
			}
		}

		rep(i, 0, sz(vec))
		{
			if (i)
				cout << " ";
			cout << vec[i];
		}
		cout << endl;
	}

	return 0;
}
