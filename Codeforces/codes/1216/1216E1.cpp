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
// % ;

int main(int argc, char **argv)
{
    crap;
    vli v(1e7,0);
    v[1]=1;
    for(int i=2;i < 1e7;i++)
    {
        v[i]=v[i-1];
        int j = i;
        while(j != 0)
            v[i]++,j/=10;
    }
    vli sum(1e7,0);
    for(int i=1;i<1e7;i++) sum[i] = sum[i-1] + v[i];
    int q;
    cin>>q;
    while(q--)
    {
        lli n ;
        cin >> n;
        int pos = upper_bound(sum.begin(),sum.end(),n) - sum.begin();
        pos--;
        if(sum[pos] == n) cout<<pos%10;
        else
        {
           int po = upper_bound(v.begin(),v.end(),n-sum[pos]) - v.begin();
           po--;
           if(v[po] == n-sum[pos]) cout<<po%10;
           else
           {
               lli j = n - sum[pos]-v[po],k = po + 1;
               vi temp;
               while(k)
                    temp.push_back(k%10),k/=10;
                reverse(temp.begin(),temp.end());
                cout<<temp[j-1];
           } 
        }
        cout<<endl;
    }

}