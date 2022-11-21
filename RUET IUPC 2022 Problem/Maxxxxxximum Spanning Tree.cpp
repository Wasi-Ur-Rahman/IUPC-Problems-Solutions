#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int N = 1e6 + 10;

int par[N];
int sz[N];

void make_set(int n) {
  sz[n] = 1;
  par[n] = n;
}

int find_set(int n) {
  if (par[n] == n) return n;
  return par[n] = find_set(par[n]);
}

void union_set(int a,int b) {
  a = find_set(a);
  b = find_set(b);

  if (a != b) {
    if (sz[a] < sz[b])
      swap(a,b);
    par[b] = a;
    sz[a] += sz[b];
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
    for (int i = 0;i <= n;i++)
      make_set(i);

    for (int i = n;i >= 1;i--) {
      for (int j = i + i;j <= n;j += i) {
        int x = find_set(i);
        int y = find_set(j);

        if (x != y) {
          cost += i;
          union_set(i,j);
        }else continue;
      }
    }
    cout << cost << '\n';
  }
  return 0;
}
