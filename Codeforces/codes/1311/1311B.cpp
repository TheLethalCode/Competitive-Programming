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
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vi v(n), p(m);
        FOR(i,n) cin>>v[i];
        FOR(j,m) cin>>p[j];
        vi te = v;
        sort(all(te));
        vi ch(n,0);
        sort(all(p));
        int cnt = 1;

        FOR(i,m)
        {
            if(ch[p[i]-1] || ch[p[i]])
            {
                int k = max(ch[p[i]-1],ch[p[i]]);
                ch[p[i]-1]=ch[p[i]] = k;
            }
            else
                ch[p[i]-1]=ch[p[i]]=cnt++;
        }
        // debugA(ch);
        // cout<<endl;
        // exit(0);
        int i=0;
        FOR(i,n) 
            if(!ch[i] && te[i]!=v[i]) 
            {
                cout<<"NO"<<endl;
                goto damn;
            }
        // debugA(ch);
        // cout<<"hi"<<endl;
        while(i<n-1)
        {
            multiset<int> wtf;
            int j = i;
            while(i < n-1 && ch[i] && ch[i]==ch[i+1]) wtf.insert(v[i]), i++;
            if(ch[i] == ch[i-1]) wtf.insert(v[i]);
            for(int a : wtf)
            {
                // cout<<a<<"! ";
                if(te[j++] != a)
                {
                    cout<<"NO"<<endl;
                    goto damn;
                }
            }
            i++;
        }
        cout<<"YES"<<endl;
        damn:;
    }
}