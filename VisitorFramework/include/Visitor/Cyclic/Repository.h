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
			typename Cyclic::VisitorBase<LoggingPolicy, BaseKind_>::template
			implementsVisitor<Visitables...>;

	using VisitorBase = Visitor;

	template<class ...ToVisit>
	using visits = VisitorBase;

	//=================================================================
	// Visitables
	//=================================================================

	using Visitable = Cyclic::Visitable<VisitorBase>;

	template<class ConcreteVisitable>
	using VisitableImpl =
			Cyclic::VisitableImpl<ConcreteVisitable, VisitorBase, LoggingPolicy>;

	template<class Adaptee, class StoragePolicy>
	using VisitableAdapter =
			Cyclic::VisitableAdapter<Adaptee, StoragePolicy, LoggingPolicy, VisitorBase>;

	// Convenience Interface
	template<class Adaptee>
	using AdapterByWeakpointer = VisitableAdapter<Adaptee, StorageByWeakPointer<Adaptee>>;
	template<class Adaptee>
	using AdapterByReference = VisitableAdapter<Adaptee, StorageByReference<Adaptee>>;
};


template<class LoggingPolicy, class BaseKind_, class ...Visitables>
struct Repository<LoggingPolicy, BaseKind_, VisitorFramework::Typelist<Visitables...>>
// delegates
: Repository<LoggingPolicy, BaseKind_, Visitables...>{};

}} // end namespace


#endif /* VISITOR_CYCLIC_REPOSITORY_H_ */
