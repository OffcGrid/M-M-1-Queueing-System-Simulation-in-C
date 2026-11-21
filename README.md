# M/M/1 Queueing System Simulation in C

## Project Overview

This project implements a discrete-event simulation of an M/M/1 single-server queueing system using the C programming language.

The simulation models random client arrivals, random service times, waiting time, and client departures from the system.

## System Description

The M/M/1 model represents a queueing system with:

- **M (Markovian Arrivals):** Clients arrive according to a Poisson process, with exponentially distributed interarrival times.
- **M (Markovian Service):** Service times follow an exponential distribution.
- **1 (Single Server):** Only one server is available to serve clients.

## Features

- Client management using a FIFO queue.
- Random arrival time generation using an exponential distribution.
- Random service time generation using an exponential distribution.
- Event scheduling and processing.
- Arrival, service-start, and departure events.
- Discrete-event simulation.
- Performance statistics calculation.

## Performance Metrics

The simulation calculates:

- **Mean Response Time:** Average time a client spends in the system.
- **Mean Waiting Time:** Average time a client waits before service.
- **Throughput:** Number of clients served per unit of simulation time.

## Project Structure

```text
.
├── events/
├── Global_vars/
├── simulation/
├── statistics/
└── main.c
```

## Simulation Parameters

| **Parameter** | **Value** |
|---|---|
| Arrival Process | Exponential Distribution |
| Mean Interarrival Time | User-defined |
| Service Process | Exponential Distribution |
| Mean Service Time | User-defined |
| Number of Servers | 1 |
| Queue Discipline | FIFO |

## Compilation and Execution

Compile the project using GCC:

```bash
gcc -g -Wall -Wextra main.c events/events.c Global_vars/system.c simulation/simulation.c statistics/statistic.c -o main -lm
```

Run the simulation:

```bash
./main
```

## Technologies

- C Programming Language
- GCC Compiler
- Linux

## Academic Context

Developed as part of a university practical assignment on queueing systems and discrete-event simulation.

GitHub: [@OffcGrid](https://github.com/OffcGrid)
