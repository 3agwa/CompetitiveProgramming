/*
 *  we'll expand our array into 2 versions of itself, this allows us to get a correct cyclic shift
 *  after expansion, accumulate the array, we'll find the minimum element in the current range
 *  and subtract an offset from this minimum, this value will indicate whether or not there is an element <= 0 in the range
 *  the offset will be the subtraction of the first i-1 elements which have affected the current range's accumulation
 *  for the current N elements starting from the i-th position, we'll use a segment tree to find the minimum value in the given range
 *  increment our solution if  mn + offset >= 0
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

const int mx = (int) (2e6 + 5);

int tree[4*mx], arr[mx];

void build(int node, int st, int en)
{
	if (st > en) return;

	if (st == en)
	{
		tree[node] = arr[st];
		return;
	}

	int mid = (st+en)/2;

	build(2*node, st, mid);
	build(2*node + 1, mid + 1, en);

	tree[node] = min(tree[2*node], tree[2*node + 1]);
}

int query(int node, int st, int en, int shemal, int yemeen)
{
	if (st > en || st > yemeen || en < shemal) return 2e9 + 5;

	if (shemal <= st && en <= yemeen)
		return tree[node];

	int mid = (st+en)/2;

	return min(query(2*node, st, mid, shemal, yemeen), query(2*node + 1, mid + 1, en, shemal, yemeen));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    while(cin >> n && n)
    {
    	vi vec;
    	rep(i, 0, n) cin >> arr[i], vec.push_back(arr[i]);
    	rep(i, n, 2*n) arr[i] = arr[i-n];

    	rep(i, 1, 2*n)
    		arr[i] += arr[i-1];

    	build(1, 0, 2*n - 1);

    	int offset = 0, ret = 0;

    	rep(i, 0, n)
    	{
    		int mn = query(1, 0, 2*n - 1, i, i + n - 1);
    		ret += (mn + offset >= 0);

    		offset -= vec[i];
    	}
    	cout << ret << endl;
    }

    return 0;
}
