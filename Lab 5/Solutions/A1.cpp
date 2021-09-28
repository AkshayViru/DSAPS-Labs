#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> vis(1000002, INT_MAX);
    int mx = 0;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        vis[x] = min(vis[x], i);
        mx = max(mx, x);
    }
    
    int res = 0, cur = 0, start = 0, idx;
    if(vis[0] != INT_MAX)
        cur++;

    for(int i=1; i<=mx+1; i++){
        if(vis[i]==INT_MAX && vis[i-1]!=INT_MAX){
            if(cur > res){
                res = cur;
                start = i-cur;
                idx = vis[start];
            }
            else if(cur == res){
                if(vis[i-cur] < vis[start])
                    start = i-cur;
            }
            cur = 0;
        }
        if(vis[i]!=INT_MAX)
            cur++;
    }

    cout << start << " " << start+res-1;
    
    return 0;
}