#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int  
#define M 1000000007
void init();

vector<int> parent, size;

int find(int x){
    if(x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

void union_(int x, int y){
    x = find(x);
    y = find(y);
    
    if(x == y)
        return;
    
    if(size[x] > size[y]){
        parent[y] = x;
        size[x] += size[y];
    }
    else{
        parent[x] = y;
        size[y] += size[x];
    }
}

void solve(int tc = 1){
    int n, m;
    cin >> n >> m;

    parent.assign(n+1, 1);
    size.assign(n+1, 1);

    for(int i=1; i<=n; i++){
        parent[i] = i;
    }

    while(m--){
        int x, y;
        cin >> x >> y;
        union_(x, y);
    }

    int res = 0;

    for(int i=1; i<=n; i++){
        res = max(res, size[i]);
    }

    cout << res << endl;
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