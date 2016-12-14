/*
 * Repository.h
 *
 *  Created on: 05.12.2016
 *      Author: Gerd
 */

#ifndef VISITOR_CYCLIC_REPOSITORY_H_
#define VISITOR_CYCLIC_REPOSITORY_H_

#include "Visitor.h"

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

	template<class ConcreteVisitable>
	using VisitableImpl =
			Cyclic::VisitableImpl<ConcreteVisitable, VisitorBase, LoggingPolicy>;

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
};


template<class LoggingPolicy, class BaseKind_, class ...Visitables>
struct Repository<LoggingPolicy, BaseKind_, VisitorFramework::Typelist<Visitables...>>
// delegates to primary
: Repository<LoggingPolicy, BaseKind_, Visitables...>{};

}} // end namespace


#endif /* VISITOR_CYCLIC_REPOSITORY_H_ */
