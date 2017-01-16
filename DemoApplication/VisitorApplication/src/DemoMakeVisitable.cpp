/*
 * DemoMakeVisitable.cpp
 *
 *  Created on: 16.01.2017
 *      Author: Gerd
 */


#include "DemoRunVisitor.h"

#include "NonVisitable.h"
#include "NonVisitableWithAccessor.h"

#include "MakeVisitableRepository.h"
#include "MakeVisitables.h"
#include "MakeVisitableVisitors.h"

#include <memory>
#include <vector>

#include <iostream>

namespace MakeVisitable{

using Visitable = std::unique_ptr<Repository::Visitable>;
//using Visitable = std::shared_ptr<Repository::Visitable>;
using Visitables = std::vector<Visitable>;


}

using namespace MakeVisitable;
using namespace std;

void demoMakeVisitable(){
	cout << "================================" << endl;
	std::cout << "==== demoMakeVisitable() ====" << std::endl;
	Visitables visitables;

	NonVisitable nv;
	auto pU = std::make_unique<NonVisitable>();
	auto pS = std::make_shared<int>(42);

	DemoVisitor visitor;

	// by Reference
	visitables.push_back(Factory::makeVisitable(nv));
	// by Value
	visitables.push_back(Factory::makeVisitable(NonVisitable()));
	visitables.push_back(Factory::makeVisitable(3.14));
	// by unique_ptr
	visitables.push_back(Factory::makeVisitable(std::move(pU) ));
	visitables.push_back(Factory::makeVisitable(std::make_unique<NonVisitable>() ));
	// by weak_ptr
	visitables.push_back(Factory::makeVisitable(pS));


	demoRunVisitor(visitor, visitables);

}
