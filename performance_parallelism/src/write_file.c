#include <stdio.h>
#include <time.h>

int main() {
    int n;
    printf("Number of lines: ");
    scanf("%d", &n);

    clock_t start = clock();

    FILE *f = fopen("performance_parallelism/data/output.txt", "w");

    for (int i = 0; i < n; i++) {
        fprintf(f, "This is line %d\n", i);
    }

    fclose(f);

    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Write time: %f\n", time_taken);

    return 0;
}
