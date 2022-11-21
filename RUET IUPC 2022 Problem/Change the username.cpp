#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int N = 1e6 + 10;

int32_t main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);cout.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
  	int n;
  	cin >> n;
  	map<string,string> par;
  	map<string,int> mp;

  	for (int i = 1;i <= n;i++) {
  	  int type;
  	  cin >> type;
  	  if (type == 1) {
  	  	string x,y;
  	  	cin >> x >> y;

  	  	if (par[x].empty()) par[x] = x;
  	  	mp[x]++;

  	  	if (par[y].empty()) {
  	  	  par[y] = par[x];
  	  	  par[x].erase();
  	  	  mp[y]++;
  	  	}
  	  }else {
  	  	string x;
  	  	cin >> x;

  	  	if (mp[x]) {
  	  	  if (par[x].empty())
  	  	  	cout << "Not in use!\n";
  	  	  else cout << par[x] << '\n';
  	  	}else {
  	  	  cout << x << '\n';
  	  	  mp[x]++;
  	  	  par[x] = x;
  	  	}
  	  }
  	}
  }


  return 0;
}
