#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define mod 1000003
#define lli long long
#define fi first
#define se second
#define pb emplace_back
#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define sz(a) (int)(a.size())
#define MAXC 200005
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// GAUSS ELIMINATION FOR MODULAR EQUATIONS
// N VARIABLES WITH N SYSTEM OF EQUATIONS. O(N^3)

lli pomo(lli n, lli p){
    if(!p){
        return 1;
    }
    if(p&1){
        return pomo(n, p-1)*n%mod;
    }
    lli t = pomo(n, p>>1);
    return t*t%mod;
}

lli modInv(lli n){
    return pomo(n, mod-2);
}

void gaussElimination(vector< vector< lli > > &M, vector< lli > &ans){
    int n = M.size();
    for(int col=0, row = 0; col<n; col++, row++){

        // If variable is 0
        int find = row;
        for(;find < n && !M[find][col];find++);
        if(find == n){
            continue;
        }
        for(int i=0;i < n;i++){
            swap(M[find][i], M[row][i]);
        }
        swap(ans[find], ans[row]);

        // Making the value at that point 1
        lli div = modInv(M[row][col]);
        for(int i=0; i<n; i++){
            M[row][i] = M[row][i] * div % mod;
        }
        ans[row] = ans[row] * div % mod;

        // Making the other positions 0
        for(int i=0; i<n; i++){
            if(i != row){
                lli mult = M[i][col];
                for(int j = 0; j<n; j++){
                    M[i][j] -= mult * M[row][j] % mod;
                    if(M[i][j] < 0){
                        M[i][j] += mod;
                    }
                }
                ans[i] -= mult * ans[row] % mod;
                if(ans[i] < 0){
                    ans[i] += mod;
                }
            }
        }
    }
}
