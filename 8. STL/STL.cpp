// STL.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

int main()
{
    const vector<string> colors{"red", "green", "white", "blue", "orange", "green", "orange", "black", "purple"};
    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)
    
    // 1) de vector in 2 nieuwe vectoren te splitsen: 1 met alles wat alfabetisch voor 'purple' komt, 1 met alles er na
    {
        cout << "Opdracht 1: " << '\n';

        auto colorsCopy = colors;
        sort(begin(colorsCopy), end(colorsCopy));
        auto purple = find(colorsCopy.begin(), colorsCopy.end(), "purple");

        cout << "Split 1: ";
        for( auto it = colorsCopy.begin(); it < purple; ++it )
            cout << *it << ", ";
        cout << '\n';

        cout << "Split 2: ";
        for( auto it = purple + 1; it < colorsCopy.end(); ++it )
            cout << *it << ", ";
        cout << '\n';

        cout << endl;
    }

    // 2) alle elementen UPPERCASE te maken.
    {
        cout << "Opdracht 2: " << '\n';

        auto colorsCopy = colors;
        transform(colorsCopy.begin(), colorsCopy.end(), colorsCopy.begin(), [](string s)
            {
                transform(s.begin(), s.end(), s.begin(), ::toupper);
                return s;
            }
        );

        for( const auto& color : colorsCopy )
            cout << color << ", ";
        cout << '\n';

        cout << endl;
    }

    // 3) alle dubbele te verwijderen
    {
        cout << "Opdracht 3: " << '\n';

        auto colorsCopy = colors;
        auto end = colorsCopy.end();
        for( auto it = colorsCopy.begin(); it < end; ++it )
            end = remove(it + 1, end, *it);
        colorsCopy.erase(end, colorsCopy.end());

        for( const auto& color : colorsCopy )
            cout << color << ", ";
        cout << '\n';

        cout << endl;
    }

    const vector<double> numbers{10, 324422, 6, -23, 234.5, 654.1, 3.1242, -9.23, 635};
    // gebruik functies uit <algorithm> en <functional> om (steeds vanuit een ORIGINELE copie van deze vector)

    // 1) alle negatieve elementen te verwijderen
    {
        cout << "Opdracht 4: " << '\n';

        auto numbersCopy = numbers;
        auto end = remove_if(numbersCopy.begin(), numbersCopy.end(), [](double number)
            {
                return number < 0;
            }
        );

        for( auto it = numbersCopy.begin(); it < end; ++it )
            cout << *it << ", ";
        cout << '\n';

        cout << endl;
    }

    // 2) voor alle elementen te bepalen of ze even of oneven zijn
    {
        cout << "Opdracht 5: " << '\n';

        auto numbersCopy = numbers;
        for_each(numbersCopy.begin(), numbersCopy.end(), [](double number)
            {
                string s = ( fmod(number, 2) == 0 ) ? "Even" : "Uneven";
                cout << number << ": " << s << '\n';
            }
        );

        cout << endl;
    }

    // 3) de som, het gemiddelde, en het product van alle getallen te berekenen
    {
        cout << "Opdracht 6: " << '\n';

        auto numbersCopy = numbers;
        double sum = accumulate(numbersCopy.begin(), numbersCopy.end(), double(0), plus<double>());
        double average = sum / numbersCopy.size();
        long double product = accumulate(numbersCopy.begin(), numbersCopy.end(), long double(1), multiplies<long double>());
        auto precision = cout.precision();
        cout.precision(10);
        cout << "Sum:     " << sum      << '\n';
        cout.precision(9);
        cout << "Average:  " << average  << '\n';
        cout.precision(32);
        cout << "Product: " << product  << '\n';
        cout.precision(precision);

        cout << endl;
    }

	return 0;
}
