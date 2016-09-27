#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <algorithm>

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

string decimalTo(int n, int b) {

	int digits = 0;
	char keys[] = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
	string r;

	// Calculate the hexadecimal
	while(n != 0) {
		r = keys[(n%b)] + r;
		n /= b;
		digits++;
		//if(digits%4 == 0) r = " " + r;
	}

	// Return the value
	return r;
}

int toDecimal(string value, int base) {

	// Get the base and number
	int pos = 0;
	int ans = 0;
	char keys[] = "0123456789ABCDEFGHIJKLMNOPQRSTUV";
	pos = value.length()-1;


	// Calculate the decimal
	while(pos >= 0) {

		// Conver value to integer
		int index = 0;
		for(int i=0; i<32; i++) {
			if(toupper(value[pos]) == keys[i]) {
				index = i;
				break;
			}
		}

		// Add to answer
		ans += index*pow(base, value.length()-(1+pos));

		// Increment position
		pos--;
	}

	// return value
	return ans;
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

	// Prompt user for input
	int base1, base2;
	string value;
	cout << "\nValue: Base 'x' to Base 'y'" << endl;
	cout << "Value: ";
	cin >> value;
	cout << "x: ";
	cin >> base1;
	cout << "y: ";
	cin >> base2;

	// Output the conversion!
	cout << decimalTo(toDecimal(value,base1) ,base2) << endl;
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