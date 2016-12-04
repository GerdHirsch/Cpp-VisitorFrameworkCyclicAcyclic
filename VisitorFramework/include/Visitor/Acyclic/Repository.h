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
#include "../MakeTypelist.h"

namespace VisitorFramework{
namespace Acyclic{

template<class LoggingPolicy, class BaseKind_, class ...Visitables>
struct Repository{

	using VisitorBase = Acyclic::VisitorBase<Visitables...>;

	using Visitable = Acyclic::Visitable;

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
struct Repository<LoggingPolicy, BaseKind_, VisitorFramework::MakeTypelist<Visitables...>>
// delegates
: Repository<LoggingPolicy, BaseKind_, Visitables...>{};

}} // end namespace


#endif /* VISITOR_ACYCLIC_REPOSITORY_H_ */
