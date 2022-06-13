#include<stdio.h>
#include "oslabs.h"
struct PCB handle_process_arrival_pp(struct PCB ready_queue[], int *queue_cnt, struct PCB current_process, struct PCB new_process, int timestamp)
{
    if(current_process.process_id == 0){
        return new_process;
    } else{
        if(current_process.process_priority <= new_process.process_priority){

            new_process.execution_starttime = 0;
            new_process.execution_endtime = 0;
            new_process.remaining_bursttime = new_process.total_bursttime;

            ready_queue[*queue_cnt].process_id = new_process.process_id;
            ready_queue[*queue_cnt].arrival_timestamp = new_process.arrival_timestamp;
            ready_queue[*queue_cnt].total_bursttime = new_process.total_bursttime;
            ready_queue[*queue_cnt].execution_starttime = new_process.execution_starttime;
            ready_queue[*queue_cnt].execution_endtime = new_process.execution_endtime;
            ready_queue[*queue_cnt].remaining_bursttime = new_process.remaining_bursttime;
            ready_queue[*queue_cnt].process_priority = new_process.process_priority;
            *queue_cnt++;
            return current_process;
        } else {

            current_process.execution_endtime = 0;
            current_process.remaining_bursttime -= (new_process.arrival_timestamp - current_process.arrival_timestamp);

            ready_queue[*queue_cnt].process_id = current_process.process_id;
            ready_queue[*queue_cnt].arrival_timestamp = current_process.arrival_timestamp;
            ready_queue[*queue_cnt].total_bursttime = current_process.total_bursttime;
            ready_queue[*queue_cnt].execution_starttime = current_process.execution_starttime;
            ready_queue[*queue_cnt].execution_endtime = current_process.execution_endtime;
            ready_queue[*queue_cnt].remaining_bursttime = current_process.remaining_bursttime;
            ready_queue[*queue_cnt].process_priority = current_process.process_priority;
            *queue_cnt++;

            new_process.execution_starttime = timestamp;
            new_process.execution_endtime = timestamp + new_process.total_bursttime;
            new_process.remaining_bursttime = new_process.total_bursttime;

            return new_process;
        }
    }
}
