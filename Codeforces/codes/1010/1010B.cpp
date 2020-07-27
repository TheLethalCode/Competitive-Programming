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
    int n, m;
    cin>>m>>n;

    int q = 1;
    string ch = "";
    int ans = 0, i = 29;

    while(true)
    {
        if(q <= n)
        {
            cout<<1<<"\n";
            cout<<flush;
            int r;
            cin>>r;
            if(r == -1)
                ch+='1';
            else if(r == 1)
                ch+='0';
            else
                exit(0);
        }
        else
        {
            while(ans + (1<<i) > m)
                i--;
            cout<<(ans + (1<<i))<<"\n";
            cout<<flush;
            int k;
            cin>>k;
            if(ch[q%n?q%n-1:n-1] == '0')
                k*=-1;
            if(k == -1)
                ans += 1 << i;
            i--;
            if(k == 0)
                exit(0);
        }
        q++;
    }
}