/*
 * MetaFunctions.h
 *
 *  Created on: 29.05.2016
 *      Author: Gerd
 */

#ifndef METAFUNCTIONS_H_
#define METAFUNCTIONS_H_

template <typename T> struct void_type { typedef void type; };

// General utility: if_<Condition, Then, Else>::type
// Selects 'Then' or 'Else' type based on the value of
// the 'Condition'
template <bool Condition, typename Then, typename Else = void>
struct IFFunction {
   typedef Then type;
};
template <typename Then, typename Else>
struct IFFunction<false, Then, Else > {
   typedef Else type;
};

template<bool Condition, class Then, class Else>
using IF = typename IFFunction<Condition, Then, Else>::type;

#endif /* METAFUNCTIONS_H_ */
