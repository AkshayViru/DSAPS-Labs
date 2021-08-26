#include <bits/stdc++.h>
using namespace std;
 
#define int long long int  
#define mod 1000000007

int lcm(int a, int b){
    return (a*b)/__gcd(a,b);
}

void solve(){
    int n;
    cin >> n;
    std::vector<int> arr(n);
    for(int &i: arr)
        cin >> i;

    vector<int> res;
    res.push_back(arr[0]);

    for(int i=1; i<n; i++)
        res.push_back(lcm(arr[i],arr[i-1]));

    res.push_back(arr.back());

    for(int &i: res)
        cout << i << " ";
    cout << endl;
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("tests.in", "r", stdin);
    int t = 1;
    cin >> t;
 
    while(t--){
        solve();
    }
}