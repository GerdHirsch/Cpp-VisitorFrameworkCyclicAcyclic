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
	void accept(VisitorBase& mv){
		std::cout << This()->toString() <<"::accept: " << mv.toString() << std::endl;
		mv.visit(*(This()->getVisitable()) );
	}
	// Muss überschrieben werden wenn ConcreteVisitable und
	// VisitableImplementation nicht übereinstimmen
	ConcreteVisitable* getVisitable() {
		return static_cast<ConcreteVisitable*>(this);
	}
	ConcreteVisitable const* getVisitable() const {
		return static_cast<ConcreteVisitable*>(this);
	}

	VisitableImplementation* This(){
		return static_cast<VisitableImplementation*>(this);
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

	VisitableAdapter(StorageType element): StoragePolicy(element){}

	ReturnType getVisitable() { return this->get(); }
	ReturnType getVisitable()const { return this->get(); }

	std::string toString() const {
		std::string message("CyclicAdapter::");
		message += this->getVisitable()->toString();
		return message;
	}
};

}




#endif /* VISITORCYCLIC_H_ */
