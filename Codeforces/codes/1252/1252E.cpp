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

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    lli L, R, K;
    cin >> n >> L >> R >> K;
    vector< lli > v(n), B(n);
    FOR(i, n){
        cin>>v[i];
    }
    B[n-1] = L;
    for(int i=n-2;i>=0;i--){
        B[i] = max(L, B[i+1] - (v[i+1]>v[i])*K + (v[i]>v[i+1]));
        if(B[i] > R){
            cout << -1 << "\n";
            return 0;
        }
    }
    for(int i=1;i<n;i++){
        if(v[i]==v[i-1]){
            B[i]=B[i-1];
        }
        else if(v[i] > v[i-1]){
            B[i]=max(B[i-1]+1, B[i]);
        }
        else{
            B[i]=max(B[i], B[i-1]-K);
            if(B[i] >= B[i-1]){
                cout << -1 << "\n";
                return 0;
            }
        }
        if(B[i] > R || abs(B[i]-B[i-1]) > K){
            cout << -1 << "\n";
            return 0;
        }
    }
    FOR(i, n){
        cout << B[i] << " ";
    }
    cout << "\n";
    return 0;
}