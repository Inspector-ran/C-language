#include <stdio.h>

/* Both pointers must refer to valid, writable int objects. */
void swap(int *first, int *second)
{
    const int temporary = *first;
    *first = *second;
    *second = temporary;
}

int main(void)
{
    int first = 3;
    int second = 7;

    printf("Before: %d, %d\n", first, second);
    swap(&first, &second);
    printf("After: %d, %d\n", first, second);
    return 0;
}
