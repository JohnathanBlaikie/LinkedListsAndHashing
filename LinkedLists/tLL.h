#pragma once

template <typename temp>
class LinkedList
{
	struct Node
	{
		temp data;

		Node* next;
		Node* previous;
	};
	Node* head;
	Node* tail;
	LinkedList()
	{
		head = NULL;
		tail = NULL;
	}		LinkedList(const LinkedList& other)
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
public:
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
			if (current.data == r.current.data && current.next == r.current.next)
			{
				return true;
			}
			return false;
		}

		bool operator !=(const iterator& r) const
		{
			if (current.data != r.current.data && current.next != r.current.next)
			{
				return true;
			}
			return false;
		}

		temp& operator*() const
		{
			current = current.next;
			return*this;
		}

		iterator& operator++()
		{
			current = current.next;
			return*this;
		}

		iterator operator++(int)
		{
			return(*this);
		}
	};

	iterator start()
	{
		iterator t(head);
		return t;
	}

	iterator end()
	{
		iterator t(head);
		while (*t != NULL)
		{
			++t;
		}
		return t;
	}

	void tLL()
	{
		Node * t = new Node;
		t.data = NULL;
		head = t;
	}

	void pushF(const temp& val)
	{
		Node * t = new Node;
		t.data = val;
		t.next = head;
		t.previous = NULL;
		if (head != NULL)
		{
			head.previous = t;
		}
		else
		{
			tail = t;
		}

		head = t;
	}
	void pushL(const temp& val)
	{
		Node * t = new Node;
		t.data = val;
		t.next = head;
		t.previous = NULL;
		if (head != NULL)
		{
			tail.next = t;
		}
		else
		{
			head = t;
		}

		tail = t;
	}

	void popF()
	{
		if (head.data != NULL)
		{
			Node* t = head;
			head = head.next;
			delete t;
		}
	}
	void popL()
	{
		if (tail.data != NULL)
		{
			Node* t = head;
			tail = tail.next;
			delete t;
			tail.next = NULL;
		}
	}

	temp& front()
	{
		return head.data;

	}

	temp& back()
	{
		return tail.data;
	}

	const temp& front() const
	{
		return head.data;
	}

	const temp& back() const
	{
		return tail.data;
	}

	void clear(const temp& val)
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
		if (head.data == NULL && head.next == nullptr) {
			return true;
		}
		else {
			return false;
		}
	}

	void clear()
	{
		for (int i = start(); i != end(); i++)
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
