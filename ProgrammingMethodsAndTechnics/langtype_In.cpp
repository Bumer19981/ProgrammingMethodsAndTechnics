#include <fstream>
#include "langtype_atd.h"
#include <string>
using namespace std;
namespace simple_langtypes {
    //void In(langtype::procedure& p, ifstream& ist);
    //void In(langtype::objectoriented& o, ifstream& ist);
    //void In(langtype::functional& f, ifstream& ist);
    langtype* In(ifstream& ifst)
    {
        langtype* l;
        int k;

        string line;
        getline(ifst, line);
        int words = 0;
        string array[1];
        for (int i = 0; i < line.length(); ++i) {

            if (line[i] == ' ' && line[i + 1] != '\0') {
                words += 1;
            }
        }
        if (words > 0 || words < 0)
        {
            throw std::invalid_argument("Error: wrong amount of params in langtype object!");
        }
        words = 0;
        for (int i = 0; i < line.length(); ++i) {

            if (line[i] == ' ' && line[i + 1] != '\0') {
                words += 1;
                i += 1;
            }
            array[words] += line[i];
            if (line[i] == ' ') {
                throw std::invalid_argument("Error: additional space char in langtype object!");
            }
        }
        if (array[0] != "1" && array[0] != "2" && array[0] != "3") {
            throw std::invalid_argument("Error: unknown langtype!");
        }

        k = stoi(array[0]);;

        if (k == 1) {
            l = new langtype;
            l->k = 1;
            In(l->p, ifst);
            getline(ifst, line);
            words = 0;
            string array1[1];
            for (int i = 0; i < line.length(); ++i) {

                if (line[i] == ' ' && line[i + 1] != '\0') {
                    words += 1;
                }
            }
            if (words > 0 || words < 0)
            {
                throw std::invalid_argument("Error: wrong amount of params in langtype mentions!");
            }
            words = 0;
            for (int i = 0; i < line.length(); ++i) {

                if (line[i] == ' ' && line[i + 1] != '\0') {
                    words += 1;
                    i += 1;
                }
                array1[words] += line[i];
                if (line[i] == ' ') {
                    throw std::invalid_argument("Error: additional space char in langtype mentions!");
                }
            }
            try {
                l->mentions = stoi(array1[0]);
                if (stoi(array1[0]) < 0) {
                    throw std::invalid_argument("!");
                }
            }
            catch (exception & e) {
                throw std::invalid_argument("Error: langtype mentions should be a positive number!");
            }
            return l;
        }
        else if (k == 2) {
            l = new langtype;
            l->k = 2;
            In(l->o, ifst);
            getline(ifst, line);
            words = 0;
            string array1[1];
            for (int i = 0; i < line.length(); ++i) {

                if (line[i] == ' ' && line[i + 1] != '\0') {
                    words += 1;
                }
            }
            if (words > 0 || words < 0)
            {
                throw std::invalid_argument("Error: wrong amount of params in langtype mentions!");
            }
            words = 0;
            for (int i = 0; i < line.length(); ++i) {

                if (line[i] == ' ' && line[i + 1] != '\0') {
                    words += 1;
                    i += 1;
                }
                array1[words] += line[i];
                if (line[i] == ' ') {
                    throw std::invalid_argument("Error: additional space char in langtype mentions!");
                }
            }
            try {
                l->mentions = stoi(array1[0]);
                if (stoi(array1[0]) < 0) {
                    throw std::invalid_argument("!");
                }
            }
            catch (exception & e) {
                throw std::invalid_argument("Error: langtype mentions should be a positive number!");
            }
            return l;
        }
        else if (k == 3) {
            l = new langtype;
            l->k = 3;
            In(l->f, ifst);
            getline(ifst, line);
            words = 0;
            string array1[1];
            for (int i = 0; i < line.length(); ++i) {

                if (line[i] == ' ' && line[i + 1] != '\0') {
                    words += 1;
                }
            }
            if (words > 0 || words < 0)
            {
                throw std::invalid_argument("Error: wrong amount of params in langtype mentions!");
            }
            words = 0;
            for (int i = 0; i < line.length(); ++i) {

                if (line[i] == ' ' && line[i + 1] != '\0') {
                    words += 1;
                    i += 1;
                }
                array1[words] += line[i];
                if (line[i] == ' ') {
                    throw std::invalid_argument("Error: additional space char in langtype mentions!");
                }
            }
            try {
                l->mentions = stoi(array1[0]);
                if (stoi(array1[0]) < 0) {
                    throw std::invalid_argument("!");
                }
            }
            catch (exception & e) {
                throw std::invalid_argument("Error: langtype mentions should be a positive number!");
            }
            return l;
        }
        else{
            return 0;
        }
    }
}