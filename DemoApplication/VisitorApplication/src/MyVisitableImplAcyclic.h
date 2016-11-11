/*
 * MyVisitableImplAcyclic.h
 *
 *  Created on: 11.11.2016
 *      Author: Gerd
 */

#ifndef MYVISITABLEIMPLACYCLIC_H_
#define MYVISITABLEIMPLACYCLIC_H_

#include <iostream>

#include <include/VisitorAcyclic.h>
#include <include/DefaultLoggingPolicy.h>

namespace MyRepositoryAcyclic{
// ab C++11
template
	<
	class ConcreteVisitable,
	class VisitableImplementation = ConcreteVisitable
	>
using Visitable =
		VisitorAcyclic::VisitableImpl
		<
			ConcreteVisitable,
			VisitableImplementation,
			EmptyLoggingPolicy
		>;

// bis C++11
template<class ConcreteVisitable, class VisitableImplementation = ConcreteVisitable>
class Repository{
public:
	typedef VisitorAcyclic::VisitableImpl
	<	ConcreteVisitable,
		VisitableImplementation,
		DemoLoggingPolicy
	> Visitable;
};

}

#endif /* MYVISITABLEIMPLACYCLIC_H_ */
