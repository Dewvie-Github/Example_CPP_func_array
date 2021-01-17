#include<iostream>
#include<string>
#include<iomanip>

// [This is nothing just for clear scr] to avoid "system", it's dangerous
// system("cls"); is nothing. It's just for clearing screen
#include <cstdlib>

using namespace std;



void pass_by_value(int a, int b) {
	cout << "This is variable in function" << endl;
	a = a + 1;
	b = b + 2;
	cout << "a = a + 1 = " << a << endl;
	cout << "b = b + 2 = " << b << endl << endl;

	cout << "a = " << a;
	cout << ", b = " << b << endl << endl;
}

void pass_by_reference(int& a, int& b) {

	cout << "This is variable in function" << endl;
	a = a + 1;
	b = b + 2;
	cout << "a = a + 1 = " << a << endl;
	cout << "b = b + 2 = " << b << endl << endl;

	cout << "a = " << a;
	cout << ", b = " << b << endl << endl;

}

// You can't use &, you can use return array[array_size];
float pass_by_reference_1D_array(float price[5], float vat[5], float total_price[5]) {
	for (int i = 0; i < 5; i++) {
		total_price[i] = price[i] * (1 + (vat[i] / 100));
	}
	return total_price[5];
}

// You can't use &, you can use return array[array_size];
float pass_by_reference_2D_array(float product[5][3]) {
	for (int i = 0; i < 5; i++) {
		product[i][2] = product[i][0] * (1 + (product[i][1] / 100));
	}

	return product[5][2];
}

int fibonacci(int num) {

	int fibonacci[99];
	int count = 2;

	fibonacci[0] = 0;
	fibonacci[1] = 1;

	// Equation is fn = (fn-1) + (fn-2)
	while ((fibonacci[count - 2] + fibonacci[count - 1]) < num) {
		fibonacci[count] = fibonacci[count - 2] + fibonacci[count - 1];

		count++;
	}

	cout << "Fibonacci is ";
	for (int i = 0; i < count; i++) {
		cout << fibonacci[i] << ", ";
	}

	return 0;
}



