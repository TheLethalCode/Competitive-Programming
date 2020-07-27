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
#define debugA(v) for(int i:v) cout<<i<<" ";
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)


lli n, x1, x2;
vpal c;
vli sir;

bool check(int k1, int k2, lli x1, lli x2, vi& v1, vi& v2)
{

    lli p1 = ceil(x1*1.0/k1);
    int pos1 = lower_bound(all(sir), p1) - sir.begin();
    if(pos1 + k1 + k2 > n)
        return false;
    
    v1.clear(), v2.clear();
    for(int i = 0; i < k1;i++)
        v1.pb(c[i+pos1].se + 1);
    for(int i = 0; i < k2;i++)
        v2.pb(c[n-1-i].se + 1);
    return true;
}

int main(int argc, char **argv)
{
    crap;
    cin>>n>>x1>>x2;
    c.resize(n);

    FOR(i, n) { cin>>c[i].fi; c[i].se = i; }
    sort(all(c));
    for(auto k : c) sir.pb(k.fi);
    
        
    int fl=0;
    vi v1, v2;
    int ind = -1;
    for(int i=n-1;i>=0;i--)
        if(sir[i] * (n-i) >= x2)
        {
            ind = n-i;
            break;
        }

    if(ind != -1)
    {
        for(int i=1;i<n;i++)
            if((x1*1.0/i) <= (x2*1.0/ind) && check(i, ind, x1, x2, v1, v2))
            {
                fl=1;
                break;
            }
    }

    if(!fl)
    {
        for(int i=n-1;i>=0;i--)
            if(sir[i] * (n-i) >= x1)
            {
                ind = n-i;
                break;
            }
    
        if(ind != -1)
        {
            for(int i=1;i<n;i++)
                if((x2*1.0/i) <= (x1*1.0/ind) && check(i, ind, x2, x1, v2, v1))
                {
                    fl=1;
                    break;
                }
        }
    }
    
    if(!fl)
        cout<<"No"<<endl;
    else
    {
        cout<<"Yes"<<endl;
        cout<<v1.size()<<" "<<v2.size()<<endl;
        debugA(v1);cout<<endl;
        debugA(v2);cout<<endl;
    }
}