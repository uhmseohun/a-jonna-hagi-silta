#include <cstdio>
const int size = 1500;
int n;
bool mat[size][size];

bool check(int sx, int sy, int ex, int ey) {
    for(int i=sx; i<=ex; ++i) {
        for(int j=sy; j<=ey; ++j) {
            if(mat[sx][sy] != mat[i][j]) return false;
        }
    }
    return true;
}

void dnc(int sx, int sy, int ex, int ey) {
    if(check(sx, sy, ex, ey)) {
        printf("%d", mat[sx][sy]);
        return;
    } else {
        printf("X");
        int mx = (sx + ex) / 2;
        int my = (sy + ey) / 2;
        dnc(sx, sy, mx, my);
        dnc(sx, my + 1, mx, ey);
        dnc(mx + 1, sy, ex, my);
        dnc(mx + 1, my + 1, ex, ey);
    }
}

int main() {
    scanf("%d", &n);
    int v;
    for(int i=1; i<=n; ++i) {
        for(int j=1; j<=n; ++j) {
            scanf("%d", &v);
            mat[i][j] = bool(v);
        }
    }
    dnc(1, 1, n, n);
    printf("\n");
    return 0;
}
