#include <iostream>
#include <map>

std::map<int, std::string> openEndedResponseMap = {
	{ 1, "The \"Zen\" of vi is that you're speaking a language. The initial y is a verb. The statement yy is a synonym for y_. The y is doubled up to make it easier to type, since it is such a common operation." },
	{ 2, "Your problem with Vim is that you don't grok vi." },
	{ 3, "vi has 26 \"marks\" and 26 \"registers.\" A mark is set to any cursor location using the m command. Each mark is designated by a single lower case letter. Thus ma sets the 'a' mark to the current location, and mz sets the 'z' mark. You can move to the line containing a mark using the ' (single quote) command. Thus 'a moves to the beginning of the line containing the 'a' mark. You can move to the precise location of any mark using the ` (backquote) command. Thus  `z will move directly to the exact location of the 'z' mark." },
	{ 4, "If you only understand basic up, down, left, and right cursor movements then vi will be no more productive than a copy of \"notepad\" for you. (Okay, you'll still have syntax highlighting and the ability to handle files larger than a piddling ~45KB or so; but work with me here)." },
	{ 5, "So, one way to cut an arbitrary selection of text would be to drop a mark (I usually use 'a' as my \"first\" mark, 'z' as my next mark, 'b' as another, and 'e' as yet another (I don't recall ever having interactively used more than four marks in 15 years of using vi; one creates one's own conventions regarding how marks and registers are used by macros that don't disturb one's interactive context). Then we go to the other end of our desired text; we can start at either end, it doesn't matter. Then we can simply use d`a to cut or y`a to copy. Thus the whole process has a 5 keystrokes overhead (six if we started in \"insert\" mode and needed to Esc out command mode). Once we've cut or copied then pasting in a copy is a single keystroke: p." },
	{ 6, "Frequently we can more succinctly describe the range of text without moving our cursor around and dropping a mark. For example if I'm in a paragraph of text I can use { and } movements to the beginning or end of the paragraph respectively. So, to move a paragraph of text I cut it using { d} (3 keystrokes). (If I happen to already be on the first or last line of the paragraph I can then simply use d} or d{ respectively." },
	{ 7, "In addition to \"verbs\" and \"subjects\" vi also has \"objects\" (in the grammatical sense of the term). So far I've only described the use of the anonymous register. However, I can use any of the 26 \"named\" registers by prefixing the \"object\" reference with \" (the double quote modifier). Thus if I use \"add I'm cutting the current line into the 'a' register and if I use \"by/foo then I'm yanking a copy of the text from here to the next line containing \"foo\" into the 'b' register. To paste from a register I simply prefix the paste with the same modifier sequence: \"ap pastes a copy of the 'a' register's contents into the text after the cursor and \"bP pastes a copy from 'b' to before the current line." }
};

std::map<std::string, int> openEndedKeywordMap = {
	{ "zen", 1 },
	{ "philosophy", 1 },
	{ "language", 1},

	{ "problem", 2},
	{ "issue", 2 },
	{ "fault", 2 },
	{ "mistake", 2 },

	{ "marks", 3 },
	{ "register", 3 },
	{ "backquote", 3 },
	{ "backtick", 3 },
	{ "single quote", 3 },
	
	{ "efficient", 4 },
	{ "inefficient", 4 },
	{ "obtuse", 4 },
	{ "slow", 4 },
	{ "productive", 4 },
	{ "notepad", 4 },

	{ "copy", 5 },
	{ "cut", 5 },
	{ "paste", 5 },
	{ "move", 5 },

	{ "paragraph", 6 },
	{ "tips", 6 },
	{ "without mark", 6 },
	{ "without a mark", 6 },
	{ "without using mark", 6 },
	{ "without including mark", 6 },
	{ "avoid mark", 6 },
	{ "avoid a mark", 6 },
	{ "avoid using mark", 6 },
	{ "avoid including mark", 6 },
	{ "exclude mark", 6 },
	{ "exclude a mark", 6 },
	{ "exclude using mark", 6 },
	{ "exclude including mark", 6 },
	{ "ignore mark", 6 },
	{ "ignore a mark", 6 },
	{ "ignore using mark", 6 },
	{ "ignore including mark", 6 },

	{ "grammar", 7 },
	{ "object", 7 },
	{ "specify register", 7 },
	{ "specify a register", 7 },
	{ "specify mark", 7 },
	{ "specify a mark", 7 },
	{ "target", 7 },
};

int categorizeInput(std::string input, std::map<std::string, int> categoryMap) {
	for (auto const& pair : categoryMap) {
		if (input.find(pair.first, 0) != std::string::npos) {
			return pair.second;
		}
	}
	return 0;
}

void openEndedLoop() {
	while (true) {
		std::string input;
		std::getline(std::cin, input);
		for (char &c : input) {
			c = std::tolower(c);
		}
		int inputCategory = categorizeInput(input, openEndedKeywordMap);
		if (inputCategory == 0) {
			break;
		}
		std::cout << openEndedResponseMap[inputCategory];
		std::cout << '\n';
	}
}

void editorPromptLoop() {
	while (true) {
		std::string input;
		std::getline(std::cin, input);
		for (char &c : input) {
			c = std::tolower(c);
		}
		int inputCategory = categorizeInput(input, openEndedKeywordMap);
		if (inputCategory == 0) {
			break;
		}
		std::cout << openEndedResponseMap[inputCategory];
		std::cout << '\n';
	}
}

typedef void (*SessionLoop)(void);

std::map<std::string, int> mainMenuResponseMap = {
	{ "open", 1 },
	{ "o", 1 }
};

std::map<int, SessionLoop> sessionMap = {
	{ 1, &openEndedLoop }
};

int main() {
	while (true) {
		std::cout << "Select menu:\n"
			<< "  Open ended conversation (`open')\n";
		std::string input;
		std::getline(std::cin, input);
		for (char &c : input) {
			c = std::tolower(c);
		}
		int inputCategory = categorizeInput(input, mainMenuResponseMap);
		if (inputCategory == 0) {
			std::cout << "Unrecognized input. ";
		} else {
			sessionMap[inputCategory]();
		}
	}
	openEndedLoop();

	return 0;
}
