#include <stdio.h>
#include <time.h>

int main() {
    clock_t start = clock();

    FILE *f = fopen("performance_parallelism/data/output.txt", "r");

    char buffer[1024];
    int chars = 0;

    while (fgets(buffer, sizeof(buffer), f) != NULL) {
        for (int i = 0; buffer[i] != '\0'; i++) {
            chars++;
        }
    }

    fclose(f);

    clock_t end = clock();

    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Characters read: %d\n", chars);
    printf("Read time: %f\n", time_taken);

    return 0;
}
