#include <stdio.h>
#include "events.h"

Event_List EventList;

void init_event_list(Event_List *list) {
    list->head = NULL;
    list->tail = NULL;
}

bool event_list_empty(const Event_List *list) {
    return list->head == NULL;
}


void Create_Event(Event_List *list, EventType type, double time) {
    Event *new_event = (Event *)malloc(sizeof(Event));

    new_event->type = type;
    new_event->time = time;
    new_event->next = NULL;

    if (event_list_empty(list)) {
        list->head = new_event;
        list->tail = new_event;
        return;
    }

    Event *prev = NULL;
    Event *curr = list->head;

    while (curr != NULL &&
           (curr->time < new_event->time ||
            (curr->time == new_event->time && curr->type <= new_event->type))) {
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL) {
        new_event->next = list->head;
        list->head = new_event;
    } else {
        new_event->next = curr;
        prev->next = new_event;
        if (curr == NULL) {
            list->tail = new_event;
        }
    }
}


Event Get_Event(Event_List *list) {

    Event *first = list->head;
    Event result = *first;
    result.next = NULL;

    list->head = first->next;
    if (list->head == NULL) {
        list->tail = NULL;
    }

    free(first);
    return result;
}

void free_event_list(Event_List *list) {
    Event *curr = list->head;
    while (curr != NULL) {
        Event *next = curr->next;
        free(curr);
        curr = next;
    }
    list->head = NULL;
    list->tail = NULL;
}