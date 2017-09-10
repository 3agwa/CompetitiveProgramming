/*
    if any number is duplicated, we return an empty vector
    else we need to get the sum of the given numbers, and the expected sum if this range
    if they're the same, we should return the min-1 "if min != 1" and max+1
    else we need to check if it's only 1 number missing, if so return it, elsewise return an empty vector
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
#define eps (1e-9)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

ll summ(ll n)
{
	return (n*(n+1)) / 2;
}

class ConsecutiveNumbers
{
public:
	vector<int> missingNumber(vector<int> numbers)
	{
		ll mn = INT_MAX, mx = 0;
		sort(all(numbers));
		ll sum = 0;
		mapii mp;
		vi vec;
		rep(i, 0, sz(numbers))
		{
			if (!mp[numbers[i]]) mp[numbers[i]] = true, vec.push_back(numbers[i]);
			else
			{
				vi hoba;
				return hoba;
			}
		}
		rep(i, 0, sz(vec))
		{
			mx = max(mx, 1LL * vec[i]), mn = min(mn, 1LL * vec[i]), sum += vec[i];
		}
		ll supposed = summ(mx) - summ(mn-1);
		vi ret;
		if (supposed == sum)
		{
			if (mn != 1) ret.push_back(mn-1);
			ret.push_back(mx+1);
		}
		else
		{
			ll lololey = supposed - sum;
			if (mn <= lololey && lololey <= mx && !binary_search(all(numbers), lololey))
				ret.push_back(lololey);
		}
		return ret;
	}
};

