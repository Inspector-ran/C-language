#include <stdio.h>

int main(void)
{
    const int limit = 5;
    int sum = 0;

    /* Add the integers from 1 through limit. */
    for (int number = 1; number <= limit; ++number) {
        sum += number;
    }

    printf("%d\n", sum);
    return 0;
}
