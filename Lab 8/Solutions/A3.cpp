#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int  
#define M 1000000007
void init();

unordered_map<int,int>par;

int find(int x){
    if(par.count(x) == 0){
        return x;
    }
    return par[x] = find(par[x]);
}
void merge(int x,int y){
    int parx = find(x);
    int pary = find(y);
    if(parx == pary)
        return;

    par[pary] = parx;
}


bool comp(vector<int>&a,vector<int>&b){
    return a[2] < b[2];
}

int ub(vector<vector<int>>&a,int val){
    int left = 0;
    int right = (int)a.size();
    while(left < right)
    {
        int mid = left + (right - left)/2;
        if(a[mid][2] > val)
        {
            right = mid;
        }
        else
        {
            left = mid+1;
        }

    }

    return left;
}

void solve(int tc = 1){
    int n,m;
    cin >> n >> m;
    par.clear();

    vector<vector<int>> edges(n,vector<int>(3)),queries(m,vector<int>(3));

    for(int i=0;i<n;i++){
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    for(int i=0;i<m;i++){
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
    }
    
    sort(edges.begin(),edges.end(),comp);
    sort(queries.begin(),queries.end(),comp);

    int start = 0;
    int ans = 0;
    for(auto q:queries){
        int end = ub(edges,q[2]);
        while(start < end){
            merge(edges[start][0],edges[start][1]);
            start++;
        }
        if(find(q[0]) == find(q[1]))
            ans++;
    }

    cout << ans << endl;
}
 
signed main(){
    init();
    int t = 1;
    //cin >> t;
 
    for(int i=1; i<=t; i++){
        solve(i);
    }
}

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt","w",stdout);
    #endif
}