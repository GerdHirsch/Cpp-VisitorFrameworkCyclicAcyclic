/*
 * MyVisitableImplCyclic.h
 *
 *  Created on: 11.11.2016
 *      Author: Gerd
 */

#ifndef MYVISITABLEIMPLCYCLIC_H_
#define MYVISITABLEIMPLCYCLIC_H_

#include "MyVisitorCyclicBase.h"

#include <include/VisitorCyclic.h>
#include <include/StoragePolicies.h>

#include <iostream>

namespace MyRepositoryCyclic{
// ab C++11
template
	<
	class ConcreteVisitable,
	class VisitableImplementation = ConcreteVisitable
	>
using VisitableImpl = VisitorCyclic::VisitableImpl<ConcreteVisitable, MyVisitorBase>;


template
	<class Adaptee,
	class StoragePolicy = StorageByReference<Adaptee>
	>
using VisitableAdapter =
		VisitorCyclic::VisitableAdapter<Adaptee, StoragePolicy, MyVisitorBase>;


// bis C++11
template<class ConcreteVisitable, class VisitableImplementation = ConcreteVisitable>
class Repository{
public:
	typedef VisitorCyclic::VisitableImpl<ConcreteVisitable, MyVisitorBase> VisitableImpl;
};

}

#endif /* MYVISITABLEIMPLCYCLIC_H_ */
