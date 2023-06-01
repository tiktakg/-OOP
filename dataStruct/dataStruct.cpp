#include <iostream>
#include <vector>
#include <Windows.h>
#include <list> 
#include <set>


#define showText(text, text2) std::cout << text << " " << text2 << std::endl
#define pauseAndClear { \
system("pause"); \
system("cls");};

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



int main()
{
	system("color 02");

	showVector();
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
	
	class Node
	{
	public:
		T element;
		int i;

		Node(T _element)
		{
			element = _element;
			i = size + 1;
		}

	};
	int size = 0;
	Node* head = nullptr;

	void pushBack(T element)
	{
		Node node = new Node(element);
		if (head == nullptr)
			head = node;

	}

	int Size()
	{
		return size;
	}


	T& operator[](int index) {
		if (index < 0 || index >= size) {
			throw std::out_of_range("Index out of range");
		}

		Node* current = head;
		int currentIndex = 0;

		while (currentIndex < index) {
			current = current->next;
			currentIndex++;
		}

		return current->element;
	}

class Iterator {
	private:
		Node* current;

	public:
		Iterator(Node* node) : current(node) {}

		T& operator*() const {
			return current->element;
		}

		Iterator& operator++() {
			current = current->next;
			return *this;
		}

		bool operator!=(const Iterator& other) const {
			return current != other.current;
		}
	};

	Iterator begin() {
		return Iterator(head);
	}

	Iterator end() {
		return Iterator(nullptr); // Итератор, указывающий на конец вектора
	}


};
void showVector()
{

	/*std::vector <int> vector;

	showText("Work of vector", "");
	showText(vector.size(), " - Size of empty vector");

	vector.resize(2);

	showText(vector.size(), " - Size of empty with resize vector");

	for (const int i : vector)
		showText(i, " - Elements of empty vector");

	vector.push_back(1);
	vector.push_back(2);
	vector.push_back(3);

	showText("--------------", "\nElements of vector after push back");

	for (const int i : vector)
		showText(i, "");*/

	customVector<int> customVector;

	customVector[0] = 1;
	showText(customVector.Size(), "");

	for (const int i : customVector)
		showText(i, " - Elements of empty vector");

	pauseAndClear;
}
#pragma endregion

#pragma region list

void showList()
{
	std::list <int> list;

	showText("Work of list", "");
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
		showText(i, "");

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
