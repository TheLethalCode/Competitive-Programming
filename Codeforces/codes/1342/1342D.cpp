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
    int n = 200000, k=200000;
    cin>>n>>k;
    vi v(k+1, 0), cnt(k,0);
    set<int> nz; 
    FOR(i,n){
        int a ; // = min(k, n*(i/(n/2))+1);
        cin>>a;
        v[a]++;
    }
    FOR(i, k){
        cin>>cnt[i];
        // cnt[i]=1;
        if(v[i+1])
            nz.insert(-(i+1));
    }

    vi next(k, -1);
    int tes = -1, val = cnt[0];
    for(int i=0;i<k;){
        while(i<k & cnt[i]==val)
            next[i++] = tes;
        tes = i-1, val=cnt[i]; 
    }

    vector< vi > ans;
    int ct = 0, prev=k;
    while(ct<n)
    {
        vi temp;
        int track=0;
        for(int i=prev;i>0;i--)
        {
            if(!v[i])
            {
                int te = *nz.lower_bound(-i);
                if(i==prev)
                    prev=-te;
                i = -te+1;
                continue;
            }
            int in = max(min(cnt[i-1]-track, v[i]), 0);
            if(!in)
            {
                if(next[i-1]==-1)
                    break;
                i = next[i-1]+2;
                continue;
            }
            v[i]-=in, ct+=in, track+=in;
            FOR(z, in)
                temp.pb(i);
            if(!v[i])
            {
                nz.erase(-i);
                if(i==prev)
                    prev--;
            }
        }
        ans.pb(temp);
    }
    cout<<ans.size()<<endl;
    for(auto te : ans)
    {
        cout<<te.size()<<" ";
        debugA(te);
    }
}