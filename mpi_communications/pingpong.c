#include <stdio.h>
#include <mpi.h>
#include <stdlib.h>

// simple timing helpers are already provided by MPI_Wtime()

int main(int argc, char **argv)
{
    int my_rank, uni_size;
    int num_pings;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &uni_size);

    // check correct usage
    if (argc != 2)
    {
        if (my_rank == 0)
        {
            printf("Usage: mpirun -np 2 ./pingpong [num_pings]\n");
        }
        MPI_Finalize();
        return -1;
    }

    num_pings = atoi(argv[1]);

    int counter = 0;
    double start_time, end_time;

    // only works with 2 processes
    if (uni_size != 2)
    {
        if (my_rank == 0)
        {
            printf("Error: must run with exactly 2 processes\n");
        }
        MPI_Finalize();
        return -1;
    }

    start_time = MPI_Wtime();

    while (counter < num_pings)
    {
        if (my_rank == 0)
        {
            // root sends ping
            MPI_Send(&counter, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);

            // root receives pong
            MPI_Recv(&counter, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        }
        else
        {
            // client receives ping
            MPI_Recv(&counter, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

            // increment
            counter++;

            // send pong
            MPI_Send(&counter, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        }
    }

    end_time = MPI_Wtime();

    if (my_rank == 0)
    {
        double elapsed = end_time - start_time;
        double avg = elapsed / num_pings;

        printf("Final counter: %d\n", counter);
        printf("Total time: %f seconds\n", elapsed);
        printf("Average time per ping: %f seconds\n", avg);
    }

    MPI_Finalize();
    return 0;
}
