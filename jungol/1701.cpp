#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int _size = 505;
char str[_size];
int len, d[_size][_size];

bool atgc(int p, int q) {
    return (str[p] == 'a' && str[q] == 't') ||
           (str[p] == 'g' && str[q] == 'c');
}

int main() {
    scanf("%s", str);
    len = strlen(str);
    for(int k=1; k<len; ++k) {
        for(int i=0; i+k<len; ++i) {
            if(k == 1 && atgc(i, i+1)) {
                d[i][i+1] = 1;
            } else {
                if(atgc(i, i+k)) d[i][i+k] = d[i+1][i+k-1] + 1;
                for(int j=i; j<i+k; ++j) {
                    d[i][i+k] = max(d[i][i+k], d[i][j] + d[j+1][i+k]);
                }
            }
        }
    }
    printf("%d\n", d[0][len-1]<<1);
    return 0;
}
