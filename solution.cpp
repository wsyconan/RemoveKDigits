#include"solution.h"

RemoveKDigits::RemoveKDigits(){}
RemoveKDigits::~RemoveKDigits(){}

RemoveKDigits::RemoveKDigits(string file_name, int k){
	this->num = num;
	this->k = k;
	ifstream file;
	file.open(file_name, ios::binary);
	this->file_name = file_name;
	if (!file) {
		cout << "Fail to open file!" << endl;
		getchar();
		exit(0);
	}
	int size;
	file.seekg(0, ios::end);
	size = file.tellg();
	if (size > 9 * 8) {
		cout << "File over size limet(9 digits)." << endl;
		getchar();
		exit(0);
	}
	file.seekg(0, ios::beg);
	int data;
	char* buffer = new char[4];
	while (!file.eof()) {
		file.read(buffer, 4);
		data = *(int*)buffer;
		num.push_back(data);
	}
	num.pop_back();
	file.close();
	this->reomve();
}

void RemoveKDigits::reomve() {
    vector<int> stack;
    for (int i = 0; i < num.size(); i++) {
        while (stack.size() > 0 && stack.back() > num[i] && k) {
            stack.pop_back();
            k -= 1;
        }
        stack.push_back(num[i]);
    }
    while (k > 0) {
        stack.pop_back();
        k--;
    }
    string res = "";
    bool first_digit = true;
    for (int i = 0; i < stack.size(); i++) {
        if (first_digit && stack[i] == 0) {
            continue;
        }
        first_digit = false;
        res += stack[i];
    }
	if (res.empty()) {
		res.push_back('0');
	}
	else {
		for (int i = 0; i < res.size(); i++) {
			res[i] += 48;
		}
	}
	cout << "Result is: " << res << endl;
}