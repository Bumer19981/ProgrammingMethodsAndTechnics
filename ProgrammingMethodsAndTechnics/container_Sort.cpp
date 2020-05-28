#include <fstream>
#include "container_atd.h"

using namespace std;
namespace simple_langtypes {
	//bool Compare(langtype* first, langtype* second);
	void sort(Container& c) {
		if (c.list.head == NULL)
		{
			throw std::invalid_argument("Error: list is empty!");
		}

		for (int i = 0; i < c.list.size - 1; i++) {
			for (int j = i + 1; j < c.list.size; j++) {
				Container::List::Node* ComparableItem1 = new Container::List::Node;
				Container::List::Node* ComparableItem2 = new Container::List::Node;
				for (int k = 0; k <= i; ++k) {
					if (k == 0) {
						ComparableItem1 = c.list.head;
					}
					else {
						ComparableItem1 = ComparableItem1->next;
					}
				}
				for (int k = 0; k <= j; ++k) {
					if (k == 0) {
						ComparableItem2 = c.list.head;
					}
					else {
						ComparableItem2 = ComparableItem2->next;
					}
				}
				if (compare(ComparableItem1->l, ComparableItem2->l)) {
					Container::List::Node* tmp;
					tmp = ComparableItem2->next;
					ComparableItem2->next = ComparableItem1->next;
					ComparableItem2->next->prev = ComparableItem2;
					ComparableItem1->next = tmp;
					ComparableItem1->next->prev = ComparableItem1;
					tmp = ComparableItem1->prev;
					ComparableItem1->prev = ComparableItem2->prev;
					ComparableItem1->prev->next = ComparableItem1;
					ComparableItem2->prev = tmp;
					ComparableItem2->prev->next = ComparableItem2;
					if (compare(c.list.head->l, ComparableItem2->l))
						c.list.head = ComparableItem2;
				}
			}
		}
		for (int i = 0; i < c.list.size; ++i) {
			if (i == 0) {
				c.list.tail = c.list.head;
			}
			else {
				c.list.tail = c.list.tail->next;
			}
		}
	}
}