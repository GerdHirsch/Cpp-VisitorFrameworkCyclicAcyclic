/*
 * VisitableAdapterStoragePolicy.h
 *
 *  Created on: 28.05.2016
 *      Author: Gerd
 */

#ifndef VISITABLEADAPTERACYCLIC_H_
#define VISITABLEADAPTERACYCLIC_H_

#include "VisitorAcyclic.h"
#include "StoragePolicies.h"
#include "DefaultLoggingPolicy.h"
#include "TypeFunctions.h"

namespace VisitorAcyclic{

template<
	class Adaptee,
	class StoragePolicy = StorageByReference<Adaptee>,
	class LoggingPolicy = DemoLoggingPolicy
		>
class VisitableAdapter :
		public VisitableImpl<
				Adaptee,
				VisitableAdapter<Adaptee, StoragePolicy>,
				LoggingPolicy>,
		public StoragePolicy
{
public:
	using StorageType = typename StoragePolicy::StorageType;
	using ReturnType = typename StoragePolicy::ReturnType;

	using Visitor = getVisitor<Adaptee>;

	VisitableAdapter(StorageType element): StoragePolicy(element){}

	ReturnType getVisitable() { return this->get(); }
	ReturnType getVisitable()const { return this->get(); }

	std::string toString() const {
		std::string message("AcyclicAdapter::");
		message += this->getVisitable()->toString();
		return message;
	}
};
} // namespace VisitorAcyclic
#endif /* VISITABLEADAPTERACYCLIC_H_ */
