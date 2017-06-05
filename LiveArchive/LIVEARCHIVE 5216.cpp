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
#define mp(x, y, z) {{x, y}, z}

string x;
int sx, sy, ex, ey;
int mxrow, mxcol;
string sd;
map< pii, vs > mp;
vii vec;
bool visited[100][100][5];
bool flag;

string directions(int i, int j, int from)
{
    string dir = "";
    vs temp = mp[ {i, j}];
    rep(a, 0, sz(temp))
    {
        if (from == 0 && temp[a][0] == 'N')
        {
            dir = temp[a];
            break;
        }
        else if (from == 1 && temp[a][0] == 'W')
        {
            dir = temp[a];
            break;
        }
        else if (from == 2 && temp[a][0] == 'S')
        {
            dir = temp[a];
            break;
        }
        else if (from == 3 && temp[a][0] == 'E')
        {
            dir = temp[a];
            break;
        }
    }
    return dir;
}

void flood(int i, int j, int from)
{
    pair< pii, int > parent[100][100][4];
    queue< int > I, J, K;
    I.push(i), J.push(j), K.push(from);
    parent[i][j][from] = mp(-1, -1, -1);
    while(!I.empty())
    {
        int i = I.front(), j = J.front(), from = K.front();
        I.pop(), J.pop(), K.pop();
        if (visited[i][j][from]) continue;
        visited[i][j][from] = true;
        if (i == ex && j == ey)
        {
            stack< pii > st;
            int tx = i, ty = j, dir = from;
            while(tx >= 0)
            {
                st.push({tx, ty});
                int ttx = parent[tx][ty][dir].first.first;
                int tty = parent[tx][ty][dir].first.second;
                int td = parent[tx][ty][dir].second;
                tx = ttx, ty = tty, dir = td;
            }
            st.push({sx, sy});

            int cnt = 0;
            while(!st.empty())
            {
                if (cnt%10 == 0) cout << "\n ";
                pii hoba = st.top();
                st.pop();
                cout << " (" << hoba.first << "," << hoba.second << ")";
                cnt++;
            }
            cout << endl;
            flag = true;
            return;
        }
        if (from == 0) // from south to north
        {
            string dir = directions(i, j, from);
            if (dir != "")
            {
                rep(a, 1, sz(dir))
                {
                    if (dir[a] == 'F')
                    {
                        if (!visited[i-1][j][0])
                        {
                            parent[i-1][j][0] = mp(i, j, from);
                            I.push(i-1), J.push(j), K.push(0);
                        }
                    }
                    else if (dir[a] == 'L')
                    {
                        if (!visited[i][j-1][1])
                        {
                            parent[i][j-1][1] = mp(i, j, from);
                            I.push(i), J.push(j-1), K.push(1);
                        }
                    }
                    else
                    {
                        if (!visited[i][j+1][3])
                        {
                            parent[i][j+1][3] = mp(i, j, from);
                            I.push(i), J.push(j+1), K.push(3);
                        }
                    }
                }
            }
        }
        else if (from == 1) // from east to west
        {
            string dir = directions(i, j, from);
            if (dir != "")
            {
                rep(a, 1, sz(dir))
                {
                    if (dir[a] == 'F')
                    {
                        if (!visited[i][j-1][1])
                        {
                            parent[i][j-1][1] = mp(i, j, from);
                            I.push(i), J.push(j-1), K.push(1);
                        }
                    }
                    else if (dir[a] == 'L')
                    {
                        if (!visited[i+1][j][2])
                        {
                            parent[i+1][j][2] = mp(i, j, from);
                            I.push(i+1), J.push(j), K.push(2);

                        }
                    }
                    else
                    {
                        if (!visited[i-1][j][0])
                        {
                            parent[i-1][j][0] = mp(i, j, from);
                            I.push(i-1), J.push(j), K.push(0);
                        }
                    }
                }
            }
        }
        else if (from == 2) // from north to south
        {
            string dir = directions(i, j, from);
            if (dir != "")
            {
                rep(a, 1, sz(dir))
                {
                    if (dir[a] == 'F')
                    {
                        if (!visited[i+1][j][2])
                        {
                            parent[i+1][j][2] = mp(i, j, from);
                            I.push(i+1), J.push(j), K.push(2);
                        }
                    }
                    else if (dir[a] == 'L')
                    {
                        if (!visited[i][j+1][3])
                        {
                            parent[i][j+1][3] = mp(i, j, from);
                            I.push(i), J.push(j+1), K.push(3);
                        }
                    }
                    else
                    {
                        if (!visited[i][j-1][1])
                        {
                            parent[i][j-1][1] = mp(i, j, from);
                            I.push(i), J.push(j-1), K.push(1);
                        }
                    }
                }
            }
        }
        else // from west to east
        {
            string dir = directions(i, j, from);
            if (dir != "")
            {
                rep(a, 1, sz(dir))
                {
                    if (dir[a] == 'F')
                    {
                        if (!visited[i][j+1][3])
                        {
                            parent[i][j+1][3] = mp(i, j, from);
                            I.push(i), J.push(j+1), K.push(3);
                        }
                    }
                    else if (dir[a] == 'L')
                    {
                        if (!visited[i-1][j][0])
                        {
                            parent[i-1][j][0] = mp(i, j, from);
                            I.push(i-1), J.push(j), K.push(0);
                        }
                    }
                    else
                    {
                        if (!visited[i+1][j][2])
                        {
                            parent[i+1][j][2] = mp(i, j, from);
                            I.push(i+1), J.push(j), K.push(2);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    while(getline(cin, x) && x != "END")
    {
        vec.clear();
        flag = 0;
        mp.clear();
        reset(visited, false);
        cin >> sx >> sy >> sd >> ex >> ey;
        int n, m;
        while(cin >> n && n)
        {
            cin >> m;
            string in;
            while(cin >> in && in != "*")
            {
                vs temp = mp[{n, m}];
                bool hoba = false;
                rep(a, 0, sz(temp))
                {
                    if (in[0] == temp[a][0])
                    {
                        hoba = true;
                        in.erase(0, 1);
                        temp[a] += in;
                        break;
                    }
                }
                if (!hoba)
                    mp[ {n, m}].push_back(in);
            }
        }
        vec.push_back({sx, sy});
        cout << x;
        if (sd == "N") flood(sx-1, sy, 0);
        else if (sd == "S") flood(sx+1, sy, 2);
        else if (sd == "E") flood(sx, sy+1, 3);
        else flood(sx, sy-1, 1);
        if (!flag)
        {
            cout << "\n  No Solution Possible\n";
        }
        cin.ignore();
    }

    return 0;
}
