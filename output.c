#include "tools.h"

FILE * temp;

void storeToFile(int * size, int * time, int plotPoint, int counter){
	if(counter == 0){
		temp = fopen("sort.temp","w"); //Opens temp file for output.
		fprintf(temp, "Quick Sort          Bubble Sort          Insertion Sort\n");
		fprintf(temp, "# Size    Time\n\n");
		fprintf(temp, "0      0        0      0        0      0\n"); //Default values for x and y.
	}
	fprintf(temp, "%05d  %05d    ", size[plotPoint], time[plotPoint]); //Writes the contents of size and time in the temp file. Makes file easier to read.
	if(counter == 2){
		fprintf(temp, "\n");//Newline for next set of points
	}
}

void gnuCommands(){ //Commands for gnuplot on startup.
	FILE * gnuCommand = popen("gnuplot -persistent", "w"); //Keeps graph open
	fprintf(gnuCommand, "set title \"Sorting Benchmark\" font \"Calibri, 20\"\n");
	fprintf(gnuCommand, "set xlabel \"Size\" font \"Calibri, 20\"\n");
	fprintf(gnuCommand, "set ylabel \"Time (ms)\" font \"Calibri, 20\"\n");
	fprintf(gnuCommand, "plot 'sort.temp' using 1:2 with lines title \"Quick Sort\",\'sort.temp' using 3:4 with lines title \"Bubble Sort\",\'sort.temp' using 5:6 with lines title \"Insertion Sort\"\n");
}


