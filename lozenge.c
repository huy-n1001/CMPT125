#include <stdio.h>
// the program is not customized when n is not an integer
int main() {
	int n;
	printf("Enter an integer n: ");
	scanf("%d", &n);
	
	// prints a message when the input number is zero or negative
	if(n <= 0){
		printf("Give me a valid input\n");
	return -1;
	}	
	
	int a;
	int b;
	// run the first loop until n input number of rows
	for(a = 0;a < n;a++){
		// initialize the loop for number of stars per row for each n input number of rows
		for(b = 0;b < n-a-1;b++)
			printf("%c",' ');
		// print the stars one by one 
		for(b = 0;b <= a;b++){
			printf("*");
		// print the space between the stars
		if(b != a)
			printf(" ");
		}
	// go down a line for each time the number of stars matches the row number	
	printf("\n");
	}
	// initialize the reverse printing
	for(a = n-2;a >= 0;a--){
		// initialize the loop for number of stars per row for each n input number of rows
		for(b = 0;b < n-a-1;b++)
			printf("%c",' ');
		// print the stars one by one
		for(b = 0;b <= a;b++){
			printf("*");
		// print the space between the stars
		if(b != a)
			printf(" ");
		}
	// go down a line for each time the number of stars matches the row number 
	printf("\n");
	}
	return 0;
}
				