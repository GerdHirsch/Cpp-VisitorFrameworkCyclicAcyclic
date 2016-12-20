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

using Visitable = std::shared_ptr<Repository::Visitable>;
using Visitables = std::vector<Visitable>;

template<class Adaptee>
using AdapterReference = Repository::AdapterByReference<Adaptee>;
template<class Adaptee>
using AdapterWeak = Repository::AdapterByWeakpointer<Adaptee>;
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

	{
		auto p = std::make_shared<NonVisitable>();
		visitables.push_back(Visitable(new AdapterWeak<NonVisitable>(p)));
	}
	visitables.push_back(Visitable(new E1));
	visitables.push_back(Visitable(new E2));
	visitables.push_back(Visitable(new E3));
	visitables.push_back(Visitable(new AdapterReference<NonVisitable>(nv)));

	demoRunVisitor(visitor13, visitables);
	demoRunVisitor(visitor23, visitables);


	std::cout << "==== end demoCyclicRepository() ====" << std::endl;
}
