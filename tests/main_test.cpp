#include "bcrypt/BCrypt.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
	string right_password = "right_password";
	string wrong_password = "wrong_password";

	// Include BCrypt header for hashing
	#include "bcrypt/BCrypt.hpp"

	// Forward declare BCrypt function
	void generateHash(const string& password, size_t hash_size);

	// Generate hash for right password
	generateHash(right_password, 12);

	// Check if right password matches stored hash
	if (right_password == BCrypt::generateHash(right_password, 12)) {
		cout << "Right password: " << right_password << endl;
	}

	// Check if wrong password matches stored hash
	else if (wrong_password == BCrypt::generateHash(right_password, 12)) {
		cout << "Wrong password: " << wrong_password << endl;
	} else {
		cout << "Password incorrect." << endl;
	}

	return 0;
}
```