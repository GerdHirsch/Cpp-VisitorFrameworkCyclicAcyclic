/*
 * MyVisitableImplAcyclic.h
 *
 *  Created on: 11.11.2016
 *      Author: Gerd
 */

#ifndef MYVISITABLEIMPLACYCLIC_H_
#define MYVISITABLEIMPLACYCLIC_H_

#include <iostream>

#include <Visitor/Acyclic/Visitor.h>
#include <Visitor/DefaultLoggingPolicy.h>
#include <Visitor/Acyclic/VisitableAdapterAcyclic.h>

class Element_2;
class NonVisitable;


namespace MyRepositoryAcyclic{

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
//using VisitableAdapter =
//		VisitorAcyclic::VisitableAdapter<Adaptee, StoragePolicy, AdapterLoggingPolicy>;



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
