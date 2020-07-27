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
#define MAXC 500001
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %
int n, m, l, r, where[MAXC][20], R[MAXC];
vector< pair< int, int > > events[MAXC];

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    FOR(i, n){
        cin >> l >> r;
        events[l].pb(0, i);
        events[r].pb(1, i);
        R[i] = r;
    }
    set< pair< int, int > , greater< pair< int, int > > > S;
    FOR(i, MAXC){
        FORR(E, events[i]){
            if(!E.fi){
                S.insert({R[E.se], E.se});
            }
            else{
                S.erase({R[E.se], E.se});
            }
        }
        where[i][0] = !S.empty()?S.begin()->fi:i;
    }
    for(int i=MAXC-1;i>=0;i--){
        for(int j=1;j<20;j++){
            where[i][j] = where[where[i][j-1]][j-1];
        }
    }
    while(m--){
        int x, y, ans = 0;
        cin >> x >> y;
        for(int i=17;i>=0;i--){
            if(where[x][i] < y){
                x = where[x][i];
                ans += (1<<i);
            }
        }
        cout << (where[x][0]>=y?ans+1:-1) << '\n';
    }
}