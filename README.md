# MY_NAVY

"MY_NAVY" is a terminal-based version of the classic game Battleship, where two players compete to sink each other's ships. This implementation requires players to use signals in C for communication, adhering strictly to the rules of the traditional Battleship game, but with a twist—communication is solely through SIGUSER1 and SIGUSER2 signals.

## Preliminaries

- **Binary Name:** my_navy
- **Language:** C
- **Group Size:** 2
- **Compilation:** Via Makefile, including `re`, `clean`, and `fclean` rules.
- **Authorized Functions:** open, close, read, write, lseek, malloc, free, getpid, kill, signal, sigaction, sigemptyset, setcontext, getcontext, usleep, nanosleep, pause, getline, fopen, fclose, fseek, memset, memcpy.

## Project Overview

In "MY_NAVY," each player sets up ships on an 8x8 grid and takes turns guessing the locations of the opponent's ships. The game progresses with each player attempting to hit the opponent's ships by calling out grid coordinates. The first player to sink all of the opponent's ships wins. Communication between the two game instances is achieved using UNIX signals, introducing a complex layer of inter-process communication.

### How to Play

1. **Starting the Game:**
   - Player 1 starts the game without a PID argument and specifies the path to their navy positions file.
   - Player 2 starts the game with Player 1's PID as an argument, along with their own navy positions file.

2. **Gameplay:**
   - Players take turns attacking by specifying grid coordinates.
   - The game displays each player's own ships and the known status of the opponent's grid after each turn.

3. **Winning the Game:**
   - The game ends when all of one player's ships have been sunk.
   - The program outputs "I won" or "Enemy won" and exits with code 0 for a win and 1 for a loss.

### Navy Positions File

The positions file, passed as a parameter, must contain lines formatted as `LENGTH:FIRST_SQUARE:LAST_SQUARE`, specifying the ship's length and start/end coordinates.

## Installation and Compilation

Clone the repository and navigate to the project directory. Compile the program using the provided Makefile:

```bash
make
```

## Usage

Player 1:
```bash
./my_navy pos1
```
Player 2:
```bash
./my_navy [Player 1 PID] pos2
```
For help:
```bash
./my_navy -h
```

## Features

- Terminal-based Battleship gameplay.
- Signal-based communication between two instances.
- Customizable ship positions via a configuration file.
