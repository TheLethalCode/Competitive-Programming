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
vi mark(26,0);
vector< set<int> > v(26);

void func(int k, string &cur)
{
    // cout<<cur<<" "<<(char)('a' + k)<<endl;
    for(int i : v[k])
    {
        if(mark[i])
            continue;
        else if(cur[0] == 'a' + k)
            cur.insert(0, 1, 'a' + i);
        else
            cur += ('a' + i);

        mark[i] = 1;
        func(i, cur);
    }
}

int main(int argc, char **argv)
{
    crap;
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        vector< set<int> > temp(26);
        vi temp1(26,0);
        v =  temp, mark = temp1;

        int n = s.size();
        for(int i=0;i < n-1;i++)
            v[s[i]-'a'].insert(s[i+1]-'a'), v[s[i+1]-'a'].insert(s[i]-'a');

        string ans = "";
        vector< vi > st(4);
        
        for(int i=0;i<26;i++)
        {
            int k = v[i].size() > 2?3:v[i].size();
            st[k].pb(i);
        }

        if(st[3].size())
        {
            cout<<"NO"<<endl;
            continue;
        }
        
        for(int k : st[0])
            ans+= ('a' + k), mark[k]=1;
        
        vector< string > wtf;

        for(int i=0;i<26;i++)
        {
            if(mark[i])
                continue;

            string temp = "";
            temp += ('a' + i), mark[i] = 1;
            func(i, temp);
            ans += temp;
        }

        int fl = 0;
        for(int i=0;i<26 & !fl;i++)
        {
            int k = ans[i] - 'a';
            int fr, bk;

            if(i)
                fr = ans[i-1] - 'a';
            if(i != 25)
                bk = ans[i+1] - 'a';

            for(int te : v[k])
                if(te != fr && te !=  bk)
                    fl = 1;
        }
        // cout<<ans<<endl;
        if(fl)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl<<ans<<endl;
    }
}