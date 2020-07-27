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

#define nl cout<<"\n"
#define FOR(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
#define debug1(x) cout<<#x<<" "<<x;nl
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;nl
#define debugA(v,n) for(int i=0;i<n;i++) cout<<v[i]<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

int main(int argc, char **argv)
{
    crap;
    while(1)
    {
        int n,m;
        cin>>n;
        if(!n)
            break;
        vi a(n);
        FOR(i,n) cin>>a[i];
        cin>>m;
        vi b(m);
        FOR(i,m) cin>>b[i];
        lli ans=0,te1=0,te2=0;
        int i=0,j=0,laj=-1,lai=-1;
        while(i<n && j<m)
        {
            if(i!=lai)
                te1+=a[i];
            if(j!=laj)
                te2+=b[j];
            lai=i,laj=j;
            if(a[i] < b[j])
                i++;
            else if(a[i] > b[j])
                j++;
            else
            {
                ans+=max(te1,te2);
                te1=te2=0;
                i++,j++;
            }
        }
        i+=(i==lai),j+=(j==laj);
        while(i<n)
            te1+=a[i],i++;
        while(j<m)
            te2+=b[j],j++;
        // debug2(te1,te2);
        ans+=max(te1,te2);
        cout<<ans<<endl;
    }
}