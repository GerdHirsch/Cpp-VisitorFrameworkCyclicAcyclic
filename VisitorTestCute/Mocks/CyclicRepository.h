/*
 * CyclicRepository.h
 *
 *  Created on: 05.12.2016
 *      Author: Gerd
 */

#ifndef CYCLICREPOSITORY_H_
#define CYCLICREPOSITORY_H_

#include "DefaultPolicy.h"

#include <visitor/DefaultPolicy.h>
#include <Visitor/Cyclic/Repository.h>
#include <Visitor/VisitableFactory.h>

class NonVisitable;
class NonVisitableWithAccessor;
class NonVisitableWithAccessor2;

namespace CyclicRepository{
class VisitableWithAccessor;
class VisitableWithAccessor2;
class E1;
class E2;
class E3;
class E4;

using typelist =
		VisitorFramework::Typelist
		< E1
		, E3
		, E4
//		, E1, E2, E3
		, NonVisitable
//		, NonVisitableWithAccessor
		>;

using typelistAccessor = VisitorFramework::Typelist
		< NonVisitableWithAccessor
		, NonVisitableWithAccessor2
		, VisitableWithAccessor
		, VisitableWithAccessor2
		>;
using AccessorRepository = VisitorFramework::Cyclic::Repository
		<
		VisitorTestMock::MockLoggingPolicy,
		BaseKind::Default,
		typelistAccessor
		>;

using Repository = VisitorFramework::Cyclic::Repository
		<
		VisitorTestMock::MockLoggingPolicy,
		BaseKind::Default,
		typelist
		>;
using AbstractRepository = VisitorFramework::Cyclic::Repository
		<
		VisitorFramework::EmptyLoggingPolicy,
		BaseKind::Abstract,
		typelist
		>;

using Factory = VisitorFramework::VisitableFactory<Repository>;

}

#endif /* CYCLICREPOSITORY_H_ */
