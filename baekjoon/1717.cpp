#include <cstdio>
int parent[1000005];
int n;

int find_parent(int index) {
    if(parent[index] == index) return index;
    else {
        parent[index] = find_parent(parent[index]);
        return parent[index];
    }
}

void union_parent(int p, int q) {
    int p_parent = find_parent(p);
    int q_parent = find_parent(q);
    parent[p_parent] = q_parent;
}

int main() {
    int k;
    scanf("%d %d", &n, &k);
    int r, p, q;
    for(int i=1; i<=n; ++i) {
        parent[i] = i;
    }
    while(k--) {
        scanf("%d %d %d", &r, &p, &q);
        if(r == 1) {
            int p_parent = find_parent(p);
            int q_parent = find_parent(q);
            puts(p_parent == q_parent ? "YES" : "NO");
        } else {
            union_parent(p, q);
        }
    }
    return 0;
}
