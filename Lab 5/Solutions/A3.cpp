#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int  
#define M 1000000007
void init();

void solve(int tc = 1){
    int n;
    cin >> n;
    vector<int> arr(n);
    ll res = 0;

    for(int &i: arr)
        cin >> i;

    for(int i=0; i<n; i++){
        priority_queue<int> maxpq;
        priority_queue<int, vector<int>, greater<int>> minpq;
        for(int j=i; j<n; j++){
            if((j-i)%2 == 0){
                if(maxpq.empty()){
                    maxpq.push(arr[j]);
                }
                else if(arr[j] <= maxpq.top()){
                    maxpq.push(arr[j]);
                }
                else{
                    minpq.push(arr[j]);
                    maxpq.push(minpq.top());
                    minpq.pop();
                }
                res += maxpq.top();
            }
            else{
                if(arr[j] >= maxpq.top()){
                    minpq.push(arr[j]);
                }
                else{
                    maxpq.push(arr[j]);
                    minpq.push(maxpq.top());
                    maxpq.pop();
                }
            }
        }
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