#define _BSD_SOURCE //So popen function works.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

#define RED  "\x1B[31m"
#define WHITE  "\x1B[37m"
#define BLUE  "\x1B[34m"
#define GREEN  "\x1B[32m"
#define YELLOW  "\x1B[33m"

void clearScreen(void);
void launchInterface(void);
int requestSize(void);
int * generateList(int size);
void sortChoice(int * numbers, int size);
void printList(int * numbers, int size);
int listAmount(void);
void compare(int * numbers, int size);
void oneListOptions(int * numbers, int size);
int * copyList(int * numbers, int size);
void storeToFile(int * size, int * time, int plotPoints, int counter);
void gnuCommands(void);
