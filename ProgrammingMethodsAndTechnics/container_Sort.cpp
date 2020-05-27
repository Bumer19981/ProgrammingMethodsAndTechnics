#include <fstream>
#include "container_atd.h"

using namespace std;
namespace simple_langtypes {
	//bool Compare(langtype* first, langtype* second);
	void Sort(container& c) {
		if (c.list.Head == NULL)
		{
			throw std::invalid_argument("Error: list is empty!");
		}

		for (int i = 0; i < c.list.size - 1; i++) {
			for (int j = i + 1; j < c.list.size; j++) {
				container::List::Node* ComparableItem1 = new container::List::Node;
				container::List::Node* ComparableItem2 = new container::List::Node;
				for (int k = 0; k <= i; ++k) {
					if (k == 0) {
						ComparableItem1 = c.list.Head;
					}
					else {
						ComparableItem1 = ComparableItem1->Next;
					}
				}
				for (int k = 0; k <= j; ++k) {
					if (k == 0) {
						ComparableItem2 = c.list.Head;
					}
					else {
						ComparableItem2 = ComparableItem2->Next;
					}
				}
				if (Compare(ComparableItem1->l, ComparableItem2->l)) {
					container::List::Node* tmp;
					tmp = ComparableItem2->Next;
					ComparableItem2->Next = ComparableItem1->Next;
					ComparableItem2->Next->Prev = ComparableItem2;

					ComparableItem1->Next = tmp;
					ComparableItem1->Next->Prev = ComparableItem1;

					tmp = ComparableItem1->Prev;
					ComparableItem1->Prev = ComparableItem2->Prev;
					ComparableItem1->Prev->Next = ComparableItem1;

					ComparableItem2->Prev = tmp;
					ComparableItem2->Prev->Next = ComparableItem2;
					if (Compare(c.list.Head->l, ComparableItem2->l))
						c.list.Head = ComparableItem2;
				}
			}
		}
		for (int i = 0; i < c.list.size; ++i) {
			if (i == 0) {
				c.list.Tail = c.list.Head;
			}
			else {
				c.list.Tail = c.list.Tail->Next;
			}
		}
	}
}