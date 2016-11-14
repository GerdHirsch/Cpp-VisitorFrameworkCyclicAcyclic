/*
 * DemoSimpleElements.cpp
 *
 *  Created on: 12.11.2016
 *      Author: Gerd
 */
#include "Element_1.h"
#include "Element_2.h"
#include "Element_3.h"
#include "NonVisitable.h"
#include "NonVisitableWithAccessor.h"

#include "MyVisitorUniversal1.h"
#include "MyVisitorUniversal2.h"

#include "MyVisitableCyclicAcyclic.h"

#include <include/VisitorAcyclic.h>
#include <include/VisitableAdapterAcyclic.h>
#include "main.h"

using namespace std;

void demoSimpleElements(){
	Element_1 e1;
	Element_2 e2;
	Element_3 e3;
	NonVisitable nv;
	NonVisitableWithAccessor nvwa;
	Repository::VisitableAdapter<NonVisitable> adapter(nv);
	typedef Repository::Visitable Visitable;

#ifdef ACYCLIC
	cout << "ACYCLIC demoSimpleElements" << endl;
#else
	cout << "CYCLIC demoSimpleElements" << endl;
#endif
	DemoSimpleElements::VisitorUniversal1 visitor1;
	std::shared_ptr<Element_2>p(new Element_2);

	Visitable * pV = &e1;
	pV->accept(visitor1);
	e2.accept(visitor1);
	e3.accept(visitor1);
	p->accept(visitor1);

	pV = &adapter;
	pV->accept(visitor1);

	cout << "=== " << endl;
}
