/*
    for each point, subtract the value of "home" from it, so we can translate about origin
    we try all configurations of rotations and check whether the 4 new points for a non-empty square or not
    we need to add the home value we subtracted earlier as we're (supposedly) rotating about the home, not the origin
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

PT arr[101][4], home[101][4];

bool square(PT a, PT b, PT c, PT d)
{
    if (a == b || a == c || a == d || b == a || b == c || b == d || c == a || c == b || c == d || d == a || d == b || d == c) return 0;
    set<int> st;
    st.insert(dist2(a, b));
    st.insert(dist2(a, c));
    st.insert(dist2(a, d));

    st.insert(dist2(b, a));
    st.insert(dist2(b, c));
    st.insert(dist2(b, d));

    st.insert(dist2(c, b));
    st.insert(dist2(c, a));
    st.insert(dist2(c, d));

    st.insert(dist2(d, b));
    st.insert(dist2(d, c));
    st.insert(dist2(d, a));
    return (sz(st) <= 2);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    rep(i, 0, n)
    {
        rep(j, 0, 4)
        {
            cin >> arr[i][j] >> home[i][j];
        }
    }
    rep(i, 0, n)
    {
        int mn = INT_MAX;
        PT a(arr[i][0]-home[i][0]);
        PT b(arr[i][1]-home[i][1]);
        PT c(arr[i][2]-home[i][2]);
        PT d(arr[i][3]-home[i][3]);

        rep(j, 0, 5)
        {
            if (j) a = RotateCCW90(a);
            rep(k, 0, 5)
            {
                if (k) b = RotateCCW90(b);
                rep(l, 0, 5)
                {
                    if (l) c = RotateCCW90(c);
                    rep(m, 0, 5)
                    {
                        if (m) d = RotateCCW90(d);
                        if (square(a + home[i][0], b + home[i][1], c + home[i][2], d + home[i][3])) mn = min(mn, j+k+l+m);
                    }
                }
            }
        }

        if (mn == INT_MAX) cout << -1 << endl;
        else cout << mn << endl;
    }

    return 0;
}
