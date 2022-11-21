#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int N = 1e6 + 10;

int par[N];
int sz[N];

int make_set(int n) {
  sz[n] = 1;
  par[n] = n;
}

int find_set(int n) {
  if (par[n] == n) return n;
  else par[n] = find_set(par[n]);
}

int union_set(int a,int b) {
  int p = find_set(a);
  int q = find_set(b);

  if (p != q) {
  	if (sz[p] < sz[q])
  		swap(p,q);
  	par[q] = p;
  	sz[p] += sz[q];
  }
}

int32_t main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(NULL);cout.tie(NULL);

  int t,test = 1;
  cin >> t;
  while (t--) {
    cout << "Case " << test++ << ": ";
    int n,cost = 0;
    cin >> n;
    memset(sz,0,sizeof sz);
    memset(par,0,sizeof par);
    for (int i = 1;i <= n;i++)
      make_set(i); 

    for (int i = n;i >= 1;i--) {
      for (int j = i + i;j <= n;j += i) {
        int x = find_set(i);
        int y = find_set(j);

        if (x != y) {
          cost += i;
          union_set(i,j);
        }
      }
    }
    cout << cost << '\n';
  }
  return 0;
}
