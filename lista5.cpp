// Cássio Luis Junqueira Mellem Filho - 32089694
// Domingos Soares do Carmo Neto - 32032889

#include <iostream>
#include <clocale>
#include "DoubleLinkedList.h"

using namespace std;


void Print(const LinkedList* list)
{
	Node* node = list->head;

	for (int i = 0; i < list->count; i++)
	{
		cout << "[" << node->id << "] " << node->name << "\n";
		node = node->next;
	}

	node = nullptr;
}

void PrintReverse(const LinkedList* list)
{
	Node* nodeR = list->tail;

	for (int i = 0; i < list->count; i++)
	{
		cout << "[" << nodeR->id << "] " << nodeR->name << "\n";
		nodeR = nodeR->previous;
	}

	nodeR = nullptr;
}

void PrintDoubleListInfo(const LinkedList* list)
{
	if (IsEmpty(list))
	{
		cout << "\nLista vazia!\n";
	}
	else
	{
		cout << "\nLista:\n";
		Print(list);
		cout << "\nLista invertida:\n";
		PrintReverse(list);
	}
}


int main()
{
	setlocale(LC_ALL, "pt_BR");

	cout << "*** Lista Circular Duplamente Ligada/Encadeada (Doubly Circular LinkedList)*** \n";
	LinkedList* list = Create();

	PrintDoubleListInfo(list);
	Insert(list, 1, "Carol");
	Insert(list, 2, "Eric");
	Insert(list, 3, "John");
	Append(list, 4, "Leo");
	Append(list, 5, "Julia");
	Append(list, 6, "Lisa");
	PrintDoubleListInfo(list);

	Clear(list);
	PrintDoubleListInfo(list);

	Insert(list, 11, "Paulo");
	Append(list, 22, "Thomas");
	Insert(list, 33, "Olga");
	Append(list, 44, "Bia");
	Insert(list, 55, "Angela");
	Append(list, 66, "Karen");
	Insert(list, 77, "Adauto");
	PrintDoubleListInfo(list);


	Node* temp = RemoveNode(list, 44);
	cout << "\nNó removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	temp = nullptr;
	PrintDoubleListInfo(list);

	temp = RemoveHead(list);
	cout << "\nNó removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	temp = nullptr;
	PrintDoubleListInfo(list);

	temp = RemoveTail(list);
	cout << "\nNó removido -> id: " << temp->id << ", name: " << temp->name << '\n';
	temp = nullptr;
	PrintDoubleListInfo(list);

	list = nullptr;
	delete list;
	delete temp;

	cout << "\nFim.\n";
}