#include <bits/stdc++.h>
using namespace std;
 
#define int long long int  
#define M 1000000007
void init();

void solve(){
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;

    int cnt = 0, last = -1;

    for(int i=0; i<n; i++){
        if(s[i] == '0')
            last = i;
        else if(last != -1){
            cnt++;
            last = -1;
        }
    }
    if(s.back() != '1')
        cnt++;

    int res = LLONG_MAX;

    if(cnt == 0){
        cout << 0 << endl;
        return;
    }

    for(int i=cnt; i>0; i--){
        res = min(res, 1ll*i*y+(cnt-i)*x);
        //cout << i << " " << 1ll*i*y+(cnt-i)*x << endl;
    }


    cout << res << endl;
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