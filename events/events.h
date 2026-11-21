#ifndef EVENTS_H
#define EVENTS_H

#include <stdlib.h>
#include <stdbool.h>


typedef enum {
    DEPARTURE,
    START_SERVICE,
    ARRIVAL
} EventType;

typedef struct Event {
    EventType type;
    double time;
    struct Event *next;
} Event;

typedef struct EVENT_LIST {
    Event *head;
    Event *tail;
} Event_List;

extern Event_List EventList;

void init_event_list(Event_List *list);
bool event_list_empty(const Event_List *list);
void Create_Event(Event_List *list, EventType type, double time);
Event Get_Event(Event_List *list);
void free_event_list(Event_List *list);

#endif