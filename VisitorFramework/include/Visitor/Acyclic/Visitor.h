/*
 * AcyclicVisitor.h
 *
 *  Created on: 10.11.2016
 *      Author: Gerd
 */

#ifndef VISITORACYCLIC_H_
#define VISITORACYCLIC_H_

#include <string>
#include <typeinfo>

#include "ElementVisitor.h"
#include "../TypeFunctions.h"

namespace VisitorFramework{

namespace Acyclic{
//=================================================================
// Visitors
//=================================================================
struct Visitor{
	virtual ~Visitor(){}
	virtual std::string toString() const{
		return typeid(*this).name();
	}
};
//---------------------------------------------------------------------
/**
 *  DefaultVisit uses LoggingPolicy as default Implementation for visit(..)
 */
template<class BaseType, class ToVisit>
struct DefaultVisit : implementsVisitor<ToVisit>{

	virtual void visit(ToVisit& v){
		static_cast<BaseType*>(this)->logNotVisited(v, static_cast<BaseType&>(*this));
//		static_cast<BaseType*>(this)->logNotVisited(v, dynamic_cast<Acyclic::Visitor&>(*this));
//		LoggingPolicy::logNotVisited(v, dynamic_cast<Acyclic::Visitor&>(*this));
	}
};
//---------------------------------------------------------------------
template<class LoggingPolicy, class... T>
class InheritFromDefault :
		public LoggingPolicy,
		public Visitor,
		public DefaultVisit< InheritFromDefault<LoggingPolicy, T...>, T>...
{};

template<class... T>
class InheritFromAbstract :
		public Visitor,
		public implementsVisitor<T>...
{};
//---------------------------------------------------------------------
template<class LoggingPolicy_, class = BaseKind::Abstract>
struct SwitchBaseKind{
	template<class ...Visitables>
	using implementsVisitor = Acyclic::InheritFromAbstract<Visitables...>;
};
template<class LoggingPolicy_>
struct SwitchBaseKind<LoggingPolicy_, BaseKind::Default>{
	template<class ...Visitables>
	using implementsVisitor = Acyclic::InheritFromDefault<LoggingPolicy_, Visitables...>;
};
//---------------------------------------------------------------------

}} // end namespace



#endif /* VISITORACYCLIC_H_ */
