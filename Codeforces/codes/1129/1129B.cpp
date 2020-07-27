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
#define mp make_pair

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
    int k, x=-1, r1, r2;
    cin>>k;
    for(r1=1;r1<2000 && x==-1;r1++){
        for(r2=1;r1+r2<=2000 && x==-1;r2++){
            if((k+r2)%(r1) || (k+r2)/r1 >= 1e6) continue;
            x = (k+r2)/r1 + 1; 
        }
    }
    r2--, r1--;
    if(x!=-1){
        cout<<r1+r2<<endl;
        FOR(i, r1-1) cout<<0<<" ";
        cout<<-1<<" ";
        FOR(i, r2-1) cout<<1<<" ";
        cout<<x-r2+1<<endl;
    }
    else cout<<-1<<endl;
}