/*
 * main.cpp
 *
 *  Created on: 10.11.2016
 *      Author: Gerd
 */

void demoSwitchCyclicAcyclic();
void demoVisitorCyclic();
void demoCyclicRepository();
void demoAcyclicRepository();

#include <iostream>

using namespace std;

int main(){
	cout << "VisitorApplication" << endl;
	demoSwitchCyclicAcyclic();
	demoCyclicRepository();
	demoAcyclicRepository();
	cout << "================================" << endl;
}
