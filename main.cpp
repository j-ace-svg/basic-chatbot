#include <iostream>

std::map<std::string, int> responseMap = {
	{ 0, "What do you seek in your text editor?" },
	{ 1, "Do you find vim to be a %s text editor?" },
	{ 2, "How do you think vim forces same-hand repetition?" },
	{ 3, "The \"Zen\" of vi is that you're speaking a language. The initial y is a verb. The statement yy is a synonym for y_. The y is doubled up to make it easier to type, since it is such a common operation." }
};

std::map<std::string, int> keywordMap = {
	{ "need", 1 }
};

int categorizeInput(std::string input) {
	
	return 0;
}

int main() {
	while (true) {
		std::string input;
		std::cin >> input;
		std::cout << input;
		int inputCategory = categorizeInput(input);
		if (inputCategory == 0) {
			break;
		}
	}

	return 0;
}
