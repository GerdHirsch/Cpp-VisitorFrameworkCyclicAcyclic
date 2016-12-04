/*
 * main.cpp
 *
 *  Created on: 10.11.2016
 *      Author: Gerd
 */

void demoSimpleElements();
void demoVisitorCyclic();
void demoMyCyclicRepository();
void demoMyAcyclicRepository();

#include <iostream>

using namespace std;

int main(){
	cout << "VisitorApplication" << endl;
//	demoSimpleElements();
	demoMyCyclicRepository();
	demoMyAcyclicRepository();
	cout << "================================" << endl;
}
