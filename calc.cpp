#include <stdlib.h>
#include <iostream>
#include <cmath>

using namespace std;

// Arithmatic Funcation Definitions ====================================================================

void mod() {

		int x,y;
		cout << endl << "x % y = z" << endl;
		cout << "x: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
		cout << "z = " << (x%y) << endl;
}

// Base conversions

void decimal() {

	// Create Variables
	int n; 
	int ans = 0;

	// Prompt user for number
	cout << endl << "Enter a number: ";
	cin >> n;

	// Calc max pow
	int max = 1;

	// Calculate the Decimal
	while(n!=0 && max > 0) {

		if(n%2!=0) ans += max;
		max*=2;
		n = n/10;
		//cout << "Current State: " << n << endl << "Max: " << max << endl << "Ans: " << ans << endl;

	}
		
	// return the decimal
	cout << ans << endl;
}

void binary() {

	// Create variables 
	int n;
	int digits = 0;
	string r;

	// Prompt user for the number
	cout << endl << "Enter a number: ";
	cin >> n;

	// Calculae the binary
    while(n!=0) {
    	
    	// Increment Digits
    	digits++;
    	
    	// Check for remaining n
    	if(n!=0) {
    		r=(n%2==0 ?"0":"1")+r; n/=2;
    		if(digits%4==0) r = " " + r;
    	}
    }

    // Ensure that digits%4 ==0
    while(digits%4 != 0) {
    	r = "0" + r;
    	digits++;
    }

    // Print it
    cout << r << endl;
}

// Algorithms / Thms

void myGcd(int a, int b, int u, int v, int x, int y, bool bez) {

	// Determine larger / smaller number
	int big, small;
	if (a>=b) {
		big = a;
		small = b;
	} else {
		big = b;
		small = a;
	}

	if(big%small == 0) cout << small << endl;
	else myGcd(small, big%small, 0, 0, 0, 0, false);
}

void belzout() {

	int a,b;

	// Pormpt user for vairable inputs
	cout << "ax + by = 1";
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;

	// Run GDC with values
	myGcd(a,b, 1, 0, 0, 1, true);
}

// Menu Interface Def. ====================================================================

void arithmatic() {

	// Prompt the user for what calculation they would like to make.
	int choice;
	int a, b, c;
	cout << "\nPick an option: \n0. Back \n1. Mod\n2. Add\n3. Sub\n4. Mult\n5. Div\n6. Expo\nChoice: ";
	cin >> choice;
	cout << "----------------------------- ";
	
	// Determine which choice the user made
	switch(choice){
		case 0: 
			break;
		case 1: 
			mod();
			break;
		case 2: 
			cout << endl << "a + b = c" << endl;
			cout << "a: ";
			cin >> a;
			cout << "b: "; 
			cin >> b;
			c = a + b;
			cout << "c = " << c << endl;
			break;
		case 3: 
			cout << endl << "a - b = c" << endl;
			cout << "a: ";
			cin >> a;
			cout << "b: "; 
			cin >> b;
			c = a - b;
			cout << "c = " << c << endl;
			break;
		case 4: 
			cout << endl << "a * b = c" << endl;
			cout << "a: ";
			cin >> a;
			cout << "b: "; 
			cin >> b;
			c = a * b;
			cout << "c = " << c << endl;
			break;
		case 5: 
			cout << endl << "a / b = c" << endl;
			cout << "a: ";
			cin >> a;
			cout << "b: "; 
			cin >> b;
			c = a / b;
			cout << "c = " << c << endl;
			break;
		case 6: 
			cout << endl << "a^(b) = c" << endl;
			cout << "a: ";
			cin >> a;
			cout << "b: "; 
			cin >> b;
			c = pow(a,b);
			cout << "c = " << c << endl;
			break;
		default:
			break;
	}
}

void baseConversion() {

	// Prompt the user for what calculation they would like to make.
	int choice;
	cout << "\nPick an option: \n0. Back \n1. Decimal to Binary\n2. Binary to Decimal\nChoice: ";
	cin >> choice;
	cout << "----------------------------- ";
	
	// Determine which choice the user made
	switch(choice){
		case 0: 
			break;
		case 1: 
			binary();
			break;
		case 2:
			decimal();
			break;
		default:
			break;
	}
}

void algorithms() {

	// Prompt the user for what calculation they would like to make.
	int choice;
	cout << "\nPick an option: \n0. Back \n1. GCD\n2. Bezouts\nChoice: ";
	cin >> choice;
	cout << "-----------------------------";
	
	// Determine which choice the user made
	switch(choice){
		case 0: 
			break;
		case 1: 
			cout << endl << "Enter two integers: ";
			int a,b;
			cin >> a >> b;
			myGcd(a,b, 1, 0, 0, 1, false);
			break;
		case 2:
			belzout();
			break;
		default:
			break;
	}
}

void mainMenu() {

	// DATLEDOODONKEY
	bool quit = false;

	// Main Menu
	while(!quit){
		
		// Prompt the user for what calculation they would like to make.
		int choice;
		cout << "-----------------------------";
		cout << "\n0. Quit \n1. Arithmatic \n2. Base Conversion\n3. Algorithms\nChoice: ";
		cin >> choice;
		cout << "----------------------------- ";
		
		// Determine which choice the user made
		switch(choice){
			case 0: 
				quit = true;
				break;
			case 1:
				arithmatic();
				break;
			case 2:
				baseConversion();
				break;
			case 3: 
				algorithms();
				break;
			default:
				break;
		}
	}

	cout << endl;
}


// Main ===================================================================================

int main() {
	
	// Start Main Menu
	mainMenu();

}