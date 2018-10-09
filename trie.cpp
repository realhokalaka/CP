#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0);cin.tie(NULL);cout.tie(NULL)
#define ll long long int
using namespace std;
const int N = 1e6 + 10;
const ll inf = -1e18;
const int mod = 1e9 + 7;

ll a[N];
struct node{
  node *left, *right;
};

node * getnode(){
  node* curr = new(node);
  curr->right = NULL;
  curr->left = NULL;
  return curr;
}

node *root;
void insert(ll n){
  node *cur = root;
  for(int i = 31; i >= 0; i--){
    ll t = ((1LL << i) & n);
    if(t){
      if(cur->right == NULL)
        cur->right = getnode();
      cur = cur->right;
    }
    else{
      if(cur->left == NULL)
        cur->left = getnode();
      cur = cur->left;
    }
  }
}

ll check(ll n){
  ll ans = 0;
  node *cur = root;
  for(int i = 31; i >= 0; i--){
    ll t = ((1LL << i) & n);
    if(!t){
      if(cur->right){
        cur = cur->right;
        ans |= (1LL << i);
      }
      else
        cur = cur->left;
    }
    else{
      if(cur->left)
        cur = cur->left;
      else{
        cur = cur->right;
        ans |= (1LL << i);
      }
    }
  }
  return ans;
}

int main(){
  fast;
  root = getnode();
  ll n, ans = 0;
  cin >> n;
  cin >> a[0];
  insert(a[0]);
  for(int i = 1; i < n; i++){
    cin >> a[i];
    ans = max(ans, a[i] ^ check(a[i]));
    insert(a[i]);
  }
  cout << ans;

  return 0;
}
