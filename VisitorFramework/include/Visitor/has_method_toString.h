/*
 * has_member_toString.h
 *
 *  Created on: 19.12.2016
 *      Author: Gerd
 */

#ifndef HAS_METHOD_TOSTRING_H_
#define HAS_METHOD_TOSTRING_H_

#include <typeinfo>
#include <string>


template<typename T>
struct has_method_toString
{
private:
	typedef std::true_type yes;
	typedef std::false_type no;

	template<typename C>
	static yes test(std::string (C::*f)() const);
	template<typename C>
	static yes test(std::string (C::*f)() );

	template<typename C>
	static yes test(std::string const& (C::*f)() const);

	template<typename C>
	static yes test(std::string const& (C::*f)() );


	template<typename C>
	static auto test(decltype(&C::toString), void*) -> decltype(test(&C::toString));

	template<typename C>
	static no test(...);

public:
	using type = decltype(test<T>(0,0));

	static constexpr bool value = type::value;
};

template<class ToPrint, bool = has_method_toString<ToPrint>::value>
struct ToString{
	static std::string toString(ToPrint const& o) {
		return o.toString();
	}
};
template<class ToPrint>
struct ToString<ToPrint, false>{
	static std::string toString(ToPrint const&) {
		return typeid(ToPrint).name();
	}
};

template<class ToPrint>
auto toString(ToPrint const& p){
	return ToString<ToPrint>::toString(p);
}



#endif /* HAS_METHOD_TOSTRING_H_ */
