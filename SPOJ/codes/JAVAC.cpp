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
#define debugA(v,n) for(int i=0;i<n;i++) cout<<v[i]<<" ";nl
#define max3(x,y,z) max(max(x,y),z)
#define min3(x,y,z) min(min(x,y),z)

int main(int argc, char **argv)
{
    crap;
    string s;
    while(cin>>s)
    {
        int fl=1;
        bool under=false;
        for(auto r:s)
            if(r=='_')
                under=true;
        if(under)
        {
            for(auto r:s)
                if(isupper(r))
                    fl=0;
            if(*s.rbegin() == '_' || *s.begin() == '_')
                fl=0;
            for(int i=0;i<s.length()-1;i++)
                if(s[i]=='_' && s[i+1]=='_')
                    fl=0;
        }
        else if(isupper(s[0]))
            fl=0;
        string ans="";
        if(fl && under)
        {
            for(int i=0;i<s.length();i++)
            {
                if(s[i]=='_')
                    i++,s[i]+=-'a'+'A';
                ans+=s[i];
            }
        }
        else if(fl)
        {
            for(auto r:s)
                if(isupper(r))
                    ans+="_",ans.pb(r-'A'+'a');
                else
                    ans+=r;
        }
        if(fl)
            cout<<ans;
        else
            cout<<"Error!";
        nl;
    }
}