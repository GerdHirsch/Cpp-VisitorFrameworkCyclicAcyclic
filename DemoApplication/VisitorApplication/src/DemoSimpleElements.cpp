/*
 * DemoSimpleElements.cpp
 *
 *  Created on: 12.11.2016
 *      Author: Gerd
 */

//Elements to be visited
#include "Element_1.h"
#include "Element_2.h"
#include "Element_3.h"
#include "NonVisitable.h"
#include "NonVisitableWithAccessor.h"

#include "MyVisitorUniversal1.h"
#include "MyVisitorUniversal2.h"

#include "MyVisitableCyclicAcyclic.h"
#include "DemoRunVisitor.h"

#include <Visitor/VisitorAcyclic.h>
#include <Visitor/VisitableAdapterAcyclic.h>

#include <vector>


namespace DemoSwitchCyclicAcyclic{

using Visitable = Repository::Visitable;
using Visitor = VisitorAcyclic::Visitor;

using SharedPointer = std::shared_ptr<Visitable>;
using Visitables = std::vector<SharedPointer>;

template<class Adaptee>
using AdapterWeak = Repository::VisitableAdapter<Adaptee, StorageByWeakPointer<Adaptee>>;
template<class Adaptee>
using AdapterReference = Repository::VisitableAdapter<Adaptee, StorageByReference<Adaptee>>;

}//end namespace


using namespace std;

void demoSimpleElements(){
#ifdef ACYCLIC
	cout << "ACYCLIC demoSimpleElements" << endl;
#else
	cout << "CYCLIC demoSimpleElements" << endl;
#endif

	using namespace DemoSwitchCyclicAcyclic;
	Visitables visitables;

//	Element_1 e1;
//	Visitable& rv =  e1;

	NonVisitable nv;

	shared_ptr<NonVisitableWithAccessor> pw(new NonVisitableWithAccessor);

	visitables.push_back(SharedPointer(new Element_1));
	visitables.push_back(SharedPointer(new Element_2));
	visitables.push_back(SharedPointer(new Element_3));
	visitables.push_back(SharedPointer(new AdapterReference<NonVisitable>(nv)));
	visitables.push_back(SharedPointer(new AdapterWeak<NonVisitableWithAccessor>(pw)));

	VisitorUniversal1 visitor1;
	VisitorUniversal2 visitor2;

	demoVisitor(visitor1, visitables);
	demoVisitor(visitor2, visitables);

	cout << "=== end demoSimpleElements" << endl;
}
