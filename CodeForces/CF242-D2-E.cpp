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

int arr[100000], tree[400000][20], lazy[400000][20];

void build(int node, int st, int en, int bit)
{
    if (st > en) return;
    if (st == en)
    {
        tree[node][bit] = ((arr[st]&1 << bit) ? 1 : 0);
        return;
    }
    int mid = (st+en)/2;
    build(2*node, st, mid, bit);
    build(2*node+1, mid+1, en, bit);
    tree[node][bit] = tree[2*node][bit] + tree[2*node+1][bit];
}

void update(int node, int st, int en, int shemal, int yemeen, int bit)
{
    if (lazy[node][bit])
    {
        tree[node][bit] = (en-st+1) - tree[node][bit];
        if (st != en)
        {
            lazy[2*node][bit] ^= 1;
            lazy[2*node+1][bit] ^= 1;
        }
        lazy[node][bit] = 0;
    }

    if (st > en || st > yemeen || en < shemal) return;

    if (shemal <= st && en <= yemeen)
    {
        tree[node][bit] = (en-st+1) - tree[node][bit];
        if (st != en)
        {
            lazy[2*node][bit] ^= 1;
            lazy[2*node+1][bit] ^= 1;
        }
        lazy[node][bit] = 0;
        return;
    }
    int mid = (st+en)/2;
    update(2*node, st, mid, shemal, yemeen, bit);
    update(2*node + 1, mid+1, en, shemal, yemeen, bit);
    tree[node][bit] = tree[2*node][bit] + tree[2*node+1][bit];
}

int query(int node, int st, int en, int shemal, int yemeen, int bit)
{
    if (lazy[node][bit])
    {
        tree[node][bit] = (en-st+1) - tree[node][bit];
        if (st != en)
        {
            lazy[2*node][bit] ^= 1;
            lazy[2*node+1][bit] ^= 1;
        }
        lazy[node][bit] = 0;
    }

    if (st > en || st > yemeen || en < shemal) return 0;

    if (shemal <= st && en <= yemeen) return tree[node][bit];

    int mid = (st+en)/2;

    return query(2*node, st, mid, shemal, yemeen, bit) +query(2*node + 1, mid+1, en, shemal, yemeen, bit);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) cin >> arr[i];
    rep(i, 0, 20) build(1, 0, n-1, i);
    cin >> m;
    while(m--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int a, b;
            cin >> a >> b;
            ll sum = 0;
            rep(i, 0, 20) sum = sum + (ll)query(1, 0, n-1, a-1, b-1, i) * (ll)((1<<i));
            cout << sum << endl;
        }
        else
        {
            int a, b, c;
            cin >> a >> b >> c;
            a--, b--;
            erep(i, 0, 20) if (c &(1<<i)) update(1, 0, n-1, a, b, i);
        }
    }
    return 0;
}
