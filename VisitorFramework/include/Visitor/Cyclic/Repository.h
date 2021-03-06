/*
 * Repository.h
 *
 *  Created on: 05.12.2016
 *      Author: Gerd
 */

#ifndef VISITOR_CYCLIC_REPOSITORY_H_
#define VISITOR_CYCLIC_REPOSITORY_H_

#include "Visitor.h"
#include "Visitable.h"
#include "VisitableAdapter.h"
#include "../StoragePolicies.h"
#include "../Typelist.h"



namespace VisitorFramework{
namespace Cyclic{

template<class LoggingPolicy, class BaseKind_, class ...Visitables>
struct Repository{

	//=================================================================
	// Visitors
	//=================================================================
	using Visitor =
			typename Cyclic::SwitchBaseKind<LoggingPolicy, BaseKind_>::template
			implementsVisitor<Visitables...>;

	using VisitorBase = Visitor;

	/**
	 * Interface compatibility with Acyclic Repository
	 */
//	template<class ...ToVisit>
//	using visits = VisitorBase;
	template<class ...ToVisit>
	struct visits : VisitorBase{};

	template<class ...ToVisit>
	struct visits<VisitorFramework::Typelist<ToVisit...>>
	// delegates to primary DRY Principle
	: visits<ToVisit...>{};

	//=================================================================
	// Visitables
	//=================================================================
	using Visitable = Cyclic::Visitable<VisitorBase>;

	//TODO introduce ConcreteVisitableBase as parameter base = Visitable
	template<class ConcreteVisitable, class BaseType = Visitable>
	using VisitableImpl =
			Cyclic::VisitableImpl<
				ConcreteVisitable,
				VisitorBase,
				LoggingPolicy,
				BaseType,
				ConcreteVisitable>;

	//=================================================================
	// VisitableAdapters
	//=================================================================
	template<class Adaptee, class StoragePolicy>
	using VisitableAdapter =
			Cyclic::VisitableAdapter<Adaptee, StoragePolicy, LoggingPolicy, VisitorBase>;

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

// Convenience Interface Specialization for Typelist
template<class LoggingPolicy, class BaseKind_, class ...Visitables>
struct Repository<LoggingPolicy, BaseKind_, VisitorFramework::Typelist<Visitables...>>
// delegates to primary
: Repository<LoggingPolicy, BaseKind_, Visitables...>{};

}} // end namespace


#endif /* VISITOR_CYCLIC_REPOSITORY_H_ */
