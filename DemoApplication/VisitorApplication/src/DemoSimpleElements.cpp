/*
 * DemoSimpleElements.cpp
 *
 *  Created on: 12.11.2016
 *      Author: Gerd
 */
#include "main.h"

#include <iostream>
using namespace std;


void demoSimpleElements(){
	Element_1 d1;
	Element_2 d2;
	Element_3 d3;

#ifdef ACYCLIC
	cout << "ACYCLIC VariableTemplateDefaultArgumente" << endl;
	typedef VisitorAcyclic::Visitable
		Visitable;
#else
	cout << "CYCLIC VariableTemplateDefaultArgumente" << endl;
	typedef VisitorCyclic::Visitable<MyRepositoryCyclic::MyVisitorBase>
		Visitable;
#endif
	VisitorUniversal visitor;
	Visitable * pV = &d1;
	pV->accept(visitor);
	d2.accept(visitor);
	d3.accept(visitor);
}
