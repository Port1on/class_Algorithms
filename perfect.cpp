// TODO: remove and replace this file header comment
// This is a .cpp file you will edit and turn in.
// Remove starter comments and add your own
// comments on each function and on complex code sections.
#include "console.h"
#include <iostream>
#include "testing/SimpleTest.h"
#include "testing/TextUtils.h"
#include "timer.h"
#include "vector.h"
using namespace std;
long smarterSum(long n);



/* This function takes in a number n and calculates the sum
 * of all proper divisors of n, excluding itself.
 *
 * Note: long is a C++ type is a variant of int that allows for a
 * larger range of values. For all intents and purposes, you can
 * treat it like you would an int.
 */
long divisorSum(long n) {
    long total = 0;
    for (long divisor = 1; divisor < n; divisor++) {
        if (n % divisor == 0) {
            total += divisor;
        }
    }
    return total;
}

/* This function is provided a number n and returns a boolean
 * (true/false) value representing whether or not the number is
 * perfect. A perfect number is a non-zero positive number whose
 * sum of its proper divisors is equal to itself.
 */
bool isPerfect (long n) {
    return (n != 0) && (n == smarterSum(n));
}

/* This function performs an exhaustive search for perfect numbers.
 * It takes as input a number called `stop` and searches for perfect
 * numbers between 1 and `stop`. Any perfect numbers that are found will
 * be printed out to the console.
 */
void findPerfects(long stop) {
    for (long num = 1; num < stop; num++) {
        if (isPerfect(num)) {
            cout << "Found perfect number: " << num << endl;
        }
        if (num % 10000 == 0) cout << "." << flush;
    }
    cout << "Done searching up to " << stop << endl;
}

/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
long smarterSum(long n){
    long total = 1;
    for (long divisor = 2; divisor <= sqrt(n); divisor++) {
        if (n % divisor == 0){
            total = total + divisor;
            if (divisor !=sqrt(n) )
                total = total + n/divisor;
        }
    }
    if(n==1) total --;
    return total;
}

/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
bool isPerfectSmarter(long n){
    /* TODO: Fill in this function. */
    return false;
}
bool isPrime(long n){
    for(long i = 2; i <= sqrt(n); i++){
        if(n%i == 0) return false;
    }
    return true;
}

/* TODO: Replace this comment with a descriptive function
 * header comment.
*/
Vector<long> findByEculid(long n){
     /* TODO: Fill in this function. */
    long a = 0, m, y;
    Vector<long> goal;
    for (long k = 1;1; k++){
        m = pow( 2 , k ) - 1;
        if(isPrime(m)){
            y = pow(2, k-1) * m;
            if(y != 1) {
                goal += y;
                a++;
            }
        }
    if(a == n) break;
    }
    return goal;
}


/* TODO: Replace this comment with a descriptive function
 * header comment.
 */
long findNthPerfectEuclid(long n){
    /* TODO: Fill in this function. */
    return 0;
}




/* * * * * * Test Cases * * * * * */

/* Note: Do not add or remove any of the PROVIDED_TEST tests.
 * You should add your own STUDENT_TEST tests below the
 * provided tests.
 */

PROVIDED_TEST("Time multiple trials of findPerfects function on doubling input sizes."){
    cout << endl;
    TIME_OPERATION(20000, findPerfects(20000));
    TIME_OPERATION(40000, findPerfects(40000));
    TIME_OPERATION(80000, findPerfects(80000));
    TIME_OPERATION(160000, findPerfects(160000));
    TIME_OPERATION(320000, findPerfects(320000));
//    TIME_OPERATION(33640000, findPerfects(33640000));
}

PROVIDED_TEST("Check divisor sums of small numbers") {
    EXPECT_EQUAL(divisorSum(1), 0);
    EXPECT_EQUAL(divisorSum(6), 6);
    EXPECT_EQUAL(divisorSum(12), 16);
}

PROVIDED_TEST("Check 6 and 28, should be perfect") {
    EXPECT(isPerfect(6));
    EXPECT(isPerfect(28));
}

PROVIDED_TEST("Imperfect numbers") {
    EXPECT(!isPerfect(12));
    EXPECT(!isPerfect(98765));
}

PROVIDED_TEST("Oddballs, zero, one, negative") {
    EXPECT(!isPerfect(0));
    EXPECT(!isPerfect(1));
    EXPECT(!isPerfect(-6));
}


PROVIDED_TEST("33550336 is perfect") {
    EXPECT(isPerfect(33550336));
}

// TODO: add your test cases here
STUDENT_TEST("if(smarterSum== divisorSum)"){
    EXPECT_EQUAL(divisorSum(1),smarterSum(1));
    EXPECT_EQUAL(divisorSum(2),smarterSum(2));
    EXPECT_EQUAL(divisorSum(3),smarterSum(3));
}
STUDENT_TEST("1if(smarterSum== divisorSum)"){
    EXPECT_EQUAL(divisorSum(4),smarterSum(4));
    EXPECT_EQUAL(divisorSum(5),smarterSum(5));
    EXPECT_EQUAL(divisorSum(6),smarterSum(6));
}

STUDENT_TEST("2if(smarterSum== divisorSum)"){
    EXPECT_EQUAL(divisorSum(28),smarterSum(28));
    EXPECT_EQUAL(divisorSum(496),smarterSum(496));
    EXPECT_EQUAL(divisorSum(8128),smarterSum(8128));
}

STUDENT_TEST("Confirm first 2 perfect numbers are 6 and 28") {
    Vector<long> goal = {6, 28,496,8128,33550336};
    EXPECT_EQUAL(findByEculid(5), goal);
}
