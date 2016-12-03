/*
 * VisitorCyclic.h
 *
 *  Created on: 10.11.2016
 *      Author: Gerd
 */

#ifndef VISITORCYCLIC_H_
#define VISITORCYCLIC_H_

#include "StoragePolicies.h"

#include <iostream>

namespace VisitorCyclic {

template<class VisitorBase>
class Visitable
{
public:
    virtual ~Visitable(){};
	virtual void accept(VisitorBase& visitor) = 0;
	virtual std::string toString() const = 0;
};

template
	<
		class ConcreteVisitable,
		class VisitorBase,
		class VisitableImplementation = ConcreteVisitable
	>
struct VisitableImpl : Visitable<VisitorBase> {
	typedef Visitable<VisitorBase> base_type;

	void accept(VisitorBase& visitor){
		std::cout << This()->toString() <<"::accept: " << visitor.toString() << std::endl;
		visitor.visit(*(This()->getVisitable()) );
	}
	// Muss überschrieben werden wenn ConcreteVisitable und
	// VisitableImplementation nicht übereinstimmen
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

template
	<
		class Adaptee,
		class StoragePolicy,
		class VisitorBase
	>
struct VisitableAdapter :
	VisitableImpl<
		Adaptee,
		VisitorBase,
		VisitableAdapter<Adaptee, StoragePolicy, VisitorBase>>,
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
 * infrastructure to Create the Baseclass of an Cyclic Visitor
 * class A; class B; class C;
 * usage: using VisitorBase = visitsDefault<A, B, C>;
 */
template<class ToVisit, class... Rest>
struct InheritFromDefault : public InheritFromDefault<Rest...>{
public:
	virtual void visit(ToVisit& visitable){
		std::cout << this->toString() << "::visit(" << typeid(visitable).name() << " &) is not implemented!" << std::endl;;
	}

	using InheritFromDefault<Rest...>::visit;
};
template<class ToVisit>
struct InheritFromDefault<ToVisit>{
public:
	virtual void visit(ToVisit& visitable){
		std::cout << this->toString() << "::visit(" << typeid(visitable).name() << " &) is not implemented!" << std::endl;;
	}

	virtual std::string toString() const = 0;
};
//---------------------------------------------------------------------
template<class ToVisit, class... Rest>
struct InheritFromAbstract : public InheritFromAbstract<Rest...>{
public:
	virtual void visit(ToVisit& v) = 0;

	using InheritFromAbstract<Rest...>::visit;
};
template<class ToVisit>
struct InheritFromAbstract<ToVisit>{
public:
	virtual void visit(ToVisit& v) = 0;

	virtual std::string toString() const = 0;
};
//---------------------------------------------------------------------
template<class ToVisit, class...Rest>
using visitsDefault = InheritFromDefault<ToVisit, Rest...>;
template<class ToVisit, class...Rest>
using visitsAbstract = InheritFromAbstract<ToVisit, Rest...>;

}




#endif /* VISITORCYCLIC_H_ */
