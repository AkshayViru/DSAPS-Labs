#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int  
#define M 1000000007
void init();

void solve(int tc = 1){
    string s;
    cin >> s;

    ll hash_L = 0, hash_R = 0, n = s.length(), mx = 10, curmx = 1;

    for(int i=0, j=n-1; i<n-1; i++, j--){
        hash_L = (hash_L*mx+(ll)(s[i]-96))%M;
        hash_R = (hash_R + 1ll*(s[j]-96)*curmx)%M;
        curmx = (curmx*mx)%M;
        if(hash_L == hash_R)
            cout << i+1 << " ";
    }
    
    cout << endl;
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