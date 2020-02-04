#pragma once

template <typename T>
class LinkedList
{
	struct Node
	{
		T data;

		Node* next;
		Node* previous;
	};
	Node* head;
	Node* tail;
public:
	LinkedList()
	{
		head = new Node();
		tail = new Node();

		head->next = tail;
		tail->previous = head;
	}

	/*Node(int val, int _Prev, int _Next)
	{
		Node* t;
		t->data = val;
		t->previous = _Prev;
		t->next = _Next;
	}*/
	
	LinkedList(const LinkedList& other)
	{
		head = NULL;
		tail = NULL;
		for (auto i = other.start(); i != other.end(); ++i)
		{
			pushL(*i);
		}
	}
	~LinkedList() {
		clearList();
	}


	void tLL()
	{
		Node * t = new Node;
		t->data = NULL;
		head = t;
	}

	void pushF(const T& val)
	{
		//Node *t = new Node(val, head, head->next);
		//head->next = t;
		//t->next->previous = t;


		Node * t = new Node;
		t->data = val;
		t->next = head;
		t->previous = NULL;
		if (head != NULL)
		{
			head->previous = t;
		}
		else
		{
			tail = t;
		}

		head = t;
	}
	void pushL(const T& val)
	{
		Node * t = new Node;
		t->data = val;
		t->next = head;
		t->previous = NULL;
		if (head != NULL)
		{
			tail->next = t;
		}
		else
		{
			head = t;
		}

		tail = t;
	}

	void popF()
	{
		if (head != NULL)
		{
			Node* t = head;
			head = head->next;
			delete t;
		}
	}
	void popL()
	{
		if (tail != NULL)
		{
			Node* t = tail;
			tail = tail->previous;
			delete t;
			if (tail != NULL) {
				tail->next = NULL;
			}
		}
	}

	T& front()
	{
		return head->data;

	}

	T& back()
	{
		return tail->data;
	}

	const T& front() const
	{
		return head->data;
	}

	const T& back() const
	{
		return tail->data;
	}


	void clearList()
	{
		Node* node = head;

		while (node != tail)
		{
			Node* tD = node;
			node = node->next;
			delete tD;
		}
		delete node;
		head = NULL;
		tail = NULL;
	}
	void removeList(const T& val)
	{
		size_t loops = 0;

		for (int i = start(); i != end(); i++)
		{
			if (*i == val)
			{
				loops++;
			}
		}

		for (size_t i = 0; i < loops; i++)
		{
			Node* node = head;

			while (node != NULL)
			{
				if (node.data == val)
				{
					if (node != head)
					{
						node.previous.next = node.next;
					}
					else {
						head = head.next;
					}

					if (node != tail)
					{
						node.next.previous = node.previous;
					}
					else
					{
						tail = tail.previous;
					}
					delete node;
					break;

				}
				node = node.next;
			}
		}
	}

	void remove(const T& val)
	{
		size_t loops = 0;
		for (auto i = start(); i != end(); ++i)
		{
			if (*i == val)
			{
				loops++;
			}
		}
		for (size_t i = 0; i < loops; i++)
		{
			Node * node = head;

			while (node != NULL)
			{
				if (node->data == val)
				{
					if (node != head)
					{
						node->previous->next = node->next;
					}
					else
					{
						head = head->next;
					}

					if (node != tail)
					{
						node->next->previous = node->previous;

					}
					else
					{
						tail = tail->previous;
					}

					delete node;
				}
				else
				{
					node = node->next;
				}
			}
		}
	}

	bool isEmpty() const
	{
		if (head == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	size_t size() const
	{
		size_t t = 0;
		for (auto i = start(); i != end(); ++i)
		{
			t++;
		}

		return t;
	}


	void resizeList(size_t nS)
	{
		size_t cS = size();

		if (nS > cS)
		{
			for (size_t i = 0; i < (nS - cS); i++)
			{
				pushL(0);
			}
		}
		else {
			for (size_t i = 0; i < (nS - cS); i++)
			{
				popL();
			}
		}
	}

	LinkedList& operator=(const LinkedList& r)
	{
		resizeList(r.size());

		auto rL = r.start();
		for (auto i = start(); i != end(); ++i)
		{
			*i = *rL;
			++rL;
		}
		return *this;

	}

	class iterator {
		Node * current;

	public:
		

		iterator()
		{
			current = nullptr;
		}

		iterator(Node * startNode)
		{
			current = startNode;
		}

		bool operator ==(const iterator& r) const
		{
			if (this->current == r.current)
			{
				return true;
			}
			return false;
		}

		bool operator !=(const iterator& r) const
		{
			return !(*this == r);
		}

		T& operator*() const
		{
			return current->data;
		}

		iterator& operator++()
		{
			//if (current != NULL) {
			//	current = current->next;
			//	return*this;
			//}
			//else {
			//	return nullptr;
			//}
			current = current->next;
			return*this;
		}

		iterator operator++(int)
		{
			return(*this);
		}
		iterator& operator--()
		{
			current = current->previous;
			return *this;
		}
		iterator operator--(int)
		{
			iterator temp = *this;
			current = current->previous;
			return temp;
		}
	};

	iterator start()
	{
		return iterator(head);
	}
	const iterator start() const
	{
		return iterator(head);
	}

	iterator end()
	{
		/*iterator temp(tail);
		++temp;
		return temp;*/

		return iterator(tail->previous);
		//return iterator(nullptr);
	}
	const iterator end() const
	{
		iterator current(tail);
		++current;
		return current;
	}


};

