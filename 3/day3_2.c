#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	FILE *fp;

   fp = fopen("input3.txt", "r");
   
   
   char * line = NULL;
   char * line2 = NULL;
   char * line3 = NULL;
   size_t len = 0;
   
   ssize_t read;
   unsigned long score = 0;
breakloop:
	while (((read = getline(&line, &len, fp)) != -1) && ((read = getline(&line2, &len, fp)) != -1) && ((read = getline(&line3, &len, fp)) != -1)) {
		size_t size = strlen(line);
		size_t size2 = strlen(line2);
		size_t size3 = strlen(line3);
   		
   		for (int i = 0; i < size; ++i) {
   			for (int j = 0; j < size2; ++j) {
   				for (int k = 0; k < size3; ++k) {
   				if (line[i] == line2[j] && line2[j] == line3[k]) {
   					if (line[i] >= 97) {
   						score += line[i] - 96;
   					}
   					else if (line[i] >= 65) {
   						score += line[i] - 38;
   					}
   					else {printf("WTF\n");}
   					goto breakloop;
   				}
   				else {
   					printf("%c and %c and %c do not match\n", line[i], line2[j], line3[k]);
   				}
   			}
   		}
   		}
	}
	printf("%d\n", score);
	
	return 0;
}
