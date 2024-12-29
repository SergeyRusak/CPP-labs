#include <iostream>
#include <vector>
#include <list>
#include <random>
#include "rational.h"
using namespace std;
int main() {
   

    std::random_device rd;  // a seed source for the random number engine
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> rational_distrib(-100, 100);
    std::uniform_int_distribution<> vector_distrib(500, 1000);


    cout << "1. ";
    int vector_size = vector_distrib(gen);
    vector<Rational> v1;
    for (int i = 0; i < vector_size; ++i) {
        int n = rational_distrib(gen);
        int d = rational_distrib(gen);
        while( d == 0 ) d = rational_distrib(gen);
        v1.emplace_back(Rational(n,d));
    }
    cout << "Created vector v1 with size " << vector_size << endl;
    cout << "2. ";
    vector<Rational> v2(v1.end() - 200, v1.end());
    v1.erase(v1.end() - 200, v1.end());
    cout << "Created vector v2 from least 200 elements of v1" << endl;
    cout << "3. ";
    uniform_int_distribution<int> dist_n1(20, 50);
    int n1 = dist_n1(gen);

    partial_sort(v1.begin(), v1.begin() + n1, v1.end(), [](Rational& a, const Rational& b) {
        return a > b;
        });

    list<Rational> list1(v1.begin(), v1.begin() + n1);
    v1.erase(v1.begin(), v1.begin() + n1);
    cout << "Created list1 with " << n1 << " max elements of v1" << endl;
    cout << "4. ";
    uniform_int_distribution<int> dist_n2(20, 50);
    int n2 = dist_n2(gen);

    partial_sort(v2.begin(), v2.begin() + n2, v2.end(), [](Rational& a, const Rational& b) {
        return a < b;
        });

    list<Rational> list2(v2.begin(), v2.begin() + n2);
    v2.erase(v2.begin(), v2.begin() + n2);
    cout << "Created list2 with " << n2 << " least elements of v2" << endl;
    cout << "6. ";
    double average_value = accumulate(list1.begin(), list1.end(), 0.0, [](double sum, const Rational& item) {
        return sum + Rational::toDecimal(item);
        }) / list1.size();

    cout << "Average value of list1: " << average_value << endl;

    list1.sort([average_value](Rational& a, const Rational& b) {
        return a > b;
        });

    list<Rational> greater_than_average;
    for (auto it = list1.begin(); it != list1.end(); ) {
        if (it->toDecimal() > average_value) {
            greater_than_average.push_back(*it);
            it = list1.erase(it);
        }
        else {
            ++it;
        }
    }

    list1.splice(list1.begin(), greater_than_average);
    cout << "list1 reordered. First elements are greather than average" << endl;
    cout << "7. ";
    list2.remove_if([](const Rational& item) {
        return abs((int) Rational::toDecimal(item)) > 1;
        });

    cout << "Removed items from list2, where numerator greather then denominator" << endl;
    cout << "8. ";
    vector<Rational> v3;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(v3));
    cout << "Created vector v3 and filled with intersection v1 and v2" << endl;
    cout << "9. ";
    int size_diff = abs((int)list1.size() - (int)list2.size());

    if (list1.size() > list2.size())
        list1.erase(list1.begin(), next(list1.begin(), size_diff));
    else if (list2.size() > list1.size())
        list2.erase(list2.begin(), next(list2.begin(), size_diff));

    list<pair<Rational, Rational>> list3;
    transform(list1.begin(), list1.end(), list2.begin(), back_inserter(list3), [](const Rational& a, const Rational& b)
        {
            return make_pair(a, b);
        });

    cout << "Created list3 with pairs of list1 and list2:" << endl;
    int C = 1;
    for_each(list3.begin(), list3.end(), [&C](const pair<Rational, Rational>& pair)
        {
            cout << '[' << C << "] Pair: " << ' ' << pair.first << ' ' << pair.second <<  endl;
            C++;
        });

    size_t min_size = min(v1.size(), v2.size());
    list<pair<Rational, Rational>> list4;
    transform(v1.begin(), v1.begin() + min_size, v2.begin(), back_inserter(list4), [](const Rational& a, const Rational& b)
        {
            return make_pair(a, b);
        });
    cout << "10. ";
    cout << "Created list3 with pairs of list1 and list2 without size normalize" << endl;



    return 0;
}
