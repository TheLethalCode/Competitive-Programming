#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007
#define crap ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define lli long long
#define pa pair<int,int>
#define pal pair<lli,lli>
#define vi vector< int >
#define vli vector< lli >
#define vpa vector< pa >
#define vpal vector< pal >
#define fi first
#define se second
#define pb emplace_back

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) (int)(a.size())
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)
#define perc %

vi prefix(string s){
    int n=sz(s);
    vi pi(n);
    for(int i=1;i<n;i++){
        int j = pi[i-1];
        while(j && s[i]!=s[j]) j=pi[j-1];
        pi[i] = j + (s[i]==s[j]);
    }
    return pi;
}

int func(string &s, vi &pi, int k, char ch){
    while(k == sz(s) || k && s[k]!=ch) k=pi[k-1];
    return k + (s[k]==ch);
}

int main(int argc, char **argv)
{
    crap;
    string c, s, t;
    cin>>c>>s>>t;
    int n = sz(c), p = sz(s), q = sz(t), ans=-mod;
    int dp[n+1][p+1][q+1], kmpS[p+1][26], kmpT[q+1][26];
    vi PIs = prefix(s), PIt = prefix(t);
    
    FOR(i, n+1) FOR(j, p+1) FOR(k, q+1) dp[i][j][k] = -mod; dp[0][0][0]=0;
    FOR(i, p+1) FOR(j, 26) kmpS[i][j] = func(s, PIs, i, 'a'+j);
    FOR(i, q+1) FOR(j, 26) kmpT[i][j] = func(t, PIt, i, 'a'+j);

    FOR(i, n){
        FOR(j, p+1){
            FOR(k, q+1){
                if(dp[i][j][k]==-mod) continue;
                if(c[i]!='*'){
                    int ks = kmpS[j][c[i]-'a'], kt = kmpT[k][c[i]-'a'];
                    dp[i+1][ks][kt] = max(dp[i+1][ks][kt], dp[i][j][k] + (ks==p) - (kt==q));
                }
                else {
                    FOR(x, 26){
                        int ks = kmpS[j][x], kt = kmpT[k][x];
                        dp[i+1][ks][kt] = max(dp[i+1][ks][kt], dp[i][j][k] + (ks==p) - (kt==q));
                    }
                }
            }
        }
    }
    FOR(i, p+1) FOR(j, q+1) ans=max(ans, dp[n][i][j]);
    cout<<ans<<endl;
}