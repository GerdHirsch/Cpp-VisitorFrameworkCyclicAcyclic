/*
 * main.cpp
 *
 *  Created on: 10.11.2016
 *      Author: Gerd
 */

#include "main.h"

#include <iostream>
using namespace std;
//using SharedPointer = std::shared_ptr<Visitable>;
//using Visitables = std::vector<SharedPointer>;

//void demoVisitor(Visitor& visitor, Visitables& visitables){
//	std::cout << std::endl << "==== " << visitor.toString() << " ====" << std::endl;
//	std::for_each(visitables.begin(), visitables.end(),
//			[&visitor](SharedPointer& visitable){ visitable->accept(visitor); });
//}



int main(){
	cout << "VariableTemplateDefaultArgumente" << endl;
	demoSimpleElements();
}
