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
#include <include/VisitableAdapterAcyclic.h>

class Element_2;
class NonVisitable;


namespace MyRepositoryAcyclic{
// ab C++11
template
	<
	class ConcreteVisitable,
	class VisitableImplementation = ConcreteVisitable
	>
using VisitableImpl =
		VisitorAcyclic::VisitableImpl
		<
			ConcreteVisitable,
			VisitableImplementation,
			EmptyLoggingPolicy
		>;

using Visitable = VisitorAcyclic::Visitable;

template<class Adaptee, class StoragePolicy>
struct MyAdapter{
	using type = VisitorAcyclic::VisitableAdapter<Adaptee, StoragePolicy, AdapterLoggingPolicy>;
};

template<class StoragePolicy>
struct MyAdapter<NonVisitable, StoragePolicy>{
	using type = VisitorAcyclic::VisitableAdapter<NonVisitable, StoragePolicy, DemoLoggingPolicy>;
};

template
	<class Adaptee,
	class StoragePolicy = StorageByReference<Adaptee>
	>
using VisitableAdapter = typename MyAdapter<Adaptee, StoragePolicy>::type;
//using VisitableAdapter =
//		VisitorAcyclic::VisitableAdapter<Adaptee, StoragePolicy, AdapterLoggingPolicy>;



// ab C++03
template<class ConcreteVisitable, class VisitableImplementation = ConcreteVisitable>
class Repository{
public:
	typedef VisitorAcyclic::VisitableImpl
	<	ConcreteVisitable,
		VisitableImplementation,
		DemoLoggingPolicy
	> VisitableImpl;
};
//Spezialisierung z.B. Type spezifisches Logging
template<class VisitableImplementation>
class Repository<Element_2, VisitableImplementation>{
public:
	typedef VisitorAcyclic::VisitableImpl
	<	Element_2,
		VisitableImplementation,
		ElementLoggingPolicy
	> VisitableImpl;
};


}

#endif /* MYVISITABLEIMPLACYCLIC_H_ */
