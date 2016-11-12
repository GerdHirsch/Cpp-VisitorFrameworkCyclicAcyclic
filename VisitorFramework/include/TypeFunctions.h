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
	std::string toString(){ return "EmptyAccessor";}
};
/*
 * Adapter erzeugt einen Visitor für ein Element
 * so dass ein ConcreteVisitor davon erben kann
 * und über den Accessor, wenn vorhanden,
 * auf die entsprechenden Member in dem jeweiligen
 * besuchten Visitable zugreifen kann
 */
template<class ToVisit, class Accessor_ = EmptyAccessor>
class Adapter{
public:
	std::string toString(){ return "VisitableAdapter";}

	void print(){ std::cout << "VisitableAdapter" << std::endl; }
	using ConcreteVisitable = ToVisit;
	using Accessor = Accessor_;
	using this_type = Adapter<ToVisit, Accessor>;
	using Visitor = ElementVisitor<this_type>;
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
	// kein Visitor und Accessor in ToVisit verfügbar
	using type = typename Adapter<ToVisit>::Visitor;
};
template<class ToVisit>
struct getVisitorType<ToVisit, typename hasVisitor<ToVisit>::type>{
	// ToVisit definiert seinen Visitor
	using type = typename hasVisitor<ToVisit>::type;

};
template<class ToVisit>
struct getVisitorType<ToVisit, typename hasAccessor<ToVisit>::type>{
	// ToVisit definiert nur einen Accessor
	using type = typename Adapter<ToVisit, typename ToVisit::Accessor>::Visitor;
};

template<typename ToVisit>
using getVisitor = typename getVisitorType<ToVisit>::type;
template<typename ToVisit>
using implementsVisitor = typename getVisitorType<ToVisit>::type;

#endif /* TYPEFUNCTIONS_H_ */
