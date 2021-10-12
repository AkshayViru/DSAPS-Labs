
PRACTICE
CERTIFICATIONNEW
COMPETE
JOBS
LEADERBOARD
Search
 akshay7797 
All Contests  DSA Lab 6  Mix Chemical
Mix Chemicallocked
Problem
Submissions
Leaderboard
Discussions
Editorial
 Editorial by akshay7797

If nothing seems to work, think binary search on answer!

Let's denote the points that have greater coordinates in their matched pairs as -points, and the points that have smaller coordinates as -points.

Suppose we have an -point that has smaller coordinate than some -point. Then we can "swap" them, and the answer won't become worse. Also, if some -point has smaller coordinate than some point that doesn't belong to any pair, or some -point has greater coordinate than some point that doesn't belong to any pair, we can swap them too.

So, if the answer is , we choose  leftmost points as -points, and  rightmost ones as -points.

For a fixed value of , it's easy to see that we should match the leftmost -point with the leftmost -point, the second -point with the second -point, and so on, in order to maximize the minimum distance in a pair. This fact allows us to check whether it is possible to construct at least  pairs, and we can use binary search to compute the answer to the problem.

 Set by akshay7797

Problem Setter's code :
#include <bits/stdc++.h>
using namespace std;

#define int long long int  
#define mod 1000000007

bool check(int mid, vector<int>& arr, int k){
    int n = arr.size();

    for(int i=0; i<mid; i++){
        if(arr[n-mid+i]-arr[i]<k)
            return false;
    }

    return true;
}

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int &i: arr) 
        cin >> i;

    sort(arr.begin(), arr.end());
    int l = 0, r = n/2+1, res = 0;

    while(l<r){
        int mid = l + (r-l)/2;
        if(check(mid, arr, k)){
            res = mid;
            l=mid+1;
        }
        else
            r = mid;
    }

    cout << res << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("tests.in", "r", stdin);
    int t = 1;
    //cin >> t;

    while(t--){
        solve();
    }
}
Statistics
Difficulty: Medium

Time Complexity:
O(nlogn)

Required Knowledge: Binary Search

Publish Date: Sep 01 2021

Contest Calendar | Interview Prep | Blog | Scoring | Environment | FAQ | About Us | Support | Careers | Terms Of Service | Privacy Policy | Request a Feature

