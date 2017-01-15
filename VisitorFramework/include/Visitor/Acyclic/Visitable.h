/*
 * Visitable.h
 *
 *  Created on: 19.12.2016
 *      Author: Gerd
 */

#ifndef VISITOR_ACYCLIC_VISITABLE_H_
#define VISITOR_ACYCLIC_VISITABLE_H_

#include "ElementVisitor.h"

#include <typeinfo>
#include <string>

namespace VisitorFramework{
namespace Acyclic{
//=================================================================
// Visitor forward declaration
//=================================================================
class Visitor;

//=================================================================
// Visitables
//=================================================================
class Visitable
{
public:
    virtual ~Visitable(){};
	virtual void accept(Visitor& visitor) = 0;
	virtual std::string toString() const{
			return typeid(*this).name();
		}
};
//=====================================================================
// Inherit only once from LoggingPolicy
template <class BaseType, class LoggingPolicy>
class VisitableBase
	: public BaseType
{ // TODO Assert BaseType is derived from Visitable
};
template<class LoggingPolicy>
class VisitableBase<Visitable, LoggingPolicy>
	:
	public Visitable,
	public LoggingPolicy
{ };
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
	class LoggingPolicy,
	class BaseType = Visitable,
	class VisitableImplementation_ = ConcreteVisitable_
	>
class VisitableImpl : public VisitableBase<BaseType, LoggingPolicy>
{

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
		return static_cast<ConcreteVisitable const*>(this);
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
		if(!visitable){
			this->logInvalidVisitable(*this, visitor);
			return;
		}

		if(v){
			this->logAccepted(*this, visitor);
			v->visit(*visitable);
		} else {
			this->logNotAccepted(*this, visitor);
		}
	}
};

}} // end namespace


#endif /* VISITOR_ACYCLIC_VISITABLE_H_ */
