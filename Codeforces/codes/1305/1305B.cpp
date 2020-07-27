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

int main(int argc, char **argv)
{
    crap;
    string s;
    cin>>s;
    int n = s.length();
    int cnt=0, fl=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='(') cnt++;
        
        int te = 0;
        for(int j=i+1;j<n;j++) if(s[j] == ')') te++;
        
        if(cnt == te) break;
        else if(cnt > te)
        {
            fl = 1;
            break;
        }
    }
    if(fl) cnt--;
    if(!cnt) cout<<0<<endl;
    else
    {
        cout<<1<<endl<<2*cnt<<endl;
        int i=0, te=0;
        for(;te<cnt;i++) if(s[i]=='(') cout<<i+1<<" ", te++;
        te=0,i=n-1;
        vi ar;
        for(;te<cnt;i--) if(s[i]==')') ar.pb(i+1), te++;
        reverse(all(ar));
        for(int x:ar) cout<<x<<" ";
        cout<<endl;
    }
}