int main() {
	int number;
	int menu;
	cout << ">> Welcome to C++ Example program <<" << endl;
	do {
		// menu
		{
			cout
				<< "=================================================" << endl
				<< " 1. Example of Pass By Value Function." << endl
				<< " 2. Example of Pass By Reference Function." << endl
				<< " 3. array 1D." << endl
				<< " 4. array 2D." << endl
				<< " 5. array 1D Pass By Reference." << endl
				<< " 6. array 2D Pass By Reference." << endl
				<< " 7. fibonacci" << endl
				<< " 8. Random Grade with 2D array Example" << endl
				<< " -1 to Exit Program " << endl
				<< "=================================================" << endl << endl;

			cout << "Enter menu : ";
			cin >> menu;
			system("cls");
			cout << endl << endl;
		}
		// Pass By Value Function
		if (menu == 1) {

			// Initial
			int a = 1, b = 2;
			cout << "This is a and b before function" << endl;
			cout << "a =" << a << ", b = " << b << endl << endl;

			// cout << a and b in function
			pass_by_value(a, b);

			cout << "This is a and b after function" << endl;
			cout << "a = " << a << ", b = " << b << endl << endl;

		}


		// Pass By Reference Function
		if (menu == 2) {
			// Initial
			int a = 1, b = 2;
			cout << "This is a and b before function" << endl;
			cout << "a =" << a << ", b = " << b << endl << endl;

			// cout << a and b in function
			pass_by_reference(a, b);

			cout << "This is a and b after function" << endl;
			cout << "a = " << a << ", b = " << b << endl << endl;
		}


		// Array 1D
		if (menu == 3) {
			int people_count;
			string name[10], surname[10];

			// Enter how many people name you want to add.
			do {
				cout << "Enter how many people name you want to add(1-10) : ";
				cin >> people_count;
			} while (people_count < 1 || people_count > 10);

			// This is input Name and Surname
			cout << endl << "Enter name and surname (Example : Fahsang Yamchao)" << endl;
			for (int i = 0; i < people_count; i++) {

				// # i+1 just for beauty you can ignore it :D
				cout << "Enter name and surname #" << i + 1 << " : ";
				cin >> name[i] >> surname[i];
			}
			cout << endl << endl;

			// This is cout all enter data in name and surname
			for (int i = 0; i < people_count; i++) {

				// # i+1 just for beauty you can ignore it... again!! :D
				cout << "name #" << i + 1 << " : " << name[i] << " " << surname[i] << endl;
			}

		}


		// Array 2D
		if (menu == 4) {
			int people_count;
			// Initial 2D arrays
			string name[10][2];

			// Enter how many people name you want to add.
			do {
				cout << "Enter how many people name you want to add(1-10) : ";
				cin >> people_count;
			} while (people_count < 1 || people_count > 10);

			// This is input Name and Surname
			cout << endl << "Enter name and surname (Example : Fahsang Yamchao)" << endl;
			for (int i = 0; i < people_count; i++) {

				// # i+1 just for beauty you can ignore it :D
				cout << "Enter name and surname #" << i + 1 << " : ";
				cin >> name[i][0] >> name[i][1];
			}
			cout << endl << endl;

			// This is cout all enter data in name and surname
			for (int i = 0; i < people_count; i++) {

				// # i+1 just for beauty you can ignore it... again!! :D
				cout << "name #" << i + 1 << " : " << name[i][0] << " " << name[i][1] << endl;
			}

		}


		// 1D Arrays Pass by reference
		if (menu == 5) {
			float product_price[5] = {}, product_vat[5] = {}, total_price[5] = {};
			int product_count;
			cout << "Price VAT calculate program." << endl;
			do {
				cout << "Enter how many product(1-5) : ";
				cin >> product_count;
			} while (product_count < 1 || product_count > 5);

			cout << endl << endl;

			// Input
			for (int i = 0; i < product_count; i++) {
				cout << "Enter product price #" << i + 1 << " : ";
				cin >> product_price[i];
				cout << "Enter product VAT #" << i + 1 << " : ";
				cin >> product_vat[i];
			}

			// call function
			pass_by_reference_1D_array(product_price, product_vat, total_price);

			cout << endl << endl;

			// Output
			for (int i = 0; i < product_count; i++) {
				cout << "Product price #" << i + 1 << " : " << product_price[i] << endl
					<< "Product VAT #" << i + 1 << " : " << product_vat[i] << endl
					<< "Total Product Price #" << i + 1 << " = " << total_price[i] << endl;
			}

		}


		// 2D Arrays Pass by reference
		if (menu == 6) {
			// column 0 = product price, 1 = vat, 2 = total price
			float product[5][3];
			int product_count;

			cout << "Price VAT calculate program." << endl;
			do {
				cout << "Enter how many product(1-5) : ";
				cin >> product_count;
			} while (product_count < 1 || product_count > 5);

			cout << endl << endl;

			// Input
			for (int i = 0; i < product_count; i++) {
				cout << "Enter product price #" << i + 1 << " : ";
				cin >> product[i][0];
				cout << "Enter product VAT #" << i + 1 << " : ";
				cin >> product[i][1];
			}

			// call function
			pass_by_reference_2D_array(product);

			cout << endl << endl;
			// Output
			for (int i = 0; i < product_count; i++) {
				cout << "Product price #" << i + 1 << " : " << product[i][0] << endl
					<< "Product VAT #" << i + 1 << " : " << product[i][1] << endl
					<< "Total Product Price #" << i + 1 << " = " << product[i][2] << endl << endl << endl;
			}

		}

		// Fibonacci Program : C++ Final Test in 2562
		else if (menu == 7) {

			cout << "Enter last number of fibonacci: ";
			cin >> number;
			cout << endl;

			// cout fibonacci
			fibonacci(number);
			cout << endl;
		}

		// Random Grade with 2D array Example
		else if (menu == 8) {

			int grade[10][3];
			string gradeText[10];

			// Initilize random seed
			srand(time(NULL));

			// Mean random between x to x+y-1
			// rand() % y + x;


			for (int i = 0; i < 10; i++) {
				grade[i][0] = rand() % 100 + 0;
			}

			// change grade to grade score
			for (int i = 0; i < 10; i++) {
				if (grade[i][0] >= 80) {
					grade[i][1] = 4;
					gradeText[i] = "A";
				}
				else if (grade[i][0] >= 70) {
					grade[i][1] = 3;
					gradeText[i] = "B";
				}
				else if (grade[i][0] >= 60) {
					grade[i][1] = 2;
					gradeText[i] = "C";
				}
				else if (grade[i][0] >= 50) {
					grade[i][1] = 1;
					gradeText[i] = "D";
				}
				else {
					grade[i][1] = 0;
					gradeText[i] = "F";
				}
			}

			for (int i = 0; i < 10; i++) {
				cout << "Student NO." << i + 1 << endl;
				cout << "Score : " << grade[i][0] << endl;
				cout << "Grade : " << gradeText[i] << endl;
				cout << "Grade Point : " << grade[i][1] << endl << endl;
			}
		}

		else if (menu == -1) {
			cout << "Exit Program." << endl;
		}
		system("pause");
		system("cls");
	} while (menu != -1);


	return 0;
}