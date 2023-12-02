#include <cstdio>

void palin(double &count) {
    int length = 0;
    char c, arrInput[21];

    while ((c = getchar()) != '\n') {  
        if (length < 21) arrInput[length++] = c;  
    }  

    if (length == 21) {
        printf("error\n");
        return;
    }

    if (length == 0) {
        printf("empty\n");
        return;
    }

    for (int i = 0; i < length / 2; i++) {
        if (arrInput[i] != arrInput[length - 1 - i]) {
            printf("no\n");
            return;
        }
    }

    count++;
    printf("yes\n");
}

int main() {
    double pct = 0;
    int N;
    scanf("%d\n", &N);

    for (int i = 0; i < N; i++) {
        palin(pct);
    }

    printf("%.3lf\n", pct * 100 / N);

    return 0;
}
