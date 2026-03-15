#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

void func(void)
{
    usleep(200);
}


int main()
{
    struct timeval start;
    struct timeval end;

    gettimeofday(&start,NULL);
    func();
    gettimeofday(&end, NULL);

    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    long local_time = (end.tv_sec - start.tv_sec * 1000000) + microseconds;

    printf("Execution Time = %ld microseconds\n", local_time);


    return(0);
}