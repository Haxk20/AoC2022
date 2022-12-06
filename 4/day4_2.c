#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *fp;

   fp = fopen("input4.txt", "r");
   
   
   char * line = NULL;
   size_t len = 0;
   
   ssize_t read;
   int range1_start = 0, range1_end = 0, range2_start = 0, range2_end = 0;
   int score = 0;
breakloop:
	while ((read = getline(&line, &len, fp)) != -1) {
   		sscanf(line, "%d-%d,%d-%d", &range1_start, &range1_end, &range2_start, &range2_end);
   		//2-4,1-5
   		//1-5,2-4
   		//range1_start-range1_end,range2_start-range2_end
   		for (int i = range1_start; i <= range1_end; ++i) {
   			for (int j = range2_start; j <= range2_end; ++j) {
				if (i == j) {
					score++;
					goto breakloop;
				}   			
   			}
   		}
   		
	}
	printf("%d\n", score);
	
	return 0;
}
