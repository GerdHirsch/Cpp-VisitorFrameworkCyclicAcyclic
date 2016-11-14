/*
 * DemoAdapter.cpp
 *
 *  Created on: 12.11.2016
 *      Author: Gerd
 */


#include "DemoAdapterAcyclic.h"

#include "NonVisitable.h"
#include "NonVisitableWithAccessor.h"
#include "Element_1.h"
#include "Element_2.h"
#include "ConfigureDemoVisitor.h"

#include "DemoRunVisitor.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;

namespace DemoAdapterAcyclic{
using Visitable = VisitorAcyclic::Visitable;
using Visitor = VisitorAcyclic::Visitor;

using SharedPointer = std::shared_ptr<Visitable>;
using Visitables = std::vector<SharedPointer>;

template<class Adaptee>
using AdapterWeak = VisitorAcyclic::VisitableAdapter<Adaptee, StorageByWeakPointer<Adaptee>>;
template<class Adaptee>
using AdapterReference = VisitorAcyclic::VisitableAdapter<Adaptee, StorageByReference<Adaptee>>;

}//end namespace

void demoAdapterAcyclic(){

	using namespace DemoAdapterAcyclic;
	cout << "demoAdapterAcyclic" << endl;
	Visitables visitables;

	NonVisitable nv;
	shared_ptr<NonVisitable> p(new NonVisitable);
	shared_ptr<NonVisitableWithAccessor> pw(new NonVisitableWithAccessor);

	visitables.push_back(SharedPointer(new AdapterWeak<NonVisitable>(p)));
	visitables.push_back(SharedPointer(new AdapterWeak<NonVisitableWithAccessor>(pw)));
	visitables.push_back(SharedPointer(new AdapterReference<NonVisitable>(nv)));
//	visitables.push_back(SharedPointer(new Element_1));
	Element_1 e1;
//	VisitorAcyclic::Visitable* pE1 = &e1;
	ConfigureDemoVisitor cdv;
//	e1.accept(cdv);

	demoVisitor(cdv, visitables);

}

