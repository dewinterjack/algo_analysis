#include "tools.h"
#include "sort.h"

int ms;

void clearScreen(){ //Default header for certain points in the program.
	system("clear");
	printf(BLUE "\nSorting Program ~ Jack Dewinter\n" WHITE);
	printf(GREEN "\nThis is a benchmarking program for sorting algorithms.\n");
}

int listAmount(){ //Gets amount of lists from the user
	int amount = 0;
	printf("\nInput 1 to view sort results and speeds, input greater than 1 to view a comparison chart." WHITE);
	printf("\n\nAmount of lists: (1 - 10)\n\n");
	scanf("%d", &amount);
	while(amount < 1 || amount > 10){
		clearScreen();
		printf(RED "\nIncorrect Value. Must be within 1 and 10.\n" WHITE);
		printf("\nAmount of lists:\n\n");
		scanf("%d", &amount);
	}
	return amount;
}

void launchInterface(){
	int amount = listAmount();
	if(amount == 1){
		int size = requestSize();
		int * numbers = generateList(size);
		clearScreen();
		printf("\nRandom list generated of size %d:\n\n", size);
		printList(numbers,size);
		oneListOptions(numbers,size);
	}
	else{
		int quickPlotSize[amount];
		int quickPlotTime[amount];
		int bubblePlotSize[amount];
		int bubblePlotTime[amount];
		int insertPlotSize[amount];
		int insertPlotTime[amount];
		int counter = 0;
		for(int i = 0; i < amount; i++){
			clearScreen();
			printf("\n%d lists to create.\n", amount);
			printf(YELLOW "\nTo get accurate data output, input values in ascending order.\n" WHITE);
			printf("\nList"  RED  " %d:\n" WHITE, i + 1);
			int size = requestSize();
			int * list = generateList(size);
			int * copy = copyList(list,size); //copy list to ensure the list is the same as original not sorted version
			int * copy2 = copyList(list,size);
			ms = quick(copy2,size);
			quickPlotSize[i] = size;
			quickPlotTime[i] = ms;
			storeToFile(quickPlotSize,quickPlotTime,i,counter); //Calls store function to plot data
			counter = 1;
			ms = bubble(copy,size);
			bubblePlotSize[i] = size;
			bubblePlotTime[i] = ms;
			storeToFile(bubblePlotSize,bubblePlotTime,i,counter);
			counter++;
			ms = insert(list,size);
			insertPlotSize[i] = size;
			insertPlotTime[i] = ms;
			storeToFile(insertPlotSize,insertPlotTime,i,counter);
			counter++;
		}
		gnuCommands();
	}
}

int * copyList(int * numbers, int size){ //Copies the list passed to it and returns the copy
	int *copy = (int*)malloc(size * sizeof(int));
	for(int i = 0; i < size; i++){
		copy[i] = numbers[i];
	}
	return copy;
}

void compare(int * numbers, int size){ //Compares execution automatically
	clearScreen();
	printf("\nComparing execution times for a list of %d values.\n", size);
	int * copy = copyList(numbers,size);
	int * copy2 = copyList(numbers,size);
	ms = bubble(copy2,size);
	printf("\nBubble Sort: %dms\n", ms);
	ms = quick(copy,size);
	printf("\nQuick Sort: %dms\n", ms);
	ms = insert(numbers,size);
	printf("\nInsertion Sort: %dms\n", ms);
}

void oneListOptions(int * numbers, int size){ //Options for 1 list chosen
	int choice;
	printf("\nCompare sorts (1) | View individual sort result (2)\n\n");
	scanf("%d", &choice);
	if(choice == 1){
		compare(numbers,size);
	}
	else if(choice == 2){
		sortChoice(numbers,size);
	}
	else{
		printf(RED "\nIncorrect Value\n" WHITE);
		oneListOptions(numbers,size);
	}
}

int requestSize(){ //Retrieves size of list from user
	int size;
	printf("\nHow many items will be in the list?\n\n");
	scanf("%d", &size);
	return size;
}

int * generateList(int size){ //Generates a random list
	int *numbers = (int*)malloc(size * sizeof(int));
	srand (time(NULL)); //Seeding random numbers against the time for true randomness.
	for(int i = 0; i < size; i++){
		numbers[i] = rand() % 1000; //Can change this value to chose the range of the random number
	}
	return numbers;
}

void sortChoice(int * numbers, int size){ //Menu for individual sorts
	clearScreen();
	int choice;
	printf("\nWhat sort would you like to run on the list?\n");
	printf("\nBubble (1) | Quick (2) | Insertion (3)\n\n");
	scanf("%d", &choice);
	clearScreen();
	printf("\n");
	switch(choice){
		case 1:
			printf("Original List:\n\n");
			printList(numbers,size);
			ms = bubble(numbers, size);	
			printf("\nAfter Bubble Sort:\n\n");
			printList(numbers,size);
			printf("\nExecution time: %dms\n", ms);
			break;
		case 2:
			printf("Original List:\n\n");
			printList(numbers,size);
			ms = quick(numbers, size);
			printf("\nAfter Quick Sort:\n\n");
			printList(numbers,size);
			printf("\nExecution time: %dms\n", ms);
			break;
		case 3:
			printf("Original List:\n\n");
			printList(numbers,size);
			ms = insert(numbers, size);
			printf("\nAfter Insertion Sort:\n\n");
			printList(numbers,size);
			printf("\nExecution time: %dms\n", ms);
			break;
		default:
			clearScreen();
			printf(RED "\nIncorrect Value\n" WHITE);
			sortChoice(numbers,size);
	}
}

void printList(int * numbers, int size){ //Prints the list passed to it
	int i;
	for(i = 0; i < size - 1; i++){
		if(i >= 20 && i%20 == 0){
			printf("\n");
		} 
		printf("%d, ", numbers[i]);
	}
	printf("%d\n", numbers[i]);
}


