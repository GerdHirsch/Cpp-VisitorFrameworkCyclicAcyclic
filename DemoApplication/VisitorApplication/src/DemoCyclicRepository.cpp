/*
 * DemoMyRepository.cpp
 *
 *  Created on: 03.12.2016
 *      Author: Gerd
 */

#include "CyclicVisitables.h"
#include "NonVisitable.h"

#include "CyclicVisitors.h"
#include "CyclicRepository.h"
#include "DemoRunVisitor.h"

#include <iostream>
#include <memory>
#include <vector>

namespace CyclicRepository{

using Visitable = Repository::Visitable;
using Visitor = Repository::Visitor;

using SharedPointer = std::shared_ptr<Visitable>;
using Visitables = std::vector<SharedPointer>;

template<class Adaptee>
using AdapterReference = Repository::AdapterByReference<Adaptee>;
}

using namespace CyclicRepository;
using namespace std;

void demoCyclicRepository(){
	cout << "================================" << endl;
	std::cout << "==== demoCyclicRepository() ====" << std::endl;
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


	std::cout << "==== end demoCyclicRepository() ====" << std::endl;
}
