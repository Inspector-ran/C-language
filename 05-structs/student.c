#include <stdio.h>

struct Student {
    char name[20];
    int age;
    double score;
};

int main(void)
{
    const struct Student student = {"Lin", 18, 92.5};

    printf("Name: %s\n", student.name);
    printf("Age: %d\n", student.age);
    printf("Score: %.1f\n", student.score);
    return 0;
}
