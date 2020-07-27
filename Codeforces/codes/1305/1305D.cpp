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

void bfs(int i, vector< vi >& ed, vi eli, vi& par)
{
    queue<int> q;
    q.push(i);
    par[i] = 0;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        eli[u] = 1;
        for(int v : ed[u])
        {
            if(eli[v] || par[v]!=-1)
                continue;
            par[v] = par[u] + 1;
            q.push(v);
        }
    }
}

int main(int argc, char **argv)
{
    crap;
    int n;
    cin>>n;
    vector< vector<int> > v(n+1);
    FOR(i,n-1)
    {
        int a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    FOR(i,n)
        sort(all(v[i+1]));
    
    vi eli(n+1,0);
    int el = 0;
    int cur = 1;

    while(el < n-1)
    {
        int k, fl=0;
        for(int i=1;i<=n;i++)
        {
            if(i==cur)
                continue;
            if(eli[i])
                continue;
            if(*lower_bound(all(v[cur]),i) == i)
                continue;
            k=i, fl=1;
            break;
        }
        if(!fl)
        {
            for(int u: v[cur])
                if(!eli[u])
                {
                    cur=u;
                    break;
                }

            if(el < n-2)   
                continue;

            for(int u: v[cur])
                if(!eli[u])
                {
                    k=u;
                    break;
                }

            cout<<"? "<<cur<<" "<<k<<endl;
            cout<<flush;
            
            int w;
            cin>>w;
            if(w==-1)
                return 0;

            cout<<"! "<<w<<endl;
            cout<<flush;
            return 0;
        }
        cout<<"? "<<cur<<" "<<k<<endl;
        cout<<flush;
        
        int w;
        cin>>w;
        if(w==-1)
            return 0;
        
        vi s1(n+1,-1), s2(n+1,-1), an(n+1,-1);
        bfs(w, v, eli, an);
        bfs(cur, v, eli, s1);
        bfs(k, v, eli, s2);

        int d1 = an[cur], d2 = an[k];
        vi re;

        for(int u: v[w])
            if(s1[u] + 1 == d1 || s2[u] + 1 == d2)
                re.pb(u);

        for(int u:re)
        {
            vi dis(n+1,-1);
            bfs(u, v, eli, dis);
            for(int i=1;i<=n;i++)
                if(dis[i] < an[i])
                    if(!eli[i])
                        eli[i] = 1, el++;
        }
        cur = w;
    }
    for(int i=1;i<=n;i++)
        if(!eli[i])
        {
            cout<<"! "<<i<<endl;
            cout<<flush;
            exit(0);
        }
}