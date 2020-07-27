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

vpal func(vli &v, vli &fw, int x=-1)
{
    int n=v.size();
    vpal te, str;
    te.pb({v[0], 1}), fw[0]=v[0];
    if(x==0)
        str = te;
    for(int i=1;i<n;i++)
    {
        int cnt = 1;
        lli sum=fw[i-1];
        while(!te.empty() && te.back().fi >= v[i])
        {
            pal tr = te.back();
            cnt+=tr.se, te.pop_back(), sum-=tr.se*tr.fi;
        }
        fw[i]=sum+cnt*v[i], te.pb({v[i], cnt});
        if(x == i)
            str = te;
    }
    return str;
}

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    vli v(n);
    FOR(i, n) cin>>v[i];
    
    vli fw(n), bk(n);
    func(v, fw);
    reverse(all(v)), func(v, bk), reverse(all(v));
    reverse(all(bk)), bk.pb(0);
    // debugA(fw); debugA(bk);

    lli ma = bk[n-1];
    int cn = -1;
    for(int i=0;i<n;i++)
        if(ma < fw[i]+bk[i+1])
            ma = fw[i]+bk[i+1], cn=i;
    
    vpal ans = func(v, fw, cn);
    reverse(all(v));
    vpal ans1 = func(v, bk, n-2-cn);
    reverse(all(ans1));
    
    for(auto x : ans)
        FOR(i, x.se)
            cout<<x.fi<<" ";
    for(auto x : ans1)
        FOR(i, x.se)
            cout<<x.fi<<" ";
    
    cout<<endl;
}