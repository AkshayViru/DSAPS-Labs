#include <bits/stdc++.h>
using namespace std;
 
#define int long long int  
#define M 1000000007

void solve(){
    string s;
    cin >> s;

    int last_L = -1, last_R = -1, n = s.length(), res = 0;

    for(int i=0; i<n; i++){
        if(s[i] == 'L'){
            if(last_R >= last_L){
                res = (res + (last_R+1)*(n-i))%M;
            }
            last_L = i;
        }
        else if(s[i] == 'R'){
            if(last_L >= last_R){
                res = (res + (last_L+1)*(n-i))%M;
            }
            last_R = i;
        }
    }

    cout << res << endl;
}
 
signed main(){
    int t = 1;
    // cin >> t;
 
    while(t--){
        solve();
    }
}
