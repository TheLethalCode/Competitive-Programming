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
#define ordered_set tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update>
#define MAXC 200005
// %

int X[MAXC], V[MAXC];

bool solve(int i, int j){
    if(X[i] > X[j]){
        swap(i, j);
    }
    if(V[i] <= V[j]){
        return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, l, w, moon = -1;
    lli ans = 0;
    cin >> n >> l >> w;
    vector< int > M[4];
    FOR(i, n){
        cin >> X[i] >> V[i];
        if(X[i] >= 0 || X[i] <= -l){
            M[(X[i]>=0)*2 + (V[i]>0)].pb(i);
        }
        else{
            moon = i;
        }
    }
    if(moon != -1){
        FOR(i, n){
            if(i != moon){
                ans += solve(moon, i);
            }
        }
    }
    ans += 1LL * M[1].size() * M[2].size();
    if(w > 1){
        ordered_set R;
        FORR(j, M[2]){
            R.insert(X[j]);
        }
        FORR(i, M[3]){
            int x = X[i] + 2*X[i]/(w-1) - l;
            ans += R.order_of_key(x);
        }
        R.clear();
        FORR(j, M[1]){
            R.insert(-X[j]-l);
        }
        FORR(i, M[0]){
            int nx = -X[i] - l;
            int x = nx + 2*nx/(w-1) - l;
            ans += R.order_of_key(x);
        }
    }
    cout << ans << '\n';
}