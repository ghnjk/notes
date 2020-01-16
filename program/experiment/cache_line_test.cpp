#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "stop_watch.h"

using cpp_util::StopWatch;


struct Dt{
    char szBuffer[50];
};
struct Dt_nt{
    char szBuffer[69];
};
const int DT_CNT = 1024 * 1024;
Dt data_opt_size[DT_CNT];
Dt_nt data_not_opt_size[DT_CNT];
void execute_without_optimize_cacheline(){
    char sz[] = "nice to meet you.";
    for(int i = 0; i < DT_CNT; i++){
        strncpy(data_not_opt_size[i].szBuffer, sz, 63);
    }
}
void execute_with_optimize_cacheline_size(){
    char sz[] = "nice to meet you.";
    for(int i = 0; i < DT_CNT; i++){
        strncpy(data_opt_size[i].szBuffer, sz, 63);
    }
}


int main(){
    StopWatch stopWatch;
    stopWatch.start();
    execute_without_optimize_cacheline();
    stopWatch.stop();
    printf("execute_without_optimize_cacheline cost %lld ms\n", stopWatch.getTimeMs());
    usleep(10 * 1000);
    stopWatch.start();
    execute_with_optimize_cacheline_size();
    stopWatch.stop();
    printf("execute_with_optimize_cacheline_size cost %lld ms\n", stopWatch.getTimeMs());
    return 0;
}