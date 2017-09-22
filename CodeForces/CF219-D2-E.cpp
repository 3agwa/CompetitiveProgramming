/*
 *  we'll maintain a set containing the rank, solution and rightmost position
 *  for a query of type 1, we update the new position, add 2 new intervals and remove the first one (duo to splitting the interval)
 *  for a query of type 2, we reverse the above operation, we merge the 2 intervals into 1 and remove those 2, and add the new interval
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

set< pair<int, pii> > st;

int n, q;

int leftt[200005], rightt[200005], id[1000005];

pair<int, pii> hoba(int l, int r)
{
	if (!l && r == n + 1) return mp(1e9, 1, n + 1);
	if (!l) return mp(-r + 1, 1, r);
	if (r == n + 1) return mp(- n + l, n, n + 1);
	return mp((l-r)/2, (l+r)/2, r);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;

	leftt[n+1] = 0, rightt[0] = n+1;

	st.insert(hoba(0, n + 1));

	while(q--)
	{
		int a, b;
		cin >> a >> b;

		if (a == 1)
		{
			pii temp = st.begin()->second;
			st.erase(st.begin());

			int idx = temp.first;
			int r = temp.second;
			int l = leftt[r];

			id[b] = idx;
			cout << idx << endl;

			leftt[idx] = l, rightt[idx] = r; // update the range for the new point
			leftt[r] = idx, rightt[l] = idx; // update the range for both l, r

			st.insert(hoba(l, idx));	   // insert the leftt interval
			st.insert(hoba(idx, r));  	   // insert the rightt interval
		}
		else
		{
			int idx = id[b], l = leftt[idx], r = rightt[idx];

			leftt[r] = l, rightt[l] = r; 	   // merge the 2 intervals together

			st.erase(hoba(l, idx));	       // remove the leftt interval from the set
			st.erase(hoba(idx, r));        // remove the rightt interval from the set
			st.insert(hoba(l, r));         // add the new merged interval
		}
	}
	return 0;
}
