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
//#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pie  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

class EllysRoomAssignmentsDiv1
{
public:
	double getAverage(vector<string> ratings)
	{
		vector<pair<double, int>> vec;
		int rooms, n;
		string x = "";
		rep(i, 0, sz(ratings))
			x += ratings[i];
		stringstream ss(x);
		int in;
		while (ss >> in)
			vec.push_back(
			{ in, 0 });
		n = sz(vec), rooms = (n + 19) / 20;
		double ret = 0;
		int idx = 0;
		rep(i, 0, n)
			vec[i].second = i;
		sort(vec.rbegin(), vec.rend());
		vd grp;

		for (int i = 0; i < n; i += rooms)
		{
			double cnt = 0;
			bool yay = false;
			rep(j, i, min(n, i + rooms))
			{
				if (!vec[j].second)
				{
					idx = j;
					cnt = vec[j].first;
					grp.push_back(cnt);
					yay = true;
					break;
				}
			}
			if (!yay)
			{
				rep(j, i, min(n, i + rooms)) cnt += vec[j].first;
				grp.push_back(cnt / ( min(n, i + rooms) - i));
			}
		}

		rep(i, 0, sz(grp)) ret += grp[i];

		double temp = n / rooms;
		if (n%rooms == 0) return ret / temp;
		else if (idx / rooms == temp) return ret / (temp + 1.);
		else
		{
			double p = (n % rooms) / (rooms*1.);
			return p * (ret / (temp + 1.)) + (1. - p) * (ret - grp[temp]) / temp;
		}


		return ret;
	}
};
