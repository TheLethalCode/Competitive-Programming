#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 1000000007
#define lli long long
#define fi first
#define se second
#define pb emplace_back
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define sz(a) (int)(a.size())
#define MAXC 200005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %
int par[MAXC], siz[MAXC], col[MAXC], ch[2], fl = 1;
vector< int > to[MAXC], C[2*MAXC];

void dfs(int u, int c){
    C[c].pb(u);
    col[u] = c;
    ch[c&1] += siz[u];
    FORR(v, to[u]){
        if(col[v] == c){
            fl = 0;
            break;
        }
        if(col[v] == -1){
            dfs(v, c^1);
        }
    }
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, x;
        fl = 1;
        cin >> n;
        vector< pair< int, int > > ar[n+1];
        iota(par, par+n, 0);
        fill_n(siz, n, 1);
        fill_n(col, n, -1);
        FOR(i, 2*n){
            cin >> x;
            to[i%n].clear();
            C[i].clear();
            ar[x].pb(i%n, i/n);
            if(ar[x].size() > 2){
                fl = 0;
            }
        }
        if(!fl){
            cout << "-1\n";
            continue;
        }
        function<int(int)> f;
        f = [&](int x){
            if(par[x] == x){
                return x;
            }
            return par[x] = f(par[x]);
        };
        FOR(i, n){
            if(ar[i+1][0].fi == ar[i+1][1].fi){
                continue;
            }
            if(ar[i+1][0].se != ar[i+1][1].se){
                int a = f(ar[i+1][0].fi), b = f(ar[i+1][1].fi);
                if(a != b){
                    par[a] = b;
                    siz[b] += siz[a];
                }
            }
        }
        FOR(i, n){
            if(ar[i+1][0].fi == ar[i+1][1].fi){
                continue;
            }
            if(ar[i+1][0].se == ar[i+1][1].se){
                int a = f(ar[i+1][0].fi), b = f(ar[i+1][1].fi);
                to[a].pb(b);
                to[b].pb(a);
            } 
        }
        int cnt = 0;
        FOR(i, n){
            if(col[f(i)]==-1){
                ch[0] = ch[1] = 0;
                dfs(f(i), cnt);
                FORR(el, C[cnt]){
                    col[el] = !(ch[0]>=ch[1]);
                }
                FORR(el, C[cnt^1]){
                    col[el] = !(ch[1]>ch[0]);
                }
                cnt += 2;
            }
        }
        if(!fl){
            cout << "-1\n";
            continue;
        }
        vector< int > ans;
        FOR(i, n){
            if(col[f(i)] == 1){
                ans.pb(i+1);
            }
        }
        cout << ans.size() << '\n';
        FORR(i, ans){
            cout << i << ' ';
        }
        cout << '\n';
    }
}