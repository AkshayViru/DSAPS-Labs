#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int  
#define M 1000000007
void init();

typedef struct node{
    ll cnt;
    node* childs[2];

    node(){
        cnt = 0;
        childs[0] = nullptr;
        childs[1] = nullptr;
    }
}node;

class Trie{
    node* root;

public:

    Trie(){
        root = new node();
    }

    void insert(ll x){
        node* cur = root;

        for(int i=62; i>=0; i--){
            int bit = ((x>>i)&1ll);
            if(!cur->childs[bit]){
                node* tmp = new node();
                cur->childs[bit] = tmp;
            }
            cur = cur->childs[bit];
            cur->cnt++;
        }
    }

    ll get(ll x, ll k){
        node* cur = root;
        ll res = 0;

        for(ll i=62; i>=0; i--){
            int bit = ((x>>i)&1ll);
            if(cur->childs[bit] && cur->childs[bit]->cnt >= k){
                cur = cur->childs[bit];
            }
            else if(!cur->childs[bit]){
                cur = cur->childs[1-bit];
                res |= (1ll<<i);
            }
            else if(!cur->childs[1-bit]){
                cur = cur->childs[bit];
            }
            else{
                k -= cur->childs[bit]->cnt;
                cur = cur->childs[1-bit];
                res |= (1ll<<i);
            }
        }

        return res;
    }

};


void solve(int tc = 1){
    int n;
    cin >> n;

    Trie trie;

    while(n--){
        int x;
        cin >> x;

        if(x == 1){
            ll y;
            cin >> y;
            trie.insert(y);
        }
        else{
            ll y, k;
            cin >> y >> k;
            cout << trie.get(y, k) << endl;
        }
    }

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