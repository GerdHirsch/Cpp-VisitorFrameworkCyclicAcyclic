/*
 * VisitableFactoryTest.h
 *
 *  Created on: 10.01.2017
 *      Author: Gerd
 */

#ifndef INCLUDE_VISITABLEFACTORYTEST_H_
#define INCLUDE_VISITABLEFACTORYTEST_H_

#include "../Mocks/VisitableFactory.h"

class VisitableFactoryTest{
	using this_type = VisitableFactoryTest;
	void makeVisitableByReference();
	void makeVisitableByValue();
	void makeVisitableByWeakpointer();
public:

	template<class DerivedTest = this_type>
	static cute::suite make_suite(){
		cute::suite s { };
		s.push_back(CUTE_SMEMFUN(DerivedTest, makeVisitableByReference));
		s.push_back(CUTE_SMEMFUN(DerivedTest, makeVisitableByValue));
		s.push_back(CUTE_SMEMFUN(DerivedTest, makeVisitableByWeakpointer));

		return s;
	}
};

inline
void VisitableFactoryTest::makeVisitableByReference(){
	ASSERTM("Todo: implement test", false);
	NonVisitable nonVisitable;
	CR::Repository::AdapterByReference<NonVisitable> adapter(nonVisitable);

	using Visitor = VTM::MockVisitor<CR::Repository, CR::E1, NonVisitable>;
	Visitor visitor;
	adapter.accept(visitor);

	ASSERTM("Cyclic Visitor::visit(NonVisitable&) not called", visitor.nonVisitableVisited);

}
inline
void VisitableFactoryTest::makeVisitableByValue(){
	ASSERTM("Todo: implement test", false);
}
inline
void VisitableFactoryTest::makeVisitableByWeakpointer(){
	ASSERTM("Todo: implement test", false);
}

#endif /* INCLUDE_VISITABLEFACTORYTEST_H_ */
