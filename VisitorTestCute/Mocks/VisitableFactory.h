/*
 * VisitableFactory.h
 *
 *  Created on: 10.01.2017
 *      Author: Gerd
 */

#ifndef MOCKS_VISITABLEFACTORY_H_
#define MOCKS_VISITABLEFACTORY_H_

#include "../Mocks/CyclicRepository.h"
#include "../Mocks/AcyclicRepository.h"

#include <Visitor/VisitableFactory.h>

namespace VisitorTestMock{

using CyclicFactory = VisitorFramework::VisitableFactory<CyclicRepository::Repository>;
using AcyclicFactory = VisitorFramework::VisitableFactory<AcyclicRepository::Repository>;

}

#endif /* MOCKS_VISITABLEFACTORY_H_ */
