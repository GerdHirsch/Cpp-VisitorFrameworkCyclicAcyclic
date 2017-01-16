/*
 * VisitableFactory.h
 *
 *  Created on: 10.01.2017
 *      Author: Gerd
 */

#ifndef VISITOR_VISITABLEFACTORY_H_
#define VISITOR_VISITABLEFACTORY_H_

#include <memory>
#include <iostream>

namespace VisitorFramework{


template<class Repository>
class VisitableFactory{
public:
	using this_type = VisitableFactory<Repository>;

	template<class ToVisit>
	using AdapterRef = typename Repository::template AdapterByReference<ToVisit>;
	template<class ToVisit>
	using AdapterVal = typename Repository::template AdapterByValue<ToVisit>;
	template<class ToVisit>
	using AdapterWeak = typename Repository::template AdapterByWeakpointer<ToVisit>;
	template<class ToVisit>
	using AdapterUnique = typename Repository::template AdapterByUniquepointer<ToVisit>;

public:
	using ReturnType = std::unique_ptr<typename Repository::Visitable>;
//	using ReturnType = std::shared_ptr<typename Repository::Visitable>;

	template<class ToVisit>
	static ReturnType makeVisitable(ToVisit& toVisit){
		return std::make_unique<AdapterRef<ToVisit>>(toVisit);
//		return std::make_shared<AdapterRef<ToVisit>>(toVisit);
	}
	template<class ToVisit>
	static ReturnType makeVisitable(ToVisit&& toVisit){
		return std::make_unique<AdapterVal<ToVisit>>(std::forward<ToVisit>(toVisit));
//		return std::make_shared<AdapterVal<ToVisit>>(std::forward<ToVisit>(toVisit));
	}
	template<class ToVisit>
	static ReturnType makeVisitable(std::shared_ptr<ToVisit> toVisit){
		return std::make_unique<AdapterWeak<ToVisit>>(toVisit);
//		return std::make_shared<AdapterWeak<ToVisit>>(toVisit);
	}
	template<class ToVisit>
	static ReturnType makeVisitable(std::unique_ptr<ToVisit> toVisit){
		return std::make_unique<AdapterUnique<ToVisit>>(std::move(toVisit));
//		return std::make_shared<AdapterUnique<ToVisit>>(std::move(toVisit));
	}
};

} // end namespace VisitorFramework

#endif /* VISITOR_VISITABLEFACTORY_H_ */
