/*
 * AcyclicVisitor.h
 *
 *  Created on: 10.11.2016
 *      Author: Gerd
 */

#ifndef VISITORACYCLIC_H_
#define VISITORACYCLIC_H_

#include <string>
#include <iostream>

namespace VisitorAcyclic{

struct Visitor{
	virtual ~Visitor(){}
	virtual std::string toString() const = 0;
};

class Visitable
{
public:
    virtual ~Visitable(){};
	virtual void accept(Visitor& visitor) = 0;
};
//=====================================================================
template<
	class ConcreteVisitable_,
	class VisitableImplementation_,
	class LoggingPolicy
	>
struct VisitableImpl : public Visitable, public LoggingPolicy {
	typedef ConcreteVisitable_ ConcreteVisitable;
	typedef ConcreteVisitable_ VisitableImplementation;

	struct Visitor{
		virtual void visit(ConcreteVisitable& d) = 0;
	};
	// liefert this als Pointer auf die Spezialisierung
	VisitableImplementation* This(){
		return static_cast<VisitableImplementation*>(this);
	}
	// Muss überschrieben werden wenn ConcreteVisitable und
	// VisitableImplementation nicht übereinstimmen
	ConcreteVisitable* getVisitable() {
		return static_cast<ConcreteVisitable*>(this);
	}
	ConcreteVisitable const* getVisitable() const {
		return static_cast<ConcreteVisitable*>(this);
	}

	void accept(VisitorAcyclic::Visitor& visitor){
		ConcreteVisitable *visitable = This()->getVisitable();
		Visitor *pV = dynamic_cast<Visitor*>(&visitor);
		if(pV){
			this->logAccepted(*visitable, visitor);
			pV->visit(*visitable);
		}else{
			this->logNotAccepted(*visitable, visitor);
		}
	}
};
}



#endif /* VISITORACYCLIC_H_ */
