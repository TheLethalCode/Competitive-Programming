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
#define MAXC 5000
#define ordered_set tree<pair< int, int > , null_type, less<pair< int, int > >, rb_tree_tag, tree_order_statistics_node_update>
// %

int n, cnt[MAXC+1][MAXC+1];
lli ans = 0;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector< pair< pair< int, int> , int > > V[2*MAXC+3];
    vector< pair< int, int > > H[2*MAXC+3];
    int val[MAXC+1];
    cin >> n;
    FOR(i, n){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1 += MAXC;
        x2 += MAXC;
        if(y1 > y2){
            swap(y1, y2);
        }
        if(x1 > x2){
            swap(x1, x2);
        }
        if(y1 == y2){
            val[i] = y1; 
            H[x1].pb(0, i);
            H[x2+1].pb(1, i);
        }
        else{
            V[x1].pb(make_pair(y1, y2), i);
        }
    }
    FOR(i, 2*MAXC+1){
        sort(V[i].begin(), V[i].end());
    }
    ordered_set sweep;
    FOR(i, 2*MAXC+1){
        FORR(eve, H[i]){
            if(!eve.fi){
                sweep.insert({val[eve.se], eve.se});
            }
            else{
                sweep.erase(sweep.find({val[eve.se], eve.se}));
            }
        }
        if(V[i].empty()){
            continue;
        }
        ordered_set copy = sweep;
        for(int j=i+1; j<=2*MAXC; j++){
            FORR(eve, H[j]){
                if(eve.fi){
                    auto it = copy.find({val[eve.se], eve.se});
                    if(it != copy.end()){
                        copy.erase(it);
                        if(copy.size() < 2){
                            goto hola;
                        }
                    }
                }
            }
            if(V[j].empty()){
                continue;
            }
            FORR(seg1, V[i]){
                FORR(seg2, V[j]){
                    int mi = max(seg1.fi.fi, seg2.fi.fi);
                    int ma = min(seg1.fi.se, seg2.fi.se);
                    if(mi >= ma){
                        continue;
                    }
                    int x = seg1.se, y = seg2.se;
                    if(x > y){
                        swap(x, y);
                    }
                    cnt[x][y] += copy.order_of_key({ma+1, -1}) - copy.order_of_key({mi, -1});
                }
            }
        }
        hola :;
    }
    for(int i=0;i<MAXC;i++){
        for(int j=i+1;j<MAXC;j++){
            ans += 1LL*cnt[i][j]*(cnt[i][j]-1)/2;
        }
    }
    cout << ans << '\n';
}