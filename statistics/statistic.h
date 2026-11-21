#ifndef STATISTIC_H
#define STATISTIC_H

#include <stdio.h>
#include "../Global_vars/system.h"

extern double total_response_time;
extern double total_waiting_time;
extern double total_service_time;
extern double total_interarrival_time;
extern int total_interarrivals;
extern int client_served;

void Statistics(void);

#endif