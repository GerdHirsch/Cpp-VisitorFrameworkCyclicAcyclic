/*
 * Repository.h
 *
 *  Created on: 04.12.2016
 *      Author: Gerd
 */

#ifndef VISITOR_ACYCLIC_REPOSITORY_H_
#define VISITOR_ACYCLIC_REPOSITORY_H_

#include "Visitable.h"
#include "Visitor.h"

#include "../Typelist.h"
#include "../TypeFunctions.h"
#include "VisitableAdapter.h"

namespace VisitorFramework{
namespace Acyclic{

template<class LoggingPolicy, class BaseKind_, class ...Visitables>
struct Repository{

	//=================================================================
	// Visitors
	//=================================================================
	using Visitor = Acyclic::Visitor;

	using VisitorBase = typename Acyclic::SwitchBaseKind<LoggingPolicy, BaseKind_>::template
			implementsVisitor<Visitables...>;

//	template<class ...ToVisit>
//	using visits = typename Acyclic::VisitorBase<LoggingPolicy, BaseKind_>::template
//			implementsVisitor<ToVisit...>;

	template<class ...ToVisit>
	struct visits
		: Acyclic::SwitchBaseKind<LoggingPolicy, BaseKind_>::template
		  implementsVisitor<ToVisit...>
	{};
	template<class ...ToVisit>
	struct visits<VisitorFramework::Typelist<ToVisit...>>
	// delegates
	: visits<ToVisit...>{};

	//=================================================================
	// Visitables
	//=================================================================
	using Visitable = Acyclic::Visitable;
	//TODO introduce ConcreteVisitableBase as parameter base = Visitable
	template<class ConcreteVisitable, class BaseType = Visitable>
	using VisitableImpl =
			Acyclic::VisitableImpl<
				ConcreteVisitable,
				LoggingPolicy,
				BaseType,
				ConcreteVisitable
				>;

	//=================================================================
	// VisitableAdapters
	//=================================================================
	template<class Adaptee, class StoragePolicy>
	using VisitableAdapter =
			Acyclic::VisitableAdapter<Adaptee, StoragePolicy, LoggingPolicy>;

	// Convenience Interfaces
	template<class Adaptee>
	using AdapterByWeakpointer =
			VisitableAdapter<Adaptee, StorageByWeakpointer<Adaptee>>;
	template<class Adaptee>
	using AdapterByReference =
			VisitableAdapter<Adaptee, StorageByReference<Adaptee>>;
	template<class Adaptee>
	using AdapterByValue =
			VisitableAdapter<Adaptee, StorageByValue<Adaptee>>;
	template<class Adaptee>
	using AdapterByUniquepointer=
			VisitableAdapter<Adaptee, StorageByUniquepointer<Adaptee>>;
};

// Convenience Interface Spezialization for Typelist
template<class LoggingPolicy, class BaseKind_, class ...Visitables>
struct Repository<LoggingPolicy, BaseKind_, VisitorFramework::Typelist<Visitables...>>
// delegates
: Repository<LoggingPolicy, BaseKind_, Visitables...>{};

}} // end namespace


#endif /* VISITOR_ACYCLIC_REPOSITORY_H_ */
