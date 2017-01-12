/*
 * StoragePolicies.h
 *
 *  Created on: 28.05.2016
 *      Author: Gerd
 */

#ifndef STORAGEPOLICIES_H_
#define STORAGEPOLICIES_H_

#include <memory>

namespace VisitorFramework{


template<class Adaptee>
struct StorageByReference{
	using StorageType = Adaptee&;
	using ReferenceType = Adaptee&;
	using ReturnType = Adaptee*;
	using ConstReturnType = Adaptee const*;

	StorageByReference(StorageType adaptee):adaptee(adaptee){}

	ReturnType get(){ return &adaptee; }
	ConstReturnType get() const { return &adaptee; }
protected:
	StorageType adaptee;
};
//------------------------------------------
template<class Adaptee>
struct StorageByValue{
	using StorageType = Adaptee;
	using ReferenceType = Adaptee&;
	using ReturnType = Adaptee*;
	using ConstReturnType = Adaptee const*;

//	StorageByValue(StorageType& adaptee):adaptee(adaptee){}
	StorageByValue(StorageType adaptee):adaptee(adaptee){}

	ReturnType get(){ return &adaptee; }
	ConstReturnType get() const { return &adaptee; }
protected:
	StorageType adaptee;
};
//------------------------------------------
template<class Adaptee>
struct StorageByWeakpointer{
	using StorageType = std::weak_ptr<Adaptee>;
	using ReferenceType = std::shared_ptr<Adaptee>&;
	using ReturnType = std::shared_ptr<Adaptee>;
	using ConstReturnType = std::shared_ptr<Adaptee const>;

	StorageByWeakpointer(StorageType adaptee):adaptee(adaptee){}
	ReturnType get(){ return adaptee.lock(); }
	ConstReturnType get() const { return adaptee.lock(); }
protected:
	StorageType adaptee;
};

} // end namespace
#endif /* STORAGEPOLICIES_H_ */
