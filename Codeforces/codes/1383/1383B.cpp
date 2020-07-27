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

int n, m, a, b, c, t, ok, V[MAXC];
lli k, r, x, y, z;

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        vector< int > cnt(30);
        ok = -1;
        FOR(i, n){
            cin >> V[i];
            a = 0;
            while(V[i]){
                cnt[a] += V[i]&1;
                a++;
                V[i]>>=1;
            }
        }
        for(int i=29;i>=0;i--){
            if(cnt[i] & 1){
                ok = (cnt[i]%4==1 || (n+cnt[i])%2);
                break;
            }
        }
        if(ok == -1){
            cout << "DRAW\n";
            continue; 
        }
        cout << (ok==1?"WIN":"LOSE") << '\n';
    }
}