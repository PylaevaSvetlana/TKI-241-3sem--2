#pragma once
#include <iostream>
#include <initializer_list>


namespace Queue
{
	template<typename T> class Queue;

	/**
	* @brief - Оператор сдвига влево.
	*/
	template<typename T>
	std::ostream& operator << (std::ostream& output, const Queue<T>& queue);

	template<typename T>
	class Queue
	{
	private:
		struct Node
		{
			T data;
			Node* next;
			Node* previous;
			Node(T value) :data{ value }, next{ nullptr }, previous{ nullptr } {}
		};
		/**
		* @brief - Узел головы очереди.
		*/
		Node* head;
		/**s
		* @brief - Узел хвоста очереди.
		*/
		Node* tail;
		/**
		* @brief - Размер очереди.
		*/
		size_t size;

	public:
		/**
		* @brief - Конструктор класса очередь.
		*/
		Queue();
        /**
		* @brief - Деструктор класса очередь.
		*/
		~Queue();
		/**
		* @brief - Конструктор со списком инициализации.
		* @param list - Список
		*/
		Queue(std::initializer_list<T> list);
		/**
		* @brief - Функция,добавляющая элемент в конце очереди.
		* @param value - Значение нового элемента.
		*/
		void enqueue(const T value);
		/**
		* @brief - Функция,извлекающая элемент из начала очереди.
		*/
		void dequeue();
		/**
		* @brief - Функция,читающая головной элемент.
		* @return - Возвращает значение первого узла.
		*/
		T peek();
		/**
		* @brief - Конструктор копирования.
		* @param other - Другая очередь.
		*/
		Queue(const Queue& other);

		/**
		* @brief - Конструктор перемещения.
		* @param other - Другая очередь.
		*/
		Queue(Queue&& other) noexcept;
		/**
		* @brief - Оператор присваивания с помощью копирования.
		* @param other - Другая очередь.
		* @return - Возвращает очередь с другими параметрами.
		*/
		Queue& operator = (const Queue& other);
		/**
		* @brief - Оператор присваивания с помощью перемещения.
		* @param other - Другая очередь.
		* @return - Возвращает очередь с другими параметрами.
		*/
		Queue& operator = (Queue&& other) noexcept;
		/*
		* @brief Функция, проверяющая очередь на пустоту.
		* @return Возвращает true если очередь пуста, иначе возвращает false.
		*/
		bool IsEmpty();
	};

	template<typename T>
	std::ostream& operator << (std::ostream& output, const Queue<T>& queue)
	{
		Queue temporary = queue;
		while (!(temporary.IsEmpty()))
		{
			output << temporary.peek() << " ";
			temporary.dequeue();
		}
		return output;
	}

	template<typename T>
	Queue<T>::Queue():head{ nullptr }, tail{ nullptr }, size{ 0 } {}

	template<typename T>
	Queue<T>::~Queue()
	{
		while (head != nullptr)
		{
			Node* temporary = head;
			head = head->next;
			delete temporary;
		}
	}

	template<typename T>
	Queue<T>::Queue(std::initializer_list<T> list)
	{
		for (auto& value : list)
		{
			enqueue(value);
		}
	}


	template<typename T>
	void Queue<T>::enqueue(const T value)
	{
		Node* lastNode = new Node(value);
		if (size == 0)
		{
			head = tail = lastNode;
		}
		else
		{
			tail->next = lastNode;
			lastNode->previous = tail;
			tail = lastNode;
		}
		++size;
	}

	template<typename T>
	void Queue<T>::dequeue()
	{
		if (size == 0)
		{
			throw std::out_of_range("");
		}
		if (tail == head)
		{
			tail = head = nullptr;
		}
		else
		{
			head = head->next;
			head->previous = nullptr;
		}
		--size;
	}

	template<typename T>
	T Queue<T>::peek()
	{

		if (size == 0)
		{
			throw std::out_of_range("");
		}
		return head->data;
	}

	template<typename T>
	Queue<T>::Queue(const Queue& other)
	{
		Node* temporary = other.head;
		while (temporary != nullptr)
		{
			enqueue(temporary->data);
			temporary = temporary->next;
		}
	}

	template<typename T>
	Queue<T>::Queue(Queue&& other) noexcept
	{
		head = other.head;
		tail = other.tail;
		size = other.size;
		other.head = other.tail = nullptr;
		other.size = 0;
	}

	template<typename T>
	Queue<T>& Queue<T>::operator = (const Queue& other)
	{
		Queue temporary(other);
		std::swap(this->head, temporary.head);
		std::swap(this->tail, temporary.tail);
		std::swap(this->size, temporary.size);
		return *this;
	}

	template<typename T>
	Queue<T>& Queue<T>::operator = (Queue&& other) noexcept
	{
		if (this != &other)
		{
			std::swap(other.head, this->head);
			std::swap(other.tail, this->tail);
			std::exchange(other.size, this->size);
		}
		return *this;
	}

	template<typename T>
	bool Queue<T>::IsEmpty()
	{
		{
			return this->size == 0;
		}
	}
}