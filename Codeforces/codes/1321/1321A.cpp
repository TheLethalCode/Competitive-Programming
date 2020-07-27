#include<bits/stdc++.h>
using namespace std;

#define modN 1000000007
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

#define nl cout<<"\n"
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v) for(int i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

#define mod %

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    vi r(n), b(n);
    FOR(i,n) cin>>r[i];
    FOR(i,n) cin>>b[i];

    int fl = 0;
    FOR(i,n)
    {
        if(r[i] == 1 && b[i]!=1)
            fl+=1;
    }

    if(!fl)
        cout<<-1;
    else
    {
        int cnt=0;
        FOR(i,n)
        {
            if(b[i]==1 && r[i]!=1)
                cnt++;
        }
        cout<<(int)ceil((cnt+1)*1.0/fl);
    } 
    cout<<endl;
}