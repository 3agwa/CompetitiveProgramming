#include <bits/stdc++.h>
/*

    for each point, check the segments which it may fall onto
    then, get Y-coordinate if the point falls onto the segment
    this could be done using slope, since we have slope of segment
    and slope X coordinate of intersection
    then get the closest segment to the point (highest Y <= Point.Y)
    lastly, check which edge the point will fall off from (lowest Y)

*/

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
double dot(PT p, PT q)
{
    return sqrt(p.x*q.x+p.y*q.y);
}
double dist2(PT p, PT q)
{
    return dot(p-q,p-q);
}
double cross(PT p, PT q)
{
    return p.x*q.y-p.y*q.x;
}
PT norm(PT x, double l)
{
    return x * sqrt(l*l / dot(x,x));
}
istream &operator>>(istream &is, PT &p)
{
    return is >> p.x >> p.y;
}
ostream &operator<<(ostream &os, const PT &p)
{
    return os << "(" << p.x << "," << p.y << ")";
}
/*around the origin*/
PT RotateCCW90(PT p)
{
    return PT(-p.y,p.x);
}
PT RotateCW90(PT p)
{
    return PT(p.y,-p.x);
}
PT RotateCCW(PT p, double t)
{
    return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}
// project point c onto line through a and b (assuming a != b)
PT ProjectPointLine(PT a, PT b, PT c)
{
    return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}
// project point c onto line segment through a and b (assuming a != b)
PT ProjectPointSegment(PT a, PT b, PT c)
{
    double r = dot(c-a, b-a)/dot(b-a,b-a);
    if (r < 0) return a;
    if (r > 1) return b;
    return a + (b-a)*r;
}

double slope(PT a, PT b)
{
    return (b.y-a.y) / (b.x-a.x);
}

pair<double, double> get(vector<PT> shemal, vector<PT> yemeen, PT hoba)
{
    vector<PT> vec;
    rep(i, 0, sz(shemal))
    {
        if (shemal[i].x <= hoba.x && hoba.x <= yemeen[i].x) // valid line to fall onto
        {
            ld slope_line = slope(shemal[i], yemeen[i]);
            ld slope_point = hoba.x - shemal[i].x;
            slope_point *= slope_line;
            slope_point += shemal[i].y;
            if (slope_point <= hoba.y)
            {
                if (shemal[i].y <= hoba.y) vec.push_back(shemal[i]);
                if (yemeen[i].y <= hoba.y) vec.push_back(yemeen[i]);
            }
        }
    }
    sort(all(vec));
    if (vec.empty()) return {0, INT_MAX};
    else
    {
        PT temp = vec.back();
        rep(i, 0, sz(shemal))
        {
            if (temp == shemal[i] && yemeen[i].y < shemal[i].y)
            {
                temp = yemeen[i];
            }
            if (temp == yemeen[i] && shemal[i].y < yemeen[i].y)
            {
                temp = shemal[i];
            }
        }
        return {temp.x, temp.y};
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    int tc;
    bool flag = false;
    cin >> tc;
    while(tc--)
    {
        if (flag) cout << endl;
        flag = true;
        int n;
        cin >> n;
        vector<PT> shemal(n);
        vector<PT> yemeen(n);
        rep(i, 0, n)
        {
            cin >> shemal[i] >> yemeen[i];
            if (yemeen[i] < shemal[i]) swap(shemal[i], yemeen[i]);
        }
        cin >> n;
        PT hoba;
        rep(i, 0, n)
        {
            cin >> hoba;
            double height = hoba.y;
            pair<double, double> temp;
            while(true)
            {
                temp = get(shemal, yemeen, hoba);
                if (temp.first == hoba.x && temp.second == hoba.y)
                {
                    cout << hoba.x << endl;
                    break;
                }
                if (temp.second == 0)
                {
                    cout << temp.first << endl;
                    break;
                }
                if (temp.second == INT_MAX)
                {
                    cout << hoba.x << endl;
                    break;
                }
                hoba = PT(temp.first, temp.second);
            }
        }
    }

    return 0;
}
