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
			langtype* l1 = new langtype;
			In(l1->p, infile);
			infile.close();
			Assert::IsTrue(l1->p.isAbstract == 0);
			Assert::IsTrue(l1->p.year == 2012);
		}
		TEST_METHOD(ProcedureOutTest)
		{
			string outPath = "../../Text_files/procedure_out.txt";
			ofstream output(outPath);
			langtype* l = new langtype;
			l->p.isAbstract = 0;
			l->p.year = 1997;
			Out(l->p, output);
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
			langtype* l1 = new langtype;
			In(l1->o, infile);
			infile.close();

			Assert::IsTrue(l1->o.inheritance == l1->o.multiple);
			Assert::IsTrue(l1->o.year == 1998);
		}
		TEST_METHOD(ObjectorientedOutTest)
		{
			string outPath = "../../Text_files/objectoriented_out.txt";
			ofstream output(outPath);
			langtype* l = new langtype;
			l->o.inheritance = l->o.once;
			l->o.year = 1988;
			Out(l->o, output);
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
			langtype* l1 = new langtype;
			In(l1->f, infile);
			infile.close();
			Assert::IsTrue(l1->f.typification == l1->f.strict);
			Assert::IsTrue(l1->f.isLazyCalculations == 0);
			Assert::IsTrue(l1->f.year == 2008);
		}
		TEST_METHOD(FunctionalOutTest)
		{
			string outPath = "../../Text_files/functional_out.txt";
			ofstream output(outPath);
			langtype* l = new langtype;
			l->f.typification = l->f.dynamic;
			l->f.year = 2019;
			l->f.isLazyCalculations = 1;
			Out(l->f, output);
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
			langtype* l = new langtype;
			l = In(infile);
			infile.close();
			Assert::IsTrue(l->p.year == 2012);
			Assert::IsTrue(l->mentions == 1);
			Assert::IsTrue(l->p.isAbstract == 0);
		}
		TEST_METHOD(LangtypeOutTest)
		{
			string outPath = "../../Text_files/langtype_Out.txt";
			ofstream output(outPath);
			langtype* l = new langtype;
			l->k = 1;
			l->p.isAbstract = 1;
			l->p.year = 2010;
			l->mentions = 5;
			Out(*l, output);
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
			langtype* l = new langtype;
			l->k = 1;
			l->p.year = 2019;
			Assert::IsTrue(AmountOfYears(*l) == 1);
		}
		TEST_METHOD(LangtypeCompareTest)
		{
			langtype* l = new langtype;
			l->k = 1;
			l->p.year = 2019;
			langtype* l1 = new langtype;
			l1->p.year = 2020;
			Assert::IsTrue(Compare(l, l1) == false);
		}
	};
	TEST_CLASS(ContainerTests)
	{
		TEST_METHOD(ContainerInitVecTest)
		{
			container c;
			InitVec(c);
			Assert::IsTrue(c.list.Head == NULL);
			Assert::IsTrue(c.list.Tail == NULL);
			Assert::IsTrue(c.list.size == 0);
		}
		TEST_METHOD(ContainerClearTest)
		{
			langtype* l = new langtype;
			container::List list;
			container::List::Node* node = new container::List::Node;
			node->l = l;
			node->Next = NULL;
			node->Prev = NULL;
			list.Head = node;
			list.Tail = node;
			list.size = 1;
			container c;
			c.list = list;
			Clear(c);
			Assert::IsTrue(c.list.Head == NULL);
			Assert::IsTrue(c.list.Tail == NULL);
			Assert::IsTrue(c.list.size == 0);
		}
		TEST_METHOD(ContainerInTest)
		{
			string inPath = "../../Text_files/container_In.txt";
			container c;
			ifstream infile(inPath);
			InitVec(c);
			InVec(c, infile);
			infile.close();
			Assert::IsTrue(c.list.size == 2);

			Assert::IsTrue(c.list.Head->l->mentions == 1);
			Assert::IsTrue(c.list.Head->l->p.year == 2012);
			langtype* l = c.list.Head->l;
			Assert::IsTrue(l->p.isAbstract == 0);
			langtype* l1 = c.list.Head->Next->l;

			Assert::IsTrue(c.list.Head->Next->l->mentions == 2);
			Assert::IsTrue(c.list.Head->Next->l->o.year == 1998);
			Assert::IsTrue(l1->o.inheritance == l1->o.multiple);

			Assert::IsTrue(c.list.Head->Next->Next->l == l);
			Assert::IsTrue(c.list.Head->Prev->l == l1);
		}
		TEST_METHOD(ContainerOutTest)
		{
			string inPath = "../../Text_files/container_In.txt";
			container c;
			ifstream infile(inPath);
			InitVec(c);
			InVec(c, infile);
			infile.close();
			string outPath = "../../Text_files/container_Out.txt";
			ofstream output(outPath);
			OutVec(c, output);
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
			container c;
			ifstream infile(inPath);
			InitVec(c);
			InVec(c, infile);
			infile.close();
			string outPath = "../../Text_files/container_SortedOut.txt";
			ofstream output(outPath);
			Sort(c);
			OutVec(c, output);
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
			container c;
			ifstream infile(inPath);
			InitVec(c);
			InVec(c, infile);
			infile.close();
			string outPath = "../../Text_files/container_OutProcedure.txt";
			ofstream output(outPath);
			Sort(c);
			OutProcedure(c, output);
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
