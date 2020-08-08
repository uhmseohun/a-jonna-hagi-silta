#include <cstdio>
#include <queue>
using namespace std;
const int _ = 105;
int n, m, h, mat[_][_][_];
bool chk[_][_][_];
const int xx[] = { -1, 0, 1, 0, 0, 0 };
const int yy[] = { 0, 1, 0, -1, 0, 0 };
const int zz[] = { 0, 0, 0, 0, 1, -1 };

struct L { int z, x, y, t; };
queue<L> q;

int main() {
    scanf("%d %d %d", &m, &n, &h);
    int r = 0;
    for(int k=0; k<h; ++k) {
        for(int i=0; i<n; ++i) {
            for(int j=0; j<m; ++j) {
                scanf("%d", &mat[k][i][j]);
                if(mat[k][i][j] > 0) {
                    q.push(L({ k, i, j, 0 }));
                } else if(!mat[k][i][j]) r++;
            }
        }
    }
    int l = 0;
    while(!q.empty() && r) {
        const L &t = q.front();
        q.pop();
        for(int i=0; i<6; ++i) {
            int mx = t.x + xx[i];
            int my = t.y + yy[i];
            int mz = t.z + zz[i];
            int mt = t.t + 1;
            if(mx<0 || my<0 || mz<0) continue;
            if(mx>=n || my>=m || mz>=h) continue;
            if(mat[mz][mx][my] != 0) continue;
            if(chk[mz][mx][my]) continue;
            mat[mz][mx][my] = 1;
            chk[mz][mx][my] = true;
            r--, l = mt;
            q.push(L({ mz, mx, my, mt }));
        }
    }
    if(!q.empty()) printf("%d\n", l);
    else puts("-1");
    return 0;
}
