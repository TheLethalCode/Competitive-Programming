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
#define debugA(v) for(int i:v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

int main(int argc, char **argv)
{
    crap;
    int n, m, k;
    cin>>n>>m>>k;
    vpa st(k), ft(k);
    FOR(i,k) cin>>st[i].fi>>st[i].se;
    FOR(i,k) cin>>ft[i].fi>>ft[i].se;
    string ans="";
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(j<m-1)
        {
            if(i)
                ans+='D';
            for(;j<m-1;j++)
                ans+='R';
        }
        else
        {
            ans+='D';
            for(;j>0;j--)
                ans+='L';
        }
    }
    string temp = ans;
    reverse(all(temp));
    for(char &a : temp)
    {
        if(a == 'R')
            a = 'L';
        else if(a == 'L')
            a = 'R';
        else
            a = 'U';
    }
    cout<<2*ans.size()<<endl;
    cout<<ans<<temp<<endl;
}