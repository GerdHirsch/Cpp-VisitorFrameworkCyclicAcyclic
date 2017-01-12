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

	using this_type = VisitableFactory<Repository>;

	template<class ToVisit>
	using AdapterRef = typename Repository::template AdapterByReference<ToVisit>;
	template<class ToVisit>
	using AdapterVal = typename Repository::template AdapterByValue<ToVisit>;
	template<class ToVisit>
	using AdapterWeak = typename Repository::template AdapterByWeakpointer<ToVisit>;

public:
	using ReturnType = std::shared_ptr<typename Repository::Visitable>;

	template<class ToVisit>
	static ReturnType makeVisitable(ToVisit& toVisit){
		return std::make_shared<AdapterRef<ToVisit>>(toVisit);
//		ReturnType retVal(new AdapterRef<ToVisit>(toVisit));
//		return retVal;
	}
	template<class ToVisit>
	static ReturnType makeVisitable(ToVisit&& toVisit){
//		std::cout << "makeVisitable(ToVisit&& toVisit)" << std::endl;
//		return std::make_shared<AdapterVal<ToVisit>>(std::move(toVisit));
		return std::make_shared<AdapterVal<ToVisit>>(std::forward<ToVisit>(toVisit));
//		return std::make_shared<AdapterVal<ToVisit>>(toVisit);
	}
	template<class ToVisit>
	static ReturnType makeVisitable(std::shared_ptr<ToVisit> toVisit){
		return std::make_shared<AdapterWeak>(toVisit);
	}
};

} // end namespace VisitorFramework

#endif /* VISITOR_VISITABLEFACTORY_H_ */
