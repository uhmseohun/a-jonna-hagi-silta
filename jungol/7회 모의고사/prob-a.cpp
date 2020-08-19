/**
 * Union-Find Algorithm & Counting Disjoint-Sets
**/
#include <cstdio>
#include <vector>
using namespace std;
int parent[100005];
int cnt[100005];

int get_parent(int q) {
    if(q == parent[q]) return q;
    parent[q] = get_parent(parent[q]);
    return parent[q];
}

void union_parent(int p, int q) {
    int p_parent = get_parent(p);
    int q_parent = get_parent(q);
    parent[p_parent] = q_parent;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; ++i) {
        parent[i] = i;
    }
    int p, q;
    for(int i=0; i<m; ++i) {
        scanf("%d %d", &p, &q);
        union_parent(p, q);
    }
    for(int i=0; i<n; ++i) {
        int i_parent = get_parent(i);
        cnt[i_parent]++;
    }
    vector<int> cnt_list;
    long long cnt_sum = 0;
    for(int i=0; i<n; ++i) {
        if(cnt[i]) {
            cnt_list.push_back(cnt[i]);
            cnt_sum += cnt[i];
        }
    }
    int cnt_size = int(cnt_list.size());
    long long answer = 0;
    for(int i=0; i<cnt_size; ++i) {
        answer += cnt_list[i] * (cnt_sum - cnt_list[i]);
    }
    printf("%lld\n", answer >> 1);
    return 0;
}
