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

int kmp(string s, string t){
    string temp = s + '#' + t;
    int n = sz(temp), k = sz(s) + 1, ma = 0;
    vi pi(n);
    pi[0] = 0;
    for(int i=1;i<n;i++){
        int j = pi[i-1];
        while(j && temp[j]!=temp[i]) j=pi[j-1];
        if(temp[j]==temp[i]) j++;
        pi[i]=j;
    }
    for(int i=k;i<n;i++) ma = max(ma, pi[i]);
    return ma;
}

int main(int argc, char **argv)
{
    crap;
    int n, a, b;
    string s;
    cin>>n>>a>>b>>s;
    bool sub[n+1][n+1];
    int dp[n+1];
    FOR(i, n+1) FOR(j, n+1) sub[i][j]=false, dp[i]=mod;
    dp[0]=0;
    for(int i=1;i<n;i++){
        int ma = kmp(s.substr(i, i), s.substr(0, i));
        for(int j=0;j<ma;j++) sub[i][i+j]=true;
    }
    FOR(i, n){
        dp[i+1] = dp[i]+a;
        FOR(j, i) if(sub[j+1][i]) dp[i+1]=min(dp[i+1], dp[j+1]+b);
    }
    cout<<dp[n]<<endl;
}