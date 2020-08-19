#include <cstdio>
const int size = 5005;
int mod = 1000000007;
int d[size][size];
// d[i, j] = i번째 수까지 쓰고, 마지막에 j가 오는 경우의 수 (수열의 길이는 i)
int s[size][size];
int n;
bool a[size], b[size];

int range_sum(int i, int p, int q) {
    // s[i][q] < s[i][p-1] 일 수 있기 때문에 mod를 더한 후 나머지 연산을 해야 함
    return (s[i][q] - s[i][p-1] + mod) % mod;
}
 
int main() {
    int na, nb;
    scanf("%d %d %d", &n, &na, &nb);
    int p;
    for(int i=0; i<na; ++i) {
        scanf("%d", &p);
        a[p] = true;
    }
    for(int i=0; i<nb; ++i) {
        scanf("%d", &p);
        b[p] = true;
    }
    d[1][1] = 1;
    s[1][1] = 1;
    for(int i=2; i<=n; ++i) {
        for(int j=1; j<=i; ++j) {
            if((a[i] || b[i-1]) && (a[i-1] || b[i]))
                continue;
            if(a[i] || b[i-1]) // p[i-1] > p[i]
                d[i][j] = range_sum(i-1, j, i-1);
            else if(a[i-1] || b[i]) // p[i-1] < p[i]
                d[i][j] = range_sum(i-1, 1, j-1);
            else
                d[i][j] = range_sum(i-1, 1, i-1);
            s[i][j] = (s[i][j-1] + d[i][j]) % mod;
        }
    }
    printf("%d\n", range_sum(n, 1, n));
    return 0;
}
