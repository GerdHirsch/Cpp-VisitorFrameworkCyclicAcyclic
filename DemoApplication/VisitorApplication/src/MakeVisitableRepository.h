/*
 * MakeVisitableRepository.h
 *
 *  Created on: 16.01.2017
 *      Author: Gerd
 */

#ifndef MAKEVISITABLEREPOSITORY_H_
#define MAKEVISITABLEREPOSITORY_H_

#include <Visitor/DefaultPolicy.h>
#include <Visitor/VisitableFactory.h>
#include <Visitor/Cyclic/Repository.h>
#include <Visitor/Acyclic/Repository.h>

class NonVisitable;
class NonVisitableWithAccessor;

namespace MakeVisitable{
class E1;
class E2;
class E3;


using typelist =
		VisitorFramework::Typelist
		< E1, E2, E3
		, NonVisitable, NonVisitableWithAccessor
		, int, double
		>;
//CAR = CyclicAcyclicRepository
//namespace CAR = VisitorFramework::Cyclic;
namespace CAR = VisitorFramework::Acyclic;

using Repository = CAR::Repository
		<
//		VisitorFramework::EmptyLoggingPolicy,
		VisitorFramework::StdOutLoggingPolicy,
//		BaseKind::Abstract,
		BaseKind::Default,
		typelist
		>;

using Factory = VisitorFramework::VisitableFactory<Repository>;


}



#endif /* MAKEVISITABLEREPOSITORY_H_ */
