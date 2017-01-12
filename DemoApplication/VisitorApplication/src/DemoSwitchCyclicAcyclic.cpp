/*
 * demoSwitchCyclicAcyclic.cpp
 *
 *  Created on: 12.11.2016
 *      Author: Gerd
 */

#include "SwitchCyclicAcyclicVisitables.h"
#include "NonVisitable.h"
#include "NonVisitableWithAccessor.h"

#include "SwitchCyclicAcyclicVisitors.h"
#include "MockVisitor.h"
#include "SwitchCyclicAcyclicRepository.h"
#include "DemoRunVisitor.h"

#include <iostream>
#include <memory>
#include <vector>

namespace CyclicAcyclicRepository{

using Visitable = std::shared_ptr<Repository::Visitable>;
using Visitables = std::vector<Visitable>;

template<class Adaptee>
using MyAdapter =
		Repository::VisitableAdapter<Adaptee, VisitorFramework::StorageByWeakpointer<Adaptee>>;

template<class Adaptee>
using AdapterReference = Repository::AdapterByReference<Adaptee>;
template<class Adaptee>
using AdapterValue = Repository::AdapterByValue<Adaptee>;
template<class Adaptee>
using AdapterWeak = Repository::AdapterByWeakpointer<Adaptee>;
}

using namespace CyclicAcyclicRepository;
using namespace VisitorTestMock;
using namespace std;


void demoSwitchCyclicAcyclic(){
	cout << "================================" << endl;
	std::cout << "==== demoSwitchCyclicAcyclic() ====" << std::endl;
	Visitables visitables;

//	DemoVisitor visitor;
	DemoVisitor13 visitor13;
//	DemoVisitor23 visitor23;
	MockVisitor<Repository, E1, NonVisitable> mock;

//	std::cout << "==== NonVisitable nv ====" << std::endl;
//	NonVisitable nv;
//	auto visitable1 = Factory::makeVisitable(nv);
//	auto visitable2 = Factory::makeVisitable( (NonVisitable()) );
	AdapterValue<NonVisitable> av( (NonVisitable()) );

//	auto pNVWA = std::make_shared<NonVisitableWithAccessor>();

//	visitables.push_back(Visitable(new E1));
//	visitables.push_back(Visitable(new E2));
//	visitables.push_back(Visitable(new E3));

//	std::cout << "==== new AdapterReference<NonVisitable>(nv) ====" << std::endl;
//	visitables.push_back(Visitable(new AdapterReference<NonVisitable>(nv)));
//	visitables.push_back(visitable1);
	std::cout << "==== makeVisitable(NonVisitable()) ====" << std::endl;
//	visitables.push_back(Factory::makeVisitable(NonVisitable()));
//	visitables.push_back(Factory::makeVisitable(nv));

//	std::cout << "==== new AdapterValue<NonVisitable>(nv) ====" << std::endl;
//	visitables.push_back(Visitable(new AdapterValue<NonVisitable>(nv)));

//	std::cout << "==== new AdapterWeak<NonVisitableWithAccessor>(pNVWA) ====" << std::endl;
//	visitables.push_back(Visitable(new AdapterWeak<NonVisitableWithAccessor>(pNVWA)));

//	demoRunVisitor(visitor, visitables);
	demoRunVisitor(visitor13, visitables);
//	demoRunVisitor(mock, visitables);
//	demoRunVisitor(visitor23, visitables);


	std::cout << "==== end demoSwitchCyclicAcyclic() ====" << std::endl;
}
