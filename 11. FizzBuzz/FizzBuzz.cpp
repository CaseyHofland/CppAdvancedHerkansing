// FizzBuzz.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <chrono>
#include <string>
#include <sstream> 
#include "keep_last_char_outbuf.h"
using namespace std; 
using namespace chrono; // I am aware of the controversy of using namespaces in c++, but in small, 
                        // short-term prototypes they are hard to resist.

const int numbers = 100; // The only time I use magic numbers is if we are dealing with a fixed mathematical
                        // standard (e.g. 360 degrees, 12 hours and 65535 bits (although there I would write
                        // it like 2^16)).
                        //
                        // Note how I'm not using capital letters to define my const name with. Capitalization
                        // of names like that was useful in the past to display a variables' purpose; however
                        // modern day code editors all use IntelliSense to display valid List Members and
                        // their parameter information, including their declaration. Therefor the 
                        // capitalization has become obselete, in which case I prefer the normal CamelCasing 
                        // rules to keep things simple to understand, and to prevent the use of underscores.
                        //
                        // Fuck underscores.
                        //
                        // There was bound to be emotion over preferences in here somewhere.

// I try to avoid the use of /* */ when writing comments (though I can't always help myself when debugging).
// I give preference over ctrl+k -> ctrl+c, which single line comments everything selected. This is to avoid
// the error of double block commenting.
// Like this:
// 
// 1 /* - Start block comment
// 2    THIS TEXT IS NOW A COMMENT
// 3    /* - New block comment undetected because it is a comment
// 4        THIS TEXT IS ALSO A COMMENT
// 5    */ - End block comment on line 1
// 6    !!! THIS TEXT IS NOT A COMMENT !!!
// 7 */ - Unknown command, compiler error

// Solutions are timed without logging the results to the console, as that is the expensive part of the program and
// not the part I can do anything about to optimize (or rather, optimizing that is not todays focus).
// Note that depending on your cpu / current setup, you may experience different speeds than I did.
void TimeSolution(void (*solution)(), int iterations = 1000) 
{
    cout.setstate(ios_base::failbit);
    auto begin = steady_clock::now();
    
    for( int t = 0; t < iterations; ++t )
        solution();

    auto end = std::chrono::steady_clock::now();
    cout.clear();

    cout << iterations << " iterations" << endl;
    cout << "Average Time = " << duration_cast<microseconds>( end - begin ).count() / iterations << "[µs]" << endl;
    cout << "               " << duration_cast<nanoseconds> ( end - begin ).count() / iterations << "[ns]" << endl;
}

// First Solution:
// As simple as it gets. No trickery, no coder-crazy optimations, just a very reasonable solution to a
// very simple problem. I hate recursion though, so even here I made sure that nothing is stored 
// unnecessarily and no operations are run twice. It turned out to be easier to start writing the actual
// string, then only check afterwards if we have written anything to the string and if we hadn't, return
// the number.
void SolutionOne() 
{
    for( int i = 1; i < numbers + 1; ++i )
    {
        string s{};
        if( i % 3 == 0 )
            s = "Fizz";
        if( i % 5 == 0 )
            s += "Buzz";

        cout << ( s.empty() ? to_string(i) : s ) << '\n'; // endl flushes the stream for you and since we are
                                                        // stuck in a linear for loop it is more efficient to
                                                        // create new lines via Unicode and only flush after 
                                                        // we're done.
    }
    cout << flush;
}
// On a 1000 iterations without logging, this solution returns speeds of ~400 to ~380 microseconds

// Second Solution:
// Alright, lets crank it up. I want have the most optimized way of writing the results. I want to do this by never
// actually storing the result, but rather assigning the value inside the stream itself. Unfortunately I'm going to
// have to cheat a little bit where good practices are concerned, as I do need to use the same code twice here to
// fit it inside a ternary operator, but never will it be RUN twice for a single evaluation.
void SolutionTwo() 
{
    for( int i = 1; i < numbers + 1; ++i )
        cout << (i % 3 == 0 ? ( i % 5 == 0 ? "FizzBuzz" : "Fizz" ) : ( i % 5 == 0 ? "Buzz" : to_string(i))) << '\n';
    cout << flush;
}
// On a 1000 iterations without logging, this solution is about ~10 to ~30 microseconds faster than solution 1
// This results in speeds from ~390 to ~350 microseconds

