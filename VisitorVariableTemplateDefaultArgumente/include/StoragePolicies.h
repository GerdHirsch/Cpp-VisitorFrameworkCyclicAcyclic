/*
 * StoragePolicies.h
 *
 *  Created on: 28.05.2016
 *      Author: Gerd
 */

#ifndef STORAGEPOLICIES_H_
#define STORAGEPOLICIES_H_

#include <memory>

template<class Adaptee>
struct StorageByReference{
	using StorageType = Adaptee&;
	using ReturnType = Adaptee*;

	StorageByReference(StorageType adaptee):adaptee(adaptee){}

	ReturnType get(){ return &adaptee; }
	ReturnType get() const { return &adaptee; }
protected:
	StorageType adaptee;
};
template<class Adaptee>
struct StorageByWeakPointer{
	using StorageType = std::weak_ptr<Adaptee>;
	using ReturnType = std::shared_ptr<Adaptee>;

	StorageByWeakPointer(StorageType adaptee):adaptee(adaptee){}
	ReturnType get(){ return adaptee.lock(); }
	ReturnType get() const { return adaptee.lock(); }
protected:
	StorageType adaptee;
};

#endif /* STORAGEPOLICIES_H_ */
