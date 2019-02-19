#include <cstddef>
#include "Node.h"
#include "LinkedBag.h"
#include <cstdlib>
#include <iostream>
#include <ctime>

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
	Node<ItemType>* cNode = headPtr;
	int count = 0;
	while (cNode != nullptr) {
		count++;

		cNode = cNode->getNext();
	}
	return count;

}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
	return getCurrentSize340RecursiveHelper(headPtr);

}

template<typename ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType>*cNode) const {
	if (cNode != nullptr) {
		return 1 + getCurrentSize340RecursiveHelper(cNode->getNext());

	}
	else {
		return 0;
	}

}

template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType& anEntry) const {
	return getFrequencyOf340RecursiveHelper(headPtr, anEntry);
}


template<typename ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType>* cNode, const ItemType& anEntry) const {

	if (cNode != nullptr) {
		if (cNode->getItem() == anEntry) {
			return 1 + getFrequencyOf340RecursiveHelper(cNode->getNext(), anEntry);

		}
		else {
			return 0 + getFrequencyOf340RecursiveHelper(cNode->getNext(), anEntry);
		}
	}
	else {
		return 0;
	}
}



template<typename ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType& newEntry) {
	
	Node<ItemType>* currentPtr = new Node<ItemType>();


	if (!isEmpty()) {

		Node<ItemType>* nextNodePtr = new Node<ItemType>(newEntry, nullptr);
		nextNodePtr->setItem(newEntry);
		nextNodePtr->setNext(nullptr);

		itemCount++;
		currentPtr = headPtr;
		while (currentPtr->getNext() != nullptr) {
			currentPtr = currentPtr->getNext();
		}
		currentPtr->setNext(nextNodePtr);

		return true;
	}
	return false;



}

template<typename ItemType>
bool LinkedBag<ItemType>::removeSecondNode340() {

	Node<ItemType>* nodeToDeletePtr = headPtr;

	headPtr = headPtr->getNext();
	headPtr->setItem(nodeToDeletePtr->getItem());

	free(nodeToDeletePtr);

	nodeToDeletePtr->setNext(nullptr);

	itemCount--;

	return true;

}



template<typename ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {
	return false;

}

