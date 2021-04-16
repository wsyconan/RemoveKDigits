#include"solution.h"

int main() {
	string file_name;
	int k;
	cout << "Please enter the file path:" << endl;
	cin >> file_name;
	while (true) {
		cin.clear();
		cin.ignore();
		cout << "Please enter the number of digits you want to reomve:" << endl;
		cin >> k;
		if (!cin.fail()) {
			break;
		}
	}
	RemoveKDigits arr(file_name, k);

	return 0;
}