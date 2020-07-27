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
#define pp pop_back

#define nl cout<<endl;
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(auto i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

// %
int main(int argc, char **argv)
{
    crap;
    int k;
    cin>>k;
    while(k--){
        lli h, c, t;
        cin>>h>>c>>t;
        if(t==h){
            cout<<1<<endl;
            continue;
        }
        if(2*t==h+c){
            cout<<2<<endl;
            continue;
        }
        lli ans = 0;
        for(int i=35;i>=0;i--){
            lli ch = ans + (1LL<<i);
            double te = (ch*h+(ch-1)*c)*1.0/(2*ch-1);
            if(te >= t)
                ans = ch;
        }
        double te = (ans*h+(ans-1)*c)*1.0/(2*ans-1), te1 = ((ans+1)*h+ans*c)*1.0/(2*ans+1);
        ans = 2*ans-1;
        if(fabs(te1 - t) < fabs(te - t)) ans+=2;
        if(fabs((h+c)/2.0 - t) < fabs(te - t) && fabs((h+c)/2.0 - t) < fabs(te1 - t)) ans = 2;
        cout<<ans<<endl;
    }
}