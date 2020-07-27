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
#define debug2(x,y) cout<<#x<<" "<<x<<", "<<#y<<" "<<y;
#define debugA(v) for(int i:v) cout<<i<<" ";
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;

        vi big, small;
        if(s[0]=='<') small.pb(0);
        else big.pb(0);

        if(s[n-2]=='>') small.pb(n-1);
        else big.pb(n-1);

        for(int i=0; i<n-2; i++)
            if(s[i]!=s[i+1])
                if(s[i]=='<')
                    big.pb(i+1);
                else
                    small.pb(i+1);

        sort(all(big)), sort(all(small));
        
        int sB = big.size(), sS = small.size();
        vi ch(n,0);
        for(int i:big) ch[i] = 1;
        for(int i:small) ch[i] = -1;

        int bi = n, sma = 1;
        vi arr(n,-1);
        for(int i:big)
        {
            arr[i] = bi--;
            int j = i-1;
            while(j>=0 && ch[j]!=-1) arr[j--] = bi--; 
            if(arr[j] == -1) arr[j] = bi--; 
            j = i+1;
            while(j<n && ch[j]!=-1) arr[j++] = bi--;
        }
        if(arr[n-1]==-1) arr[n-1]=bi--;

        bi = n, sma = 1;
        vi arr1(n,-1);
        for(int i:small)
        {
            arr1[i] = sma++;
            int j = i-1;
            while(j>=0 && ch[j]!=1) arr1[j--] = sma++; 
            if(arr1[j] == -1) arr1[j] = sma++; 
            j = i+1;
            while(j<n && ch[j]!=1) arr1[j++] = sma++;
        }
        if(arr1[n-1]==-1) arr1[n-1]=sma++;
        debugA(arr);cout<<endl;
        debugA(arr1);cout<<endl;
    }
}