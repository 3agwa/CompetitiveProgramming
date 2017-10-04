/*
 *  if we have N objects to choose from, then on the first pick we have N, second pick we have N-1 and so on
 *  that being said, probability of picking the correct number is (n-k)/n
 *  the cost would be the inverse of that which is n / (n-k) for each k
 *  we'll simplify the fraction each time to avoid overflow 
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

int len(ll n)
{
	int cnt = 0;
	while (n)
	{
		cnt++;
		n /= 10;
	}
	return cnt;
}
class Frac
{
public:
	long long a, b;
	Frac()
	{
		a = 0, b = 1;
	}
	Frac(long long x, long long y)
	{
		a = x, b = y;
		reduce();
	}
	Frac operator+(const Frac &y)
	{
		long long ta, tb;
		tb = this->b / gcd(this->b, y.b) * y.b;
		ta = this->a * (tb / this->b) + y.a * (tb / y.b);
		Frac z(ta, tb);
		return z;
	}
	Frac operator-(const Frac &y)
	{
		long long ta, tb;
		tb = this->b / gcd(this->b, y.b) * y.b;
		ta = this->a * (tb / this->b) - y.a * (tb / y.b);
		Frac z(ta, tb);
		return z;
	}
	Frac operator*(const Frac &y)
	{
		long long tx, ty, tz, tw, g;
		tx = this->a, ty = y.b;
		g = gcd(tx, ty), tx /= g, ty /= g;
		tz = this->b, tw = y.a;
		g = gcd(tz, tw), tz /= g, tw /= g;
		Frac z(tx * tw, ty * tz);
		return z;
	}
	Frac operator/(const Frac &y)
	{
		long long tx, ty, tz, tw, g;
		tx = this->a, ty = y.a;
		g = gcd(tx, ty), tx /= g, ty /= g;
		tz = this->b, tw = y.b;
		g = gcd(tz, tw), tz /= g, tw /= g;
		Frac z(tx * tw, ty * tz);
		return z;
	}
	void print()
	{
		if (b == 1)
		{
			cout << a << endl;
		}
		else
		{
			ll o = a / b;
			ll d = a % b;
			int pad = len(o);
			int dag = len(b);
			if (o)
			{
				erep(i, 0, pad)
					cout << " ";

				cout << d << endl;
				cout << o << " ";

				rep(i, 0, dag)
					cout << "-";

				cout << endl;

				erep(i, 0, pad)
					cout << " ";
				cout << b << endl;
			}
			else
			{
				cout << d << endl;
				rep(i, 0, dag)
					cout << " ";
				cout << b << endl;
			}
		}
	}
private:
	static long long gcd(long long x, long long y)
	{
		if (!y)
			return x;
		if (x < 0)
			x *= -1;
		if (y < 0)
			y *= -1;
		long long t;
		while (x % y)
			t = x, x = y, y = t % y;
		return y;
	}
	void reduce()
	{
		long long g = gcd(a, b);
		a /= g, b /= g;
		if (b < 0)
			a *= -1, b *= -1;
	}
};
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	while(cin >> n)
	{
		Frac frac = {0, 1};


		rep(i, 0, n)
		{
			frac = frac + Frac(n, n-i);
		}

		frac.print();
	}
	return 0;
}
