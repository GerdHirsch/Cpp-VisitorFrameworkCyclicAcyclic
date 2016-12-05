/*
 * demoSwitchCyclicAcyclic.cpp
 *
 *  Created on: 12.11.2016
 *      Author: Gerd
 */

#include "SwitchCyclicAcyclicVisitables.h"
#include "NonVisitable.h"

#include "SwitchCyclicAcyclicVisitors.h"
#include "SwitchCyclicAcyclicRepository.h"
#include "DemoRunVisitor.h"

#include <iostream>
#include <memory>
#include <vector>

namespace CyclicAcyclicRepository{

using Visitable = Repository::Visitable;
using Visitor = Repository::Visitor;

using SharedPointer = std::shared_ptr<Visitable>;
using Visitables = std::vector<SharedPointer>;

template<class Adaptee>
using AdapterReference = Repository::AdapterByReference<Adaptee>;
}

using namespace CyclicAcyclicRepository;
using namespace std;

void demoSwitchCyclicAcyclic(){
	cout << "================================" << endl;
	std::cout << "==== demoSwitchCyclicAcyclic() ====" << std::endl;
	Visitables visitables;

	DemoVisitor13 visitor13;
	DemoVisitor23 visitor23;
	NonVisitable nv;

	visitables.push_back(SharedPointer(new E1));
	visitables.push_back(SharedPointer(new E2));
	visitables.push_back(SharedPointer(new E3));
	visitables.push_back(SharedPointer(new AdapterReference<NonVisitable>(nv)));

	demoRunVisitor(visitor13, visitables);
	demoRunVisitor(visitor23, visitables);


	std::cout << "==== end demoSwitchCyclicAcyclic() ====" << std::endl;
}
