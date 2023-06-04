﻿#include <iostream>
#include <Windows.h>
#include <list> 
#include <set>

#define showText(text, text2) std::cout << text << " " << text2 << std::endl
#define pauseAndClear { \
system("pause"); \
system("cls");};

#pragma region allMethods

void showVector();
void showList();
void showSet();
void showMultiset();
void showMap();
void showStack();
void showQueue();
void showPriorityQueue();
void showBitSet();
void showUnorderedSet();

#pragma endregion

int main()
{
	system("color 0F");

	//showVector();
	showList();
	showSet();
	showMultiset();
	showMap();
	showStack();
	showQueue();
	showPriorityQueue();
	showBitSet();
	showUnorderedSet();

}

#pragma region vector
template <typename T>
class customVector
{
public:
	class Iterator;
	class Node;

	int length = 0;
	
	Node* start = nullptr;
	Node* last = nullptr;
	
	void pushBack(T element) 
	{
		Node* node = new Node(element);

		if (start == nullptr) {
			start = node;
			last = node;
		}
		else {
			last->next = node;
			last = node;
		}
		length++;
	}

	int size()
	{
		return length;
	}
	
	Iterator begin()
	{
		return Iterator(start);
	}

	Iterator end()
	{
		return Iterator(nullptr);
	}

	T& operator[](int index) 
	{
		if (index < 0 || index >= length) 
			throw std::out_of_range("Index out of range");	

		Node* current = start;
		int currentIndex = 0;

		while (currentIndex < index) 
		{
			current = current->next;
			currentIndex++;
		}

		return current->element;
	}

	class Node
	{
	public:
		Node* next;
		T element;
	
	
		Node(T _element) : next(nullptr)
		{
			element = _element;
		}
	};

	class Iterator 
	{
	private:
		Node* current;

	public:
		Iterator(Node* node) : current(node) {}

		T& operator*() const 
		{
			return current->element;
		}

		Iterator& operator++() 
		{
			current = current->next;
			return *this;
		}

		bool operator!=(const Iterator& other) const 
		{
			return current != other.current;
		}
	};
};


void showVector()
{
	customVector<int> customVector;

	customVector.pushBack(0);
	customVector.pushBack(1);
	customVector.pushBack(2);
	


	showText(customVector.size(), " - size of vector");

	showText(customVector[0], " - first element of vector");
	showText(customVector[1], " - second element of vector");
	showText(customVector[2], " - third element of vector\n");
	
	showText("Elements of  vector use for ech", "");

	for (const int i : customVector)
		showText(i, "");

	showText("Elements of  vector use for ", "");

	for (int i = 0; i < customVector.size(); ++i)
		showText(customVector[i], "");

	pauseAndClear;
}

#pragma endregion

#pragma region list

template <typename T>
class customList
{
	class Node;
	class Iterator;

	Node* headNode = nullptr;
	Node* lastNode = nullptr;

public:

	
	void pushFront(T element)
	{
		Node* newNode = new Node(element);

		if (headNode == nullptr)
		{
			headNode = newNode;
			lastNode = newNode;
		}
		else
		{
			lastNode->next = newNode;
			newNode->last = lastNode;
			lastNode = newNode;
		}
	}

	void pushBack(T element)
	{
		Node* newNode = new Node(element);

		if (headNode == nullptr)
		{
			headNode = newNode;
			lastNode = newNode;
		}
		else
		{
			headNode->last = newNode;
			newNode->next = headNode;
			headNode = newNode;
		}

	}

	void testShow()
	{
		Node* node = headNode;

		if (node == nullptr)
		{
			std::cout << "NUll";
		}
		while (node != nullptr)
		{
			std::cout << "Work show \n";
			std::cout << node->element << " ";
			node = node->next;
		}

		
	}
	void popBack()
	{
		if (headNode != nullptr)
		{
			Node* nodeForDelete = headNode;

			headNode = headNode->next;
			headNode->last = nullptr;

			delete nodeForDelete;
		}
	}

	void popFront()
	{
		if (lastNode != nullptr)
		{
			Node* nodeForDelete = lastNode;

			lastNode = lastNode->last;
			lastNode->next = nullptr;

			delete nodeForDelete;
		}
	}

	void erase()
	{


	}

