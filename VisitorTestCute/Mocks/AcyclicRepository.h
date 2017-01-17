/*
 * AcyclicRepository.h
 *
 *  Created on: 05.12.2016
 *      Author: Gerd
 */

#ifndef ACYCLICREPOSITORY_H_
#define ACYCLICREPOSITORY_H_


#include "DefaultPolicy.h"

#include <visitor/DefaultPolicy.h>
#include <Visitor/Acyclic/Repository.h>
#include <Visitor/VisitableFactory.h>

class NonVisitable;
class NonVisitableWithAccessor;

namespace AcyclicRepository{

class E1;
class E2;
class E3;

using typelist =
		VisitorFramework::Typelist
		<
		E1, E3,
//		E1, E2, E3,
		NonVisitableWithAccessor
		>;

using Repository = VisitorFramework::Acyclic::Repository
		<
		VisitorTestMock::MockLoggingPolicy,
		BaseKind::Default,
		typelist
		>;

using AbstractRepository = VisitorFramework::Acyclic::Repository
		<
		VisitorFramework::EmptyLoggingPolicy,
		BaseKind::Abstract,
		typelist
		>;
using Factory = VisitorFramework::VisitableFactory<Repository>;

}




#endif /* ACYCLICREPOSITORY_H_ */
