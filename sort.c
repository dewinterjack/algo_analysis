#include "sort.h"
#include "tools.h"

struct timeval t1,t0;


int elapsed;

int bubble(int * numbers, int size){
	gettimeofday(&t0, 0); 
	int temp;
	for(int i = 0; i < size - 1; i++){
		for(int j = 0; j < size - i - 1; j++){ //Size to be sorted shrinks everytime a full pass is complete.
			if(numbers[j] > numbers[j + 1]){
				swapValues(numbers, j, j+1);
			}
		}
	}
	gettimeofday(&t1, 0);
	elapsed = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec; //Storing a milisecond value for elapsed time in execution.
	return elapsed;
}

int quick(int * numbers, int size){
	gettimeofday(&t0, 0);
	int first = 0;
	int last = size - 1;
	sortPartition(numbers,first,last); //Splits list into partitions 
	gettimeofday(&t1, 0);
	elapsed = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
	return elapsed;
}

int insert(int * numbers, int size){
	gettimeofday(&t0, 0);
	int index;
	int current;
	for(int i = 1; i < size; i++){
		current = numbers[i];
		index = i - 1;
		while(index >= 0 && numbers[index] > current){ //Checks if index is meeting pivot point
			numbers[index + 1] = numbers[index];
			index = index - 1;
		}
		numbers[index + 1] = current;
	}
	gettimeofday(&t1, 0);
	elapsed = (t1.tv_sec-t0.tv_sec)*1000000 + t1.tv_usec-t0.tv_usec;
	return elapsed;
}

void sortPartition(int * numbers,int first,int last){
	if(last - first >= 1){
	int j = first - 1;
	int pivot = numbers[last];
		for(int i = first; i < last; i++){
			if(numbers[i] < pivot){
				j++;
				swapValues(numbers, i, j);
			} 
		}
		swapValues(numbers, last, j + 1);
		sortPartition(numbers,first,j);	//Recursive function for sorting an unknown amount of partitions.
		sortPartition(numbers,j + 2, last);		
	}
}

void swapValues(int * numbers, int position1, int position2){ //Reusable function for swapping values for a sort.
	int temp;
	temp = numbers[position1];
	numbers[position1] = numbers[position2];
	numbers[position2] = temp;
}


