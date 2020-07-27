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
int n, hi, v[MAXC];

bool solve(){
    vector< int > C;
    FOR(i, n){
        if(C.size() && v[i] > C.back()){
            return false;
        }
        if(C.size() && v[i] == C.back()){
            C.pop_back();
        }
        else{
            C.pb(v[i]);
        }
        hi = max(v[i], hi);
    }
    if(C.empty () || C.back() == hi){
        return C.size() <= 1;
    }
    return false;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    FOR(i, n){
        cin >> v[i];
    }
    cout << (solve()?"YES":"NO") << '\n';
}