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
int n;
string s, t, s1, t1;

bool can(int st, int en){
    int cur = st;
    for(int i=0;i<n;i++){
        if(s[i] == t[cur]){
            cur++;
            if(cur == en){
                return true;
            }
        }
    }
    return false;
}

void solve(){
    for(int l=n;l>0;l--){
        for(int i=0, j=i+l-1; j<n; i++, j++){
            if(can(i, j+1)){
                cout << n-l << "\n";
                return;
            }
        }
    }
}
int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--){
        cin >> n >> s >> t;
        s1 = s, t1 = t;
        sort(s1.begin(), s1.end()), sort(t1.begin(), t1.end());
        if(s1 != t1){
            cout << -1 << "\n";
            continue;
        }
        solve();
    }
}