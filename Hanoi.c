#include <stdio.h>

void towers(int num, char frompole, char topole, char auxpole) {

	if ( num > 0) {
		towers(num - 1, frompole, auxpole, topole);
		printf("\n%c to %c", frompole, topole);
		towers(num - 1, auxpole, topole, frompole);
	}
}

int main() {
	int num;
	scanf("%d", &num);
	towers(num, 'A', 'B', 'C');
	printf("\n");
}
