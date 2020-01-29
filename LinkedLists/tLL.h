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
		head = NULL;
		tail = NULL;
	}	
	LinkedList(const LinkedList& other)
	{
		head = NULL;
		tail = NULL;
		for (int i = other.begin(); i != other.end(); ++i)
		{
			pushL(*i);
		}
	}
	~LinkedList() {
		clear();
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
			current = current->next;
			return*this;
		}

		iterator operator++(int)
		{
			return(*this);
		}
	};

	iterator start()
	{
		return iterator(head);
	}

	iterator end()
	{
		/*iterator t(head);
		while (*t != NULL)
		{
			++t;
		}*/
		return iterator(nullptr);
	}

	void tLL()
	{
		Node * t = new Node;
		t->data = NULL;
		head = t;
	}

	void pushF(const T& val)
	{
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

	void clear(const T& val)
	{
		size_t loops = 0;

		for (int i = start(); i != end(); i++)
		{
			if (*i == val)
			{
				loops++;
			}
		}

		for (size_t i = 0; i < loops ;i++)
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

	bool isEmpty() const
	{
		if (head == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	void clear()
	{
		for (auto i = start(); i != end(); i++)
		{
			popL();
		}
	}

	void resize(size_t nS)
	{
		int size = 0;
		for (int i = start(); i != end(); i++)
		{
			pushL(1);
		}
	}

};
