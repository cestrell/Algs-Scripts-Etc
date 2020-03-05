#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> nums;
	char num;
	while (cin.get(num)) {
		nums.push_back(num - '0');
	}
	
	for (int i = 0; i < 10; ++i) {
		for (int i = 0; i < nums.size() - 1; ++i) {
			nums[i] = (++nums[i]) % 10;
			cout << nums[i];
		}
		cout << '\n';
	}
	return 0;
}
