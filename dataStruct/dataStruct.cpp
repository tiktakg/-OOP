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

void showVector()
{

	std::vector <int> vector;

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
		showText(i, "");

	pauseAndClear;
}

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

template <typename T>

#pragma region Set

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



void showMultiset()
{
	pauseAndClear;
}

void showMap()
{
	pauseAndClear;

}

void showStack()
{
	pauseAndClear;

}

void showQueue()
{
	pauseAndClear;

}

void showPriorityQueue()
{
	pauseAndClear;

}

void showBitSet()
{
	pauseAndClear;

}

void showUnorderedSet()
{
	pauseAndClear;

}




