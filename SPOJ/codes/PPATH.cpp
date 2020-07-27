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
#define debugA(v) for(int i: v) cout<<i<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

int calc(vi k)
{
    reverse(all(k));
    int a=1,ans=0;
    for(auto t:k)
        ans+=a*t,a*=10;
    return ans;
}

vi neig(int a)
{
    vi te;
    while(a)
        te.pb(a%10),a/=10;
    reverse(all(te));
    vi ans;
    for(int i=0;i<te.size();i++)
    {
        vi l=te;
        for(int j=0+(i==0);j<=9;j++)
        {
            l[i]=j;
            ans.pb(calc(l));
        }
    }
    return ans;
}

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;

    vi v(1e4+1,1);
    for(int i=2;i<=1e2;i++)
        for(int j=i*i;j<=1e4;j+=i)
            v[j]=0;

    while(t--)
    {
        int a,b;
        cin>>a>>b;
        vi w(1e4+1,0);
        int ans=0,fl=1;
        queue<int> q;
        q.push(a);
        w[a]=1;
        while(!q.empty() && fl)
        {
            int u=q.front();
            q.pop();
            if(u==b)
            {
                ans=w[u],fl=0;
                break;
            }
            for(auto te:neig(u))
            {
                if(v[te] && !w[te])
                    q.push(te),w[te]=w[u]+1;
                if(te==b)
                {
                    ans=w[u]+1;fl=0;
                    break;
                }
            }
        }
        if(ans)
            cout<<ans-1;
        else
            cout<<"Impossible";
        nl;
    }    
}