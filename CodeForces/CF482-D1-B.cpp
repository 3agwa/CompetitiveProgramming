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

int arr[200001], tree[600000][2], lazy[600000];

void build(int node, int st, int en)
{
    if (st > en) return;
    if (st == en)
    {
        tree[node][0] = arr[st];
        return;
    }
    int mid = (st+en)/2;
    build(2*node, st, mid);
    build(2*node + 1, mid + 1, en);
    tree[node][0] = tree[2*node][0] & tree[2*node + 1][0];
}


void update(int node, int st, int en, int shemal, int yemeen, int val)
{
    if (lazy[node])
    {
        tree[node][1] |= lazy[node];
        if (st != en)
        {
            lazy[2*node] |= lazy[node];
            lazy[2*node + 1] |= lazy[node];
        }
        lazy[node] = 0;
    }
    if (st > en || st > yemeen || en < shemal) return;

    if (shemal <= st && en <= yemeen)
    {
        tree[node][1] |= val;
        if (st != en) lazy[2*node] |= val, lazy[2*node+1] |= val;
        return;
    }

    int mid = (st+en)/2;
    update(2*node, st, mid, shemal, yemeen, val);
    update(2*node+1, mid+1, en, shemal, yemeen, val);
    tree[node][1] = tree[2*node][1] | tree[2*node+1][1];
}

int query_or(int node, int st, int en, int shemal, int yemeen)
{
    if (lazy[node])
    {
        tree[node][1] |= lazy[node];
        if (st != en)
        {
            lazy[2*node] |= lazy[node];
            lazy[2*node + 1] |= lazy[node];
        }
        lazy[node] = 0;
    }

    if (st > en || st > yemeen || en < shemal) return 0;

    if (shemal <= st && en <= yemeen) return tree[node][1];

    int mid = (st+en)/2;
    return query_or(2*node, st, mid, shemal, yemeen) | query_or(2*node + 1, mid + 1, en, shemal, yemeen);
}

int query_and(int node, int st, int en, int shemal, int yemeen)
{
    if (st > en || st > yemeen || en < shemal) return INT_MAX; // kefaya copying conditions :)

    if (shemal <= st && en <= yemeen) return tree[node][0];

    int mid = (st+en)/2;
    return query_and(2*node, st, mid, shemal, yemeen) & query_and(2*node + 1, mid + 1, en, shemal, yemeen);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector< pair< pii, int > > queries;
    rep(i, 0, m)
    {
        int x, y, z;
        cin >> x >> y >> z;
        queries.push_back(mp(x-1, y-1, z));
        update(1, 0, n-1, x-1, y-1, z);
    }
    rep(i, 0, n) arr[i] = query_or(1, 0, n-1, i, i);
    build(1, 0, n-1);
    rep(i, 0, sz(queries))
    {
        int x = queries[i].first.first, y = queries[i].first.second, z = queries[i].second;
        if (query_and(1, 0, n-1, x, y) != z)
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES\n";
    rep(i, 0, n) cout << arr[i] << " ";
    return 0;
}
