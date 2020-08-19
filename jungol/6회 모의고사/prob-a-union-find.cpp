#include <cstdio>
#include <vector>
using namespace std;
int parent[50005];
int n, m;
vector<int> answer;

int get_parent(int q) {
    if(parent[q] == q) return q;
    else {
        parent[q] = get_parent(parent[q]);
        return parent[q];
    }
}

void union_parent(int p, int q) {
    parent[p] = parent[q];
}

int main() {
    scanf("%d %d", &n, &m);
    int p, q;
    for(int i=1; i<=n; ++i) {
        parent[i] = i;
    }
    for(int i=0; i<m; ++i) {
        scanf("%d %d", &p, &q);
        int p_parent = get_parent(p);
        int q_parent = get_parent(q);
        if(p_parent != q_parent) {
            answer.push_back(i + 1);
            union_parent(p_parent, q_parent);
        }
    }
    printf("%d\n", int(answer.size()));
    for(int index: answer) {
        printf("%d ", index);
    }
    printf("\n");
    return 0;
}
