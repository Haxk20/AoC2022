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
   		if (oponent == 'Q' && me == 'Q') {
   			break;
   		}
   		if ((oponent == 'A' && me == 'X') || (oponent == 'B' && me == 'Y') || (oponent == 'C' && me == 'Z')) {
   			win = 3;
   			printf("Draw\n");
   		}
   		else if ((oponent == 'A' && me == 'Y') || (oponent == 'B' && me == 'Z') || (oponent == 'C' && me == 'X')) {
   			win = 6;
   			printf("Win\n");
   		}
   		else {
   			win = 0;
   			printf("Loose\n");
   		}
   		score += win;
   		if (me == 'X') {
   			score++;
   			printf("Rock\n");
   		} else if (me == 'Y') {
   			score = score + 2;
   			printf("Paper\n");
   		} else if (me == 'Z') {
   			score = score + 3;
   			printf("Scissors\n");
   		}
	}
	printf("%d\n", score);
	
	return 0;
}
