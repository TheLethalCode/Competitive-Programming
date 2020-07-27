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

int n, m, i, j, t, q, ok, cnt, V[MAXC];
lli k, r, x, y, z, ans;
string s, c;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(int q=1;q<=t;q++){
        cin >> n >> s >> c;
        bool poss[n][n];
        memset(poss, 0, sizeof(poss));
        FOR(i, n){
            poss[i][i] = 1;
        }
        for(int l=2;l<=n;l++){
            for(int i=0, j=l-1;j<n;i++, j++){
                poss[i][j] = poss[i][j-1] & c[j-1]=='Y' & s[j]=='Y';
                poss[j][i] = poss[j][i+1] & c[i+1]=='Y' & s[i]=='Y';
            }
        }
        cout << "Case #" << q << ":\n";
        FOR(i, n){
            FOR(j, n){
                cout << (poss[i][j]?'Y':'N');
            }
            cout << '\n';
        }
    }
}