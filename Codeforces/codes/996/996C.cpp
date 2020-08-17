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

struct data {
    int i, r, c;
    data(int _i, int _r, int _c) : i(_i), r(_r), c(_c) {}
};

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int A[4][50], r = -1, c = -1, done = 0;
    pair< int, int > ch[4][n];
    FOR (i, 4) {
        FOR (j, n) {
            cin >> A[i][j];
        }
    }
    vector< data > ans;
    auto poss = [&](int i, int j) {
        if(A[i][j]){
            if (i == 1 && A[i][j] == A[i-1][j]){
                ans.pb(A[i][j], 1, j+1);
                A[i][j] = 0;
                done++;
            }
            if (i == 2 && A[i][j] == A[i+1][j]){
                ans.pb(A[i][j], 4, j+1);
                A[i][j] = 0;
                done++;
            }
        }
    };
    FOR (i, n) {
        poss(1, i);
        poss(2, i);
        if (!A[1][i]) {
            r = 1, c = i;
        }
        if (!A[2][i]) {
            r = 2, c = i;
        }
        ch[1][i] = i==n-1 ? make_pair(2, i) : make_pair(1, i+1) ;
        ch[2][i] = !i ? make_pair(1, i) : make_pair(2, i-1) ;
    }
    if (r==-1) {
        cout << -1 << '\n';
        return 0;
    }
    int pr = -1, pc = -1;
    while (done < k) {
        if (A[r][c]) {
            ans.pb(A[r][c], pr+1, pc+1);
            A[pr][pc] = A[r][c];
            A[r][c] = 0;
            poss(pr, pc);
        }
        pr = r, pc = c;
        r = ch[pr][pc].fi, c = ch[pr][pc].se;
    }
    cout << ans.size() << '\n';
    FORR(d, ans) {
        cout << d.i << " " << d.r << " " << d.c << '\n';
    }
}