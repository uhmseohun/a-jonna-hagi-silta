//
//  main.cpp
//  cpp-project
//
//  Created by 엄서훈 on 2020/07/31.
//  Copyright © 2020 seohun. All rights reserved.
//

#include <stdio.h>

const int _size = 100;
int mat[_size][_size];
int n, m;

const int xx[] = { -1, 0, 1, 0 };
const int yy[] = { 0, 1, 0, -1 };

void flood_fill(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m) return;
    if(!mat[x][y]) return;
    mat[x][y] = 0;
    for (int i=0; i<4; ++i) {
        flood_fill(x+xx[i], y+yy[i]);
    }
}

int main () {
    int tc;
    int k, x, y;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d %d %d", &m, &n, &k);
        while(k--) {
            scanf("%d %d", &y, &x);
            mat[x][y] = 1;
        }
        
        int ans = 0;
        
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if(!mat[i][j]) continue;
                flood_fill(i, j);
                ans++;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
