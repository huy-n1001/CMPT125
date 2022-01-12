//The big-O estimate of the worst case scenario is O(n^2)

#include <stdio.h>
#include <string.h>

void replica_string(char str[]) {

	int i;
	int j;
	int orig_length;
	int index = 0;	
	char res[1000] = ""; // stores the result string when its length is larger than 0
	int res_length = 0;
		
	orig_length = strlen(str);
	int rs[orig_length][orig_length]; 
	
	// Initializing an empty array
	for (i = 0; i <= orig_length; i++) {
		for (j = 0; j <= orig_length; j++) {
			rs[i][j] = 0;
		}
	}
	// Searching for the result string from i to n-1
	for (i = 1; i <= orig_length; i++) {
		for (j = i + 1; j <= orig_length; j++) {
			// printing only one result substring instead of two
			if(str[i-1] == str[j-1] && rs[i-1][j-1] < (j-1)) {
				rs[i][j] = rs[i-1][j-1] + 1;
				// extracting the length of the result string
				if(res_length < rs[i][j]) {
					res_length = rs[i][j];
					// ending the search of indexes
					if (index < i) { 
						index = i; 
					}
				}
			}
			else {
				rs[i][j] = 0;
			}
		}
	}
	// initialize the length of result string
	if(res_length > 0) {
		for(i = index - res_length; i < index; i++) {
			printf("%c", str[i]);
		}	
	}
	printf("\n");
}

int main() {

	char str[1000];
	printf("Input: ");
	scanf("%s", str);
	printf("Output: ");
	replica_string(str);
	
	return 0;
}	
	