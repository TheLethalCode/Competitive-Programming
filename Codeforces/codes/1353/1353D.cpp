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

struct lex_compare
{
    bool operator() (pa a, pa b)
    { 
        if(a.se - a.fi == b.se - b.fi)
            return a.fi < b.fi;
        return a.se - a.fi > b.se - b.fi;
    }
};

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        set< pa , lex_compare > st;
        vi ar(n+1,0);
        st.insert({1,n});
        int cnt = 1;
        while(!st.empty())
        {
            pa te = *st.begin();
            int mid = te.fi + te.se >> 1;
            ar[mid] = cnt++;
            st.erase(st.begin());

            if(te.fi <= mid - 1)
                st.insert({te.fi, mid-1});
            
            if(mid+1 <= te.se)
                st.insert({mid+1, te.se});
        }
        for(int i=1;i<=n;i++)
            cout<<ar[i]<<" ";
        cout<<endl;
    }
}