// Third Solution:
// There was one thing that still bothered me very much about the calculation and that was that I had to expensively
// convert my ints to a string, where I would rather just print the value as is. After first struggling to change my
// ternary operator into something that could return different types (didn't work) and then seeing how I could convert
// my numbers into char* (still required string conversion), I hit on something much simpler; just do that shit manually
// using ASCII codes! It sounds stupid easy, but that's exactly why I wasn't thinking about it. No one would do this in
// any functional program unless they were VEEEERY paranoid about performance... so there's that.
void SolutionThree() 
{
    for( int i = 1; i < numbers + 1; ++i )
        cout << ( i % 3 == 0 ? ( i % 5 == 0 ? "FizzBuzz" : "Fizz" ) : ( i % 5 == 0 ? "Buzz" : new char[3]{ (i > 9 ? char(48 + (int)(i / 10)) : '\10'), char(48 + i % 10), '\0' } ) ) << '\n';
    cout << flush;
}
// This is a big one...
// On a 1000 iterations without logging, this solution is about ~240 to ~280 microseconds faster than solution 1
// This results in speeds from ~160 to ~100 microseconds

// Fourth Solution:
// I think this is the one. If this isn't the perfect FizzBuzz solution, then you are likely coding a better one in assembly.
// Of course it still bothered me that I was using a web of ternary operators that had recursion in them. And I still wanted,
// ideally, to just log the number instead of converting it. When I then looked back at my first solution, I realised I had
// gone at this problem all wrong. I don't have to maintain a string value, never had to. I could simply directly output a
// string without starting a new line until the output was 'finished'. This also meant that I could simply log the number
// directly instead of doing some conversion first!
// Only thing left was a way off knowing if I should log a number or not. Now I 'could' have gone for a much simpler approach
// of throwing some else statements into the loop, but I wouldn't stand for that! That would mean repeating myself and doing a
// calculation I had already done the same over! I needed something that specifically handled this case. So I searched far and
// wide how I could read from my output stream. I quickly realised I only really needed the last character from my stream, and
// on a forgotten post on stackoverflow found this weird script that I'm still not quite sure of how it works. The point is; it
// works.
// After some cleanup and an EXTREMELY dirty solution for catching the first character... well, don't blink.
void SolutionFour()
{
    auto cbuf = cout.rdbuf(); // back up cout's streambuf
    auto state = cout.flags(); // back up cout's state
    keep_last_char_outbuf keep_last_buf(cout.rdbuf()); // assign your streambuf to cout
    cout.rdbuf(&keep_last_buf);
    cout.setstate(state);

    cout << 1 << '\n'; // I hate this, but the dream of optimization is too big...
    for( int i = 2; i < numbers + 1; ++i )
    {
        if( i % 3 == 0 )
            cout << "Fizz";
        if( i % 5 == 0 )
            cout << "Buzz";
        if( keep_last_buf.get_last_char() == '\n' ) // I realise I also need to check for /r here, but again I'm ommiting quality
            cout << i;                              // in favor of performance. Please forgive me (but just LOOK at the numbers!)
        cout << '\n';
    }
    cout << flush;

    cout.clear();
    cout.rdbuf(cbuf); // restore cout's original streambuf
}
// On a 1000 iterations without logging, this solution is about ~300 to ~325 microseconds faster than solution 1
// This results in speeds from ~100 to ~55 microseconds



// I hope you enjoyed my journey through the FizzBuzz test. It got... kinda out of hand very quickly when I realised that it was
// actually pretty fun. Of course, if you still wanted to optimize it you could create seperate threads or run them in parallel
// jobs, but I'm unfortunately not skilled enough in either of those to do it.
int main()
{
    cout << "Solution One: " << endl;
    TimeSolution(&SolutionOne);
    cout << endl;

    cout << "Solution Two: " << endl;
    TimeSolution(&SolutionTwo);
    cout << endl;

    cout << "Solution Three: " << endl;
    TimeSolution(&SolutionThree);
    cout << endl;

    cout << "Solution Four: " << endl;
    TimeSolution(&SolutionFour);
    cout << endl;

    // To log the FizzBuzz test, simple uncomment one of the solutions.
    // SolutionOne();
    // SolutionTwo();
    // SolutionThree();
    // SolutionFour();

    return 0;
}



// Kind regards.