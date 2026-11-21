#ifndef SIMULATION_H
#define SIMULATION_H

#include "../Global_vars/system.h"
#include "../events/events.h"
#include "../statistics/statistic.h"

double generate_exponential(double lambda);
void Initialization(void);
void PArrival(void);
void PStart_Service(void);
void PDeparture(void);

#endif