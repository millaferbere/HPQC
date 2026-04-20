#include <stdio.h>
#include <time.h>

int main()
{
    FILE *fp = fopen("data/output.txt", "r");
    int value;

    struct timespec start, end;
    timespec_get(&start, TIME_UTC);

    while (fscanf(fp, "%d", &value) != EOF) {}

    timespec_get(&end, TIME_UTC);
    fclose(fp);

    double runtime = (end.tv_sec - start.tv_sec) +
                     (end.tv_nsec - start.tv_nsec)/1e9;

    printf("Read time: %lf seconds\n", runtime);

    return 0;
}
