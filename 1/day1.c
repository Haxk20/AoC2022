#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *fp;

   fp = fopen("input1.txt", "r");
   
   long highest3[1000];
   for (int i = 0; i < 1000; i++) {
		highest3[i] = 0;
	}
   int index = 0;
   
   char * line = NULL;
   size_t len = 0;
   
   long count = 0;
   long highest = 0;
   long a;
   
   ssize_t read;
   char * ptr;
   
   while ((read = getline(&line, &len, fp)) != -1) {
   		if (line[0] != '\n') {
   			count += strtol(line, &ptr, 10);
   			if (count > highest) {
   				highest = count;
   			}
   		}
   		else {
   			highest3[index] = count;
   			index++;
   			count = 0;
   		}
	}
	for (int j = 0; j < 1000; j++) {
		for (int i = j+1; i < 1000; i++) {
		if (highest3[j] > highest3[i]) {
			a = highest3[j];
			highest3[j] = highest3[i];
			highest3[i] = a;
			}
		}
	}
	printf("Part 1: %d\n", highest3[999]);
	printf("Part 2: %d\n", highest3[999] + highest3[998] + highest3[997]);
	
	return 0;
}
