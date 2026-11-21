#include "system.h"

double mean_interarrival_time;
double mean_service_time;
double arrival_rate;
double service_rate;
double Tnow = 0.0;
int id_client = 0;
ServerStatus Server = IDLE;
queue QueueList;
client CurrentClient;

void initial_queue(queue *q) {
    q->head = NULL;
    q->tail = NULL;
}

bool is_empty(const queue *q) {
    return (q->head == NULL);
}

void enqueue(queue *q, int id, double t_arrival, double t_start_service, double t_service) {
    client *new_client = (client *)malloc(sizeof(client));

    new_client->id = id;
    new_client->t_arrival = t_arrival;
    new_client->t_start_service = t_start_service;
    new_client->t_service = t_service;
    new_client->suiv = NULL;

    if (is_empty(q)) {
        q->head = new_client;
        q->tail = new_client;
    } else {
        q->tail->suiv = new_client;
        q->tail = new_client;
    }
}

bool dequeue(queue *q, client *c) {
    if (is_empty(q)) {
        return false;
    }

    client *temp = q->head;
    *c = *temp;
    c->suiv = NULL;

    q->head = temp->suiv;
    if (q->head == NULL) {
        q->tail = NULL;
    }

    free(temp);
    return true;
}

void free_queue(queue *q) {
    client *curr = q->head;
    while (curr != NULL) {
        client *next = curr->suiv;
        free(curr);
        curr = next;
    }
    q->head = NULL;
    q->tail = NULL;
}