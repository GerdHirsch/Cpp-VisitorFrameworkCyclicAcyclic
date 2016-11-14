/*
 * DemoRunVisitor.h
 *
 *  Created on: 14.11.2016
 *      Author: Gerd
 */

#ifndef DEMORUNVISITOR_H_
#define DEMORUNVISITOR_H_

#include <iostream>
#include <algorithm>

template<class Visitor, class Visitables>
inline
void demoVisitor(Visitor& visitor, Visitables& visitables){
	std::cout << std::endl << "==== " << visitor.toString() << " ====" << std::endl;
	std::for_each
	(	visitables.begin(),
		visitables.end(),
		[&visitor](auto& visitable){
			std::cout << "---" << std::endl;
			visitable->accept(visitor);
		}
	);

	std::cout << std::endl << "==== " << visitor.toString() << " ====" << std::endl;
}



#endif /* DEMORUNVISITOR_H_ */
