#include <bits/stdc++.h>
using namespace std;
 
#define int long long int  
#define M 1000000007
void init();

void solve(int tc = 1){
    string s;
    cin >> s;
    stack<pair<char,int>> st;
    int n = s.length();
    int k;
    cin >> k;
    k--;

    for(int i=0; i<n; i++){
        if(st.empty()){
            st.push({s[i],1});
        }
        else{
            if(st.top().first == s[i]){
                if(st.top().second == k){
                    while(!st.empty() && st.top().first==s[i])
                        st.pop();
                }
                else{
                    st.push({s[i], st.top().second+1});
                }
            }
            else{
                st.push({s[i], 1});
            }
        }
    }

    string res = "";
    while(!st.empty()){
        res += st.top().first;
        st.pop();
    }

    reverse(res.begin(), res.end());
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