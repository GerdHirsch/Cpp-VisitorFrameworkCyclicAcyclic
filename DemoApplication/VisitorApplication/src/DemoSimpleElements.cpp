/*
 * DemoSimpleElements.cpp
 *
 *  Created on: 12.11.2016
 *      Author: Gerd
 */
//#include "main.h"
#include "Main.h"

#include "Element_1.h"
#include "Element_2.h"
#include "Element_3.h"
#include "NonVisitable.h"

#include "MyVisitorUniversal1.h"
#include "MyVisitorUniversal2.h"

#include "MyVisitableCyclicAcyclic.h"

#include <include/VisitorAcyclic.h>
#include <include/VisitableAdapterAcyclic.h>

using namespace std;

void demoSimpleElements(){
	Element_1 d1;
	Element_2 d2;
	Element_3 d3;
	NonVisitable nv;
	Repository::VisitableAdapter<NonVisitable> adapter(nv);
	typedef Repository::Visitable Visitable;

#ifdef ACYCLIC
	cout << "ACYCLIC demoSimpleElements" << endl;
#else
	cout << "CYCLIC demoSimpleElements" << endl;
#endif
	DemoSimpleElements::VisitorUniversal1 visitor1;
	Visitable * pV = &d1;
	pV->accept(visitor1);
	d2.accept(visitor1);
	d3.accept(visitor1);
	pV = &adapter;
	pV->accept(visitor1);


//	DemoSimpleElements::VisitorUniversal2 visitor2;
//	pV->accept(visitor2);
//	d2.accept(visitor2);
//	d3.accept(visitor2);
//	adapter.accept(visitor2);

}
