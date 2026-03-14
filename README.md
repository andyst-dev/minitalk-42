# minitalk

A small UNIX signal-based communication program developed as part of the 42 curriculum.
`minitalk` is a small client-server project that sends data between two processes using only `SIGUSR1` and `SIGUSR2`.

It was a good way to build solid foundations in inter-process communication, signal handling, bitwise operations and message reconstruction in C.

## Features
- Communication between two processes using UNIX signals
- Client-server architecture
- Character-by-character transmission through bit encoding
- Custom `ft_printf` integration for formatted output

## Project structure
- `inc/minitalk.h` — main header file
- `src/client.c` — client program sending a message bit by bit
- `src/server.c` — server program receiving and reconstructing the message
- `src/utils.c` — utility functions
- `ft_printf/` — local formatted output implementation used by the project
- `Makefile` — builds the `client` and `server` executables

## Mandatory part
The mandatory part focuses on the communication flow between the client and the server.

### Programs
- `server` — starts first, prints its PID, then waits for incoming signals
- `client` — takes a server PID and a string, then sends the message to the server

### Core behavior
- the server prints its PID on startup
- the client sends a string to the server using only `SIGUSR1` and `SIGUSR2`
- the server reconstructs each character from incoming bits
- the received message is displayed immediately on the server side

### Main components
- `client.c` — encodes each character into bits and sends them through signals
- `server.c` — receives signals, rebuilds characters and prints them
- `utils.c` — provides local utility helpers such as conversions

## Build
Build the project:

```bash
make
```

Clean object files:

```bash
make clean
```

Remove object files and executables:

```bash
make fclean
```

Rebuild everything:

```bash
make re
```

## Usage
Start the server first:

```bash
./server
```

Then run the client with the server PID and a message:

```bash
./client <PID> "Hello from client"
```

## Learning outcomes
This project was my first real introduction to signal-based inter-process communication in C.
It helped build solid foundations in:
- UNIX signal handling
- client-server communication patterns
- bitwise encoding and decoding
- asynchronous message reconstruction
- process identifiers and signaling
- modular program organization
