/*
	
	enumerate all points, each having a unique idx
	connect the points in the same collection
	for all pairs of line segments, check if they intersect at a point or not
	if they intersect at a point, link that point to the collection of the first and the second line, joining them together
	if there is no intersection point, then they might intersect in a segment
	check if there is segment intersection using slopes and check that the points lie inside the line
	if that happens, iterate over all integer points on the slope and add a connection between that point
	and the 2 endpoints of the intersection segment
	finally, run dfs from each idx to count the # of connected components and return the answer

*/
#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define vs vector<string>
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector< vector<int> >
#define mapii map<int, int>
#define rep(i, x, n) for(auto i = x; i<(ll)(n); i++)
#define sz(v) ((int)((v).size()))
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'

using namespace std;


double INF = 1e100;
double EPS = 1e-7;

struct PT
{
    double x, y;
    PT() {}
    PT(double x, double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y)    {}
    PT operator + (const PT &p)  const
    {
        return PT(x+p.x, y+p.y);
    }
    PT operator - (const PT &p)  const
    {
        return PT(x-p.x, y-p.y);
    }
    PT operator * (double c)     const
    {
        return PT(x*c,   y*c  );
    }
    PT operator / (double c)     const
    {
        return PT(x/c,   y/c  );
    }
    bool operator<(const PT &p)  const
    {
        return make_pair(x,y)<make_pair(p.x,p.y);
    }
    bool operator==(const PT &p)  const
    {
        return !(*this < p) && !(p < *this);
    }
};
ostream &operator<<(ostream &os, const PT &p)
{
    return os << "(" << p.x << "," << p.y << ")";
}


bool intersection(PT a, PT b, PT c, PT d) // 1, 2 - 1, 2
{
    double a1 = b.y-a.y, b1 = a.x-b.x, c1 = a1*a.x + b1*a.y;
    double a2 = d.y-c.y, b2 = c.x-d.x, c2 = a2*c.x + b2*c.y;
    double det = a1*b2 - a2*b1;
    if (!det)
    {
        return false;
    }
    double x = (b2*c1 - b1*c2) / det;
    double y = (a1*c2 - a2*c1) / det;
    return (min(a.x, b.x) <= x && x <= max(a.x, b.x) && min(a.y, b.y) <= y && y <= max(a.y, b.y) &&
            min(c.x, d.x) <= x && x <= max(c.x, d.x) && min(c.y, d.y) <= y && y <= max(c.y, d.y));
}

PT intersection2(PT a, PT b, PT c, PT d) // 1, 2 - 1, 2
{
    double a1 = b.y-a.y, b1 = a.x-b.x, c1 = a1*a.x + b1*a.y;
    double a2 = d.y-c.y, b2 = c.x-d.x, c2 = a2*c.x + b2*c.y;
    double det = a1*b2 - a2*b1;
    if (!det) return {-INT_MAX, INT_MAX};
    double x = (b2*c1 - b1*c2) / det;
    double y = (a1*c2 - a2*c1) / det;
    return {x, y};
}

double dot(PT p, PT q)
{
    return p.x*q.x+p.y*q.y;
}

double cross(PT p, PT q)
{
    return p.x*q.y-p.y*q.x;
}

bool isCollinear(PT a, PT b, PT c) {
	return fabs( cross(b-a, c-a) ) < EPS;
}

PT ProjectPointSegment(PT a, PT b, PT c)
{
    double r = dot(c-a, b-a)/dot(b-a,b-a);
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b-a)*r;
}

map< pii, int > idx;
map<int, pii> rev;
vvi node;
bool visited[100100];

void dfs(int v)
{
    visited[v] = true;
    rep(i, 0, sz(node[v])) if (!visited[node[v][i]]) dfs(node[v][i]);
}

bool inside(PT x, PT a, PT b)
{
    double mnx = min(a.x, b.x);
    double mny = min(a.y, b.y);
    double mxx = max(a.x, b.x);
    double mxy = max(a.y, b.y);
    return (mnx <= x.x && x.x <= mxx && mny <= x.y && x.y <= mxy);
}

double area(PT a, PT b, PT c)
{
    return fabs(0.5*(a.x*(b.y-c.y) + b.x*(c.y - a.y) + c.x*(a.y-b.y)));
}

double slope(PT a, PT b)
{
    double x = b.x-a.x, y = b.y-a.y;
    if (!x) return 1e9;
    if (!y) return -1e9;
    return y/x;
}

