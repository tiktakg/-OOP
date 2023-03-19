#include <iostream>
#include <string>
#include <windows.h>



std::string enterData(std::string text)
{
	std::string data;
	std::cout << text;
	std::cin >> data;
	return data;
}

//struct Stack
//{
//private:
//
//	struct Node
//	{
//		std::string str;
//		Node* next;
//
//		Node(std::string _str):next(nullptr)
//		{
//			str = _str;
//		}
//	};
//
//	Node* lastNode = nullptr;
//
//	void enterNode(std::string _str)
//	{
//		Node* node = new Node(_str);
//
//		if (lastNode != nullptr)
//			node->next = lastNode;
//
//		lastNode = node;
//		
//	}
//
//	
//	void deleteLastNode()
//	{
//		if (lastNode != nullptr)
//		{
//			Node*  _node = lastNode->next;
//			delete(lastNode);
//			lastNode = _node;
//		}
//		else
//			std::cout << "List is note created\n";
//	
//	}
//
//	void printAndDeleteAllList()
//	{
//		if (lastNode == nullptr)
//			std::cout << "List is note created\n";
//
//		while (lastNode != nullptr)
//		{
//			Node* _node = lastNode->next;
//			std::cout << lastNode->str << std::endl;
//			delete(lastNode);
//			lastNode = _node;
//		}
//	}
//
//	void PrintLastNode()
//	{
//		
//		if (lastNode != nullptr)
//			std::cout << lastNode->str << std::endl;
//		else
//			std::cout << "List is note created\n";
//		
//	}
//
//public:
//	void menu(Stack list)
//	{
//		int number;
//		std::string data, bettenData;
//
//
//		system("cls");
//
//		std::cout << "Choose a number:\n";
//		std::cout << "1 - enter a node to end of list or create list\n";
//		std::cout << "2 - Print first node \n";
//		std::cout << "3 - delete first node\n";
//		std::cout << "4 - Print and delete all node  \n";
//		std::cout << "5 - exit\n";
//
//		std::cin >> number;
//
//		switch (number)
//		{
//		case 1:
//			list.enterNode(enterData("Write a date for node\n"));
//			break;
//
//		case 2:
//			list.PrintLastNode();
//			break;
//
//		case 3:
//			list.deleteLastNode();
//			break;
//
//		case 4:
//			list.printAndDeleteAllList();
//			break;
//
//		case 5:
//			return;
//			break;
//		}
//
//		system("Pause");
//		menu(list);
//	}
//};


//struct Queue
//{
//private:
//
//	struct Node
//	{
//		std::string str;
//		Node* next;
//
//		Node(std::string _str) :next(nullptr)
//		{
//			str = _str;
//		}
//	};
//
//	Node* firstNode = nullptr;
//	Node* lastNode = nullptr;
//
//	void enterNode(std::string _str)
//	{
//		Node* node = new Node(_str);
//
//		if (firstNode == nullptr)
//		{
//			firstNode = node;
//			return;
//		}
//
//		if (firstNode->next == nullptr)
//		{
//			firstNode->next = node;
//			lastNode = node;
//			return;
//		}
//
//		lastNode->next = node;
//		lastNode = node;
//		
//	}
//
//
//	void deleteLastNode()
//	{
//		if (firstNode != nullptr)
//		{
//			Node* node = firstNode->next;
//			delete(firstNode);
//			firstNode = node;
//		}
//		else
//			std::cout << "List is note created\n";
//
//	}
//
//	void printAndDeleteAllList()
//	{
//		if (firstNode == nullptr)
//			std::cout << "List is note created\n";
//
//		while (firstNode != nullptr)
//		{
//			Node* _node = firstNode->next;
//			std::cout << firstNode->str << std::endl;
//			delete(firstNode);
//			firstNode = _node;
//		}
//	}
//
//	void PrintLastNode()
//	{
//
//		if (firstNode != nullptr)
//			std::cout << firstNode->str << std::endl;
//		else
//			std::cout << "List is note created\n";
//	}
//
//
//
//public:
//	void menu(Queue list)
//	{
//		int number;
//		std::string data, bettenData;
//
//
//		system("cls");
//
//		std::cout << "Choose a number:\n";
//		std::cout << "1 - enter a node to end of list or create list\n";
//		std::cout << "2 - Print first node \n";
//		std::cout << "3 - delete first node\n";
//		std::cout << "4 - Print and delete all node  \n";
//		std::cout << "5 - exit\n";
//
//		std::cin >> number;
//
//		switch (number)
//		{
//		case 1:
//			list.enterNode(enterData("Write a date for node\n"));
//			break;
//
//		case 2:
//			list.PrintLastNode();
//			break;
//
//		case 3:
//			list.deleteLastNode();
//			break;
//
//		case 4:
//			list.printAndDeleteAllList();
//			break;
//
//		case 5:
//			return;
//			break;
//		}
//
//		system("Pause");
//		menu(list);
//	}
//};

