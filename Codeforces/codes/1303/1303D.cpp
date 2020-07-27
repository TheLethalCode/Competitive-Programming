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
    int t;
    cin>>t;

    vli pow2(62, 1);
    FOR(i,61)
        pow2[i+1] = 2*pow2[i];

    while(t--)
    {
        lli n, m;
        cin>>n>>m;

        vli cnt(62,0);
        lli tot = 0, ans=0;
        for(int i=0;i<m;i++)
        {
            int x;
            cin>>x;
            tot += x, x = log2(x);
            cnt[x]++;
        }

        if( tot < n)
        {
            cout<<-1<<endl;
            continue;
        }

        int bi = 0;
        while(n)
        {
            if(n % 2)
            {
                lli x=0;
                int k = bi;
                
                while(k >= 0 && x < pow2[bi])
                    x+=pow2[k]*cnt[k], k--;

                if(x >= pow2[bi])
                { 
                    k = bi, x = 0;
                    while(k >= 0 & x < pow2[bi])
                    {
                        if(x + cnt[k]*pow2[k] <= pow2[bi])
                            x += cnt[k]*pow2[k], cnt[k]=0;
                        else
                        {
                            lli te = (pow2[bi] - x)/pow2[k];
                            x += te * pow2[k], cnt[k] -= te;
                        }
                        k--;
                    }
                }
                else
                {
                    k = bi;
                    while(!cnt[k])
                        k++;
                    cnt[k]--;
                    for(int i=k-1;i>=bi;i--)
                        cnt[i]++;
                    ans += k-bi;
                }
            }
            n/=2, bi++;
        }
        cout<<ans<<endl;
    }
}