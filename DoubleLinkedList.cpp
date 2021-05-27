// C�ssio Luis Junqueira Mellem Filho - 32089694
// Domingos Soares do Carmo Neto - 32032889

#include <string>
#include "DoubleLinkedList.h"


LinkedList* Create()
{
	LinkedList* list = new LinkedList;

	list->count = 0;
	list->head = nullptr;
	list->tail = nullptr;

	return list;
}

Node* CreateNode(int id, Node* tail, Node* head, std::string name)
{
	Node* node = new Node;

	node->id = id;
	node->name = name;
	node->previous = tail;
	node->next = head;

	return node;
}


void Insert(LinkedList* list, int id, std::string name)
{
	/*	Para a implementa��o do Insert temos 2 poss�veis casos, 1- caso estiver vazio ,2- caso ter algo na lista

		1- Parte mais simples pois simplesmente define esse n� como o come�o e o fim da fila (tanto head quanto tail)
		2- Como queremos adicionar no come�o da lista, primeiramente dizemos que o previous do n� head atual tem q apontar para o node (que ser� o novo head),
				p�s isso podemos dizer que o head � igual aos dados do novo n�.

										New Head			   Old Head
								[previous][id][next] <--> [previous][id][next]

										New Head			        Tail
							|-> [previous][id][next]      [previous][id][next] <-|
							|----------------------------------------------------|					*/


	Node* node = CreateNode(id, list->tail, list->head, name);

	if (IsEmpty(list))
	{
		list->tail = node;
		list->head = node;
	}
	else
	{
		list->head->previous = node;
		list->head = node;
	}

	list->tail->next = list->head;
	++list->count;
}

void Append(LinkedList* list, int id, std::string name)
{
	/*	Para a implementa��o do Append temos 2 poss�veis casos, 1- caso estiver vazio ,2- caso ter algo na lista

		1- Parte mais simples pois simplesmente define esse n� como o come�o e o fim da fila (tanto head quanto tail)
		2- Como queremos adicionar no fim da lista, primeiramente dizemos que o next do n� head atual tem q apontar para o node (que ser� o novo tail),
				p�s isso podemos dizer que o tail � igual aos dados do novo n�.

										Old Tail			      New Tail
								[previous][id][next] <--> [previous][id][next]

										Head			          New Tail
							|-> [previous][id][next]      [previous][id][next] <-|
							|----------------------------------------------------|					*/

	Node* node = CreateNode(id, list->tail, list->head, name);

	if (IsEmpty(list))
	{
		list->tail = node;
		list->head = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
	}

	list->head->previous = list->tail;
	++list->count;
}


Node* RemoveHead(LinkedList* list)
{
	/*	Para a implementa��o do RemoveHead temos 2 poss�veis casos, 1- caso estiver vazio ,2- caso ter algo na lista

		1- Simplesmente retorna nullptr, pois n�o existe nada na lista
		2- Para realizar a oper��o precisa-se "pular" este n� e ligar o anterior e o next deste. Para isso, o head passa a apontar para o seu pr�ximo
				e o seu anterior passa a apontar para o tail da lista (por conta de ser circular), o tail next aponta para o head (por conta de ser circular)
				e por fim, diminui 1 do count, pois foi retirado um n�mero da lista.																			*/

	Node* removeH = list->head;

	if (removeH == nullptr)
	{
		return nullptr;
	}
	else {
		list->head = list->head->next;
		list->head->previous = list->tail;
		list->tail->next = list->head;

		list->count--;

		return removeH;
	}
}

Node* RemoveTail(LinkedList* list)
{
	/*	Principio � o mesmo do RemoveHead, por�m mudam algumas opera��o para se adaptar ao Tail.	*/

	Node* removeT = list->tail;

	list->tail = list->tail->previous;
	list->tail->next = list->head;
	list->head->previous = list->tail;

	list->count--;

	return removeT;
}

Node* RemoveNode(LinkedList* list, int id)
{
	/*	Principio � o mesmo do RemoveHead, por�m mudam algumas opera��o para se adaptar ao Node. Por�m tem-se agora que toda vez que o id do removeN for diferente
			vai para frente uma posi��o at� suprir a necessidade.																									*/

	Node* removeN = list->head;

	for (int i = 0; i < list->count; i++)
	{
		if (removeN == nullptr)
		{
			return nullptr;
		}
		else if (removeN->id == id)
		{
			removeN->previous->next = removeN->next;
			removeN->next->previous = removeN->previous;
		}
		else {
			removeN = removeN->next;
		}
	}

	list->count--;

	return removeN;
}


Node* GetHead(const LinkedList* list)
{
	return list->head;
}

Node* GetTail(const LinkedList* list)
{
	return list->tail;
}

void Clear(LinkedList* list)
{

	/*	N�o podemos simplesmente deletar a lista, queremos limpar, neste caso. Para tal, tem-se 2 structs Node, uma para deletar (aux) e outra com os dados (node).
		Como estamos utilizando ponteiros, caso a vari�vel seja deletada (aux) ja conseguimos realizar um clear daqueles dados anteriores.
		Por fim, para n�o ter problemas com os IsEmpty, declara-se nullptr para o head e para o tail. E claro, por fim o count fica zerado.
																																										*/
	Node* node = list->head;
	Node* aux = nullptr;

	for (int i = 0; i < list->count; i++)
	{
		aux = node;
		node = node->next;

		delete aux;
	}

	list->head = nullptr;
	list->tail = nullptr;

	list->count = 0;

	node = nullptr;
	aux = nullptr;
}


int Count(const LinkedList* list)
{
	return list->count;
}

bool IsEmpty(const LinkedList* list)
{
	return list->head == nullptr && list->tail == nullptr;
}


