#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include <omp.h>
#include <crypt.h>
#include <unistd.h>

int main(int argc, char* argv[]){	

	char id[] = "mpiuser";
	char salt[] = "$6$4GfdWqHx$";
	char *encrypted = crypt(id, salt);
	printf("%s\n",encrypted);

/*	int nprocs, rank;*/

/*	MPI_Init(&argc, &argv);*/
/*	MPI_Comm_rank(MPI_COMM_WORLD, &rank);*/
/*	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);*/

/*	Regarding MPI Send & Receive:				*/
/*	===========================================	*/
/*	array size communication on tag 		= 0 */
/*	array itself communication on tag 		= 1 */
/*	number to search communication on tag 	= 2 */
/*	abort message communication on tag 		= 3 */

/*	// master*/
/*	if (rank==0){*/
/*		// clearing the console*/
/*		int sysRet = system("clear");*/
/*		if (sysRet==-1){*/
/*			printf("System Method Failed.\n");*/
/*			return 0;*/
/*		}*/
/*		*/
/*		printf("i170227 - Ahmed Mustafa Malik\n\n");*/
/*		*/
/*		// initializing variables*/
/*		int count, i=0, toSearch;*/
/*		printf("Enter Array Size: ");*/
/*		if (scanf("%d", &count)){}*/
/*		int *numbers = malloc(count * sizeof(int));*/
/*		printf("\nEnter Array Elements:\n");*/
/*		for (;i<count;i++) {*/
/*		    if (scanf("%d", &numbers[i])){}*/
/*		}*/
/*		printf("\nEnter Number to Search: ");*/
/*		if (scanf("%d", &toSearch));*/
/*		printf("\n");*/

/*		// each process gets equal size i.e., (total items) / (#slaves) in chunkLength*/
/*		int iproc, chunkStart=0, chunkLength=count/(nprocs-1), abort=0;*/
/*		MPI_Status status;*/

/*		printf("Master: The number to search is %d\n",toSearch);*/
/*		printf("Process 0 has input data: ");*/
/*		for (iproc=0;iproc<count;iproc++){*/
/*			printf("%d ",numbers[iproc]);*/
/*		}*/
/*		printf("\n");*/

/*		// distributing the array*/
/*		for (iproc=1;iproc<nprocs;iproc++){*/
/*			MPI_Send(&chunkLength, 1, MPI_INT, iproc, 0, MPI_COMM_WORLD);// size of array sent with tag 0*/
/*			int *localChunk = malloc(chunkLength * sizeof(int));*/
/*			memcpy(localChunk, numbers+chunkStart, chunkLength*sizeof(int));*/
/*			MPI_Send(localChunk, chunkLength, MPI_INT, iproc, 1, MPI_COMM_WORLD);// array sent with tag 1*/
/*			MPI_Send(&toSearch, 1, MPI_INT, iproc, 2, MPI_COMM_WORLD);// number to search sent with tag 2*/
/*			chunkStart += chunkLength;*/
/*		}*/
/*		// waiting for good news*/
/*		MPI_Recv(&abort, 1, MPI_INT, MPI_ANY_SOURCE, 3, MPI_COMM_WORLD, &status);// abort message received with tag 3*/
/*		printf("Master: Process %d has found the number!\n", status.MPI_SOURCE);*/
/*		printf("Master: Informing all processes to abort!\n");*/
/*		// sending abort message*/
/*		for (iproc=1;iproc<nprocs;iproc++)*/
/*			MPI_Send(&abort, 1, MPI_INT, iproc, 3, MPI_COMM_WORLD);// abort messages sent with tag 3*/
/*	}*/

/*	// slaves*/
/*	else { */
/*		// initializing variables*/
/*		int chunkLength, toSearch, abort=0;*/
/*		// each slave receiving size of array and allocating memory*/
/*		MPI_Recv(&chunkLength, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);*/
/*		int *arrayToSearch = malloc(chunkLength * sizeof(int));*/
/*		// receiving the array itself*/
/*		MPI_Recv(arrayToSearch, chunkLength, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);*/
/*		// receiving the number to search*/
/*		MPI_Recv(&toSearch, 1, MPI_INT, 0, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);*/
/*		*/
/*		printf("Process %d has local data: ",rank);*/
/*		int i;*/
/*		for (i=0;i<chunkLength;i++){*/
/*			printf("%d ",arrayToSearch[i]);*/
/*		}*/
/*		printf("\n");*/
/*		*/
/*		// using openmp to create 2 threads*/
/*		#pragma omp parallel num_threads(2)*/
/*		{*/
/*			// thread-1: does the searching*/
/*			if (omp_get_thread_num()==0){*/
/*				int i = 0;*/
/*				for (;i<chunkLength;i++){*/
/*					// abandon rest of searching if abort message found*/
/*					if (abort!=0){*/
/*						printf("Process %d: Aborting Search!\n",rank);*/
/*						break;*/
/*					}*/
/*					// if found: notify master*/
/*					if (arrayToSearch[i]==toSearch){*/
/*						printf("Process %d: I have found the number :-)\n",rank);*/
/*						MPI_Send(&i, 1, MPI_INT, 0, 3, MPI_COMM_WORLD);// abort message with tag 3*/
/*						break;*/
/*					}*/
/*					// sleep for demonstration*/
/*					if (rank!=1)*/
/*						sleep(5);*/
/*				}*/
/*			}*/
/*			// thread-2: waits to hear for abort message*/
/*			else if (omp_get_thread_num()==1){*/
/*				// waiting for abort message from master with tag 3*/
/*				MPI_Recv(&abort, 1, MPI_INT, 0, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);*/
/*			}*/
/*		}*/
/*		*/
/*	}*/
/*    MPI_Finalize();*/
    return 0;
}