class PolylineUnion
{
public:
    int countComponents(vector <string> polylines)
    {
        idx.clear();
        rev.clear();
        node = vvi(100100);
        reset(visited, false);
        string ans = "";
        for(int i = 0; i<(int)polylines.size(); i++)
        {
            rep(j, 0, sz(polylines[i]))
            {
                if ((polylines[i][j] >= '0' && polylines[i][j] <= '9') || polylines[i][j] == ',' || polylines[i][j] == '-' || polylines[i][j] == ' ')
                {
                    ans += polylines[i][j];
                }
            }
        }
        string x = "";
        vs vec;
        ans += " ";
        rep(i, 0, sz(ans))
        {
            if (ans[i] == ' ')
            {
                if (!x.empty())
                {
                    x += '-';
                    vec.push_back(x);
                }
                x = "";
            }
            else x += ans[i];

        }
        int cnt = 1;
        vvi temp(sz(vec));
        vector< pair< pii, int > > hoba;
        rep(i, 0, sz(vec))
        {
            int x = 0, y = 0;
            bool comma = false;
            rep(j, 0, sz(vec[i]))
            {
                if (vec[i][j] == '-')
                {
                    if (!idx[ {x, y}])
                    {
                        rev[cnt] = {x, y};
                        temp[i].push_back(cnt);
                        idx[ {x, y}] = cnt++;
                    }
                    else
                    {
                        temp[i].push_back(idx[ {x, y}]);
                    }
                    hoba.push_back({{x, y}, i});
                    x = y = 0;
                    comma = false;
                    continue;
                }
                if (vec[i][j] == ',')
                {
                    comma = true;
                    continue;
                }
                if (!comma) x = x*10 + (vec[i][j]-48);
                else y = y*10 + (vec[i][j]-48);
            }

            rep(j, 0, sz(temp[i])-1)
            {
                node[temp[i][j]].push_back(temp[i][j+1]);
                node[temp[i][j+1]].push_back(temp[i][j]);
            }
        }
        vector< pair<int, int> > hela;

        rep(i, 0, sz(temp))
        {
            rep(j, 0, sz(temp[i])-1)
            {
                rep(k, 0, sz(hoba)-1)
                {
                    if (hoba[k].second == hoba[k+1].second)
                    {
                        pii t1 = rev[temp[i][j]];
                        PT a(t1.first, t1.second);

                        pii t2 = rev[temp[i][j+1]];
                        PT b(t2.first, t2.second);

                        pii t3 = hoba[k].first;
                        PT c(t3.first, t3.second);

                        pii t4 = hoba[k+1].first;
                        PT d(t4.first, t4.second);
                        if (b < a) swap(a, b);
                        if (d < c) swap(d, c);
                        if (intersection(a, b, c, d))
                        {
                            node[temp[i][j]].push_back(idx[t3]);
                            node[idx[t3]].push_back(temp[i][j]);
                        }
                        else if (slope(a, b) == slope(b, c) && slope(b, c) == slope(c, d) &&  (inside(c, a, b) || inside(d, a, b) || inside(a, c, d) || inside(b, c, d)))
                        {

                            node[temp[i][j]].push_back(idx[t3]);
                            node[idx[t3]].push_back(temp[i][j]);
                            int change_y = d.y-a.y, change_x = d.x-a.x;
                            int slope_x, slope_y;
                            if (change_y == 0) slope_x = 1, slope_y = 0;
                            else if (change_x == 0) slope_y = 1, slope_x = 0;
                            else
                            {
                                slope_x = change_x/__gcd(abs(change_x), abs(change_y)), slope_y = change_y/__gcd(abs(change_x), abs(change_y));
                            }
                            int q = a.x + slope_x, w = a.y + slope_y;
                            int m = -INT_MIN, n = INT_MIN;
                            while(true)
                            {
                                if (q == m && w == n) break;
                                m = q, n = w;
                                if (q >= d.x) break;
                                if (slope(a, PT(q, w)) == slope(PT(q, w), d) && inside(PT(q, w), a, d))
                                {
                                    if (!idx[ {q, w}])
                                    {
                                        rev[cnt] = {q, w};
                                        idx[ {q, w}] = cnt++;
                                    }
                                    node[idx[{a.x, a.y}]].push_back(idx[ {q, w}]);
                                    node[idx[{q, w}]].push_back(idx[{a.x, a.y}]);
                                    node[idx[{q, w}]].push_back(idx[{d.x, d.y}]);
                                    node[idx[{d.x, d.y}]].push_back(idx[ {q, w}]);
                                }
                                q += slope_x, w += slope_y;
                            }
                        }
                    }
                }
            }
        } //{{"1,1 1,1-2,2 13,13 14,12-12,14"}}
        int sol = 0;
        rep(i, 1, cnt)
        {
            if (!visited[i])
            {
                sol++;
                dfs(i);
            }
        }
        return sol;
    }
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, vector <string> p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p0[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	PolylineUnion *obj;
	int answer;
	obj = new PolylineUnion();
	clock_t startTime = clock();
	answer = obj->countComponents(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p1;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	vector <string> p0;
	int p1;

	{
	// ----- test 0 -----
	string t0[] = {"0,0-10,10 0,10-10,0"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 1 -----
	string t0[] = {"0,0-10,5 5,0-15,5-10,10-5,5"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 2 -----
	string t0[] = {"1","3,0-5,5 4,0-4,20"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 2;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 3 -----
	string t0[] = {"10,0-10,1-9,2-9,3-8,4 ","8,2-9,2-10,3 ","12,2-11,2-9,1"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 4 -----
	string t0[] = {"0,0-10,0-0,0 20,0-8,0-20,0"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 5 -----
	string t0[] = {"1,1 2,2 3,3 4,4 3,3-4,4"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 3;
	all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 6 -----
	string t0[] = {"10,10-20,10 20,10-15,18 15,18-10,10"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(6, p0, true, p1) && all_right;
	// ------------------
	}

	{
	// ----- test 7 -----
	string t0[] = {"1,1 1,1"};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	p1 = 1;
	all_right = KawigiEdit_RunTest(7, p0, true, p1) && all_right;
	// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
