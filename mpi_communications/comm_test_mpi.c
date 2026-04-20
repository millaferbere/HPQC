#include <stdio.h>
#include <mpi.h>

// function declarations added
int root_task(int uni_size);
void client_task(int my_rank, int send_message);

int main(int argc, char **argv) 
{
	// declare and initialise error handling variable
	int ierror = 0;
	
	// declare and initialise rank and size varibles
	int my_rank, uni_size;
	my_rank = uni_size = 0;

	// intitalise MPI
	ierror = MPI_Init(&argc, &argv);

	// gets the rank and world size
	ierror = MPI_Comm_rank(MPI_COMM_WORLD,&my_rank);
	ierror = MPI_Comm_size(MPI_COMM_WORLD,&uni_size);

	// creates and initialies transmission variables
	int send_message, recv_message, count, dest, source, tag;
	send_message = recv_message = dest = source = tag = 0;
	count = 1;
	MPI_Status status;
	
	if (uni_size > 1)
	{
		if (0 == my_rank)
		{
			// ROOT TASK MOVED INTO FUNCTION

			root_task(uni_size);
		}
		else // i.e. (0 != my_rank)
		{
			// sets the destination for the message
			dest = 0; // destination is root

			// creates the message
			send_message = my_rank * 10;

			// CLIENT TASK MOVED INTO FUNCTION
			client_task(my_rank, send_message);

			// prints the message from the sender
            printf("Hello, I am %d of %d. Sent %d to Rank %d\n",
                     my_rank, uni_size, send_message, dest);

		} // end else
	} // end if
	else
	{
		// prints a warning
		printf("Unable to communicate with less than 2 processes. MPI communicator size = %d\n", uni_size);
	}

	// finalise MPI
	ierror = MPI_Finalize();
	return 0;
}


int root_task(int uni_size)
{
	int recv_message, count, source, tag;
	recv_message = source = tag = 0;
	count = 1;
	MPI_Status status;

	for (source = 1; source < uni_size; source++)
	{
		MPI_Recv(&recv_message, count, MPI_INT, source, tag, MPI_COMM_WORLD, &status);

		printf("Hello, I am 0 of %d. Received %d from Rank %d\n",
				uni_size, recv_message, source);
	}

	return 0;
}


void client_task(int my_rank, int send_message)
{
	int dest = 0;
	int count = 1;
	int tag = 0;

	MPI_Send(&send_message, count, MPI_INT, dest, tag, MPI_COMM_WORLD);
}
