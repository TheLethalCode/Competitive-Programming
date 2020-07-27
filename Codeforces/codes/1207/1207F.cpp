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
#define sz(a) a.size()
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

#define perc %

#define rN 500

int main(int argc, char **argv)
{
    crap;
    int pro[rN][rN], ar[5*100000+2]={}, q;
    FOR(i, rN) FOR(j, rN) pro[i][j]=0;
    cin>>q;
    while(q--){
        int t, x, y;
        cin>>t>>x>>y;
        if(t==1){
            ar[x]+=y;
            FOR(i, rN-1) pro[i+1][x%(i+1)]+=y;
        }
        else{
            if(x < rN) cout<<pro[x][y]<<endl;
            else{
                int sum = 0;
                for(int k = y; k<=500000;k+=x) sum += ar[k];
                cout<<sum<<endl;
            }
        }
    }
}