/*
 * CyclicRepository.h
 *
 *  Created on: 05.12.2016
 *      Author: Gerd
 */

#ifndef CYCLICREPOSITORY_H_
#define CYCLICREPOSITORY_H_

#include "DefaultPolicy.h"
#include <visitor/Typelist.h>
#include <Visitor/Cyclic/Repository.h>
#include <Visitor/Acyclic/Repository.h>

class NonVisitable;

namespace CyclicRepository{
class E1;
class E2;
class E3;

namespace VF = VisitorFramework;
namespace VTM = VisitorTestMock;

using typelist =
		VisitorFramework::Typelist
		<
		E1, E2, E3,
		NonVisitable
		>;

using Repository = VF::Cyclic::Repository
		<
		VTM::MockLoggingPolicy,
//		BaseKind::Abstract,
		BaseKind::Default,
		typelist
		>;
using AbstractRepository = VisitorFramework::Cyclic::Repository
		<
		VisitorFramework::EmptyLoggingPolicy,
		BaseKind::Abstract,
		typelist
		>;


}

#endif /* CYCLICREPOSITORY_H_ */
