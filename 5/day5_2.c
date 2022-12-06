#include <stdio.h>
#include <stdlib.h>

int main(void) {
	FILE *fp;

   fp = fopen("input5.txt", "r");
   
   char stacks[9][72] = {{'B', 'P', 'N', 'Q', 'H', 'D', 'R', 'T'},
   						 {'W', 'G', 'B', 'J', 'T', 'V'},
   						 {'N', 'R', 'H', 'D', 'S', 'V', 'M', 'Q'},
   						 {'P', 'Z', 'N', 'M', 'C'},
   						 {'D', 'Z', 'B'},
   						 {'V', 'C', 'W', 'Z'},
   						 {'G', 'Z', 'N', 'C', 'V', 'Q', 'L', 'S'},
   						 {'L', 'G', 'J', 'M', 'D', 'N', 'V'}, 
   						 {'T', 'P', 'M', 'F', 'Z', 'C', 'G'}};
   int stackSizes[9] = {8, 6, 8, 5, 3, 4, 8, 7, 7};
   char * line = NULL;
   size_t len = 0;
   int amount = 0;
   int from = 0;
   int to = 0;
   
   ssize_t read;
   
   for (int i = 0; i < 9; ++i) {
   				for (int j = 0; j < stackSizes[i]; ++j) {
   					printf("%c ", stacks[i][j]);
   				}
   				printf("\n");
   			}
   
	while ((read = getline(&line, &len, fp)) != -1) {
		if (line[0] == 'm') {
   			sscanf(line, "move %d from %d to %d", &amount, &from, &to);
   			--from;
   			--to;
   			printf("move %d from %d to %d\n", amount, from+1, to+1);
   			for (int i = 0, j = amount - 1; i < amount && j >= 0; ++i, --j) {
   				stacks[to][stackSizes[to]+i] = stacks[from][stackSizes[from]-j-1];
   				stacks[from][stackSizes[from]-j-1] = 0;
   				
   			}
   			stackSizes[from] -= amount;
   			stackSizes[to] += amount;
   			printf("----------------------------------\n");
   			for (int i = 0; i < 9; ++i) {
   				for (int j = 0; j < stackSizes[i]; ++j) {
   					printf("%c ", stacks[i][j]);
   				}
   				printf("\n");
   			}
   			printf("----------------------------------\n");
   		}
	}
	//printf("%c, %c, %c, %c, %c, %c, %c, %c, %c\n", stacks[stackSizes[0]-1], stacks[stackSizes[1]-1], stacks[stackSizes[2]-1], stacks[stackSizes[3]-1], stacks[stackSizes[4]-1], stacks[stackSizes[5]-1], stacks[stackSizes[6]-1], stacks[stackSizes[7]-1], stacks[stackSizes[8]-1]);
	return 0;
}
