#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int check_args(int argc, char **argv);
void initialise_vector(double vector[], int size, double initial);
void update_positions(double* positions, int points, double time);
double driver(double time);
int generate_timestamps(double* time_stamps, int time_steps, double step_size);

int main(int argc, char **argv)
{
        int points = check_args(argc, argv);

        int cycles = 5;
        int samples = 25;
        int time_steps = cycles * samples + 1;
        double step_size = 1.0 / samples;

        double* time_stamps = malloc(time_steps * sizeof(double));
        double* positions = malloc(points * sizeof(double));

        if (time_stamps == NULL || positions == NULL)
        {
                printf("Memory allocation failed\n");
                exit(-1);
        }

        initialise_vector(time_stamps, time_steps, 0.0);
        initialise_vector(positions, points, 0.0);
        generate_timestamps(time_stamps, time_steps, step_size);

        FILE* out_file = fopen("../data/improved_output.csv", "w");

        if (out_file == NULL)
        {
                printf("ERROR: could not open output file\n");
                free(time_stamps);
                free(positions);
                exit(-1);
        }

        for (int i = 0; i < time_steps; i++)
        {
                update_positions(positions, points, time_stamps[i]);

                fprintf(out_file, "%d, %lf", i, time_stamps[i]);

                for (int j = 0; j < points; j++)
                {
                        fprintf(out_file, ", %lf", positions[j]);
                }

                fprintf(out_file, "\n");
        }

        free(time_stamps);
        free(positions);
        fclose(out_file);

        return 0;
}

double driver(double time)
{
        return sin(time * 2.0 * M_PI);
}

void update_positions(double* positions, int points, double time)
{
        double* new_positions = malloc(points * sizeof(double));

        if (new_positions == NULL)
        {
                printf("Memory allocation failed\n");
                exit(-1);
        }

        new_positions[0] = driver(time);
        new_positions[points - 1] = positions[points - 1];

        for (int i = 1; i < points - 1; i++)
        {
                new_positions[i] =
                        positions[i]
                        + 0.1 * (positions[i - 1]
                        - 2.0 * positions[i]
                        + positions[i + 1]);
        }

        for (int i = 0; i < points; i++)
        {
                positions[i] = new_positions[i];
        }

        free(new_positions);
}

void initialise_vector(double vector[], int size, double initial)
{
        for (int i = 0; i < size; i++)
        {
                vector[i] = initial;
        }
}

int generate_timestamps(double* timestamps, int time_steps, double step_size)
{
        for (int i = 0; i < time_steps; i++)
        {
                timestamps[i] = i * step_size;
        }
        return 0;
}

int check_args(int argc, char **argv)
{
        if (argc != 2)
        {
                printf("Usage: %s [points]\n", argv[0]);
                exit(-1);
        }

        return atoi(argv[1]);
}
