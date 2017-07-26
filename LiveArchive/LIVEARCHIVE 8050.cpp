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
#define eps (1e-9)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
//#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {{x, y}, z}

int mn[1 << 22], mx[1 << 22], lazy[1 << 22];

void propagate(int node, int st, int en)
{
    mn[node] += lazy[node];
    mx[node] += lazy[node];
    if (st != en) lazy[2*node] += lazy[node], lazy[2*node+1] += lazy[node];
    lazy[node] = 0;
}

void update(int node, int st, int en, int shemal, int yemeen, int val)
{
    propagate(node, st, en);
    if (st > en || st > yemeen || en < shemal) return;

    if (shemal <= st && en <= yemeen)
    {
        lazy[node] += val;
        propagate(node, st, en);
        return;
    }

    int mid = (st+en)/2;
    update(2*node, st, mid, shemal, yemeen, val);
    update(2*node + 1, mid + 1, en, shemal, yemeen, val);
    mn[node] = min(mn[2*node], mn[2*node+1]);
    mx[node] = max(mx[2*node], mx[2*node+1]);
}

int query_min(int node, int st, int en, int shemal, int yemeen)
{
    propagate(node, st, en);
    if (st > en || st > yemeen || en < shemal) return 1e9;

    if (shemal <= st && en <= yemeen) return mn[node];
    int mid = (st+en)/2;
    return min(query_min(2*node, st, mid, shemal, yemeen), query_min(2*node + 1, mid + 1, en, shemal, yemeen));
}

int query_max(int node, int st, int en, int shemal, int yemeen)
{
    propagate(node, st, en);
    if (st > en || st > yemeen || en < shemal) return -1e9;

    if (shemal <= st && en <= yemeen) return mx[node];
    int mid = (st+en)/2;
    return max(query_max(2*node, st, mid, shemal, yemeen), query_max(2*node + 1, mid + 1, en, shemal, yemeen));
}

struct rect
{
    int x1, x2, y1, y2;
    rect(int _x1, int _x2, int _y1, int _y2)
    {
        x1 = _x1, x2 = _x2, y1 = _y1, y2 = _y2;
    }
};

vector<rect> rects;

bool cmp(rect a, rect b)
{
    return a.y1 < b.y1;
}

bool sweep()
{
    reset(lazy, 0), reset(mn, 0), reset(mx, 0);
    sort(all(rects), cmp);

    set< pair< int, pii > > st; // end, [x1, x2] (interval)
    rep(i, 0, sz(rects))
    {
        int x1 = rects[i].x1, x2 = rects[i].x2;
        int y1 = rects[i].y1, y2 = rects[i].y2;

        while(!st.empty() && st.begin()->first <= y1) // closing event before mine
        {
            int _x1 = st.begin()->second.first, _x2 = st.begin()->second.second;
            // check for the cases
            // if two rectangles intersect, then maximum in range [_x1, _x2] won't equal maximum in range[_x1, _x2]
            if (query_min(1, 0, (1<<19), _x1, _x2) != query_max(1, 0, (1<<19), _x1, _x2)) return false;
            // second case
            // if 2 rectangles have the same border, this is also invalid
            // could check by abs difference between _x1, _x1-1
            // and abs difference between _x2, _x2+1
            // if the diff is greater than 1, then there exists more than one rectangle on that line
            if (abs(query_min(1, 0, (1<<19), _x1-1, _x1-1) - query_min(1, 0, (1<<19), _x1, _x1)) > 1) return false;

            if (abs(query_min(1, 0, (1<<19), _x2+1, _x2+1) - query_min(1, 0, (1<<19), _x2, _x2)) > 1) return false;

            // if all is well, remove the interval
            update(1, 0, (1<<19), _x1, _x2, -1);
            st.erase(st.begin());
        }
        // add new interval

        update(1, 0, (1<<19), x1, x2, 1);
        st.insert({y2+1, {x1, x2}});

        if (query_min(1, 0, (1<<19), x1, x2) != query_max(1, 0, (1<<19), x1, x2)) return false;
        if (abs(query_min(1, 0, (1<<19), x1-1, x1-1) - query_min(1, 0, (1<<19), x1, x1)) > 1) return false;
        if (abs(query_min(1, 0, (1<<19), x2+1, x2+1) - query_min(1, 0, (1<<19), x2, x2)) > 1) return false;
    }

    return true;
}

bool valid()
{
    if (!sweep()) return false;

    rep(i, 0, sz(rects)) swap(rects[i].x1, rects[i].y1), swap(rects[i].x2, rects[i].y2);

    if (!sweep()) return false;

    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector< pair<pii, int> > vec(2*n), input;
    rep(i, 0, 2*n)
    {
        cin >> vec[i].first.first >> vec[i].first.second;
        vec[i].second = i;
    }
    input = vec;
    sort(all(vec));
    set<pii> st;
    vi output(n);
    //st.insert({-2e9, -1});
    // check if there is an opening event without a closing one
    rep(i, 0, 2*n)
    {
        int x = vec[i].first.first, y = vec[i].first.second, idx = vec[i].second;
        if (idx < n) // opening event
            st.insert({y, idx});
        else // closing event
        {
            auto it = st.lower_bound({y, idx});

            if (it == st.begin())
            {
                cout << "syntax error\n";
                return 0;
            }
            it--;

//barra:
            int old_idx = it->second, old_y = it->first;
            output[old_idx] = idx;
            rects.push_back(rect(input[old_idx].first.first, x, old_y, y)); // form the new rectangle
            st.erase(it);
        }
    }

    // compress
    int comp = 1;
    mapii xs, ys;
    rep(i, 0, sz(rects))
    {
        int x1 = rects[i].x1, x2 = rects[i].x2, y1 = rects[i].y1, y2 = rects[i].y2;
        xs[x1] = 0, xs[x2] = 0;
        ys[y1] = 0, ys[y2] = 0;
    }

    for(mapii ::iterator it = xs.begin(); it != xs.end(); it++) it->second = comp++;//, comp += 2;
    comp = 1;

    for(mapii ::iterator it = ys.begin(); it != ys.end(); it++) it->second = comp++;//, comp += 2;

    rep(i, 0, sz(rects))
    {
        int x1 = rects[i].x1, x2 = rects[i].x2, y1 = rects[i].y1, y2 = rects[i].y2;
        rects[i].x1 = xs[x1];
        rects[i].x2 = xs[x2];
        rects[i].y1 = ys[y1];
        rects[i].y2 = ys[y2];
    }

    if (!valid()) cout << "syntax error\n";
    else rep(i, 0, n) cout << output[i] - n + 1 << endl;

    return 0;
}
