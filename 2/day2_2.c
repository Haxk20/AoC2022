#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *fp;

   fp = fopen("input2.txt", "r");
   
   
   char * line = NULL;
   size_t len = 0;
   
   ssize_t read;
   char oponent, me;
   int score = 0;
   int win = 0;
   
	while ((read = getline(&line, &len, fp)) != -1) {
   		sscanf(line, "%c %c", &oponent, &me);
   		printf("%c %c\n", oponent, me);
   		if (me == 'X') {
   			win = 0;
   			printf("Loose\n");
   			if (oponent == 'A') {
   				win = win + 3;
   			}
   			else if (oponent == 'B') {
   				win = win + 1;
   			}
   			else {
   				win = win + 2;
   			}
   		}
   		else if (me == 'Y') {
   			win = 3;
   			printf("Draw\n");
   			if (oponent == 'A') {
   				win = win + 1;
   			}
   			else if (oponent == 'B') {
   				win = win + 2;
   			}
   			else {
   				win = win + 3;
   			}
   		}
   		else {
   			win = 6;
   			printf("Win\n");
   			if (oponent == 'A') {
   				win = win + 2;
   			}
   			else if (oponent == 'B') {
   				win = win + 3;
   			}
   			else {
   				win = win + 1;
   			}
   		}
   		score += win;
	}
	printf("%d\n", score);
	
	return 0;
}
