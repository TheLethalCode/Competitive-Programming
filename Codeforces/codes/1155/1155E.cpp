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
// %

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

lli poly(lli x, vector< lli > &ans){
    int n = ans.size();
    lli sum = 0;
    FOR(i, n){
        sum += ans[i] * pomo(x, i) % mod;
    }
    return sum % mod;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    vector< vector< lli > > M(11, vector<lli>(11, 0));
    vector< lli > ans(11);
    for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            M[i][j] = pomo(i, j);
        }
        cout << "? " << i << endl;
        cin >> ans[i];
    }
    gaussElimination(M, ans);
    for(int i=0; i<mod; i++){
        if(!poly(i, ans)){
            cout << "! " << i << endl;
            return 0;
        }
    }
    cout << "! -1\n";
    return 0;
}