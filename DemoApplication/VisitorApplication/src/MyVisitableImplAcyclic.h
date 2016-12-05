/*
 * MyVisitableImplAcyclic.h
 *
 *  Created on: 11.11.2016
 *      Author: Gerd
 */

#ifndef MYVISITABLEIMPLACYCLIC_H_
#define MYVISITABLEIMPLACYCLIC_H_

#include <iostream>
//#include "MyTypeList.h"


#include "Element_1.h"
#include "Element_2.h"
#include "NonVisitable.h"
#include "NonVisitableWithAccessor.h"

#include <Visitor/DefaultLoggingPolicy.h>
#include <Visitor/BaseKind.h>

#include <Visitor/Acyclic/Visitor.h>
#include <Visitor/Acyclic/TypeFunctions.h>
#include <Visitor/Acyclic/Repository.h>
#include <Visitor/MakeTypelist.h>

class Element_2;
class NonVisitable;

class Element_1;
class Element_2;
class NonVisitable;
class NonVisitableWithAccessor;

using typelist = VisitorFramework::MakeTypelist
		<
		Element_1,
		Element_2,
		NonVisitable,
		NonVisitableWithAccessor
		>;

namespace MyRepositoryAcyclic{

namespace VF = VisitorFramework;

using Repo = VF::Acyclic::Repository
		<
		VF::DemoLoggingPolicy,
//		VF::EmptyLoggingPolicy,
		BaseKind::Default,
		typelist
		>;

using MyVisitorBase = Repo::VisitorBase;

using namespace VisitorFramework;
// ab C++11
template
	<
	class ConcreteVisitable,
	class VisitableImplementation = ConcreteVisitable
	>
using VisitableImpl =
		Acyclic::VisitableImpl
		<
			ConcreteVisitable,
			VisitableImplementation,
			VisitorFramework::EmptyLoggingPolicy
		>;

using Visitable = Acyclic::Visitable;

template<class Adaptee, class StoragePolicy>
struct MyAdapter{
	using type =
			Acyclic::VisitableAdapter<Adaptee, StoragePolicy, VisitorFramework::AdapterLoggingPolicy>;
};

template<class StoragePolicy>
struct MyAdapter<NonVisitable, StoragePolicy>{
	using type =
			Acyclic::VisitableAdapter<NonVisitable, StoragePolicy, VisitorFramework::DemoLoggingPolicy>;
};

template
	<class Adaptee,
	class StoragePolicy = StorageByReference<Adaptee>
	>
using VisitableAdapter = typename MyAdapter<Adaptee, StoragePolicy>::type;

//vor C++11
template<class ConcreteVisitable, class VisitableImplementation = ConcreteVisitable>
class Repository{
public:
	typedef Acyclic::VisitableImpl
	<	ConcreteVisitable,
		VisitableImplementation,
		VisitorFramework::DemoLoggingPolicy
	> VisitableImpl;
};
//Spezialisierung z.B. Type spezifisches Logging
template<class VisitableImplementation>
class Repository<Element_2, VisitableImplementation>{
public:
	typedef Acyclic::VisitableImpl
	<	Element_2,
		VisitableImplementation,
		VisitorFramework::ElementLoggingPolicy
	> VisitableImpl;
};

}

#endif /* MYVISITABLEIMPLACYCLIC_H_ */
