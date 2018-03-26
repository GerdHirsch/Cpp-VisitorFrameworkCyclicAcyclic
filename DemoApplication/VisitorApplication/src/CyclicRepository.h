/*
 * CyclicRepository.h
 *
 *  Created on: 05.12.2016
 *      Author: Gerd
 */

#ifndef CYCLICREPOSITORY_H_
#define CYCLICREPOSITORY_H_

#include <Visitor/DefaultPolicy.h>
#include <visitor/Typelist.h>
#include <Visitor/Cyclic/Repository.h>
//#include <Visitor/Acyclic/Repository.h>

class NonVisitable;
class NonVisitableWithAccessor;
class NonVisitableWithAccessor2;

namespace CyclicRepository{
class E1;
class E2;
class E3;

namespace VF = VisitorFramework;

using typelist =
		VisitorFramework::Typelist
		< E1
		, E2
		, E3
		, NonVisitableWithAccessor
		, NonVisitable
		, NonVisitableWithAccessor2
		>;

using Repository = VF::Cyclic::Repository
		<
//		VF::EmptyLoggingPolicy,
		VF::StdOutLoggingPolicy,
		BaseKind::Abstract,
//		BaseKind::Default,
		typelist
		>;
}

#endif /* CYCLICREPOSITORY_H_ */
