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

#include "ElementVisitor.h"
#include "TypeFunctions.h"

namespace VisitorFramework{

namespace Acyclic{

struct Visitor{
	virtual ~Visitor(){}
	virtual std::string toString() const = 0;
};


template<class LoggingPolicy, class ToVisit>
struct DefaultVisit : implementsVisitor<ToVisit>{
	// needed for dynamic_cast
	virtual ~DefaultVisit(){}
	void visit(ToVisit& v){
		LoggingPolicy::logNotVisited(v, dynamic_cast<Acyclic::Visitor&>(*this));
	}
};

template<class LoggingPolicy, class... T>
class InheritFromDefault :
		public Visitor,
		public DefaultVisit<LoggingPolicy, T>...
{};

template<class... T>
class InheritFromAbstract :
		public Visitor,
		public Acyclic::implementsVisitor<T>...
{};

template<class LoggingPolicy_, class = BaseKind::Abstract>
struct VisitorBase{
	template<class ...Visitables>
	using implementsVisitor = Acyclic::InheritFromAbstract<Visitables...>;
};
template<class LoggingPolicy_>
struct VisitorBase<LoggingPolicy_, BaseKind::Default>{
	template<class ...Visitables>
	using implementsVisitor = Acyclic::InheritFromDefault<LoggingPolicy_, Visitables...>;
};

class Visitable
{
public:
    virtual ~Visitable(){};
	virtual void accept(Visitor& visitor) = 0;
	virtual std::string toString() const = 0;
};


//=====================================================================

/**
 * VisitableImpl stellt eine allgemeine Implementierung
 * für alle ConcreteVisitables zur Verfügung.
 * Dazu gehört:
 * eine accept(VisitorAcyclic::Visitor&) Methode
 * für alle Visitables -> Implementation Inheritance
 * Wenn die Ausgaben entfernt werden, bleibt eine einfache TemplateMethod
 * (siehe GoF TemplateMethod Pattern) mit folgender Struktur übrig:
 * cast des Visitors auf einen speziellen ElementVisitor
 * wenn das möglich ist v.visit(this)
 * ansonsten log("not accepted")
 *
 * log steht als policy zur Verfügung
 * (see: policy based design)
 *
 * Außerdem definiert VisitableImpl das Interface Visitor
 * für die ConcreteVisitors auf der Basis des template ElementVisitor
 */
template<
	class ConcreteVisitable_,
	class VisitableImplementation_,
	class LoggingPolicy
	>
class VisitableImpl : public Visitable, public LoggingPolicy{

public:
	// Default Accessor für ElementVisitor,
	// kann von einem konkreten Visitable überschrieben werden
	class Accessor{};

	// Parametertyp für visit in ElementVisitor
	using ConcreteVisitable = ConcreteVisitable_;

	// Typ der das Interface Visitable implementiert!
	// Muss von VisitableImpl<..> erben!
	// stellt Infrastruktur für ElementVisitor zur Verfügung:
	// Accessor, ConcreteVisitable
	// kann vom Parameter von visit(..) abweichen (Adapter)
	using VisitableImplementation = VisitableImplementation_;

	// Interface Definition für die konkreten Visitors
	using Visitor = ElementVisitor<VisitableImplementation>;

	// Muss überschrieben werden wenn ConcreteVisitable und
	// VisitableImplementation nicht übereinstimmen
	ConcreteVisitable* getVisitable() {
		return static_cast<ConcreteVisitable*>(this);
	}
	ConcreteVisitable const* getVisitable() const {
		return static_cast<ConcreteVisitable*>(this);
	}

	// liefert this als Pointer auf die Spezialisierung
	VisitableImplementation* This(){
		return static_cast<VisitableImplementation*>(this);
	}
	VisitableImplementation const* This() const{
		return static_cast<VisitableImplementation*>(this);
	}

	void accept(Acyclic::Visitor& visitor){
		using Visitor = typename VisitableImplementation::Visitor;
		Visitor* v = dynamic_cast<Visitor*>(&visitor); //crosscast

//		ConcreteVisitable* visitable = This()->getVisitable();
		decltype(auto) visitable = This()->getVisitable();

		// visitable kann z.B. shared_ptr<ConcreteVisitable> sein
		// der nicht mehr gültig ist
		// TODO: einfach nix machen ist das elegant?
		if(!visitable){
			//this->logInvalidVisitable(*This(), visitor);
			return;
		}

		if(v){
			this->logAccepted(*this, visitor);
//			this->logAccepted(*visitable, visitor);
			v->visit(*visitable);
		} else {
			this->logNotAccepted(*this, visitor);
//			this->logNotAccepted(*visitable, visitor);
		}
	}
};

}} // end namespace



#endif /* VISITORACYCLIC_H_ */
