/*
 * Repository.h
 *
 *  Created on: 04.12.2016
 *      Author: Gerd
 */

#ifndef VISITOR_ACYCLIC_REPOSITORY_H_
#define VISITOR_ACYCLIC_REPOSITORY_H_

#include "Visitor.h"
#include "VisitableAdapterAcyclic.h"
#include "../Typelist.h"
#include "TypeFunctions.h"

namespace VisitorFramework{
namespace Acyclic{

template<class LoggingPolicy, class BaseKind_, class ...Visitables>
struct Repository{

	//=================================================================
	// Visitors
	//=================================================================
	using Visitor = Acyclic::Visitor;

	using VisitorBase = typename Acyclic::VisitorBase<LoggingPolicy, BaseKind_>::template
			implementsVisitor<Visitables...>;

	using Visitable = Acyclic::Visitable;

	template<class ToVisit>
	using implementsVisitor = Acyclic::implementsVisitor<ToVisit>;

	template<class ...ToVisit>
	using visits = typename Acyclic::VisitorBase<LoggingPolicy, BaseKind_>::template
			implementsVisitor<ToVisit...>;

	//=================================================================
	// Visitables
	//=================================================================
	template<class ConcreteVisitable>
	using VisitableImpl =
			Acyclic::VisitableImpl<ConcreteVisitable, ConcreteVisitable, LoggingPolicy>;

	template<class Adaptee, class StoragePolicy>
	using VisitableAdapter =
			Acyclic::VisitableAdapter<Adaptee, StoragePolicy, LoggingPolicy>;

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


#endif /* VISITOR_ACYCLIC_REPOSITORY_H_ */