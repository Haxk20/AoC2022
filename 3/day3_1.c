#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *fp;

   fp = fopen("input3.txt", "r");
   
   
   char * line = NULL;
   size_t len = 0;
   
   ssize_t read;
   unsigned long score = 0;
breakloop:
	while ((read = getline(&line, &len, fp)) != -1) {
		size_t size = strlen(line);
   		char right[size/2+1];
   		char left[size/2+1];
   		for (int i = 0; i < size/2; ++i) {
   			left[i] = line[i];
   			right[i] = line[size/2+i];
   		}
   		right[size/2] = '\0';
   		left[size/2] = '\0';
   		
   		for (int i = 0; i < size/2; ++i) {
   			for (int j = 0; j < size/2; ++j) {
   				if (right[i] == left[j]) {
   					if (right[i] >= 97) {
   						score += right[i] - 96;
   					}
   					else if (right[i] >= 65) {
   						score += right[i] - 38;
   					}
   					else {printf("WTF\n");}
   					goto breakloop;
   				}
   				else {
   					printf("%c and %c do not match\n", right[i], left[j]);
   			}
   		}
	}
	printf("%d\n", score);
	
	return 0;
}
