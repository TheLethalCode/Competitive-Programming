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

map< pair< string, int > , int > st;

int findClassy(string l, string r, int prev)
{
    if(prev > 3)
        return 0;

    if(prev == 3)
    {
        for(char t : l)
            if(t != '0')
                return 0;
        return 1;
    }

    if(l.size() == 1)
        return r[0] - l[0] + 1;
    
    if(l[0] == r[0])
        return findClassy(l.substr(1), r.substr(1), prev + (l[0]!='0'));
    
    if(l[0] < r[0])
    {
        string k(r.size()-1,'9'), z(r.size()-1,'0');
        string te = "", te1 = ""; te += l[0], te1 += r[0];
        int l1 = r.size() - 1;
        int ans = (r[0] - l[0] - 1) * ((prev<3)*1 + (prev<2)*l1*9 + (prev<1)*(l1*(l1-1)/2)*9*9);
        int x = findClassy(l, te + k, prev), y = findClassy(te1 + z, r, prev);
        return  x + y + ans;
    }
    return 0;
}

int main(int argc, char **argv)
{
    crap;
    int t=1;
    cin>>t;

    vector< vli > dp(19,vli(4,0));

    while(t--)
    {
        string l, r;
        lli ans = 0;
        cin>>l>>r;

        int k = r.size();
        reverse(all(l));
        while(l.size() < r.size())
            l.pb('0');
        reverse(all(l));

        cout<<findClassy(l,r,0)<<endl;
    }
}