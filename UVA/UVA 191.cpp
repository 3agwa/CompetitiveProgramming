/*
    first thing to do is to get the coordinates of all corners of rectangle
    second thing is to check whether the line is inside the rectangle or not
    if not, check if the line intersects with any of the 4 sides of the rectangle
    output answer depending on intersection happened or not

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

double area(PT a, PT b, PT c)
{
    return fabs(0.5*(a.x*(b.y-c.y) + b.x*(c.y - a.y) + c.x*(a.y-b.y)));
}

bool inside(PT a, PT b, vector<PT> vec)
{
    double low_x = INT_MAX, low_y = INT_MAX, high_x = INT_MIN, high_y = INT_MIN;
    rep(i, 0, sz(vec))
    {
        low_x = min(low_x, vec[i].x);
        high_x = max(high_x, vec[i].x);
        low_y = min(low_y, vec[i].y);
        high_y = max(high_y, vec[i].y);
    }
    return ((low_x <= a.x && a.x <= high_x && low_y <= a.y && a.y <= high_y) ||
            (low_x <= b.x && b.x <= high_x && low_y <= b.y && b.y <= high_y));
}

bool intersection(PT a, PT b, PT c, PT d, vector<PT> vec) // 1, 2 - 1, 2
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

int main()
{
    output;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        PT st, en;
        cin >> st >> en;
        vector<PT> vec;
        PT a, b;
        cin >> a >> b;
        vec.push_back(a);
        vec.push_back(b);
        vec.push_back(PT(a.x, b.y));
        vec.push_back(PT(b.x, a.y));
        sort(all(vec));
        if (inside(st, en, vec)) cout << "T\n";
        else
        {
            if (intersection(st, en, vec[0], vec[1], vec) ||
                intersection(st, en, vec[0], vec[2], vec) ||
                intersection(st, en, vec[1], vec[3], vec) ||
                intersection(st, en, vec[2], vec[3], vec))
            {
                cout << "T\n";
            }
            else cout << "F\n";
        }
    }

    return 0;
}
