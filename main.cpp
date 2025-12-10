#include <iostream>
#include <vector>
#include <cmath> 

// ---------------------------------------------------------
// 1. Conditional Statements 
// ---------------------------------------------------------
// Translates the provided MATLAB switch statement to C++.
void test_conditional() {
    int n;
    std::cout << "--- Q1: Conditional Statements ---" << std::endl;
    std::cout << "Enter a number: ";
    std::cin >> n;

    switch (n) {
        case -1:
            std::cout << "negative one" << std::endl;
            break;
        case 0:
            std::cout << "zero" << std::endl;
            break;
        case 1:
            std::cout << "positive one" << std::endl;
            break;
        default:
            std::cout << "other value" << std::endl;
            break;
    }
    std::cout << std::endl;
}

// ---------------------------------------------------------
// 2. Printing a Vector 
// ---------------------------------------------------------
// Function to print elements of a vector to the console.
// This is defined early so it can be used by Q4 and Q5.
void print_vector(std::vector<int> v) {
    std::cout << "[ ";
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i];
        if (i < v.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " ]" << std::endl;
}

// ---------------------------------------------------------
// 3. While Loops 
// ---------------------------------------------------------
// Fibonacci sequence (starting 1, 2) values not exceeding 4,000,000.
void fibonacci_limit() {
    std::cout << "--- Q3: Fibonacci Sequence (< 4,000,000) ---" << std::endl;
    int a = 1;
    int b = 2;

    // Print the first two terms as per the prompt example: 1, 2...
    std::cout << a << ", " << b;

    while (true) {
        int next_term = a + b;
        if (next_term > 4000000) { // Limit defined in prompt
            break;
        }
        std::cout << ", " << next_term;
        a = b;
        b = next_term;
    }
    std::cout << std::endl << std::endl;
}

// ---------------------------------------------------------
// 4. Functions
// ---------------------------------------------------------

// 4.1 If Prime 
bool isprime(int n) {
    if (n <= 1) return false; // 0 and 1 are not prime
    
    // Check from 2 up to square root of n
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false; // Found a divisor
        }
    }
    return true;
}

// 4.2 Factorize
// Finds all factors of a number.
std::vector<int> factorize(int n) {
    std::vector<int> answer;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            answer.push_back(i);
        }
    }
    return answer;
}

// 4.3 Prime Factorization
// Finds the prime factorization of a number.
std::vector<int> prime_factorize(int n) {
    std::vector<int> answer;
    
    // Divide by 2 until n is odd
    while (n % 2 == 0) {
        answer.push_back(2);
        n = n / 2;
    }

    // n must be odd now, skip 2 elements (i = i + 2)
    for (int i = 3; i * i <= n; i = i + 2) {
        while (n % i == 0) {
            answer.push_back(i);
            n = n / i;
        }
    }

    // If n is a prime number greater than 2
    if (n > 2) {
        answer.push_back(n);
    }
    
    return answer;
}

// ---------------------------------------------------------
// 5. Pascal's Triangle 
// ---------------------------------------------------------
// Prints the first n rows without using combinatorics.
void pascals_triangle(int n) {
    std::cout << "--- Q5: Pascal's Triangle (" << n << " rows) ---" << std::endl;
    
    if (n <= 0) return;

    // Previous row buffer
    std::vector<int> prev_row;
    prev_row.push_back(1);
    print_vector(prev_row); // First row is always [1]

    for (int i = 1; i < n; ++i) {
        std::vector<int> current_row;
        current_row.push_back(1); // Start with 1

        // Calculate middle values based on the previous row
        for (size_t j = 1; j < prev_row.size(); ++j) {
            current_row.push_back(prev_row[j - 1] + prev_row[j]);
        }

        current_row.push_back(1); // End with 1
        print_vector(current_row);
        
        // Update previous row for the next iteration
        prev_row = current_row;
    }
    std::cout << std::endl;
}

// ---------------------------------------------------------
// Main Execution 
// ---------------------------------------------------------
int main() {
    // 1. Run Question 1
    test_conditional();

    
    // 3. Run Question 3
    fibonacci_limit();

    // 4. Run Question 4 Tests
    // 4.1
    std::cout << "--- Q4.1: isprime Tests ---" << std::endl;
    std::cout << "isprime(2) = " << (isprime(2) ? "true" : "false") << '\n';
    std::cout << "isprime(10) = " << (isprime(10) ? "true" : "false") << '\n';
    std::cout << "isprime(17) = " << (isprime(17) ? "true" : "false") << '\n';
    std::cout << std::endl;

    // 4.2
    std::cout << "--- Q4.2: factorize Tests ---" << std::endl;
    std::cout << "Factors of 2: "; print_vector(factorize(2));
    std::cout << "Factors of 72: "; print_vector(factorize(72));
    std::cout << "Factors of 196: "; print_vector(factorize(196));
    std::cout << std::endl;

    // 4.3
    std::cout << "--- Q4.3: prime_factorize Tests ---" << std::endl;
    std::cout << "Prime Factors of 2: "; print_vector(prime_factorize(2));
    std::cout << "Prime Factors of 72: "; print_vector(prime_factorize(72));
    std::cout << "Prime Factors of 196: "; print_vector(prime_factorize(196));
    std::cout << std::endl;

    // 5. Run Question 5 Test
    pascals_triangle(8); // Example: print first 8 rows

    return 0;
}