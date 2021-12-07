#include <bits/stdc++.h>
using namespace std;
#define int long long int  

bool partitionEqualSubsetSum(int);
int dp[10][50];

signed main(){
    int a, b, res = 0;
    cin >> a >> b;

    for(int i=a; i<=b; i++){
        if(partitionEqualSubsetSum(i)){
            res++;
        }
    }

    cout << res << endl;
}

//top down
bool recur(int idx, int target, vector<int>& arr){
    if(target == 0){
        return true;
    }
    if(idx<0)
        return false;

    if(dp[idx][target] != -1)
        return dp[idx][target];

    if(target >= arr[idx]){
        if(recur(idx-1, target-arr[idx], arr))
            return dp[idx][target] = true;
    }

    return dp[idx][target] = recur(idx-1, target, arr);
}

//bottom up
bool canPartition(vector<int>& arr) {
    int sum = 0;
    for(int &i : arr) 
        sum+=i;
    if(sum&1) 
        return false;

    int tar = sum/2;
    int n = arr.size();

    bool dp[n+1][tar+1];
    memset(dp, false, sizeof dp);
    
    for(int j=0; j<=n; j++) 
        dp[j][0] = true;

    for(int i=1; i<=n; i++){
        int curval = arr[i-1];
        for(int j=1; j<=tar; j++){
            if(curval <= j){
                dp[i][j] = dp[i-1][j] || dp[i-1][j-curval];
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][tar];
}

bool partitionEqualSubsetSum(int x){
    vector<int> arr;
    int sum = 0;
    while(x){
        arr.push_back(x%10);
        sum += x%10;
        x/=10;
    }

    if(sum&1){
        return false;
    }

    int tar = sum/2, n = arr.size();
    memset(dp, -1, sizeof dp);

    return recur(n-1, tar, arr);
}