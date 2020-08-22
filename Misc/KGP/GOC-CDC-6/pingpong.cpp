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

lli pomo(lli n, lli p){
    if(!p){
        return 1;
    }
    if(p & 1){
        return pomo(n, p-1) * n % mod;
    }
    lli t = pomo(n, p >> 1);
    return t * t % mod;
}

vector< lli > fact(MAXC, 1);

lli nCr(int n, int r){
    lli low = pomo(fact[n-r], mod-2) * pomo(fact[r], mod-2) % mod;
    return fact[n] * low % mod;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, n, x, y;
    cin >> t;
    for(int i=1;i<MAXC;i++){
        fact[i] = fact[i-1] * i % mod;
    }
    while(t--){
        cin >> n >> x >> y;
        if(x < y){
            swap(x, y);
        }
        if(x == n && x - y >= 2){
            cout <<  nCr(n - 1 + y, y) << '\n';
        }
        else if(x > n && x - y == 2){
            cout << nCr(2*n - 2, n - 1) * pomo(2, y - n + 1) % mod << '\n';
        }
        else{
            cout << "0\n";
        }
    }
}