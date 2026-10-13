#include <stdio.h>

int main(void)
{
    const int numbers[] = {1, 2, 3, 4, 5};
    const size_t count = sizeof numbers / sizeof numbers[0];
    int sum = 0;

    for (size_t index = 0; index < count; ++index) {
        sum += numbers[index];
    }

    printf("%d\n", sum);
    return 0;
}
