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
    lli A, B, C, D;
    cin>>A>>B>>C>>D;
    lli ans = 0;
    for(int z = C; z <= D; z++)
    {
        lli w = z+1-A, t = z+1-B;
        if(w <= B)
            ans += (C-B+1)*(B-A+1);
        else if(w >= C)
        {
            if(t > C)
                ans += 0;
            else if(t < B)
                ans += (C-B+1)*(B-z) + C*(C+1)/2 - (B-1)*(B)/2;
            else
                ans += (C-t+1)*(B-z) + C*(C+1)/2 - (t-1)*(t)/2;
        }
        else
        {
            if(t < B)
                ans += (C-w)*(B-A+1), ans += (w-B+1)*(B-z) + w*(w+1)/2 - (B-1)*(B)/2;
            else if(t > C)
                ans += 0;
            else
                ans += (C-w)*(B-A+1), ans += (w-t+1)*(B-z) + w*(w+1)/2 - (t-1)*(t)/2;
        }
    }
    cout<<ans<<endl;
}