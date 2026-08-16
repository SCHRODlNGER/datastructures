#include <bits/stdc++.h>
#include <queue>
using namespace std;

int getMaxCost(vector<int> &a, int lastEleIdx, int k) {
  int cost = 0;
  cost += a[lastEleIdx];
  vector<int> visited(a.size(), 0);
  visited[lastEleIdx] = 1;
  priority_queue<int, vector<int>, greater<int> > s;
  if (lastEleIdx + 1 < a.size() && lastEleIdx - 1 >= 0) {
    if (a[lastEleIdx + 1] > a[lastEleIdx - 1]) {
      cost += a[lastEleIdx + 1];
      visited[lastEleIdx + 1] = 1;
    } else {
      cost += a[lastEleIdx - 1];
      visited[lastEleIdx - 1] = 1;
    }
  } else if (lastEleIdx + 1 < a.size()) {
    cost += a[lastEleIdx + 1];
    visited[lastEleIdx + 1] = 1;
  } else if (lastEleIdx - 1 >= 0) {
    cost += a[lastEleIdx - 1];
    visited[lastEleIdx - 1] = 1;
  }

  for (int i = 0; i < a.size(); i++) {
    if (visited[i] == 1)
      continue;
    s.push(a[i]);
    if (s.size() > k - 1)
      s.pop();
  }

  while (s.size()) {
    cost += s.top();
    s.pop();
  }
  return cost;
}

void solve() {
  int n;
  int k;
  cin >> n >> k;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cout << getMaxCost(a, i, k) << endl;
    ans = max(ans, getMaxCost(a, i, k));
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif

  long long t = 1;
  cin >> t;
  while (t--)
    solve();
}