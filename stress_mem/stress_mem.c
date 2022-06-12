#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <errno.h>

int min(int x, int y)
{
  return (x < y) ? x : y;
}

int main(void) {
	srand(time(0));
	int cnt = 0;
	double elapsed_success;
	int success_seconds = (rand() % (90 - 60)) + 60;
	time_t success_start, success_end;
	success_start = time(NULL);
	for (;;) {
		success_end = time(NULL);
		elapsed_success = difftime(success_end, success_start);
		if (elapsed_success >= success_seconds) {
			fprintf(stderr, "Error! Exiting...\n");
			return -1;
		}
		// determining the proportion of next 10 seconds of execution
		int load_seconds = (rand() % (9 - 1 + 1)) + 1;
		int sleep_seconds = 10 - load_seconds;
		// time issues 
		time_t start, end;
		double elapsed;
		start = time(NULL);
		int terminate = 1;
		// printf("allocated: %d\n", mem_load);
		// load simulation
		int* addr[10];
		struct rusage r_usage;
		int *p = 0;
		int i = 0;
		printf("Simulating memory load\n");
		while (terminate) {
			end = time(NULL);
			elapsed = difftime(end, start);
			if (elapsed >= load_seconds) {
				terminate = 0;
			} else {
				int rnd = (rand() % (5 - 1 + 1)) + 1;
				//printf("random number = %d \n", rnd);				
				p = (int*)malloc(rnd*30*1000000);
				addr[i] = p;				
				i++;
				//printf("address: %d \n", p);
				memset(p, 1488, rnd*30*1000000);
				//int ret = getrusage(RUSAGE_SELF,&r_usage);
				//if(ret == 0)
					//printf("Memory usage: %ld \n",r_usage.ru_maxrss);
				//else
					//printf("Error in getrusage. errno = %d\n", errno);
				sleep(1);	
    		}
		}
		printf("Freeing the allocated memory!\n");
		for (int j = i; j > 0; j--) {
			free(addr[j-1]);
		}
		printf("Simulating absence of load\n");
		// sleep
		sleep(sleep_seconds);
		printf("Iteration %d is done!\n", cnt);
		cnt++;
	}
	//free(mem_load);
	return 0;
}
