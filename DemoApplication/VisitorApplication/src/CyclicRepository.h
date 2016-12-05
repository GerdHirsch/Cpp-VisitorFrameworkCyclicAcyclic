/*
 * CyclicRepository.h
 *
 *  Created on: 05.12.2016
 *      Author: Gerd
 */

#ifndef CYCLICREPOSITORY_H_
#define CYCLICREPOSITORY_H_

#include <Visitor/DefaultLoggingPolicy.h>
#include <visitor/MakeTypelist.h>
#include <Visitor/Cyclic/Visitor.h>

class NonVisitable;

namespace CyclicRepository{
class E1;
class E2;
class E3;

namespace VF = VisitorFramework;

using typelist =
		VisitorFramework::MakeTypelist
		<
		E1, E2, E3,
		NonVisitable
		>;

using Repository = VF::Cyclic::Repository
		<
//		VF::EmptyLoggingPolicy,
		VF::DemoLoggingPolicy,
//		BaseKind::Abstract,
		BaseKind::Default,
		typelist
		>;
}

#endif /* CYCLICREPOSITORY_H_ */
