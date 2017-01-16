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
private:
	class DisableCtor;
public:
	using StorageType = Adaptee&;

	using LValueReferenceType = Adaptee&;
	using RValueReferenceType = DisableCtor&;

	using ReturnType = Adaptee*;
	using ConstReturnType = Adaptee const*;

	StorageByReference(LValueReferenceType adaptee):adaptee(adaptee){}

	ReturnType get(){ return &adaptee; }
	ConstReturnType get() const { return &adaptee; }
protected:
	StorageType adaptee;
};

//------------------------------------------
template<class Adaptee>
struct StorageByValue{
	using StorageType = Adaptee;

	using LValueReferenceType = Adaptee&;
	using RValueReferenceType = Adaptee&&;

	using ReturnType = Adaptee*;
	using ConstReturnType = Adaptee const*;

	StorageByValue(LValueReferenceType adaptee):adaptee(adaptee){}
	StorageByValue(RValueReferenceType adaptee):adaptee(std::move(adaptee)){}
	// to many copy ctors
//	StorageByValue(StorageType adaptee):adaptee(adaptee){}

	ReturnType get(){ return &adaptee; }
	ConstReturnType get() const { return &adaptee; }
protected:
	StorageType adaptee;
};
//------------------------------------------
template<class Adaptee>
struct StorageByWeakpointer{
public:
	using StorageType = std::weak_ptr<Adaptee>;

	using LValueReferenceType = std::shared_ptr<Adaptee>&;
	using RValueReferenceType = StorageType&;

	using ReturnType = std::shared_ptr<Adaptee>;
	using ConstReturnType = std::shared_ptr<Adaptee const>;

	StorageByWeakpointer(LValueReferenceType adaptee):adaptee(adaptee){}
	StorageByWeakpointer(StorageType& adaptee):adaptee(adaptee){}

	ReturnType get(){ return adaptee.lock(); }
	ConstReturnType get() const { return adaptee.lock(); }
protected:
	StorageType adaptee;
};
template<class Adaptee>
struct StorageByUniquepointer{
private:
	class DisableCtor;
public:
	using StorageType = std::unique_ptr<Adaptee>;

	using LValueReferenceType = DisableCtor&;
//	using LValueReferenceType = StorageType;
	using RValueReferenceType = StorageType&&;

	using ReturnType = Adaptee*;
	using ConstReturnType = Adaptee const *;

	StorageByUniquepointer(LValueReferenceType adaptee):adaptee(adaptee){}
	StorageByUniquepointer(RValueReferenceType adaptee):adaptee(std::move(adaptee)){}

	ReturnType get(){ return &*adaptee; }
	ConstReturnType get() const { return &*adaptee; }
protected:
	StorageType adaptee;
};

} // end namespace
#endif /* STORAGEPOLICIES_H_ */
