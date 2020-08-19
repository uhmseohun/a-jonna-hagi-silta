#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef pair<int, int> ipair;
int n, k;
vector<ipair> w;
queue<ipair> q;

int square(int v) {
  return v * v;
}

int get_cost(ipair a, ipair b) {
  int x = square(a.first - b.first);
  int y = square(a.second - b.second);
  double dist = sqrt(x + y);
  return int(dist) / 10;
}

int main() {
  scanf("%d %d", &n, &k);
  int x, y;
  for(int i=0; i<n; ++i) {
    scanf("%d %d", &x, &y);
    w.push_back(make_pair(x, y));
  }
  const ipair src = make_pair(0, 0);
  const ipair dest = make_pair(10000, 10000);
  w.push_back(dest);
  q.push(src);
  while(!q.empty()) {
    const ipair f = q.front();
    for(const ipair &u: w) {
      
    }
  }
  return 0;
}
