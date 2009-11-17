#include <stdio.h>

int main(void)
{
    char c[4] = "ABCD"; 
    char d[4] = { 'A', 'B', 'C', 'D' };
    printf("c[0] is '%c'\n", c[0]);
    d[4] = 'Z';
    printf("c[0] is '%c'\n", c[0]);
    return 0;
}