	void remove(T element)
	{
		Node* nodeForDelete = headNode;
		Node* nodeBeforeNodeForDelete = nodeForDelete->next;
		Node* nodeAfterNodeForDelete = nodeForDelete->next;

		while (nodeForDelete->element != element)
		{
			nodeForDelete = nodeForDelete->next;
			nodeAfterNodeForDelete = nodeForDelete->next;
			nodeBeforeNodeForDelete = nodeForDelete->last;
		}


		if (nodeForDelete == headNode)
		{
			headNode = nodeAfterNodeForDelete;
			headNode->next = nodeAfterNodeForDelete->next;

		}
		else if (nodeForDelete == lastNode)
		{
			lastNode = nodeBeforeNodeForDelete;
			lastNode->last = nodeBeforeNodeForDelete->last;
			lastNode->next = nullptr;
		}
		else
		{
			nodeBeforeNodeForDelete->next = nodeForDelete->next;
			nodeAfterNodeForDelete->last = nodeForDelete->last;
		}




		delete nodeForDelete;
	}

	Iterator begin()
	{

	}

	Iterator end()
	{
		
	}

	class Node
	{
	public:
		Node* last;
		Node* next;

		T element;

		Node(T _element) :next(nullptr),last(nullptr)
		{
			element = _element;
		}
	};


	class Iterator
	{

	};

};

void showList()
{
	std::list <int> list;
	
	customList<int> customList;
	
	customList.pushBack(0);
	customList.pushBack(-1);
	customList.pushBack(-2);

	customList.pushFront(1);
	customList.pushFront(2);
	customList.pushFront(3);


	showText("--------", "");
	customList.testShow();
	showText("--------", "");

	customList.remove(3);
	customList.testShow();

	customList.pushFront(3);
	customList.testShow();

	/*showText("Work of list", "");
	showText(list.size(), " - Size of list");

	list.resize(2);


	showText(list.size(), " - Size after resize list");
	showText("--------------", "");

	for (const int i : list)
		showText(i, " - Elements of empty list");

	list.push_back(1);

	showText("Elements of list after push back 1", "");

	for (const int i : list)
		showText(i, "");

	list.push_front(2);

	showText("Elements of list after push front 2", "");

	for (const int i : list)
		showText(i, "");*/

	pauseAndClear;
}
#pragma endregion

#pragma region set

template <typename T>
class customSet
{
public:
	class Node
	{
	public:
		T element;
		Node* next;

		Node(T _element) :next(nullptr)
		{
			element = _element;
		}
	};

	Node* start = nullptr;
	Node* last = nullptr;

	void insert(T element)
	{
		if (!checkElement(element))
			return;

		Node* _node = new Node(element);

		if (start == nullptr)
		{
			start = _node;
			last = _node;
		}
		else
		{
			last->next = _node;
			last = _node;
		}
	}

	void showElement()
	{
		Node* _node = start;

		while (_node != nullptr)
		{
			showText(_node->element, "");
			_node = _node->next;
		}
	}

	void erase(T element)
	{
		Node* _node = start;
		Node* _last = nullptr;
		Node* _next = nullptr;
		while (_node != nullptr)
		{
			if (_node->element == element)
			{
				Node* _next = _node->next;
				_last->next = _next;
				delete(_node);
				return;

			}
			_last = _node;
			_node = _node->next;
		}
	}

	bool checkElement(T element)
	{
		Node* _node = start;

		while (_node != nullptr)
		{
			if (_node->element == element)
				return false;

			_node = _node->next;
		}

		return true;
	}
};

void showSet()
{
	showText("Work of custom set", "");

	customSet<int> customSet;

	customSet.insert(1);
	customSet.insert(2);
	customSet.insert(3);
	customSet.insert(4);
	customSet.insert(5);

	showText("Show element of customr set after inesrt 1 2 3 4 5", "");

	customSet.showElement();

	showText("--------------", "\nShow element of customr set after erase 3 ");

	customSet.erase(3);
	customSet.showElement();

	pauseAndClear;
}

#pragma endregion

#pragma region multiset

void showMultiset()
{
	pauseAndClear;
}
#pragma endregion

#pragma region map
void showMap()
{
	pauseAndClear;

}
#pragma endregion

#pragma region Stack

void showStack()
{
	pauseAndClear;

}

#pragma endregion

#pragma region queue

void showQueue()
{
	pauseAndClear;

}
#pragma endregion

#pragma region priorityQueue

void showPriorityQueue()
{
	pauseAndClear;

}
#pragma endregion

#pragma region bitSet

void showBitSet()
{
	pauseAndClear;

}
#pragma endregion

#pragma region unorderedSet

void showUnorderedSet()
{
	pauseAndClear;

}
#pragma endregion
