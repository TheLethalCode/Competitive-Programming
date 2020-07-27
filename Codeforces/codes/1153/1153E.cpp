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

int ask(int x1, int y1, int x2, int y2){
    int a;
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    cin >> a;
    return a&1;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector< int > col, row;
    for(int i=1;i<=n;i++){
        if(ask(1, i, n, i)){
            col.pb(i);
        }
        if(ask(i, 1, i, n)){
            row.pb(i);
        }
    }
    if(row.size() == 2 && col.size() == 2){
        vector< pair< int, int > > ans;
        FOR(i, 2){
            FOR(j, 2){
                if(ask(row[i], col[j], row[i], col[j])){
                    ans.pb(row[i], col[j]);
                }
            }
        }
        cout << "! " << ans[0].fi << " " << ans[0].se << " ";
        cout << ans[1].fi << " " << ans[1].se << endl;
    }
    else if(row.size() == 2){
        int col = (1<<10);
        for(int i=9;i>=0;i--){
            if(col-(1<<i) >= n){
                col -= 1<<i;
                continue;
            }
            if(ask(row[0], 1, row[0], col-(1<<i))){
                col -= 1<<i;
            }
        }
        cout << "! " << row[0] << " " << col << " " << row[1] << " " << col << endl;
    }
    else{
        int row = (1<<10);
        for(int i=9;i>=0;i--){
            if(row-(1<<i) >= n){
                row -= 1<<i;
                continue;
            }
            if(ask(1, col[0], row - (1<<i), col[0])){
                row -= 1<<i;
            }
        }
        cout << "! " << row << " " << col[0] << " " << row << " " << col[1] << endl;
    }
}