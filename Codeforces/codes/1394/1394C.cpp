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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define MAXC 500005
// %

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, ret, x, y;
    cin >> n;
    vector< pair< int, int > > v(n);
    FOR(i, n){
        string s;
        cin >> s;
        FORR(x, s){
            (x=='B'?v[i].fi:v[i].se)++;
        }
    }
    auto can = [&](int ans)->bool{
        int lx = 0, rx = MAXC, ly = 0, ry = MAXC, ldx = -MAXC, rdx = MAXC;
        FOR(i, n){
            lx = max(lx, v[i].fi - ans);
            rx = min(rx, v[i].fi + ans);
            ly = max(ly, v[i].se - ans);
            ry = min(ry, v[i].se + ans);
            ldx = max(ldx, v[i].se - v[i].fi - ans);
            rdx = min(rdx, v[i].se - v[i].fi + ans);
        }
        ldx = max(ldx, ly-rx);
        rdx = min(rdx, ry-lx);
        if(lx <= rx && ly <= ry && ldx <= rdx){
            ret = ans;
            int dif[] = {ldx, rdx}, X[] = {lx, rx}, Y[] = {ly, ry};
            FOR(i, 2){
                FOR(j, 2){
                    x = X[i], y = dif[j] + x;
                    if(y >= ly && y <= ry && (x || y)){
                        return true;    
                    }
                    x = Y[i] - dif[j], y = Y[i]; 
                    if(x >= lx && x <= rx && (x || y)){
                        return true;    
                    }
                }
            }
        }
        return false;
    };
    int lo = 0, hi = MAXC, mid;
    while (lo <= hi) {
        if (can(mid = lo + hi >> 1)) {
            hi = mid - 1;
        } else {
            lo =  mid + 1;
        }
    }
    cout << ret << '\n';
    cout << string(x, 'B') + string(y, 'N') << '\n';
}