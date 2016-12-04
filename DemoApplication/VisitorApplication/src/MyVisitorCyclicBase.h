/*
 * MyVisitorBase.h
 *
 *  Created on: 11.11.2016
 *      Author: Gerd
 */

#ifndef MYVISITORCYCLICBASE_H_
#define MYVISITORCYCLICBASE_H_

//Definitions
#include "NonVisitable.h"
//ForwardDeclarations
class NonVisitableWithAccessor;
class Element_1; // Element_1 cannot be included because of recursive Definitions
class Element_2;
class Element_3;

#include <iostream>
#include <Visitor/VisitorCyclic.h>
#include <Visitor/DefaultLoggingPolicy.h>
#include <Visitor/CyclicRepository.h>


namespace MyRepositoryCyclic{

using typelist = Visitor::MakeTypelist
		<
		Element_1,
		Element_2,
		Element_3,
		NonVisitable,
		NonVisitableWithAccessor
		>;

using Repo = VisitorCyclic::Repository
		<
			AdapterLoggingPolicy,
//			DemoLoggingPolicy,
			BaseKind::Default,
			typelist
		>;

using Visitable = Repo::Visitable;
using MyVisitorBase = Repo::VisitorBase;

}

#endif /* MYVISITORCYCLICBASE_H_ */
