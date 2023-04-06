/*
Aleksandr Gryzlov
01/18/2023
Assignment 1.4
*/


// This assignment was taken from glorious instructor
// However I do understand the proccess this code is going for, I just can't write it all myself

#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

//First, Dr.lewis created a struct to store number of tokens from cmd
struct redirInputTypes {
	enum rITypes {redirInputNone, redirInputCreate, redirInputAppend};
};

struct redirOutputTypes {
	enum rOTypes { redirOutputNone, redirOutputCreate, redirOutputAppend };
};

//Second, created struct for dynamic allocated array C-string
typedef struct {
	size_t argc;
	char** argv;
	redirInputTypes::rITypes redirInput;
	redirOutputTypes::rOTypes redirOutput;
} ArgumentStruct;

struct split {
	enum empties_t{ empties_ok, no_empties };
};

//This is a big container that uses split to split a string, it is just a general tokenizer that was taken by Dr.Lewis from https://cplusplus.com/faq/sequences/strings/split/, he used combination of iostreams and getline() 
//and string::find_first_of(), this is the part where I couldn't do it myself and decided to use code from Dr.Lewis
template <typename Container>
Container& split(
	Container& result,
	const typename Container::value_type& s,
	const typename Container::value_type& delimits,
	split::empties_t empties = split::empties_ok)
{
	result.clear();
	size_t current;
	size_t next = -1;  
	do {
		if (empties == split::no_empties) {
			next = s.find_first_not_of(delimits, next + 1);
			if (next == Container::value_type::npos) break;
			next -= 1;
		}
		current = next + 1;
		next = next + 1;
		next = s.find_first_of(delimits, current);
		result.push_back(s.substr(current, next - current));
	} while (next != Container::value_type::npos);
	return result;
}

//vector cleanes the input and make it easier to tokenize by looking for speciar characters like < << > >> and then at line 89 starts tokenization
vector<string> readCommandVector(string& s) {
	vector<string> progArgs;
	size_t found = s.find(">>");
	if (found != string::npos) {
		s.replace(found, 2, ">>", 4);
	}
	else {
		found = s.find(">");
		if (found != string::npos) {
			s.replace(found, 2, ">", 3);
		}
	}
	found = s.find("<<");
	if (found != string::npos) {
		s.replace(found, 2, "<<", 4);
	}
	else {
		found = s.find("<");
		if (found != string::npos) {
			s.replace(found, 1, "<", 3);
		}
	}
	split(progArgs, s, "\t", split::no_empties);
	return progArgs;
}

//same thing here, we clean input and make it easier to tokenize, than we tokenize it on line 124,
//workingspace is our dynamiclly allocated array of C-strings, we convert our vector data to C-string on line 127
ArgumentStruct& readCommand(string& s) {
	ArgumentStruct* tmps = new ArgumentStruct;
	tmps->redirInput = redirInputTypes::redirInputNone;
	tmps->redirOutput = redirOutputTypes::redirOutputNone;
	vector<string> progArgs;
	size_t found = s.find(">>");
	if (found != string::npos) {
		s.replace(found, 2, ">>", 4);
		tmps->redirOutput = redirOutputTypes::redirOutputAppend;
	}
	else {
		found = s.find(">");
		if (found != string::npos) {
			s.replace(found, 2, ">", 3);
			tmps->redirOutput = redirOutputTypes::redirOutputCreate;
		}
	}
	found = s.find("<<");
	if (found != string::npos) {
		s.replace(found, 2, "<<", 4);
		tmps->redirInput = redirInputTypes::redirInputAppend;
	}
	else {
		found = s.find(">");
		if (found != string::npos) {
			s.replace(found, 1, "<", 3);
			tmps->redirInput = redirInputTypes::redirInputCreate;
		}
	}
	split(progArgs, s, "\t", split::no_empties);
	tmps->argc = progArgs.size();

	char** workingStorage = new char* [progArgs.size() + 1];
	for (size_t i = 0; i < progArgs.size(); i++)
	{
		workingStorage[i] = new char[progArgs[i].size() + 1];
		strcpy(workingStorage[i], progArgs[i].c_str());
	}
	workingStorage[progArgs.size()] = (char*)NULL;
	tmps->argv = workingStorage;
	return *tmps;
}


// this is just main to pass our command and generate some output
int main(int argc,const char* argv[]) {
	string t;
	ArgumentStruct as;
	cout << "NOW\n\n" << endl;
	string command(" ");
	while (command.compare("exit")) {
		cout << "Enter Cntrl-C to Quit: " << flush;
		getline(cin, t);
		as = readCommand(t);
		cout << "command argument count: " << as.argc << endl;
		for (int i = 0; i < as.argc; i++)
		{
			cout << "Token [" << i << "] :" << as.argv[i] << endl;
		}
		command = as.argv[0];
		if (as.redirInput != redirInputTypes::redirInputNone) {
			cout << "Redirection (input) command detection" << endl;
		}
		if (as.redirOutput != redirOutputTypes::redirOutputNone) {
			cout << "Redirection (output) command detection" << endl;
		}
	}
	return 0;
}