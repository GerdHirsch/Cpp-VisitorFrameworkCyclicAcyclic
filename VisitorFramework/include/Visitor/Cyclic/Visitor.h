/*
 * VisitorCyclic.h
 *
 *  Created on: 10.11.2016
 *      Author: Gerd
 */

#ifndef VISITORCYCLIC_H_
#define VISITORCYCLIC_H_

#include "../StoragePolicies.h"
#include "../BaseKind.h"
#include "../Typelist.h"
#include "../TypeFunctions.h"

#include <iostream>
namespace VisitorFramework{

namespace Cyclic {
//---------------------------------------------------------------------
template<class VisitorBase>
class Visitable
{
public:
    virtual ~Visitable(){};
	virtual void accept(VisitorBase& visitor) = 0;
	virtual std::string toString() const = 0;
};
//---------------------------------------------------------------------
/**
 * Baseclass for all Visitables:
 * usage: MyVisitable : VisitableImpl<MyVisitable, ...>{...}
 * is used in Repository
 */
template
	<
		class ConcreteVisitable,
		class VisitorBase,
		class LoggingPolicy,
		class VisitableImplementation = ConcreteVisitable
	>
struct VisitableImpl : Visitable<VisitorBase>, LoggingPolicy {
	typedef Visitable<VisitorBase> base_type;

	void accept(VisitorBase& visitor){
		this->logAccepted(*this, visitor);
		visitor.visit(*(This()->getVisitable()) );
	}
protected:
	// Muss überschrieben werden wenn ConcreteVisitable und
	// VisitableImplementation nicht übereinstimmen (siehe Adapter)
	ConcreteVisitable* getVisitable() {
		return static_cast<ConcreteVisitable*>(this);
	}
	ConcreteVisitable const* getVisitable() const {
		return static_cast<ConcreteVisitable const*>(this);
	}

	VisitableImplementation* This(){
		return static_cast<VisitableImplementation*>(this);
	}
	VisitableImplementation const* This() const {
		return static_cast<VisitableImplementation const*>(this);
	}
};
//---------------------------------------------------------------------
/**
 * VisitableAdapter to adapt NonVisitable Types
 * StoragePolicy from StoragePolicies.h:
 * StorageByReference, StorageByWeakPointer
 */
template
	<
		class Adaptee,
		class StoragePolicy,
		class LoggingPolicy,
		class VisitorBase
	>
struct VisitableAdapter :
	VisitableImpl<
		Adaptee,
		VisitorBase,
		LoggingPolicy,
		VisitableAdapter<Adaptee, StoragePolicy, LoggingPolicy, VisitorBase>>,
	StoragePolicy
{
	using StorageType = typename StoragePolicy::StorageType;
	using ReturnType = typename StoragePolicy::ReturnType;
	using ConstReturnType = typename StoragePolicy::ConstReturnType;

	VisitableAdapter(StorageType element): StoragePolicy(element){}

	ReturnType getVisitable() { return this->get(); }
	ConstReturnType getVisitable() const { return this->get(); }

	std::string toString() const {
		std::string message("CyclicAdapter::");
		message += this->getVisitable()->toString();
		return message;
	}
};
//---------------------------------------------------------------------
/**
 * infrastructure to Create the Baseclass of a Cyclic Visitor
 * class A; class B; class C;
 */
template<class LoggingPolicy, class ToVisit, class... Rest>
struct InheritFromDefault
	:
//	protected getAccessor<ToVisit>,
	public InheritFromDefault<LoggingPolicy, Rest...>
{
public:
	virtual void visit(ToVisit& visitable){
//		LoggingPolicy::logNotVisited(visitable, *this);
		this->logNotVisited(visitable, *this);
	}

	using InheritFromDefault<LoggingPolicy, Rest...>::visit;
};
template<class LoggingPolicy, class ToVisit>
struct InheritFromDefault<LoggingPolicy, ToVisit>
	:
//	protected getAccessor<ToVisit>,
	public LoggingPolicy
{
public:
	virtual void visit(ToVisit& visitable){
//		LoggingPolicy::logNotVisited(visitable, *this);
		this->logNotVisited(visitable, *this);
	}

	virtual std::string toString() const = 0;
};
//---------------------------------------------------------------------
template<class ToVisit, class... Rest>
struct InheritFromAbstract
	:
//	protected getAccessor<ToVisit>,
	public InheritFromAbstract<Rest...>{
public:
	virtual void visit(ToVisit& v) = 0;

	using InheritFromAbstract<Rest...>::visit;
};
template<class ToVisit>
struct InheritFromAbstract<ToVisit>
//	: protected getAccessor<ToVisit>
{
public:
	virtual void visit(ToVisit& v) = 0;

	virtual std::string toString() const = 0;
};
//---------------------------------------------------------------------
/**
 * infrastructure to Create the Baseclass of an Cyclic Visitor
 * class A; class B; class C;
 * usage: using VisitorBase = visitsDefault<A, B, C>;
 */
template<class LogginPolicy, class ToVisit, class...Rest>
using visitsDefault = InheritFromDefault<LogginPolicy, ToVisit, Rest...>;
template<class ToVisit, class...Rest>
using visitsAbstract = InheritFromAbstract<ToVisit, Rest...>;
//---------------------------------------------------------------------

template<class LoggingPolicy_, class = BaseKind::Abstract>
struct VisitorBase{
	template<class ...Visitables>
	using implementsVisitor = Cyclic::InheritFromAbstract<Visitables...>;
};
template<class LoggingPolicy_>
struct VisitorBase<LoggingPolicy_, BaseKind::Default>{
	template<class ...Visitables>
	using implementsVisitor = Cyclic::InheritFromDefault<LoggingPolicy_, Visitables...>;
};

}} // end namespace VisitorCyclic


#endif /* VISITORCYCLIC_H_ */
