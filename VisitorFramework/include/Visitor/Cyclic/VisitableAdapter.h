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
	using StorageType = typename StoragePolicy::StorageType;
	using ReturnType = typename StoragePolicy::ReturnType;
	using ConstReturnType = typename StoragePolicy::ConstReturnType;

	VisitableAdapter(StorageType element): StoragePolicy(element){}

	ReturnType getVisitable() { return this->get(); }
	ConstReturnType getVisitable() const { return this->get(); }

	std::string toString() const {
		std::string message("CyclicAdapter::");
		//TODO check has_toString_member
//		message += this->getVisitable()->toString();
		message += VisitorFramework::toString(*this->getVisitable());
		return message;
	}
};

}}

#endif /* VISITOR_CYCLIC_VISITABLEADAPTER_H_ */
