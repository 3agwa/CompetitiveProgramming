/*
    for each 2 consecutive lines, get the points of intersection between that line and the circle
    get the projection of each of those lines on line AB
    if the projected point is the same as original point, then it lies on AB line segment
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
#define mp(x, y, z) {{x, y}, z}


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
    return p.x*q.x+p.y*q.y;
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

int dcmp(double a, double b)
{
    return fabs(a-b) <= eps ? 0 : a<b ? -1 : 1;
}

vector<PT> intersectLineCircle(PT p0, PT p1, PT C, double r)
{
    double a = dot(p1-p0, p1-p0), b = 2*dot(p1-p0, p0-C),
           c = dot(p0-C, p0-C) - r*r;
    double f = b*b - 4*a*c;

    vector<PT> v;
    if( dcmp(f, 0) >= 0)
    {
        if( dcmp(f, 0) == 0)	f = 0;
        double t1 =(-b + sqrt(f))/(2*a);
        double t2 =(-b - sqrt(f))/(2*a);
        v.push_back( p0 + (p1-p0)*t1 );
        if( dcmp(f, 0) != 0)	v.push_back( p0 + (p1-p0)*t2 );
    }
    return v;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while(tc--)
    {
        PT c;
        ll r;
        cin >> c >> r;
        vector< PT > vec(3);
        rep(i, 0, 3) cin >> vec[i];
        bool ret = false;
        rep(i, 0, 3)
        {
            PT a = vec[i], b = vec[(i+1)%3];
            vector< PT > temp = intersectLineCircle(a, b, c, r);
            rep(j, 0, sz(temp))
            {
                PT x = ProjectPointSegment(a, b, temp[j]);
                ret |= (dcmp(x.x, temp[j].x) == 0 && dcmp(x.y, temp[j].y) == 0);
            }
        }
        if (ret) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
