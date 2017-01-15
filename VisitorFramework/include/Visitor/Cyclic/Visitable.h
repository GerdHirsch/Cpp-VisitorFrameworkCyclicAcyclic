/*
 * Visitable.h
 *
 *  Created on: 19.12.2016
 *      Author: Gerd
 */

#ifndef VISITOR_CYCLIC_VISITABLE_H_
#define VISITOR_CYCLIC_VISITABLE_H_

namespace VisitorFramework{
namespace Cyclic{
//=================================================================
// Visitables
//=================================================================
template<class VisitorBase>
class Visitable
{
public:
    virtual ~Visitable(){};
	virtual void accept(VisitorBase& visitor) = 0;
	virtual std::string toString() const{
			return typeid(*this).name();
	}
};
//---------------------------------------------------------------------
//=====================================================================
// Inherit only once from LoggingPolicy
template <class BaseType, class VisitorBase, class LoggingPolicy>
class VisitableBase
	: public BaseType
{ // TODO Assert BaseType is derived from Visitable
};
template<class VisitorBase, class LoggingPolicy>
class VisitableBase<Visitable<VisitorBase>, VisitorBase, LoggingPolicy>
	:
	public Visitable<VisitorBase>,
	public LoggingPolicy
{ };
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
		class BaseType = Visitable<VisitorBase>,
		class VisitableImplementation = ConcreteVisitable
	>
struct VisitableImpl : VisitableBase<BaseType, VisitorBase, LoggingPolicy>
//struct VisitableImpl : Visitable<VisitorBase>, LoggingPolicy
{
	typedef Visitable<VisitorBase> base_type;

	void accept(VisitorBase& visitor){
		this->logAccepted(*this, visitor);
		decltype(auto) visitable = This()->getVisitable();

		// visitable kann z.B. shared_ptr<ConcreteVisitable> sein
		// der nicht mehr gültig ist
		if(!visitable){
			this->logInvalidVisitable(*this, visitor);
			return;
		}
		visitor.visit(*visitable );
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
}}

#endif /* VISITOR_CYCLIC_VISITABLE_H_ */
