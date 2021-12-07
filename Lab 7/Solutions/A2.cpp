#include <bits/stdc++.h>
using namespace std;
 
#define int long long int  
#define mod 1000000007
 
int exp(int a, int b){
    int res = 1;

    while(b){
        if(b&1) res = (res*a)%mod;
        a = (a*a)%mod;
        b >>= 1;
    }

    return res;
}
 
signed main(){ 
    int x, y, n;
    cin >> x >> y >> n;

    int powr = exp(5, n/2);
    int res_x = (powr*x)%mod, res_y = (powr*y)%mod;

    if(n&1){
        int org_x = res_x, org_y = res_y;
        res_x = (mod + org_y - (2*org_x)%mod)%mod;
        res_y = (mod + (2*org_y)%mod + org_x)%mod;
    }

    cout << res_x << " " << res_y << endl;
}
