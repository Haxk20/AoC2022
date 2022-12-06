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
   
	while ((read = getline(&line, &len, fp)) != -1) {
   		sscanf(line, "%d-%d,%d-%d", &range1_start, &range1_end, &range2_start, &range2_end);
   		//2-4,1-5
   		//1-5,2-4
   		//range1_start-range1_end,range2_start-range2_end
   		if ((range1_start <= range2_start && range1_end >= range2_end) || (range1_start >= range2_start && range1_end <= range2_end)) {
   			score++;
   		}
   		
	}
	printf("%d\n", score);
	
	return 0;
}
