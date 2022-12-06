#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
	char input[] = "mjqjpqmgbljsphdztnvjfqwrcgsmlb";
	for (int i = 0; i < strlen(input) - 15; ++i) {
		int matched = 0;
		for (int x = i; x < i + 14; ++x) {
			for (int y = i; y < i + 14; ++y) {
				printf("%c %c\n", input[x], input[y]);
				if (input[x] == input[y] && x != y) {
					matched = 1;
				}
			}
			printf("\n");
		}
		if (!matched) {
			printf("Found start of message at index: %d\n", i+14);
			return 0;
		}
	}
	
	return 0;
}
