/*
 * VisitorImplementation.h
 *
 *  Created on: 29.05.2016
 *      Author: Gerd
 */

#ifndef TYPEFUNCTIONS_H_
#define TYPEFUNCTIONS_H_

#include "MetaFunctions.h"
#include "ElementVisitor.h"

#include <string>

namespace VisitorFramework{

struct EmptyAccessor{
//	virtual std::string toString() const { return "EmptyAccessor";}
};
/*
 * VisitorInterface erzeugt einen Visitor für ein Element
 * so dass ein ConcreteVisitor davon erben kann
 * und über den Accessor, wenn vorhanden,
 * auf die entsprechenden Member in dem jeweiligen
 * besuchten Visitable zugreifen kann
 */
template<class ToVisit, class Accessor_ = EmptyAccessor>
class CreateVisitorInterface{
public:
	std::string toString(){ return "VisitorInterface";}

//	void print(){ std::cout << "VisitorInterface" << std::endl; }
	using ConcreteVisitable = ToVisit;
	using Accessor = Accessor_;
	using this_type = CreateVisitorInterface<ToVisit, Accessor>;
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
template<class ToVisit, class = // create Default Type for primary template
								IF<	hasVisitor<ToVisit>::value,
									typename hasVisitor<ToVisit>::type,
								IF<	hasAccessor<ToVisit>::value,
									typename hasAccessor<ToVisit>::type,
									EmptyAccessor>
								>
		>
struct getVisitorType{
	// no Visitor and no Accessor in ToVisit available
	using type = typename CreateVisitorInterface<ToVisit>::type;
};
template<class ToVisit> // Specialization for ToVisit::Visitor SFINAE if not exist
struct getVisitorType<ToVisit, typename hasVisitor<ToVisit>::type>{
	// ToVisit defines its Visitor
	using type = typename hasVisitor<ToVisit>::type;
};
template<class ToVisit> // Specialization for ToVisit::Accessor SFINAE if not exist
struct getVisitorType<ToVisit, typename hasAccessor<ToVisit>::type>{
	// ToVisit defines only an Accessor
	using type = typename CreateVisitorInterface<ToVisit, typename ToVisit::Accessor>::type;
};

//=====================================================================
// For Cyclic Visitors inherit from ToVisit::Accessor or
// from EmptyAccessor
//=====================================================================
template<class ToVisit, class = IF<	hasAccessor<ToVisit>::value,
									typename hasAccessor<ToVisit>::type,
									EmptyAccessor>
		>
struct getAccessorType{
	using type = EmptyAccessor;
};
template<class ToVisit>
struct getAccessorType<ToVisit, typename hasAccessor<ToVisit>::type>{
	// ToVisit defines an Accessor
	using type = typename CreateVisitorInterface<ToVisit, typename ToVisit::Accessor>::type;
};

template<class ToVisit>
using getAccessor = typename getAccessorType<ToVisit>::type;


template<typename ToVisit>
using getVisitor = typename getVisitorType<ToVisit>::type;
template<typename ToVisit>
using implementsVisitor = typename getVisitorType<ToVisit>::type;

//}
} // end namespace

#endif /* TYPEFUNCTIONS_H_ */
