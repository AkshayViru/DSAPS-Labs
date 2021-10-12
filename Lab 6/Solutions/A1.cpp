#include <bits/stdc++.h>
using namespace std;
 
#define int long long int  
#define M 1000000007
void init();

void solve(int tc = 1){
    int n, m;
    cin >> n >> m;
    int res = -1, start = -1, last = -1;

    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        if(last == -1){
            start = x;
        }
        else if(res == -1){
            res = x-last;
        }
        else{
            res =__gcd(res, x-last);
        }
        last = x;
    }

    int ans = -1;
    for(int i=0; i<m; i++){
        int x;
        cin >> x;
        if(res%x == 0){
            ans = max(ans, x);
        }
    }

    if(ans != -1){
        cout << "YES\n" << start << " " << ans << endl;
    }
    else{
        cout << "NO\n";
    }
}
 
signed main(){
    init();
    int t = 1;
    cin >> t;
 
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