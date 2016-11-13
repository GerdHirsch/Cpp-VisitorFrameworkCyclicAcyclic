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
#include "NonVisitableWithAccessor.h"

#include "MyVisitorUniversal1.h"
#include "MyVisitorUniversal2.h"

#include "MyVisitableCyclicAcyclic.h"

#include "ConfigureDemoVisitor.h"

#include <include/VisitorAcyclic.h>
#include <include/VisitableAdapterAcyclic.h>

using namespace std;

void demoSimpleElements(){
	Element_1 e1;
	Element_2 e2;
	Element_3 e3;
	NonVisitable nv;
	NonVisitableWithAccessor nvwa;
	Repository::VisitableAdapter<NonVisitable> adapter(nv);
	Repository::VisitableAdapter<NonVisitableWithAccessor> adapter2(nvwa);
	typedef Repository::Visitable Visitable;

#ifdef ACYCLIC
	cout << "ACYCLIC demoSimpleElements" << endl;
#else
	cout << "CYCLIC demoSimpleElements" << endl;
#endif
	DemoSimpleElements::VisitorUniversal1 visitor1;
	DemoAdapterAcyclic::ConfigureDemoVisitor visitorConfigure;
	std::shared_ptr<Element_2>p(new Element_2);

	Visitable * pV = &e1;
	pV->accept(visitor1);
	e2.accept(visitor1);
	e3.accept(visitor1);
	p->accept(visitor1);

	pV = &adapter;
	pV->accept(visitor1);
	adapter2.accept(visitor1);

	cout << "=== " << endl;
	p->accept(visitorConfigure);
	pV->accept(visitorConfigure);
	adapter2.accept(visitorConfigure);
	e2.accept(visitorConfigure);
	e3.accept(visitorConfigure);


//	DemoSimpleElements::VisitorUniversal2 visitor2;
//	pV->accept(visitor2);
//	d2.accept(visitor2);
//	d3.accept(visitor2);
//	adapter.accept(visitor2);

}