struct Deck
{
private:

	struct Node
	{
		std::string str;
		Node* next;

		Node(std::string _str) :next(nullptr)
		{
			str = _str;
		}
	};

	Node* firstNode = nullptr;
	Node* lastNode = nullptr;

	void enterNode(std::string _str)
	{
		Node* node = new Node(_str);

		if (firstNode == nullptr)
		{
			firstNode = node;
			lastNode = node;
			return;
		}

		if (firstNode->next == nullptr)
		{
			firstNode->next = node;
			lastNode = node;
			return;
		}

		node->next = lastNode;
		lastNode->next = node;
		lastNode = node;




	}


	void DeleteFirstNode()
	{
		if (firstNode != nullptr)
		{
			Node* node = firstNode->next;
			delete(firstNode);
			firstNode = node;
		}
		else
			std::cout << "List is note created\n";

	}

	void PrintFirstNode()
	{

		if (firstNode != nullptr)
			std::cout << firstNode->str << std::endl;
		else
			std::cout << "List is note created\n";
	}

	void DeleteLastNode()
	{
		if (lastNode != nullptr)
		{
			Node* _node = lastNode->next;
			delete(lastNode);
			lastNode = _node;
		}
		else
			std::cout << "List is note created\n";

	}

	void PrintLastNode()
	{

		if (lastNode != nullptr)
			std::cout << lastNode->str << std::endl;
		else
			std::cout << "List is note created\n";

	}



	void printAndDeleteAllList()
	{

		if (firstNode == nullptr)
		{
			std::cout << "List is note created\n";
			return;
		}

		while (lastNode != firstNode)
		{
			Node* _node = firstNode->next;
			std::cout << firstNode->str << std::endl;
			delete(firstNode);
			firstNode = _node;
		}

		if (lastNode != nullptr)
		{
			std::cout << firstNode->str << std::endl;
			delete(firstNode);
		}
		firstNode = nullptr;
		lastNode = nullptr;

	}


public:
	void menu(Deck list)
	{
		int number;

		system("cls");

		std::cout << "Choose a number:\n";
		std::cout << "1 - enter a node to end of list or create list\n";
		std::cout << "2 - Print first node \n";
		std::cout << "3 - Delete first node\n";
		std::cout << "4 - Print last node \n";
		std::cout << "5 - Delete last node\n";
		std::cout << "6 - Print and delete all node with start  \n";
		std::cout << "7 - exit\n";

		std::cin >> number;



		switch (number)
		{
		case 1:
			list.enterNode(enterData("Write a date for node\n"));
			break;

		case 2:
			list.PrintFirstNode();
			break;

		case 3:
			list.DeleteFirstNode();
			break;

		case 4:
			list.PrintLastNode();
			break;

		case 5:
			list.DeleteLastNode();
			break;

		case 6:
			list.printAndDeleteAllList();
			break;

		case 7:
			return;
			break;
		}

		system("Pause");
		menu(list);

	}
};




int main()
{
	Deck qu;
	qu.menu(qu);

}
