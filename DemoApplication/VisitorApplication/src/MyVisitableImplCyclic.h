/*
 * MyVisitableImplCyclic.h
 *
 *  Created on: 11.11.2016
 *      Author: Gerd
 */

#ifndef MYVISITABLEIMPLCYCLIC_H_
#define MYVISITABLEIMPLCYCLIC_H_

#include "MyVisitorCyclicBase.h"

#include <Visitor/VisitorCyclic.h>
#include <Visitor/StoragePolicies.h>


#include <iostream>

namespace MyRepositoryCyclic{
// ab C++11
template<class ConcreteVisitable>
using VisitableImpl = Repo::VisitableImpl<ConcreteVisitable>;

template
	<class Adaptee,
	class StoragePolicy = StorageByReference<Adaptee>
	>
using VisitableAdapter = Repo::VisitableAdapter<Adaptee, StoragePolicy>;
}

#endif /* MYVISITABLEIMPLCYCLIC_H_ */
