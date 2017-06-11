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

int tc, n, m, s, indexer;
map< pair< PT, PT >, int > idx;
vector<PT> up, down, island;
mapii mp;
vector< vector< pair< int, double > > > node;

double min_dist(PT a, PT b, PT c, PT d)
{
    double mn1 = dist2(ProjectPointSegment(c, d, a), a);
    double mn2 = dist2(ProjectPointSegment(c, d, b), b);
    double mn3 = dist2(ProjectPointSegment(a, b, c), c);
    double mn4 = dist2(ProjectPointSegment(a, b, d), d);
    return sqrt(min(mn1, min(mn2, min(mn3, mn4))));
}


double dijkstra(int s)
{
    vector<double> dist(indexer, -1);
    set< pair< double, int > > st;
    st.insert({0.0, s});
    while(!st.empty())
    {
        pair<double, int> hoba = *st.begin();
        st.erase(st.begin());
        double cost = hoba.first, idx = hoba.second;
        if (dist[idx] != -1) continue;
        dist[idx] = cost;
        if (mp[idx]) return cost;
        rep(i, 0, sz(node[idx]))
        {
            double c = node[idx][i].second, child = node[idx][i].first;
            if (dist[child] == -1) st.insert({cost + c, child});
        }
    }
    return 1e14;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> tc;
    while(tc--)
    {
        indexer = 0;
        cin >> n >> m >> s;
        node = vector< vector< pair< int, double > > >(10001);
        up = vector<PT>(n), down = vector<PT>(m), island.clear();
        mp.clear(), idx.clear();
        rep(i, 0, n)
        {
            cin >> up[i];
            if (i) idx[{up[i-1], up[i]}] = indexer++;
        }
        rep(i, 0, m)
        {
            cin >> down[i];
            if (i)
            {
                mp[indexer] = true;
                idx[{down[i-1], down[i]}] = indexer++;
            }
        }
        vector< vector< PT> > vec(s);
        //cout << endl;
        rep(i, 0, s)
        {
            int a;
            PT b;
            cin >> a;
            rep(j, 0, a)
            {
                cin >> b;
                vec[i].push_back(b);
            }
            rep(j, 0, a)
            {
                idx[{vec[i][mod(j-1, a)], vec[i][j]}] = indexer++;
            }
            rep(j, 0, a)
            {
                rep(k, j+1, a)
                {
                    int idx1 = idx[{vec[i][mod(j-1, a)], vec[i][j]}];
                    int idx2 = idx[{vec[i][mod(k-1, a)], vec[i][k]}];
                    node[idx1].push_back({idx2, 0.0});
                    node[idx2].push_back({idx1, 0.0});
                }
            }
        }

        /*rep(i, 0, s)
        {
            rep(j, 0, sz(vec[i]))
            {
                cout << idx[{vec[i][mod(j-1, sz(vec[i]))], vec[i][j]}] << " ";
            }
            cout << endl << endl;
        }*/

        rep(i, 1, n) // bank to bank
        {
            rep(j, 1, m)
            {
                double hoba = min_dist(up[i-1], up[i], down[j-1], down[j]);
                int idx1 = idx[{up[i-1], up[i]}], idx2 = idx[{down[j-1], down[j]}];
                node[idx1].push_back({idx2, hoba});
                node[idx2].push_back({idx1, hoba});
            }
        }

        rep(i, 1, n) // bank to island
        {
            rep(a, 0, s)
            {
                rep(j, 0, sz(vec[a]))
                {
                    double hoba = min_dist(up[i-1], up[i], vec[a][mod(j-1, sz(vec[a]))], vec[a][j]);
                    int temp = idx[{vec[a][mod(j-1, sz(vec[a]))], vec[a][j]}];
                    int idx1 = idx[{up[i-1], up[i]}], idx2 = temp;
                    node[idx1].push_back({idx2, hoba});
                    node[idx2].push_back({idx1, hoba});

                }
            }
        }

        rep(i, 0, s) // island to island
        {
            rep(j, 0, sz(vec[i]))
            {
                rep(a, i+1, s)
                {
                    rep(k, 0, sz(vec[a]))
                    {
                        double hoba = min_dist(vec[i][mod(j-1, sz(vec[i]))], vec[i][j], vec[a][mod(k-1, sz(vec[a]))], vec[a][k]);
                        int temp = idx[{vec[a][mod(k-1, sz(vec[a]))], vec[a][k]}];
                        int idx1 = idx[{vec[i][mod(j-1, sz(vec[i]))], vec[i][j]}], idx2 = temp;
                        node[idx1].push_back({idx2, hoba});
                        node[idx2].push_back({idx1, hoba});
                    }
                }
            }
        }

        rep(i, 0, s) // island to bank
        {
            rep(j, 0, sz(vec[i]))
            {
                rep(k, 1, m)
                {
                    double hoba = min_dist(vec[i][mod(j-1, sz(vec[i]))], vec[i][j], down[k-1], down[k]);
                    int temp = idx[{down[k-1], down[k]}];
                    int idx1 = idx[{vec[i][mod(j-1, sz(vec[i]))], vec[i][j]}], idx2 = temp;
                    node[idx1].push_back({idx2, hoba});
                    node[idx2].push_back({idx1, hoba});
                }
            }
        }


        double mn = DBL_MAX;
        rep(i, 1, n)
        {
            mn = min(mn, dijkstra(idx[{up[i-1], up[i]}]));
        }
        cout << fixed << setprecision(3) << mn << endl;
    }

    return 0;
}
