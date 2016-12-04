/*
 * VisitorImplementation.h
 *
 *  Created on: 29.05.2016
 *      Author: Gerd
 */

#ifndef TYPEFUNCTIONS_H_
#define TYPEFUNCTIONS_H_

#include "VisitorAcyclic.h"
#include "MetaFunctions.h"

struct EmptyAccessor{
	virtual std::string toString() const { return "EmptyAccessor";}
};
/*
 * Adapter erzeugt einen Visitor für ein Element
 * so dass ein ConcreteVisitor davon erben kann
 * und über den Accessor, wenn vorhanden,
 * auf die entsprechenden Member in dem jeweiligen
 * besuchten Visitable zugreifen kann
 */
template<class ToVisit, class Accessor_ = EmptyAccessor>
class VisitorInterface{
public:
	std::string toString(){ return "VisitorInterface";}

	void print(){ std::cout << "VisitorInterface" << std::endl; }
	using ConcreteVisitable = ToVisit;
	using Accessor = Accessor_;
	using this_type = VisitorInterface<ToVisit, Accessor>;
	using type = ElementVisitor<this_type>;
};

template<class T, class = void>
struct hasVisitor{
	enum {value = false};
	using type = void;
};
template<class T>
struct hasVisitor<T, typename void_type<typename T::Visitor>::type>{
	enum {value = true};
	using type = typename T::Visitor;
};

template<class T, class = void>
struct hasAccessor{
	enum {value = false};
	using type = void;
};
template<class T>
struct hasAccessor<T, typename void_type<typename T::Accessor>::type>{
	enum {value = true};
	using type = typename T::Accessor;
};
//---------------------------------------------------------------------
template<class ToVisit, class =
								IF<	hasVisitor<ToVisit>::value,
									typename hasVisitor<ToVisit>::type,
								IF<	hasAccessor<ToVisit>::value,
									typename hasAccessor<ToVisit>::type,
									EmptyAccessor>
								>
		>
struct getVisitorType{
	// no Visitor and no Accessor in ToVisit available
	using type = typename VisitorInterface<ToVisit>::type;
};
template<class ToVisit>
struct getVisitorType<ToVisit, typename hasVisitor<ToVisit>::type>{
	// ToVisit defines its Visitor
	using type = typename hasVisitor<ToVisit>::type;
};
template<class ToVisit>
struct getVisitorType<ToVisit, typename hasAccessor<ToVisit>::type>{
	// ToVisit defines only an Accessor
	using type = typename VisitorInterface<ToVisit, typename ToVisit::Accessor>::type;
};

template<typename ToVisit>
using getVisitor = typename getVisitorType<ToVisit>::type;
template<typename ToVisit>
using implementsVisitor = typename getVisitorType<ToVisit>::type;

#endif /* TYPEFUNCTIONS_H_ */
