#include <cstring>
#include <iostream>
#include <stack>

#define N 4
#define M 5

using namespace std;

class node {
public:
	int x, y;
	int dir;
	node(int i, int j) {
		x = i;
		y = j;
	
		// set initial direction to 0
		dir = 0;
	}
};

// maze of matrix
int n = N, m = M;

// Food coordinates
int fx, fy;
bool food[N][M];


bool isReachable(int maze[N][M], int fx, int fy) {
	int i = 0, j = 0; // current location
	stack<node> s; // stack of nodes to go through
	
	// Initially starting at (0, 0).
	node temp(i , j);
	s.push(temp);
	
	while (!s.empty()) {
	
		temp = s.top();
		int d = temp.dir;
		i = temp.x, j = temp.y;
		
		temp.dir++;
		s.pop();
		s.push(temp);
		
		if ( i == fx and j == fy) {
			return true;
		}

		// dir = 0 for upwards
		if ( d == 0) {
			if ( i - 1 >= 0 and maze[i - 1][j] and food[i - 1][j]) {
				node temp1(i - 1, j);
				food[i - 1][j] = false;
				s.push(temp1);
			}
		}
		
		// dir = 1 for left
		else if ( d == 1) {
			if (j - 1 >= 0 and maze[i][j - 1] and food[i][j - 1]) {
				node temp1(i - 1, j);
				food[i][j - 1] = false;
				s.push(temp1);
			}
		}
		
		// dir = 2 for downwards
		else if ( d == 2) {
			if (i + 1 < n and maze[i + 1][j] and food[i + 1][j]) {
				node temp1(i + 1, j);
				food[i + 1][j] = false;
				s.push(temp1);
			}
		}
		
		// dir = 3 for right
		else if ( d == 3) {
			if (j + 1 < m and maze[i][j + 1] and food[i][j + 1]) {
				node temp1(i, j + 1);
				food[i][j + 1] = false;
				s.push(temp1);
			}
		}
		
		// go back to previous spot if none of the directions above works
		else {
			food[temp.x][temp.y] = true;
			s.pop();
		}
	}
	// return false if no path is found
	return false;		
}

// Driver code
int main() {

	// set the position of carrot to be true	
	memset(food, true, sizeof(food));
	//Maze matrix

	int maze[N][M] = {
		{1,0,1,1,0},
		{1,1,1,0,1},
		{0,1,0,1,1},
		{1,1,1,1,1}
	};
	
	int fx = 1;
	int fy = 2;
	// int fy = 2;
	
	/*
	int maze[N][M] = {
		{1,0,1,1,0},
		{1,1,1,0,1},
		{0,1,0,1,1},
		{1,1,1,1,1}
	};	
	
	// Food coordinates
	int fx = 2;
	int fy = 3;
	*/
	
	if (isReachable(maze, fx, fy)) {
		cout << "Path found!" << '\n';
	} else {
		cout << "No path found!" << '\n';
	}
	
	return 0;
}
