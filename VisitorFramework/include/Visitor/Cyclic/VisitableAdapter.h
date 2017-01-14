/*
 * Adapter.h
 *
 *  Created on: 19.12.2016
 *      Author: Gerd
 */

#ifndef VISITOR_CYCLIC_VISITABLEADAPTER_H_
#define VISITOR_CYCLIC_VISITABLEADAPTER_H_

#include "Visitor.h"
#include "../has_method_toString.h"


namespace VisitorFramework{
namespace Cyclic{
//---------------------------------------------------------------------
/**
 * VisitableAdapter to adapt NonVisitable Types
 * StoragePolicy from StoragePolicies.h:
 * StorageByReference, StorageByWeakPointer
 */
template
	<
		class Adaptee,
		class StoragePolicy,
		class LoggingPolicy,
		class VisitorBase
	>
struct VisitableAdapter :
	VisitableImpl<
		Adaptee,
		VisitorBase,
		LoggingPolicy,
		VisitableAdapter<Adaptee, StoragePolicy, LoggingPolicy, VisitorBase>>,
	StoragePolicy
{
	using LValueReferenceType = typename StoragePolicy::LValueReferenceType;
	using RValueReferenceType = typename StoragePolicy::RValueReferenceType;

	using ReturnType = typename StoragePolicy::ReturnType;
	using ConstReturnType = typename StoragePolicy::ConstReturnType;

	VisitableAdapter(LValueReferenceType element): StoragePolicy(element){}
	VisitableAdapter(RValueReferenceType element): StoragePolicy(std::forward<RValueReferenceType>(element)){}

	ReturnType getVisitable() { return this->get(); }
	ConstReturnType getVisitable() const { return this->get(); }

	std::string toString() const {
		std::string message("CyclicAdapter::");
		//TODO wo gehört die prüfung hin?
		auto visitable = this->getVisitable();
		if(visitable)
			message += VisitorFramework::toString(*this->getVisitable());
		else
			message += typeid(Adaptee).name();
		return message;
	}
};

}}

#endif /* VISITOR_CYCLIC_VISITABLEADAPTER_H_ */
