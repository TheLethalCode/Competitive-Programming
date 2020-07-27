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
        int n, ans = 0;
        cin>>n;
        vi v(n);
        FOR(i, n) cin>>v[i];
        sort(all(v));
        n = unique(all(v)) - v.begin();
        for(int i=n-1;i>=0;i--){
            int a1 = v[i], a2 = 0, a3 = 0, j;
            for(j=i-1;j>=0 && !a2;j--) if(a1%v[j]) a2=v[j];
            for(int k=i-1;k>=0 && !a3;k--) if(a1%v[k] && a2%v[k]) a3=v[k];
            ans = max(ans, a1+a2+a3);
        }
        cout<<ans<<endl;
    }
}