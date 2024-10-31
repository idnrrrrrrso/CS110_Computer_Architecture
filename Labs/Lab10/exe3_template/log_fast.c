#include <stdio.h>
#include <sys/time.h>
#include <time.h>

#define NUM_ENTRIES 409600

struct log_entry{
    int status[NUM_ENTRIES];
    long reference_time[NUM_ENTRIES];
    int src_ip[NUM_ENTRIES];
    char URL[128];
    char bro[128];

}logs;

void traverse(){
    for(int i=0;i<NUM_ENTRIES;i++){
        if(logs.status[i]){
            logs.reference_time[i] = 0;
            logs.src_ip[i] = 0;
        }
    }
}

void make_logs(){
    for(int i=0;i<NUM_ENTRIES;i++){
        logs.src_ip[i] = i*123;
        logs.reference_time[i] = i*123;
        logs.status[i] = 1;
    }
}

int main(){
    make_logs();
    struct timeval start_time, stop_time, elapsed_time; 
    gettimeofday(&start_time,NULL);
    for(int i=0;i<100;i++)
        traverse();
    gettimeofday(&stop_time,NULL);
    timersub(&stop_time, &start_time, &elapsed_time); 
    printf("%f \n", elapsed_time.tv_sec+elapsed_time.tv_usec/1000000.0);
    return 0;
}