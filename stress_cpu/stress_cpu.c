#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <errno.h>

int main(void) {
	srand(time(0));
	int cnt = 0;
	int success_seconds = (rand() % (90 - 60)) + 60; 
	//int * mem_load = malloc(1000000*300);
	//memset(mem_load, 1488, 1000000*300);
	time_t success_start, success_end;
	success_start = time(NULL);
	double elapsed_success;
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
		while (terminate) {
			end = time(NULL);
			printf("Simulating load\n");
			elapsed = difftime(end, start);
			if (elapsed >= load_seconds) {
				terminate = 0;
			} else {
				int primes = 0;
				int limit = 100000;
    				for (int num = 1; num <= limit; num++) {
    					// mem_load[num-1] = num;
       					int i = 2; 
       					while(i <= num) { 
           					if(num % i == 0)
               					break;
           					i++; 
        				}
        				if(i == num)
            				primes = primes + 1; //mem_load[num-1];
    				}
    			}
		}
		printf("Simulating absence of load\n");
		// sleep
		sleep(5);
		printf("Iteration %d is done!\n", cnt);
		cnt++;
	}
	//free(mem_load);
	return 0;
}
