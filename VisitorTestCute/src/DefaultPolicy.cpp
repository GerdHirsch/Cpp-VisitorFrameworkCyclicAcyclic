/*
 * DefaultPolicy.cpp
 *
 *  Created on: 09.01.2017
 *      Author: Gerd
 */
#include "../Mocks/DefaultPolicy.h"

namespace VisitorTestMock{

bool MockLoggingPolicy::notAccepted = false;
bool MockLoggingPolicy::accepted = false;
bool MockLoggingPolicy::notVisited = false;
bool MockLoggingPolicy::invalidVisitable = false;

}

