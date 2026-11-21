#include <math.h>
#include <time.h>
#include "simulation.h"

/* Inverse CDF method: X = -ln(U) / lambda, with U strictly in (0, 1). */
double generate_exponential(double lambda) {
    double u;
    do {
        u = (double)rand() / ((double)RAND_MAX + 1.0);
    } while (u <= 0.0 || u >= 1.0);

    return -log(u) / lambda;
}

void Initialization(void) {
    srand((unsigned int)time(NULL));

    Server = IDLE;
    initial_queue(&QueueList);
    init_event_list(&EventList);

    Tnow = 0.0;
    id_client = 0;

    do {
        printf("Enter mean interarrival time (> 0): ");
        if (scanf("%lf", &mean_interarrival_time) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            mean_interarrival_time = 0.0;
        }
        if (!(mean_interarrival_time > 0.0)) {
            printf("Invalid input. Mean interarrival time must be strictly positive.\n");
        }
    } while (!(mean_interarrival_time > 0.0));

    do {
        printf("Enter mean service time (> 0): ");
        if (scanf("%lf", &mean_service_time) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF) {}
            mean_service_time = 0.0;
        }
        if (!(mean_service_time > 0.0)) {
            printf("Invalid input. Mean service time must be strictly positive.\n");
        }
    } while (!(mean_service_time > 0.0));

    arrival_rate = 1.0 / mean_interarrival_time;
    service_rate = 1.0 / mean_service_time;

    total_response_time = 0.0;
    total_waiting_time = 0.0;
    total_service_time = 0.0;
    total_interarrival_time = 0.0;
    total_interarrivals = 0;
    client_served = 0;

    Create_Event(&EventList, ARRIVAL, Tnow);
}

void PArrival(void) {
    double interarrival = generate_exponential(arrival_rate);
    double t_service = generate_exponential(service_rate);

    total_interarrival_time += interarrival;
    total_interarrivals++;

    enqueue(&QueueList, id_client++, Tnow, 0.0, t_service);

    if (Server == IDLE) {
        Server = BUSY;                          /* claim the server NOW */
        Create_Event(&EventList, START_SERVICE, Tnow);
    }

    Create_Event(&EventList, ARRIVAL, Tnow + interarrival);
}

void PStart_Service(void) {
    if (!dequeue(&QueueList, &CurrentClient)) {
        return;
    }

    CurrentClient.t_start_service = Tnow;
    Create_Event(&EventList, DEPARTURE, Tnow + CurrentClient.t_service);
}

void PDeparture(void) {
    total_response_time += (Tnow - CurrentClient.t_arrival);
    total_waiting_time  += (CurrentClient.t_start_service - CurrentClient.t_arrival);
    total_service_time  += CurrentClient.t_service;
    client_served++;

    if (!is_empty(&QueueList)) {
        Create_Event(&EventList, START_SERVICE, Tnow);
    } else {
        Server = IDLE;
    }
}