/*
 * MyRepository.h
 *
 *  Created on: 03.12.2016
 *      Author: Gerd
 */

#ifndef VISITORCYCLICREPOSITORY_H_
#define VISITORCYCLICREPOSITORY_H_

#include <include/VisitorCyclic.h>
#include <include/BaseKind.h>

namespace VisitorCyclic{


template<class ...Types>
struct MakeTypelist;

template<class LoggingPolicy_, class = BaseKind::Abstract>
struct VisitorBase{
	template<class ...Visitables>
	using implementsVisitor = VisitorCyclic::InheritFromAbstract<Visitables...>;
};
template<class LoggingPolicy_>
struct VisitorBase<LoggingPolicy_, BaseKind::Default>{
	template<class ...Visitables>
	using implementsVisitor = VisitorCyclic::InheritFromDefault<LoggingPolicy_, Visitables...>;
};

template<class LoggingPolicy, class BaseKind_, class ...Visitables>
struct Repository{
	using VisitorBase =
			typename VisitorBase<LoggingPolicy, BaseKind_>::template
			implementsVisitor<Visitables...>;

	template<class ConcreteVisitable>
	using Visitable =
			VisitorCyclic::VisitableImpl<ConcreteVisitable, VisitorBase>;
//			VisitorCyclic::VisitableImpl<ConcreteVisitable, VisitorBase, DemoLoggingPolicy>;

	template<class Adaptee, class StoragePolicy>
	using VisitableAdapter =
			VisitorCyclic::VisitableAdapter<Adaptee, StoragePolicy, VisitorBase>;
//			VisitorCyclic::VisitableAdapter<Adaptee, StoragePolicy, DemoLoggingPolicy, VisitorBase>;

	// Convenience Interface
	template<class Adaptee>
	using AdapterByWeakpointer = VisitableAdapter<Adaptee, StorageByWeakPointer<Adaptee>>;
	template<class Adaptee>
	using AdapterByReference = VisitableAdapter<Adaptee, StorageByReference<Adaptee>>;
};

template<class LoggingPolicy, class BaseKind_, class ...Visitables>
struct Repository<LoggingPolicy, BaseKind_, MakeTypelist<Visitables...>>
// delegates
: Repository<LoggingPolicy, BaseKind_, Visitables...>{};

//vertauschte Argumentliste
//template<class LoggingPolicy, class BaseKind_, class ...Visitables>
//struct Repository<MakeTypelist<Visitables...>, LoggingPolicy, BaseKind_>
//: Repository<LoggingPolicy, BaseKind_, Visitables...>{};


// keine duplicate via delegation
//template<class LoggingPolicy, class BaseKind_, class ...Visitables>
//struct Repository<LoggingPolicy, BaseKind_, MakeTypelist<Visitables...>>{
//	using VisitorBase =
//			typename VisitorBase<LoggingPolicy, BaseKind_>::template
//			implementsVisitor<Visitables...>;
//
//	template<class ConcreteVisitable>
//	using Visitable = VisitorCyclic::VisitableImpl<ConcreteVisitable, VisitorBase>;
//};


} // end namespace VisitorCyclic

#endif /* VISITORCYCLICREPOSITORY_H_ */
