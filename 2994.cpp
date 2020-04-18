#include <cstdio>
#include <climits>
#include <algorithm>
#include <set>
#include <cstdlib>
#include <vector>
using namespace std;
// <position, distance>
typedef pair<int, int> ipair;
const int _size = 100005;
 
struct Data {
    int x, s, e;
    bool operator < (const Data &r) const {
        return x < r.x;
    }
} o[_size];
 
int main () {
    // input
    int n, s, b;
    scanf("%d %d %d", &n, &s, &b);
    for (int i=0; i<n; ++i) {
        scanf("%d %d %d", &o[i].x, &o[i].s, &o[i].e);
    }
 
    // pre-process
    sort(o, o+n);
    set <ipair> q;
    q.insert(make_pair(s, 0));
 
    // process
    for (int i=0; i<n; ++i) {
        int vs=INT_MAX, ve=INT_MAX;
        auto qs = lower_bound(q.begin(), q.end(), make_pair(o[i].s, 0));
        auto j = qs;
        for (; j!=q.end() && (*j).first<o[i].e; ++j) {
            vs = min(vs, (*j).second + abs((*j).first-o[i].s));
            ve = min(ve, (*j).second + abs((*j).first-o[i].e));
        }
        q.erase(qs, j);
        if (vs != INT_MAX) q.insert(make_pair(o[i].s, vs));
        if (ve != INT_MAX) q.insert(make_pair(o[i].e, ve));
    }
 
    // output
    int minv = INT_MAX;
    for (auto i=q.begin(); i!=q.end(); ++i) {
        minv = min(minv, (*i).second);
    }
    printf("%d\n", minv+b);
    vector <int> pp;
    for (auto i=q.begin(); i!=q.end(); ++i) {
        if ((*i).second == minv) pp.push_back((*i).first);
    }
    printf("%d ", pp.size());
    for (int &p: pp) {
        printf("%d ", p);
    }
    printf("\n");
    return 0;
}
