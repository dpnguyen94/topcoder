#include <stdio.h>
#include <math.h>

using namespace std;

int find(int X, int Y) {
    if (X > Y) return 1;
    return 10;
}

int main() {
    for (int i = 0; i <= 10; i ++) printf("Hello World!\n");
    printf("%d\n", find(10,100));
    return 0;
}
