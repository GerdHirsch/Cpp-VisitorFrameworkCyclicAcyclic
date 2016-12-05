/*
 * DemoMyAcyclicRepository.cpp
 *
 *  Created on: 04.12.2016
 *      Author: Gerd
 */

#include "AcyclicVisitables.h"
#include "NonVisitable.h"

#include "AcyclicVisitors.h"
#include "AcyclicRepository.h"
#include "DemoRunVisitor.h"

#include <iostream>
#include <memory>
#include <vector>

namespace AcyclicRepository{

using Visitable = Repository::Visitable;
using Visitor = Repository::Visitor;

using SharedPointer = std::shared_ptr<Visitable>;
using Visitables = std::vector<SharedPointer>;

template<class Adaptee>
using AdapterReference = Repository::AdapterByReference<Adaptee>;
}

using namespace AcyclicRepository;
using namespace std;

void demoAcyclicRepository(){
	cout << "================================" << endl;
	std::cout << "==== demoAcyclicRepository() ====" << std::endl;
	Visitables visitables;

	DemoVisitor23 visitor1;
	DemoVisitor13 visitor2;
	NonVisitable nv;

	visitables.push_back(SharedPointer(new E1));
	visitables.push_back(SharedPointer(new E2));
	visitables.push_back(SharedPointer(new E3));
	visitables.push_back(SharedPointer(new AdapterReference<NonVisitable>(nv)));

	demoRunVisitor(visitor1, visitables);
	demoRunVisitor(visitor2, visitables);


	std::cout << "==== end demoAcyclicRepository() ====" << std::endl;
}
