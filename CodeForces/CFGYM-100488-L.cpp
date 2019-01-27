/*
 *  This problem could be solved using Treap or deque, my solution includes the deque approach
 *  we'll maintain 3 deques referring to the left/center/right parts
 *  left [1, L-1], center [L, R], right [R + 1, N]
 *  we'll maintain a boolean INV that indicates whether the range is inversed or not
 *  if the range is normal, we can simulate the queries by pushing and popping from the corresponding deques
 *  if the range is inversed we do the same thing but chance the pop/push (front/back since the range is inversed)
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int> > vvi;
typedef pair<int, int> pii;

#define erep(i, x, n) for (auto i = x; i<=(ll)(n); i++)
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define mod(n, m) (((n%m) + m)%m)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	deque<char> dl, dr, dc;

	int n, l, r;
	cin >> n >> l >> r;
	l--, r--;
	string x;
	cin >> x;

	rep(i, 0, l)
		dl.push_back(x[i]);
	erep(i, l, r)
		dc.push_back(x[i]);
	rep(i, r + 1, n)
		dr.push_back(x[i]);

	int q;
	cin >> q;
	bool inv = false;
	while (q--)
	{
		char c;
		cin >> c;
		if (c == 'R')
			inv ^= 1;
		else if (c == 'Q')
		{
			cin >> c;
			if (inv)
			{
				if (c == 'L')
					cout << dc.back();
				else
					cout << dc.front();
			}
			else
			{
				if (c == 'L')
					cout << dc.front();
				else
					cout << dc.back();
			}
		}
		else
		{
			char a, b;
			cin >> a >> b;

			if (!inv)
			{
				if (a == 'L')
				{
					if (b == 'L')
					{
						dc.push_front(dl.back());
						dl.pop_back();
					}
					else
					{
						dl.push_back(dc.front());
						dc.pop_front();
					}
				}
				else
				{
					if (b == 'L')
					{
						dr.push_front(dc.back());
						dc.pop_back();
					}
					else
					{
						dc.push_back(dr.front());
						dr.pop_front();
					}
				}
			}
			else
			{
				if (a == 'L')
				{
					if (b == 'L')
					{
						dc.push_back(dl.back());
						dl.pop_back();
					}
					else
					{
						dl.push_back(dc.back());
						dc.pop_back();
					}
				}
				else
				{
					if (b == 'L')
					{
						dr.push_front(dc.front());
						dc.pop_front();
					}
					else
					{
						dc.push_front(dr.front());
						dr.pop_front();
					}
				}
			}
		}
	}

	return 0;
}
