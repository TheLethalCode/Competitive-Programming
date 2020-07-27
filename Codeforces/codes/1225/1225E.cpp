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
#define MAXC 2003
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// %

lli R[MAXC][MAXC], D[MAXC][MAXC], sumR[MAXC][MAXC], sumD[MAXC][MAXC];
int Rf[MAXC][MAXC], Cf[MAXC][MAXC], Rr[MAXC][MAXC], Cr[MAXC][MAXC];

inline void func(lli &x){
    if(x >= mod){
        x -= mod;
    }
    if(x < 0){
        x += mod;
    }
}

inline void norm(int i, int j){
    func(R[i][j]);
    func(D[i][j]);
    func(sumR[i][j]);
    func(sumD[i][j]);    
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector< string > s(n);
    FOR(i, n){
        cin >> s[i];
    }
    if(n==1 && m==1){
        cout << 1 << "\n";
        return 0;
    }
    for(int i=n;i;i--){
        for(int j=m;j;j--){
            Rf[i][j] = Rf[i][j+1] + (s[i-1][j-1]=='.');
            Cf[i][j] = Cf[i+1][j] + (s[i-1][j-1]=='.');
            Rr[i][j] = j;
            Cr[i][j] = i;
        }
    }
    for(int i=n;i;i--){
        for(int j=m;j;j--){
            Rr[i][j+Rf[i][j+1]] = j;
            Cr[i+Cf[i+1][j]][j] = i;
        }
    }
    for(int i=n;i;i--){
        for(int j=m;j;j--){
            Rr[i][j-1] = min(Rr[i][j-1], Rr[i][j]);
            Cr[i-1][j] = min(Cr[i-1][j], Cr[i][j]);
        }
    }
    R[1][1] = D[1][1] = sumD[1][1] = sumR[1][1] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i==1 && j==1){
                continue;
            }
            R[i][j] = sumD[i-1][j] - sumD[Cr[i][j]-1][j];
            D[i][j] = sumR[i][j-1] - sumR[i][Rr[i][j]-1];
            sumR[i][j] = sumR[i][j-1] + R[i][j];
            sumD[i][j] = sumD[i-1][j] + D[i][j];
            norm(i, j);
        }
    }
    cout << (R[n][m] + D[n][m]) % mod << "\n";
}