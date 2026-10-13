#include <stdio.h>

int max_of_two(int first, int second);

int main(void)
{
    printf("%d\n", max_of_two(3, 7));
    return 0;
}

int max_of_two(int first, int second)
{
    if (first > second) {
        return first;
    }
    return second;
}
