#include "my_type.h"
static int s = 0;
void rotate(int n, MY_TYPE src[n][n], MY_TYPE dst[n][n]) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            dst[n-1-j][i] = src[i][j];
        }
    }
    s++;
}

// 最初に配布されたサンプルプログラム