#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include "../ProgrammingMethodsAndTechnics/container_atd.h"
#include "../ProgrammingMethodsAndTechnics/langtype_atd.h"

using namespace simple_langtypes;
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProgrammingMethodsAndTechnicsTests
{
	TEST_CLASS(ProcedureTests)
	{
	public:
		TEST_METHOD(ProcedureInDataTest)
		{
			string inputPath = "../../Text_files/procedure_in.txt";
			ifstream infile(inputPath);
			Langtype* l1 = new Langtype;
			in(l1->p, infile);
			infile.close();
			Assert::IsTrue(l1->p.isAbstract == 0);
			Assert::IsTrue(l1->p.year == 2012);
		}
		TEST_METHOD(ProcedureOutTest)
		{
			string outPath = "../../Text_files/procedure_out.txt";
			ofstream output(outPath);
			Langtype* l = new Langtype;
			l->p.isAbstract = 0;
			l->p.year = 1997;
			out(l->p, output);
			output.close();
			ifstream infile(outPath);
			std::stringstream buffer;
			buffer << infile.rdbuf();
			string result = buffer.str();
			string ideal = "It is a procedure language: is abstract = 0, year = 1997\n";
			Assert::AreEqual(ideal, result);
		}
	};
	TEST_CLASS(ObjectorientedTests)
	{
		TEST_METHOD(ObjectorientedInTest)
		{
			string inputPath = "../../Text_files/objectoriented_in.txt";
			ifstream infile(inputPath);
			Langtype* l1 = new Langtype;
			in(l1->o, infile);
			infile.close();

			Assert::IsTrue(l1->o.inheritance == l1->o.MULTIPLE);
			Assert::IsTrue(l1->o.year == 1998);
		}
		TEST_METHOD(ObjectorientedOutTest)
		{
			string outPath = "../../Text_files/objectoriented_out.txt";
			ofstream output(outPath);
			Langtype* l = new Langtype;
			l->o.inheritance = l->o.ONCE;
			l->o.year = 1988;
			out(l->o, output);
			output.close();
			ifstream infile(outPath);
			std::stringstream buffer;
			buffer << infile.rdbuf();
			string result = buffer.str();
			string ideal = "It is an object-oriented language: inheritance = once, year = 1988\n";
			Assert::AreEqual(ideal, result);

		}
	};
	TEST_CLASS(FunctionalTests)
	{
		TEST_METHOD(FunctionalInDataTest)
		{
			string inputPath = "../../Text_files/functional_in.txt";
			ifstream infile(inputPath);
			Langtype* l1 = new Langtype;
			in(l1->f, infile);
			infile.close();
			Assert::IsTrue(l1->f.typification == l1->f.STRICT);
			Assert::IsTrue(l1->f.isLazyCalculations == 0);
			Assert::IsTrue(l1->f.year == 2008);
		}
		TEST_METHOD(FunctionalOutTest)
		{
			string outPath = "../../Text_files/functional_out.txt";
			ofstream output(outPath);
			Langtype* l = new Langtype;
			l->f.typification = l->f.DYNAMIC;
			l->f.year = 2019;
			l->f.isLazyCalculations = 1;
			out(l->f, output);
			output.close();
			ifstream infile(outPath);
			std::stringstream buffer;
			buffer << infile.rdbuf();
			string result = buffer.str();
			string ideal = "It is a functional language: typification = dinamic, lazy calculations = 1, year = 2019\n";
			Assert::AreEqual(ideal, result);
		}
	};
	TEST_CLASS(LangtypeTests)
	{
		TEST_METHOD(LangtypeInTest)
		{
			string inputPath = "../../Text_files/langtype_in.txt";
			ifstream infile(inputPath);
			Langtype* l = new Langtype;
			l = in(infile);
			infile.close();
			Assert::IsTrue(l->p.year == 2012);
			Assert::IsTrue(l->mentions == 1);
			Assert::IsTrue(l->p.isAbstract == 0);
		}
		TEST_METHOD(LangtypeOutTest)
		{
			string outPath = "../../Text_files/langtype_Out.txt";
			ofstream output(outPath);
			Langtype* l = new Langtype;
			l->k = 1;
			l->p.isAbstract = 1;
			l->p.year = 2010;
			l->mentions = 5;
			out(*l, output);
			output.close();
			ifstream infile(outPath);
			std::stringstream buffer;
			buffer << infile.rdbuf();
			string result = buffer.str();
			string ideal = "It is a procedure language: is abstract = 1, year = 2010\nmentions = 5\n";
			Assert::AreEqual(ideal, result);
		}
		TEST_METHOD(LangtypeAmountOfYearsTest)
		{
			Langtype* l = new Langtype;
			l->k = 1;
			l->p.year = 2019;
			Assert::IsTrue(amountOfYears(*l) == 1);
		}
		TEST_METHOD(LangtypeCompareTest)
		{
			Langtype* l = new Langtype;
			l->k = 1;
			l->p.year = 2019;
			Langtype* l1 = new Langtype;
			l1->p.year = 2020;
			Assert::IsTrue(compare(l, l1) == false);
		}
	};
	TEST_CLASS(ContainerTests)
	{
		TEST_METHOD(ContainerInitVecTest)
		{
			Container c;
			initVec(c);
			Assert::IsTrue(c.list.head == NULL);
			Assert::IsTrue(c.list.tail == NULL);
			Assert::IsTrue(c.list.size == 0);
		}
		TEST_METHOD(ContainerClearTest)
		{
			Langtype* l = new Langtype;
			Container::List list;
			Container::List::Node* node = new Container::List::Node;
			node->l = l;
			node->next = NULL;
			node->prev = NULL;
			list.head = node;
			list.tail = node;
			list.size = 1;
			Container c;
			c.list = list;
			clear(c);
			Assert::IsTrue(c.list.head == NULL);
			Assert::IsTrue(c.list.tail == NULL);
			Assert::IsTrue(c.list.size == 0);
		}
		TEST_METHOD(ContainerInTest)
		{
			string inPath = "../../Text_files/container_In.txt";
			Container c;
			ifstream infile(inPath);
			initVec(c);
			inVec(c, infile);
			infile.close();
			Assert::IsTrue(c.list.size == 2);

			Assert::IsTrue(c.list.head->l->mentions == 1);
			Assert::IsTrue(c.list.head->l->p.year == 2012);
			Langtype* l = c.list.head->l;
			Assert::IsTrue(l->p.isAbstract == 0);
			Langtype* l1 = c.list.head->next->l;

			Assert::IsTrue(c.list.head->next->l->mentions == 2);
			Assert::IsTrue(c.list.head->next->l->o.year == 1998);
			Assert::IsTrue(l1->o.inheritance == l1->o.MULTIPLE);

			Assert::IsTrue(c.list.head->next->next->l == l);
			Assert::IsTrue(c.list.head->prev->l == l1);
		}
		TEST_METHOD(ContainerOutTest)
		{
			string inPath = "../../Text_files/container_In.txt";
			Container c;
			ifstream infile(inPath);
			initVec(c);
			inVec(c, infile);
			infile.close();
			string outPath = "../../Text_files/container_Out.txt";
			ofstream output(outPath);
			outVec(c, output);
			output.close();

			ifstream infile1(outPath);
			std::stringstream buffer;
			buffer << infile1.rdbuf();
			string result = buffer.str();
			string ideal = "Container contents 2 elements.\nIt is a procedure language: is abstract = 0, year = 2012\nmentions = 1\namount of years = 8\nIt is an object-oriented language: inheritance = multiple, year = 1998\nmentions = 2\namount of years = 22\n";
			Assert::AreEqual(ideal, result);
		}
		TEST_METHOD(ContainerSortTest)
		{
			string inPath = "../../Text_files/container_In.txt";
			Container c;
			ifstream infile(inPath);
			initVec(c);
			inVec(c, infile);
			infile.close();
			string outPath = "../../Text_files/container_SortedOut.txt";
			ofstream output(outPath);
			sort(c);
			outVec(c, output);
			output.close();

			ifstream infile1(outPath);
			std::stringstream buffer;
			buffer << infile1.rdbuf();
			string result = buffer.str();
			string ideal = "Container contents 2 elements.\nIt is an object-oriented language: inheritance = multiple, year = 1998\nmentions = 2\namount of years = 22\nIt is a procedure language: is abstract = 0, year = 2012\nmentions = 1\namount of years = 8\n";
			Assert::AreEqual(ideal, result);
		}
		TEST_METHOD(ContainerOutProcedureTest)
		{
			string inPath = "../../Text_files/container_In.txt";
			Container c;
			ifstream infile(inPath);
			initVec(c);
			inVec(c, infile);
			infile.close();
			string outPath = "../../Text_files/container_OutProcedure.txt";
			ofstream output(outPath);
			sort(c);
			outProcedure(c, output);
			output.close();

			ifstream infile1(outPath);
			std::stringstream buffer;
			buffer << infile1.rdbuf();
			string result = buffer.str();
			string ideal = "Only procedure.\n0: \n1: It is a procedure language: is abstract = 0, year = 2012\nmentions = 1\namount of years = 8\n";
			Assert::AreEqual(ideal, result);
		}
	};
}
