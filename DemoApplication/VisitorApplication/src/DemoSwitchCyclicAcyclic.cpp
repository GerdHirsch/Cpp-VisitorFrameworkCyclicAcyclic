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
using AdapterWeak = Repository::AdapterByWeakpointer<Adaptee>;
}

using namespace CyclicAcyclicRepository;
using namespace std;

void demoSwitchCyclicAcyclic(){
	cout << "================================" << endl;
	std::cout << "==== demoSwitchCyclicAcyclic() ====" << std::endl;
	Visitables visitables;

	DemoVisitor visitor;
	DemoVisitor13 visitor13;
	DemoVisitor23 visitor23;

	NonVisitable nv;
	auto pNVWA = std::make_shared<NonVisitableWithAccessor>();

	visitables.push_back(Visitable(new E1));
	visitables.push_back(Visitable(new E2));
	visitables.push_back(Visitable(new E3));
	visitables.push_back(Visitable(new AdapterReference<NonVisitable>(nv)));
	visitables.push_back(Visitable(new AdapterWeak<NonVisitableWithAccessor>(pNVWA)));

	demoRunVisitor(visitor, visitables);
	demoRunVisitor(visitor13, visitables);
	demoRunVisitor(visitor23, visitables);


	std::cout << "==== end demoSwitchCyclicAcyclic() ====" << std::endl;
}
