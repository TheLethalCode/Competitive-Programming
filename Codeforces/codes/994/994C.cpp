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
#define MAXC 200005
// %

bool solve(vector< pair< int, int > > A, vector< pair< int, int > > B) {
    int smX = 101, biX = -101, smY = 101, biY = -101;
    for (int i = 0; i < 4; i++) {
        smX = min(smX, A[i].fi);
        smY = min(smY, A[i].se);
        biX = max(biX, A[i].fi);
        biY = max(biY, A[i].se);
    }
    for (int i = 0; i < 4; i++) {
        int x1 = B[i].fi, x2 = B[(i+1)%4].fi;
        int y1 = B[i].se, y2 = B[(i+1)%4].se;
        int dis = abs(x1 - x2);
        for (int j = 0, curX = x1, curY = y1; j < dis; j++) {
            curX += (x1 < x2)?1:-1;
            curY += (y1 < y2)?1:-1;
            if (smX <= curX && curX <= biX && smY <= curY && curY <= biY) {
                return true;
            }
        }
    }
    return false;
}

vector< pair< int, int > > transform(vector< pair< int, int > > A) {
    vector< pair< int, int > > B(4);
    FOR (i, 4) {
        B[i] = {A[i].fi + A[i].se, A[i].fi - A[i].se};
    }
    return B;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector< pair< int, int > > A, B;
    FOR (i, 4) {
        int x, y;
        cin >> x >> y;
        A.pb(x, y);
    }
    FOR (i, 4) {
        int x, y;
        cin >> x >> y;
        B.pb(x, y);
    }
    cout << ((solve(A, B) || solve(transform(B), transform(A)))? "YES" : "NO") << '\n';
}