#include "statistic.h"

double total_response_time = 0.0;
double total_waiting_time = 0.0;
double total_service_time = 0.0;
double total_interarrival_time = 0.0;
int total_interarrivals = 0;
int client_served = 0;

void Statistics(void) {
    double mean_response = (client_served > 0) ? (total_response_time / client_served) : 0.0;
    double mean_waiting = (client_served > 0) ? (total_waiting_time / client_served) : 0.0;
    double mean_service = (client_served > 0) ? (total_service_time / client_served) : 0.0;
    double throughput = (Tnow > 0.0) ? ((double)client_served / Tnow) : 0.0;
    double utilization = (Tnow > 0.0) ? (total_service_time / Tnow) : 0.0;
    double avg_interarrival = (total_interarrivals > 0) ? (total_interarrival_time / total_interarrivals) : 0.0;

    printf("Total Customers Served     : %d\n", client_served);
    printf("Total Simulation Time      : %.6f s\n", Tnow);
    printf("Average Interarrival Time  : %.6f s\n", avg_interarrival);
    printf("Average Service Time       : %.6f s\n", mean_service);
    printf("Mean Waiting Time          : %.6f s\n", mean_waiting);
    printf("Mean Response Time         : %.6f s\n", mean_response);
    printf("Throughput                 : %.6f customers/s\n", throughput);
    printf("Server Utilization         : %.6f\n", utilization);
    printf("Arrival Rate (lambda)      : %.6f customers/s\n", arrival_rate);
    printf("Service Rate (mu)          : %.6f customers/s\n", service_rate);

   
}