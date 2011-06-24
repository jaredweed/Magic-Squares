#include <iostream>
#include <ctime>
using namespace std;

#define N 4
#define M N * ((N * N) + 1) / 2
#define Nsq N*N

bool isMagic(int (&arr)[N][N]);

/*  +---+---+---+---+
    | A | B | - | C |
	+---+---+---+---+
	| G | E | F | - |
	+---+---+---+---+
	| - | - | - | - |
	+---+---+---+---+
	| - | - | - | D |
	+---+---+---+---+ */

/*	To create the magic square, as opposed to testing Nsq! permutations, it is easier to
	partially create the magic square, by permuting only (N-1)^2 - 2 parameters, and simply
	filling in the remaining variables using facts about the magic square. For instance,
	in row 1, the missing element is simply MagicNumber (34) - A - B - C. This procedure
	is consistent for the remaining elements. Thus, instead of Nsq^Nsq permutations, we
	break that down into Nsq * Nsq - 1 * ... * (Nsq - (N-1)^2 - 1) permutations. */

int main(){
	time_t start, end; // variables to hold time durations (for efficiency testing purposes)
	time (&start);
	int squares = 0, counter = 0;
	// squares are the squares found (7040 in all)
	//counter keeps track of all squares tested
	
	int magicArr[N][N];

/*	Note that, for each for loop, excluding the first, there are quality checks that measure
	uniqueness in numbers (first pass), and to ensure that the current permutation of
	numbers is in fact creating a partially magic square. In example, if A + B + C is less
	than M - 16, then that partial permutation is impossible. In this case, the program
	stops the current permutation and proceeds to the next. This form is a psuedo-method
	for backtracking, with the exclusion of recursive searches. */

	for(int a = 1; a <= Nsq; a++){
		magicArr[0][0] = a;
		for(int b = 1; b <= Nsq; b++){
			if(a == b)
				continue;
			magicArr[0][1] = b;
			for(int c = 1; c <= Nsq; c++){
				if(a == c || b == c || M - a - b - c > 16)
					continue;
				magicArr[0][3] = c;
				for(int d = 1; d <= Nsq; d++){
					if(a == d || b == d || c == d || M - a - c - d > 16)
						continue;
					magicArr[3][3] = d;
					for(int e = 1; e <= Nsq; e++){
						if(a == e || b == e || c == e || d == e || M - a - e - d > 16)
							continue;
						magicArr[1][1] = e;
						for(int f = 1; f <= Nsq; f++){
							if(a == f || b == f || c == f || d == f || e == f)
								continue;
							magicArr[1][2] = f;
							for(int g = 1; g <= Nsq; g++){
								if(a == g || b == g || c == g || d == g || e == g || f == g || M - e - f - g > 16)
									continue;
								magicArr[1][0] = g;

/*	At this point, the loops have successfully found 7 parameters that can fit a magic square;
	but not necessarily, when filled with the remaining elements. There are cases where
	duplicates arise (since we are not using forced-parameters on these elements) or cases
	when a row, column, or diagonal do not add up to M. Regardless, the elements are filled
	and then tested for magic properties. */

/*	Each element's value can be found by the aformentioned method, wherein the 7 parameters
	make up the element's value through some arithmatic operation. */

								magicArr[0][2] = M - a - b - c;
								magicArr[1][3] = M - e - f - g;
								magicArr[2][0] = c + d - g;
								magicArr[2][1] = a + d - f;
								magicArr[2][2] = M - a - e - d;
								magicArr[2][3] = e + f + g - c - d;
								magicArr[3][0] = M - c - a - d;
								magicArr[3][1] = M - a - e - d + f - b;
								magicArr[3][2] = 2*a + d + c + e - f + b - M;

								counter++; // if the code got this far, then we have a filled-in square

/*	At this point, the code will use a boolean function to test all the properties of 
	the created square. It will return false if any flags are raised, and then continue
	onto the next series of permutations. */

								if(isMagic(magicArr)){
									squares++;
									//printSquare(magicArr); /* Uncomment to see all squares printed */
									if(squares%1000 == 0) // more efficiency testing. . .
										cout << squares << " built . . ." << endl;
								}
							}
						}
					}
				}
			}
		}
	}
	cout << "Number of squares: " << squares << endl;
	cout << "Number of attempts: " << counter << endl;
	time (&end);
	cout << "Time to complete: " << difftime(end, start) << " seconds." << endl;
}
	

bool isMagic(int (&arr)[N][N]){
	/*	Function that will test all properties for magic squares.
		The order in which these properties are tested is significant.
			* First test to see if the cells contain the set {1, 2, .... Nsq).
				In many cases, the elements can be filled in with negative numbers
				or numbers that are greater than 16. 
			* Second test to see if all cells are unique (extension of first test).
				Again, many cases produce duplicates in the elements (parameters
				are always unique). While most squares are thrown out by the above
				test, this test is still required.
			* Remaining tests (row, column, and diagonal sums)
				If the 10% of squares that do not get thrown out by the above two
				tests, these tests will do final (actual) magic-square tests. If 
				all tests are passed, the function returns true and increases
				the square count. */


	// check if each cell has an appropriate number (1 -- 16)
	for(int i = 0; i <= 3; i++){
		for(int j = 0; j <= 3; j++){
			if(arr[i][j] <= 0 || arr[i][j] > Nsq)
				return false;
		}
	}

	//check for duplicates
	for(int h = 1; h <= Nsq; h++){
		int total = 0;
		for(int i = 0; i <= 3; i++){
			for(int j = 0; j <= 3; j++){
				if(arr[i][j] == h)
					total++;

			}
		}
		if(total != 1){
			return false;}
	}

	//check rows and columns for magic sum
	for(int i = 0; i <= 3; i++){
		int sum = 0, sum2 = 0;
		for(int j = 0; j <= 3; j++){
			sum += arr[i][j];
			sum2 += arr[j][i];
		}
		if(sum != M || sum2 != M){
			return false;}
	}

	//check diagonals for magic sum
	int sum = 0, sum2 = 0;
	int j = 0;
	for(int i = 0; i <= 3; i++){
		sum += arr[i][j];
		sum2 += arr[i][3-j];
		j++;
	}
	if(sum != M || sum2 != M)
		return false;
	return true;
}


void printSquare(int (&arr)[N][N]){
	/*	If you wish to see the squares printed, this function is
		just a simple way to print out each square. */

	for(int i = 0; i <= 3; i++){
		for(int j = 0; j <= 3; j++){
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}