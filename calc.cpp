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

// Base conversions ====================================================================

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

// Algorithms / Thms ====================================================================

void myGcd(int a, int b) {

	// Determine larger / smaller number
	int big, small;
	if (a>=b) {
		big = a;
		small = b;
	} else {
		big = b;
		small = a;
	}

	
	if(big%small == 0) cout << "GCD = " << small << endl;
	else myGcd(small, big%small);
}

void belzout() {

	int a,b;

	// Pormpt user for vairable inputs
	cout << "\nax + by = 1";
	cout << "\na: ";
	cin >> a;
	cout << "b: ";
	cin >> b;

	// Run Belzout
	int divisor = (a>b) ? b : a ;
	int p = (a>b) ? a/b : b/a;
	int r = (a>b) ? a%b : b%a;
	int u = 1;
	int v = 0;
	int s = 0;
	int t = 1;
	int end = 0;

	while(r > 0) {

		int tmp1 = s;
		int tmp2 = t;
		int tmp3 = r;

		s = u - p*s;
		t = v - p*t;

		u = tmp1;
		v = tmp2;

		p = divisor / r;
		r = divisor % r;
		divisor = tmp3;

		if(r == 0) end++;

	}

	cout << "x = " << s << "\ny = " << t << endl;
}

void fastPowering() {

	// Gather Inputs
	int a,b,c,d,m;
	cout << "\na^b (mod m)\n";
	cout << "a: ";
	cin >> a;
	cout << "b: ";
	cin >> b;
	cout << "m: ";
	cin >> m;

	// Computer Result
	c = a;
	d = 1;
	while(b>0) {
		if(b%2 == 1) d = (d*c)%m;
		c = (c*c)%m;
		b = b/2;	
	}

	cout << "Ans = " << d << endl;
}

void fibonacci() {

	// Get nth degree
	int n, a, b, c;
	a = c = 0;
	b = 1;
	cout << "\nf(n), n: ";
	cin >> n;
	
	// Calc fib
	if(n == 1 || n == 2) c = 1;
	else for(int i=1; i<n; i++) {
		c = a + b;
		a = b;
		b = c;
	}

	cout << "f(" << n << ") = " << c << endl;

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
	cout << "\nPick an option: \n0. Back \n1. GCD\n2. Bezouts\n3. Fast Powering\n4. Fibonacci\nChoice: ";
	cin >> choice;
	cout << "-----------------------------";
	
	// Determine which choice the user made
	switch(choice){
		case 0: 
			break;
		case 1: 
			cout << endl << "gcd(a,b)\n";
			cout << "a: ";
			int a,b;
			cin >> a;
			cout << "b: ";
			cin >> b;
			myGcd(a,b);
			break;
		case 2:
			belzout();
			break;
		case 3:
			fastPowering();
			break;
		case 4: 
			fibonacci();
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