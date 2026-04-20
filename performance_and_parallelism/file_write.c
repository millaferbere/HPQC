#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Usage: ./file_write [N]\n");
        return 1;
    }

    int n = atoi(argv[1]);
    FILE *fp = fopen("data/output.txt", "w");

    struct timespec start, end;
    timespec_get(&start, TIME_UTC);

    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", i);
    }

    timespec_get(&end, TIME_UTC);
    fclose(fp);

    double runtime = (end.tv_sec - start.tv_sec) +
                     (end.tv_nsec - start.tv_nsec)/1e9;

    printf("Write time: %lf seconds\n", runtime);

    return 0;
}
