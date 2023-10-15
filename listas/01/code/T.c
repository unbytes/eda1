#include <stdlib.h>
#include <stdio.h>

#define MAX 112345

typedef long long ll;

void solve() {
    char str[MAX];
    fgets(str, sizeof(str), stdin);
    
    for (int i = 0; i < MAX; i++) {
        if (str[i] == '\0') {
            printf("%d\n", i - 1);
            break;
        }
    }
}

int main() {
    int t = 1;
    //scanf("%d", &t);

    while (t--) {
        solve();
    }

    return 0;
}