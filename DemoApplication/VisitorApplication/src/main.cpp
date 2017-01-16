/*
 * main.cpp
 *
 *  Created on: 10.11.2016
 *      Author: Gerd
 */

void demoCyclicRepository();
void demoAcyclicRepository();
void demoSwitchCyclicAcyclic();
void demoMakeVisitable();

#include <iostream>

using namespace std;

int main(){
	cout << "VisitorApplication" << endl;
//	demoCyclicRepository();
//	demoAcyclicRepository();
//	demoSwitchCyclicAcyclic();
	demoMakeVisitable();
	cout << "================================" << endl;
}
