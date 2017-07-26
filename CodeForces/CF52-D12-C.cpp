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
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {{x, y}, z}

int n, m;

ll arr[200000], tree[600000], lazy[600000];

void build(int node, int st, int en)
{
    if (st > en) return;
    if (st == en)
    {
        tree[node] = arr[st];
        return;
    }
    int mid = (st+en)/2;
    build(2*node, st, mid);
    build(2*node + 1, mid + 1, en);
    tree[node] = min(tree[2*node], tree[2*node + 1]);
}

void propagate(int node, int st, int en)
{
    if (lazy[node])
    {
        tree[node] += lazy[node];
        if (st != en)
        {
            lazy[2*node] += lazy[node];
            lazy[2*node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int st, int en, int shemal, int yemeen, ll val)
{
    propagate(node, st, en);

    if (st > en || st > yemeen || en < shemal) return;

    if (shemal <= st && en <= yemeen)
    {
        tree[node] += val;

        if (st != en)
        {
            lazy[2*node] += val;
            lazy[2*node + 1] += val;
        }
        return;

    }

    int mid = (st+en)/2;

    update(2*node, st, mid, shemal, yemeen, val);
    update(2*node + 1, mid + 1, en, shemal, yemeen, val);
    tree[node] = min(tree[2*node], tree[2*node + 1]);
}

ll query(int node, int st, int en, int shemal, int yemeen)
{
    if (st > en || st > yemeen || en < shemal) return 1e16;
    propagate(node, st, en);
    if (shemal <= st && en <= yemeen)
        return tree[node];
    int mid = (st+en)/2;
    return min(query(2*node, st, mid, shemal, yemeen), query(2*node + 1, mid + 1, en, shemal, yemeen));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) cin >> arr[i];
    build(1, 0, n-1);
    cin >> m;
    string x;
    getline(cin, x);
    rep(i, 0, m)
    {
        getline(cin, x);
        stringstream ss(x);
        vi vec;
        ll hoba;
        while(ss >> hoba)vec.push_back(hoba);
        ll leftt, rightt, val;
        if (sz(vec) == 2)
        {
            leftt = vec[0], rightt = vec[1];
            if (leftt <= rightt) cout << query(1, 0, n-1, leftt, rightt) << endl;
            else cout << min( query(1, 0, n-1, leftt, n-1), query(1, 0, n-1, 0, rightt) ) << endl;
        }
        else
        {
            leftt = vec[0], rightt = vec[1], val = vec[2];
            if (leftt <= rightt) update(1, 0, n-1, leftt, rightt, val);
            else update(1, 0, n-1, leftt, n-1, val), update(1, 0, n-1, 0, rightt, val);
        }
    }
    return 0;
}
