#include "simulation/simulation.h"
#include "events/events.h"
#include "statistics/statistic.h"
#include "Global_vars/system.h"

int main(void) {
    Initialization();

    while (client_served < MAX_CUSTOMERS && !event_list_empty(&EventList)) {
        Event e = Get_Event(&EventList);
        Tnow = e.time;

        switch (e.type) {
            case ARRIVAL:
                PArrival();
                break;
            case START_SERVICE:
                PStart_Service();
                break;
            case DEPARTURE:
                PDeparture();
                break;
        }
    }

    Statistics();

    free_event_list(&EventList);
    free_queue(&QueueList);

    return 0;
}