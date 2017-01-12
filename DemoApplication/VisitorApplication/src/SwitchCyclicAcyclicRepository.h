/*
 * SwitchCyclicAcyclicRepository.h
 *
 *  Created on: 05.12.2016
 *      Author: Gerd
 */

#ifndef SWITCHCYCLICACYCLICREPOSITORY_H_
#define SWITCHCYCLICACYCLICREPOSITORY_H_

#include <Visitor/DefaultPolicy.h>
//#include <visitor/Typelist.h>
//#include <visitor/BaseKind.h>

#include <Visitor/VisitableFactory.h>
#include <Visitor/Cyclic/Repository.h>
#include <Visitor/Acyclic/Repository.h>

class NonVisitable;
class NonVisitableWithAccessor;

namespace CyclicAcyclicRepository{
class E1;
class E2;
class E3;


using typelist =
		VisitorFramework::Typelist
		< E1
		, E2
		, E3
		, NonVisitable
		, NonVisitableWithAccessor
		>;

//CAR = CyclicAcyclicRepository
//namespace CAR = VisitorFramework::Cyclic;
namespace CAR = VisitorFramework::Acyclic;

using Repository = CAR::Repository
		<
//		VisitorFramework::EmptyLoggingPolicy,
		VisitorFramework::StdOutLoggingPolicy,
		BaseKind::Abstract,
//		BaseKind::Default,
		typelist
		>;

using Factory = VisitorFramework::VisitableFactory<Repository>;

}
#endif /* SWITCHCYCLICACYCLICREPOSITORY_H_ */
