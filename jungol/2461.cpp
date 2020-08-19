#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;
typedef pair<int, int> ipair;
typedef vector<ipair> ivector;
int n;
ivector flowers;

int get_day(int m, int d) {
    return m * 100 + d;
}

bool comparator(ipair a, ipair b) {
    return a.second > b.second;
}

ipair get_latest(int limit) {
    ipair answer = make_pair(0, 0);
    bool flag = false;
    for(const ipair& flower: flowers) {
        if(limit < flower.first) continue;
        if(flower.second <= limit) continue;
        flag = true;
        if(answer.second < flower.second) {
            answer = flower;
        }
    }
    if(!flag) {
        printf("%d\n", 0);
        exit(0);
    } else {
        return answer;
    }
}

int main() {
    scanf("%d", &n);
    int m, d;
    for(int i=0; i<n; ++i) {
        scanf("%d %d", &m, &d);
        int s = get_day(m, d);
        scanf("%d %d", &m, &d);
        int e = get_day(m, d);
        flowers.push_back(make_pair(s, e));
    }
    sort(flowers.begin(), flowers.end(), comparator);
    int current = get_day(3, 1);
    int answer = 0;
    while(current < get_day(12, 1)) {
        ipair flower = get_latest(current);
        current = flower.second;
        answer++;
    }
    printf("%d\n", answer);
    return 0;
}
