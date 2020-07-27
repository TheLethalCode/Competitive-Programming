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
int n, x;
bitset< MAXC > v;

bool solve(bitset< MAXC > v){
    vector< int > C;
    FOR(i, n){
        if(v[i]){
            if(C.size() && (i-C.back())%2){
                C.pop_back();
            }
            else{
                C.pb(i);
            }
        }
    }
    return C.empty();
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i, n){
        cin >> x;
        v[i] = x&1;
    }
    cout << (solve(v)||solve(~v)?"YES":"NO") << '\n';
}