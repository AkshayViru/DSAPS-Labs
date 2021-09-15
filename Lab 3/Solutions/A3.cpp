#include <bits/stdc++.h>
using namespace std;
 
#define int long long int  
#define M 1000000007
void init();

void solve(){
    int n, m;
    cin >> n >> m;
    
    // `vals` will have both `a` values and `b` values
    // `a_only` will have only `a` values
    vector<vector<int>> vals;
    vector<int> a_only;
    vector<int> prefix(m,0);

    for(int i=0; i<m; i++){
        int x, y;
        cin >> x >> y;
        vals.push_back({x,y});
        a_only.push_back(x);
    }

    sort(a_only.begin(), a_only.end());
    
    prefix[m-1] = a_only[m-1];
    for(int i=m-2; i>=0; i--){
        prefix[i] = a_only[i]+prefix[i+1];
    }
    
    int res = 0;
    for(auto &z: vals){
        // first take all the `a` values which are greater than current b_i
        int taken = a_only.end() - lower_bound(a_only.begin(), a_only.end(), z[1]);
        int cur_sum = 0;
        
        if(taken >= n){
            // if we have taken more than n values, it's better to take the n greatest values of a
            // sum of n greatest values of a will be in prefix[m-n]
            res = max(res, prefix[m-n]);
        }
        else if(taken > 0){
            cur_sum += prefix[m-taken];
            // If current a_i is less than b_i, we need to add it
            if(z[0] < a_only[m-taken]){
                taken++;
                cur_sum += z[0];
            }
        }
        else{
            // If we have not taken anything, lets add a_i to our current sum
            cur_sum += z[0];
            taken++;
        }
        // add the additional b_i's that we will take
        if(taken < n)
            cur_sum += (n-taken)*z[1];
        res = max(res, cur_sum);
    }

    cout << res << endl;
}
 
signed main(){
    int t = 1;
 
    while(t--){
        solve();
    }
}