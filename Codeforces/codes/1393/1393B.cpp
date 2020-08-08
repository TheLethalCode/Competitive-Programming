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
#define MAXC 100005
// %

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, q;
    cin >> n;
    vector< int > cnt(MAXC, 0), which(2, 0);
    FOR(i, n){
        cin >> x;
        cnt[x]++;
    }
    FOR(i, MAXC){
        which[1] += cnt[i] / 4;
        which[0] += cnt[i] % 4 / 2;
    }
    cin >> q;
    while(q--){
        char t;
        cin >> t >> x;
        which[1] -= cnt[x] / 4;
        which[0] -= cnt[x] % 4 / 2;
        cnt[x] += (t=='+'?1:-1);
        which[1] += cnt[x] / 4;
        which[0] += cnt[x] % 4 / 2;
        if(which[1] >= 2 || which[1] == 1 && which[0] >= 2){
            cout << "YES";
        }
        else{
            cout << "NO";
        }
        cout << '\n';
    }
}