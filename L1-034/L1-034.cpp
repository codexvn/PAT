#include<cstdio>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);//点赞的数量
    int K, F[1001] = {0}, max_time = 0, flag = 0;
    for (int i = 0; i < N; ++i) {
        scanf("%d", &K);
        int Fn;
        for (int j = 0; j < K; ++j) {
            scanf("%d", &Fn);
            F[Fn]++;
            if (F[Fn] > max_time) {
                flag = Fn;
                max_time = F[Fn];
            } else if (F[Fn] == max_time and Fn > flag)
                flag = Fn;
        }
    }
    printf("%d %d", flag, max_time);
}

