#ifndef SYSTEM_H
#define SYSTEM_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_CUSTOMERS 100000

typedef enum {
    IDLE,
    BUSY
} ServerStatus;

typedef struct client {
    int id;
    double t_arrival;
    double t_start_service;
    double t_service;
    struct client *suiv;
} client;

typedef struct queue {
    client *head;
    client *tail;
} queue;

extern double Tnow;
extern ServerStatus Server;
extern queue QueueList;
extern double mean_interarrival_time;
extern double mean_service_time;
extern double arrival_rate;
extern double service_rate;
extern int id_client;
extern client CurrentClient;

void initial_queue(queue *q);
bool is_empty(const queue *q);
void enqueue(queue *q, int id, double t_arrival, double t_start_service, double t_service);
bool dequeue(queue *q, client *c);
void free_queue(queue *q);

#endif