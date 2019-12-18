#ifndef __ATTRIBUTES_H
#define __ATTRIBUTES_H

#include <vector>
#include <string>
#include <iostream>
#include <sstream>


using namespace std; 
using std::string; 
using std::vector;

typedef struct {
	string name; 
	string type; 
	int offset; 
	int val;
	vector<string> args_types;
	string retType;
	int number_of_preconditions;
} Symbol;

class Table {
	vector<Symbol> symbols;
public:
	Table() {}
	vector<Symbol> getSymbolsVector(void) {
		return symbols;
	}
	void push(Symbol s) {
		symbols.push_back(s);
	}
	void pop() {
		symbols.pop_back();
	}
	~Table() {}
};

typedef struct {
	string name; 
	string type; 
	int offset; 
	int val;
	vector<string> args_types;
	string retType;
	int number_of_preconditions;
	/* HW5 */
	string reg;
	string quad;
	vector<string> regsList;
	vector<int>	nextList;
	vector<int> breakList;
	vector<int> continueList;
	vector<int> trueList;
	vector<int> falseList;
} STYPE;

#define YYSTYPE STYPE	// Tell Bison to use STYPE as the stack type
#define YYSTYPE_IS_DECLARED = 1

#endif
