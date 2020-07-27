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

// %
int a,b,c;

pair<bool, pair< int, pa > > poss(int k, int rem)
{
    int j=max(1, (int)ceil((b-rem)*1.0/k));
    while(abs(k*j - b) <= rem)
    {
        int r = 1, cur = rem - abs(k*j - b), teb = k*j;
        r = max(1, (int)ceil((c-cur)*1.0/teb));
        while(abs(teb*r - c) <= cur)
            return {true,{k,{teb,teb*r}}};
        j++;
    }
    return {false,{0,{0,0}}};
}

pair<bool, pair< int, pa > > can(int ans)
{
    if(abs(b-a)+abs(c-a) <= ans)
        return {true,{a,{a,a}}};
    
    if(abs(c-b) + abs(c-a) <=  ans)
        return {true,{c,{c,c}}};
    
    if(abs(c-b) + abs(a-b) <= ans)
        return {true,{b,{b,b}}};

    for(int i=0;i<=ans;i++)
    {
        pair<bool, pair< int, pa > > val = poss(a+i, ans-i);
        if(val.fi)
            return val;
        val = poss(a-i,ans-i);
        if(a-i > 0 && val.fi)
            return val;
    }
    return {false,{0,{0,0}}};
}

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        int ans = 1 << 15;
        pair<bool, pair< int, pa > > num,anss;
        for(int i=14;i>=0;i--)
        {
            pair<bool, pair< int, pa > > num = can(ans-(1<<i));
            if(num.fi)
                anss = num, ans -= 1<<i;
        }
        num = can(0);
        if(num.fi)
            ans = 0, anss = num;
        cout<<ans<<endl;
        cout<<anss.se.fi<<" "<<anss.se.se.fi<<" "<<anss.se.se.se<<endl;
    }
}