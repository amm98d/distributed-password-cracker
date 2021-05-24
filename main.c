#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mpi.h>
#include <omp.h>
#include <crypt.h>
#include <unistd.h>
#include <math.h>

int main(int argc, char* argv[]){	

/*	char id[] = "mpiuser";*/
/*	char salt[] = "$6$4GfdWqHx$";*/
/*	char *encrypted = crypt(id, salt);*/
/*	printf("%s\n",encrypted);*/

	int nprocs, rank;

	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

/*	Regarding MPI Send & Receive:				*/
/*	===========================================	*/
/*	array size communication on tag 		= 0 */
/*	array itself communication on tag 		= 1 */
/*	number to search communication on tag 	= 2 */
/*	abort message communication on tag 		= 3 */

	// master
	if (rank==0){
		// clearing the console
		int sysRet = system("clear");
		if (sysRet==-1){
			printf("System Method Failed.\n");
			return 0;
		}
		
		printf("PDC Project - Distributed Password Cracker\n");
		printf("============================================\n\n");

		// [TODO]
/*		1. Receive username as input*/
/*		2. /etc/shadow file/
/*		2. Store hash found against the username in the variable targetHash*/

		// initializing variables
/*		int count, i=0, toSearch;*/
/*		char username[] = 	;*/
/*		printf("Enter username: ");*/
/*		if (scanf("%s" , username)){}*/
		char *targetHash = "$6$ap6wFyoK$2cB1M133QM8UeBpEA5BM8Jk9vfqvhA3ehCxmUMJDTph5DeFYrqYxHi2mp7Ey0TVd5XB4AeHLotPxlLJ.dBF7v0:18700:0:99999:7:::";
		size_t hashLen = strlen(targetHash);

		// each process gets equal range i.e., (total permutations) / (#slaves)

		// [TODO]
/*		1. Calculate total number of permutations*/

		int numDigits = 4, totalPermutations = 10000;
		int iproc, chunkStart=0, chunkLength=totalPermutations/(nprocs-1), abort=0;
		MPI_Status status;

		printf("Master: The hash to crack is:\n%d\n\n",targetHash);

		// distributing the array
		for (iproc=1;iproc<nprocs;iproc++){
			// MPI_Send(&chunkLength, 1, MPI_INT, iproc, 0, MPI_COMM_WORLD);// chunklenght sent with tag 0
			// MPI_Send(targetHash, hashLen, MPI_CHAR, iproc, 1, MPI_COMM_WORLD);// number to search sent with tag 1
			chunkStart += chunkLength;
		}

/*		// waiting for good news*/
/*		MPI_Recv(&abort, 1, MPI_INT, MPI_ANY_SOURCE, 3, MPI_COMM_WORLD, &status);// abort message received with tag 3*/
/*		printf("Master: Process %d has found the number!\n", status.MPI_SOURCE);*/
/*		printf("Master: Informing all processes to abort!\n");*/
/*		// sending abort message*/
/*		for (iproc=1;iproc<nprocs;iproc++)*/
/*			MPI_Send(&abort, 1, MPI_INT, iproc, 3, MPI_COMM_WORLD);// abort messages sent with tag 3*/
	}

	// slaves
	else { 
		// // initializing variables
		// int chunkLength, abort=0;
		// // each slave receiving size of array and allocating memory
		// MPI_Recv(&chunkLength, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		// int *arrayToSearch = malloc(chunkLength * sizeof(int));
		// // receiving the array itself
		// MPI_Recv(arrayToSearch, chunkLength, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		// // receiving the number to search
		// MPI_Recv(&toSearch, 1, MPI_INT, 0, 2, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		
		// printf("Process %d has local data: ",rank);
		// int i;
		// for (i=0;i<chunkLength;i++){
		// 	printf("%d ",arrayToSearch[i]);
		// }
		// printf("\n");
		
		// // using openmp to create 2 threads
		// #pragma omp parallel num_threads(2)
		// {
		// 	// thread-1: does the searching
		// 	if (omp_get_thread_num()==0){
		// 		int i = 0;
		// 		for (;i<chunkLength;i++){
		// 			// abandon rest of searching if abort message found
		// 			if (abort!=0){
		// 				printf("Process %d: Aborting Search!\n",rank);
		// 				break;
		// 			}
		// 			// if found: notify master
		// 			if (arrayToSearch[i]==toSearch){
		// 				printf("Process %d: I have found the number :-)\n",rank);
		// 				MPI_Send(&i, 1, MPI_INT, 0, 3, MPI_COMM_WORLD);// abort message with tag 3
		// 				break;
		// 			}
		// 			// sleep for demonstration
		// 			if (rank!=1)
		// 				sleep(5);
		// 		}
		// 	}
		// 	// thread-2: waits to hear for abort message
		// 	else if (omp_get_thread_num()==1){
		// 		// waiting for abort message from master with tag 3
		// 		MPI_Recv(&abort, 1, MPI_INT, 0, 3, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		// 	}
		// }		
	}
    MPI_Finalize();
    return 0;
}