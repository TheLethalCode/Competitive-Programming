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
#define pb push_back

#define FOR(i,n) for(int i=0;i<n;i++)
#define FORR(x,v) for(auto x : v)
#define all(v) v.begin(), v.end()
#define sz(a) (int)(a.size())
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

#define perc %

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        int ar[n][n];
        if(k%n) cout<<2<<endl;
        else cout<<0<<endl;
        FOR(i, n) FOR(j, n) ar[i][j]=0;
        for(int i=0;i<n && k;i++)
            for(int j=0;j<n && k;j++)
                ar[(i+j)%n][j]=1, k--;
        FOR(i, n){
            FOR(j, n) cout<<ar[i][j];
            cout<<endl;
        }
    }
}