#ifndef COMPI_HW5_REGISTERAUXILARY_H
#define COMPI_HW5_REGISTERAUXILARY_H

#include "attributes.hpp"
#include "bp.hpp"
#include <iostream>
#include <vector>
#include <string>

#define REG_NUM 18

using namespace std;

/* register is represented with string, it's name,
   and bool, wether it's available or not */
class regPair { 
	string reg; 
	bool used;
public:
	regPair(string reg_name) : reg(reg_name), used(false) {}
	bool getUsed() { return used; }
	string getReg() { return reg; }
	void setUsed(bool is_used) { used = is_used; }
};

class Registers { 
	vector<regPair> reg_pool;
	int available_regs;
public:
	Registers() : available_regs(REG_NUM) {
		/* using registers $t8-$t25 */
		for(int i = 8; i <= 25; i++) {
			ostringstream ss;
			ss << i;
			reg_pool.push_back(regPair("$" + ss.str()));
		}
	}
	string getReg() {
		for (int i = 0; i < REG_NUM; i++) {
			if (!reg_pool[i].getUsed()) {
				available_regs--;
				reg_pool[i].setUsed(true);
				return reg_pool[i].getReg();
			}
		}
		cout << "ERROR NO MORE AVAILABLE REGS" << endl; 
	}

	string getReg(string reg) {
		for (int i = 0; i < REG_NUM; i++) {
			if (!reg_pool[i].getUsed() && reg_pool[i].getReg() == reg) {
				available_regs--;
				reg_pool[i].setUsed(true);
				return reg_pool[i].getReg();
			}
		}
		cout << "ERROR REG " + reg + " IS NOT AVAILABLE" << endl; 
	}

	vector<string> getUsedRegs() {
		vector<string> used_regs;
		for(int i = 0; i < REG_NUM; i++) {
			if(reg_pool[i].getUsed())
				used_regs.push_back(reg_pool[i].getReg());
		}
		return used_regs;
	}

	void freeReg(string reg) {
		for (int i = 0; i < REG_NUM; i++) {
			if (reg_pool[i].getUsed() && reg_pool[i].getReg() == reg) {
				available_regs++;
				reg_pool[i].setUsed(false);
			}
		} 
	}
	
	int getAvailable() { return available_regs; }

	void deallocateAllRegs() {
		for(int i = 0; i < REG_NUM; i++)
			reg_pool[i].setUsed(false);
		available_regs = REG_NUM;
	}
};
#endif