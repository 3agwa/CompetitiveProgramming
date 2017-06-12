/*
    first of all, we need to get the prime numbers in our range
    this could be done using sieve, pre-process them once before test cases
    
    now, we'll update and answer the queries using segment tree
    but since the updates are a lot, we'll use the help of lazy propagation
    when updating, if the node has a prime number, then tree[node] = the interval [en-st+1] inclusive
    if we're updating a non-prime number, tree[node] = 0;
    we do the same check with the lazy propagation
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
#define INF  LLONG_MAX
#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)((v).size()))
#define pie  acos(-1)
#define mod(n,m) ((n % m + m) % m)
#define eps (1e-8)
#define reset(n, m) memset(n, m, sizeof n)
#define endl '\n'
#define output freopen("output.txt", "w", stdout)
#define mp(x, y, z) {x, {y, z}}

const int mx1 = 1e4 + 5;
const int mx2 = 1e6 + 5;

bool visited[mx2];
int arr[mx1], tree[4*mx1], lazy[4*mx1];

void build(int node, int st, int en)
{
    if (st > en) return;
    if (st == en)
    {
        tree[node] = !visited[arr[st]];
        return;
    }
    int mid = (st+en)/2;
    build(2*node, st, mid);
    build(2*node+1, mid+1, en);
    tree[node] = tree[2*node] + tree[2*node + 1];
}

void update(int node, int st, int en, int shemal, int yemeen, int val)
{
    if (lazy[node])
    {
        if (!visited[lazy[node]]) tree[node] = en-st+1;
        else tree[node] = 0;
        if (st != en)
        {
            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        lazy[node] = 0;
    }
    if (st > en || st > yemeen || en < shemal) return;

    if (shemal <= st && en <= yemeen)
    {
        if (!visited[val]) tree[node] = en-st+1;
        else tree[node] = 0;
        if (st != en)
        {
            lazy[2*node] = val;         // check if += or =
            lazy[2*node + 1] = val;
        }
        return;
    }

    int mid = (st+en)/2;

    update(2*node, st, mid, shemal, yemeen, val);
    update(2*node + 1, mid + 1, en, shemal, yemeen, val);

    tree[node] = tree[2*node] + tree[2*node + 1];
}

int query(int node, int st, int en, int shemal, int yemeen)
{
    if (lazy[node])
    {
        if (!visited[lazy[node]]) tree[node] = en-st+1;
        else tree[node] = 0;
        if (st != en)
        {
            lazy[2*node] = lazy[node];
            lazy[2*node+1] = lazy[node];
        }
        lazy[node] = 0;
    }
    if (st > en || st > yemeen || en < shemal) return 0;
    if (shemal <= st && en <= yemeen) return tree[node];
    int mid = (st+en)/2;
    return query(2*node, st, mid, shemal, yemeen) + query(2*node+1, mid+1, en, shemal, yemeen);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 2; i*i <= 1000000; i++)
    {
        if (!visited[i])
        {
            for(int j = 2*i; j <= 1000000; j+=i) visited[j] = true;
        }
    }
    int tc, n, m, type, a, b, c;
    cin >> tc;
    erep(t, 1, tc)
    {
        rep(i, 0, 4*mx1) tree[i] = lazy[i] = 0;
        cin >> n >> m;
        rep(i, 0, n) cin >> arr[i];
        build(1, 0, n-1);
        cout << "Case " << t << ":\n";
        while(m--)
        {
            cin >> type;
            if (type)
            {
                cin >> a >> b;
                cout << query(1, 0, n-1, a-1, b-1) << endl;
            }
            else
            {
                cin >> a >> b >> c;
                update(1, 0, n-1, a-1, b-1, c);
            }
        }
    }

    return 0;
}
