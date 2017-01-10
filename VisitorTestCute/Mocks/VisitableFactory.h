/*
 * VisitableFactory.h
 *
 *  Created on: 10.01.2017
 *      Author: Gerd
 */

#ifndef MOCKS_VISITABLEFACTORY_H_
#define MOCKS_VISITABLEFACTORY_H_

#include "../Mocks/DefaultPolicy.h"

#include "../Mocks/MockVisitor.h"

#include "../Mocks/CyclicVisitables.h"
#include "../Mocks/AcyclicVisitables.h"

#include "../Mocks/CyclicRepository.h"
#include "../Mocks/AcyclicRepository.h"

#include <Visitor/VisitableFactory.h>

namespace VisitorTestMock{
namespace CR = CyclicRepository;
namespace AR = AcyclicRepository;

using CyclicFactory = VisitorFramework::VisitableFactory<CR::Repository>;
using AcyclicFactory = VisitorFramework::VisitableFactory<AR::Repository>;

}

#endif /* MOCKS_VISITABLEFACTORY_H_ */
