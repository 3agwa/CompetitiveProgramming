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
#define erep(i, x, n) for (int i = x; i<=(int)(n); i++)
#define rep(i, x, n) for(int i = x; i<(int)(n); i++)
#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pie  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-9)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

ll arr[100002], operation[100002], tree[270000], lazy[270000];

void update(int node, int a, int b, int i, int j, ll value)
{
    if (lazy[node] != 0)
    {
        tree[node] += lazy[node];
        if (a != b)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (a > b || a > j || b < i) return;

    if (a >= i && b <= j)
    {
        tree[node] += value;

        if (a != b)
        {
            lazy[2*node] += value;
            lazy[2*node + 1] += value;
        }
        return;
    }
    update(node*2, a, (a+b)/2, i, j, value);
    update(node*2 + 1, (a+b)/2 + 1, b, i, j, value);
    tree[node] = tree[node*2] + tree[node*2 + 1];
}

ll query(int node, int a, int b, int i, int j)
{
    if (a > b || a > j || b < i) return 0;

    if (lazy[node] != 0)
    {
        tree[node] += lazy[node];
        if (a != b)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if (a >= i && b <= j)
        return tree[node];
    return query(node*2, a, (a+b)/2, i, j) + query(node*2 + 1, (a+b)/2 + 1, b, i, j);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    rep(i, 0, n) cin >> arr[i];
    vector< pair< pii, ll> > vec(m);
    rep(i, 0, m)
        cin >> vec[i].first.first >> vec[i].first.second >> vec[i].second;
    while(k--)
    {
        int x, y;
        cin >> x >> y;
        operation[x-1]++, operation[y]--; // nice trick
    }
    erep(i, 1, m)
        operation[i] += operation[i-1];
    rep(i, 0, m)
        update(1, 0, n-1, vec[i].first.first-1, vec[i].first.second-1, operation[i]*vec[i].second);
    rep(i, 0, n)
    {
        cout << arr[i] + query(1, 0, n-1, i, i) << " ";
    }
    return 0;
}
