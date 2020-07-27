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
#define all(v) v.begin(), v.end()
#define sz(a) (int)(a.size())
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
template <class T> inline bool chmin(T a, T b){
    if(a > b){
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmax(T a, T b){
    if(a < b){
        a = b;
        return true;
    }
    return false;
}
// %
int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, cnt=0;
    cin>>n;
    int fact[n+1];
    for(int i=1;i<=n;i++){
        for(int j=2*i;j<=n;j+=i){
            fact[j] = i;
        }
    }
    vector< int > gc(n, 0);
    for(int i=2;i<=n;i++){
        gc[fact[i]]++;
    }
    for(int j=1;j<=n/2;j++){
        FOR(k, gc[j]){
            cout<<j<<" ";
        }
    }
    cout << "\n";
}