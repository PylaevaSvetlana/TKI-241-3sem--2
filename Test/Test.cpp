#include "pch.h"
#include "CppUnitTest.h"
#include "..\Solver\Queue.h"
#include "..\ClassTest\Vector.h"
#include "..\ClassTest\Point.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{
	TEST_CLASS(QueueTest)
	{
	public:

		TEST_METHOD(EnqueueInt_ValidData_Success)
		{
			Queue::Queue<int> queue;
			queue.enqueue(5);
			Assert::AreEqual(queue.peek(), 5);
		}

		TEST_METHOD(EnqueueInt_ValidData_Fail)
		{
			Queue::Queue<int> queue;
			queue.enqueue(5);
			Assert::AreNotEqual(queue.peek(), 3);
		}

		TEST_METHOD(DequeueInt_ValidData_Success)
		{
			Queue::Queue<int> queue{ 1,2,3,4,5 };
			queue.dequeue();
			Assert::AreEqual(queue.peek(), 2);
		}

		TEST_METHOD(DequeueInt_ValidData_Fail)
		{
			Queue::Queue<int> queue{ 1,2,3,4,5 };
			queue.dequeue();
			Assert::AreNotEqual(queue.peek(), 3);
		}

		TEST_METHOD(СopyСonstructorInt_ValidData_Success)
		{
			Queue::Queue<int> queue1{ 1,2,3 }, queue2(queue1);
			Assert::AreEqual(queue1.peek(), queue2.peek());
			queue1.dequeue();
			queue2.dequeue();
			Assert::AreEqual(queue1.peek(), queue2.peek());
			queue1.dequeue();
			queue2.dequeue();
			Assert::AreEqual(queue1.peek(), queue2.peek());
		}

		TEST_METHOD(MoveConstructorInt_ValidData_Success)
		{
			Queue::Queue<int> queue1{ 1,2,3 }, queue2 = queue1, queue3(std::move(queue2));
			Assert::AreEqual(queue1.peek(), queue3.peek());
			queue1.dequeue();
			queue3.dequeue();
			Assert::AreEqual(queue1.peek(), queue3.peek());
			queue1.dequeue();
			queue3.dequeue();
			Assert::AreEqual(queue1.peek(), queue3.peek());
		}

		TEST_METHOD(OperatorEqualCopyingInt_ValidData_Success)
		{
			Queue::Queue<int> queue1{ 1,2,3 }, queue2 = queue1;
			Assert::AreEqual(queue1.peek(), queue2.peek());
			queue1.dequeue();
			queue2.dequeue();
			Assert::AreEqual(queue1.peek(), queue2.peek());
			queue1.dequeue();
			queue2.dequeue();
			Assert::AreEqual(queue1.peek(), queue2.peek());
		}

		TEST_METHOD(OperatorEqualMovingInt_ValidData_Success)
		{
			Queue::Queue<int> queue1{ 1,2,3 }, queue2 = queue1, queue3 = std::move(queue2);
			Assert::AreEqual(queue1.peek(), queue3.peek());
			queue1.dequeue();
			queue3.dequeue();
			Assert::AreEqual(queue1.peek(), queue3.peek());
			queue1.dequeue();
			queue3.dequeue();
			Assert::AreEqual(queue1.peek(), queue3.peek());
		}

		TEST_METHOD(EnqueueDouble_ValidData_Success)
		{
			Queue::Queue<double> queue;
			queue.enqueue(5.5);
			Assert::AreEqual(queue.peek(), 5.5);
		}

		TEST_METHOD(EnqueueDouble_ValidData_Fail)
		{
			Queue::Queue<double> queue;
			queue.enqueue(5.5);
			Assert::AreNotEqual(queue.peek(), 3.3);
		}

		TEST_METHOD(DequeueDouble_ValidData_Success)
		{
			Queue::Queue<double> queue{ 1.1,2.2,3.3,4.4,5.5 };
			queue.dequeue();
			Assert::AreEqual(queue.peek(), 2.2);
		}

		TEST_METHOD(DequeueDouble_ValidData_Fail)
		{
			Queue::Queue<double> queue{ 1.1,2.2,3.3,4.4,5.5 };
			queue.dequeue();
			Assert::AreNotEqual(queue.peek(), 3.3);
		}

		TEST_METHOD(СopyСonstructorDouble_ValidData_Success)
		{
			Queue::Queue<double> queue1{ 1.1,2.2,3.3 }, queue2(queue1);
			Assert::AreEqual(queue1.peek(), queue2.peek());
			queue1.dequeue();
			queue2.dequeue();
			Assert::AreEqual(queue1.peek(), queue2.peek());
			queue1.dequeue();
			queue2.dequeue();
			Assert::AreEqual(queue1.peek(), queue2.peek());
		}

		TEST_METHOD(MoveConstructorDouble_ValidData_Success)
		{
			Queue::Queue<double> queue1{ 1.1,2.2,3.3 }, queue2 = queue1, queue3(std::move(queue2));
			Assert::AreEqual(queue1.peek(), queue3.peek());
			queue1.dequeue();
			queue3.dequeue();
			Assert::AreEqual(queue1.peek(), queue3.peek());
			queue1.dequeue();
			queue3.dequeue();
			Assert::AreEqual(queue1.peek(), queue3.peek());
		}

		TEST_METHOD(OperatorEqualCopyingDouble_ValidData_Success)
		{
			Queue::Queue<double> queue1{ 1.1,2.2,3.3 }, queue2 = queue1;
			Assert::AreEqual(queue1.peek(), queue2.peek());
			queue1.dequeue();
			queue2.dequeue();
			Assert::AreEqual(queue1.peek(), queue2.peek());
			queue1.dequeue();
			queue2.dequeue();
			Assert::AreEqual(queue1.peek(), queue2.peek());
		}

		TEST_METHOD(OperatorEqualMovingDouble_ValidData_Success)
		{
			Queue::Queue<double> queue1{ 1.1,2.2,3.3 }, queue2 = queue1, queue3 = std::move(queue2);
			Assert::AreEqual(queue1.peek(), queue3.peek());
			queue1.dequeue();
			queue3.dequeue();
			Assert::AreEqual(queue1.peek(), queue3.peek());
			queue1.dequeue();
			queue3.dequeue();
			Assert::AreEqual(queue1.peek(), queue3.peek());
		}
		TEST_METHOD(EnqueueString_ValidData_Success)
		{
			Queue::Queue < std::string > queue;
			queue.enqueue("abc");
			std::string word = "abc";
			Assert::AreEqual(queue.peek(), word);
		}

		TEST_METHOD(EnqueueString_ValidData_Fail)
		{
			Queue::Queue<std::string> queue;
			queue.enqueue("abc");
			std::string word = "cbd";
			Assert::AreNotEqual(queue.peek(), word);
		}

		TEST_METHOD(DequeueString_ValidData_Success)
		{
			Queue::Queue<std::string> queue{ "a","b","c","d","e"};
			queue.dequeue();
			std::string word = "b";
			Assert::AreEqual(queue.peek(), word);
		}

		TEST_METHOD(DequeueString_ValidData_Fail)
		{
			Queue::Queue<std::string> queue{ "a","b","c","d","e" };
			queue.dequeue();
			std::string word = "c";
			Assert::AreNotEqual(queue.peek(), word);
		}

		TEST_METHOD(СopyСonstructorString_ValidData_Success)
		{
			Queue::Queue<std::string> queue1{ "a","b","c" }, queue2(queue1);
			Assert::AreEqual(queue1.peek(), queue2.peek());
			queue1.dequeue();
			queue2.dequeue();
			Assert::AreEqual(queue1.peek(), queue2.peek());
			queue1.dequeue();
			queue2.dequeue();
			Assert::AreEqual(queue1.peek(), queue2.peek());
		}

		TEST_METHOD(MoveConstructorString_ValidData_Success)
		{
			Queue::Queue<std::string> queue1{ "a","b","c" }, queue2 = queue1, queue3(std::move(queue2));
			Assert::AreEqual(queue1.peek(), queue3.peek());
			queue1.dequeue();
			queue3.dequeue();
			Assert::AreEqual(queue1.peek(), queue3.peek());
			queue1.dequeue();
			queue3.dequeue();
			Assert::AreEqual(queue1.peek(), queue3.peek());
		}

		TEST_METHOD(OperatorEqualCopyingString_ValidData_Success)
		{
			Queue::Queue<std::string> queue1{ "a","b","c" }, queue2 = queue1;
			Assert::AreEqual(queue1.peek(), queue2.peek());
			queue1.dequeue();
			queue2.dequeue();
			Assert::AreEqual(queue1.peek(), queue2.peek());
			queue1.dequeue();
			queue2.dequeue();
			Assert::AreEqual(queue1.peek(), queue2.peek());
		}

		TEST_METHOD(OperatorEqualMovingString_ValidData_Success)
		{
			Queue::Queue<std::string> queue1{ "a","b","c" }, queue2 = queue1, queue3 = std::move(queue2);
			Assert::AreEqual(queue1.peek(), queue3.peek());
			queue1.dequeue();
			queue3.dequeue();
			Assert::AreEqual(queue1.peek(), queue3.peek());
			queue1.dequeue();
			queue3.dequeue();
			Assert::AreEqual(queue1.peek(), queue3.peek());
		}

		TEST_METHOD(EnqueueVector_ValidData_Success)
		{
			Queue::Queue<Vector::Vector> queue;
			Point::Point a(0, 0, 0);
			Point::Point b(1,1,1);
			Vector::Vector vector(a, b);
			queue.enqueue(vector);
			Assert::IsTrue(queue.peek() == vector);
		}

		TEST_METHOD(DequeueVector_ValidData_Success)
		{
			Point::Point a1(0, 0, 0);
			Point::Point b1(1, 1, 1);
			Vector::Vector vector1(a1,b1);
			Point::Point a2(0, 0, 0);
			Point::Point b2(1, 1, 1);
			Vector::Vector vector2(a2,b2);
			Point::Point a3(0, 0, 0);
			Point::Point b3(1, 1, 1);
			Vector::Vector vector3(a3,b3);
			Queue::Queue<Vector::Vector> queue{ vector1,vector2,vector3 };
			queue.dequeue();
			Assert::IsTrue(queue.peek() == vector2);
		}

		TEST_METHOD(СopyСonstructorVector_ValidData_Success)
		{
			Point::Point a1(0, 0, 0);
			Point::Point b1(1, 1, 1);
			Vector::Vector vector1(a1, b1);
			Point::Point a2(0, 0, 0);
			Point::Point b2(1, 1, 1);
			Vector::Vector vector2(a2, b2);
			Point::Point a3(0, 0, 0);
			Point::Point b3(1, 1, 1);
			Vector::Vector vector3(a3, b3);
			Queue::Queue<Vector::Vector> queue1{ vector1,vector2,vector3 }, queue2(queue1);
			Assert::IsTrue(queue1.peek() == queue2.peek());
			queue1.dequeue();
			queue2.dequeue();
			Assert::IsTrue(queue1.peek() == queue2.peek());
			queue1.dequeue();
			queue2.dequeue();
			Assert::IsTrue(queue1.peek() == queue2.peek());
		}

		TEST_METHOD(MoveConstructorVector_ValidData_Success)
		{
			Point::Point a1(0, 0, 0);
			Point::Point b1(1, 1, 1);
			Vector::Vector vector1(a1, b1);
			Point::Point a2(0, 0, 0);
			Point::Point b2(1, 1, 1);
			Vector::Vector vector2(a2, b2);
			Point::Point a3(0, 0, 0);
			Point::Point b3(1, 1, 1);
			Vector::Vector vector3(a3, b3);
			Queue::Queue<Vector::Vector> queue1{ vector1,vector2,vector3 }, queue2 = queue1, queue3(std::move(queue2));
			Assert::IsTrue(queue1.peek() == queue3.peek());
			queue1.dequeue();
			queue3.dequeue();
			Assert::IsTrue(queue1.peek() == queue3.peek());
			queue1.dequeue();
			queue3.dequeue();
			Assert::IsTrue(queue1.peek() == queue3.peek());
		}

		TEST_METHOD(OperatorEqualCopyingVector_ValidData_Success)
		{
			Point::Point a1(0, 0, 0);
			Point::Point b1(1, 1, 1);
			Vector::Vector vector1(a1, b1);
			Point::Point a2(0, 0, 0);
			Point::Point b2(1, 1, 1);
			Vector::Vector vector2(a2, b2);
			Point::Point a3(0, 0, 0);
			Point::Point b3(1, 1, 1);
			Vector::Vector vector3(a3, b3);
			Queue::Queue<Vector::Vector> queue1{ vector1,vector2,vector3 }, queue2 = queue1;
			Assert::IsTrue(queue1.peek() == queue2.peek());
			queue1.dequeue();
			queue2.dequeue();
			Assert::IsTrue(queue1.peek() == queue2.peek());
			queue1.dequeue();
			queue2.dequeue();
			Assert::IsTrue(queue1.peek() == queue2.peek());
		}

		TEST_METHOD(OperatorEqualMovingVector_ValidData_Success)
		{

			Point::Point a1(0, 0, 0);
			Point::Point b1(1, 1, 1);
			Vector::Vector vector1(a1, b1);
			Point::Point a2(0, 0, 0);
			Point::Point b2(1, 1, 1);
			Vector::Vector vector2(a2, b2);
			Point::Point a3(0, 0, 0);
			Point::Point b3(1, 1, 1);
			Vector::Vector vector3(a3, b3);
			Queue::Queue<Vector::Vector> queue1{ vector1,vector2,vector3 }, queue2 = queue1, queue3(std::move(queue2));
			Assert::IsTrue(queue1.peek() == queue3.peek());
			queue1.dequeue();
			queue3.dequeue();
			Assert::IsTrue(queue1.peek() == queue3.peek());
			queue1.dequeue();
			queue3.dequeue();
			Assert::IsTrue(queue1.peek() == queue3.peek());
		}
		
	};
}