#include <bits/stdc++.h>
using namespace std;
 
#define int long long int  
#define M 1000000007
void init();
int dp[1001];
int solve(int n){
    if(n == 1)
        return 0;

    dp[n] = 1+solve(n-1);

    if(n%2==0)
        dp[n] = min(dp[n],1+solve(n/2));
    if(n%3==0)
        dp[n] = min(dp[n],1+solve(n/3));

    return dp[n];
}

void solve(){
    int n;
    cin >> n;
    memset(dp, -1, sizeof dp);
    cout << solve(n) << endl;
}
 
signed main(){
    init();
    int t = 1;
    //cin >> t;
 
    while(t--){
        solve();
    }
}

void init(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("tests.in", "r", stdin);
        //freopen("output.txt","w",stdout);
    #endif
}