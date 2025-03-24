//##c-practical-

//1 :-Write a program to compute the sum of the first n terms of the following serie= 1-1/2²+1/3²-1/4²+1/5² .....The number of terms n is to be taken from the user through the command line. If thecommand line argument is not found ### then prompt the user to enter the value of n.
#include <iostream>
#include <cmath> // For the pow() function
using namespace std;

double seriesSum(int n) {
    double sum = 0;
    for (int i = 1; i <= n; i++) {
        double term = 1.0 / pow(i, i); 
        if (i % 2 == 0) {
            sum -= term; 
        } else {
            sum += term; 
        }
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter the number of terms: ";
    cin >> n;
    cout << "Sum of series: " << seriesSum(n) << endl;
    return 0;
}



//## 2Write a program to remove the duplicates from an array
#include <iostream>
#include <vector>
#include <set>
using namespace std;

void removeDuplicates(vector<int>& arr) {
    set<int> uniqueElements(arr.begin(), arr.end()); 
    arr.assign(uniqueElements.begin(), uniqueElements.end()); 
}

int main() {
    vector<int> arr = {1, 2, 2, 3, 4, 4, 5, 6, 6}; 

    cout << "Original array: ";
    for (int num : arr) 
        cout << num << " ";
    removeDuplicates(arr);
    cout << "\nArray after removing duplicates: ";
    for (int num : arr) 
        cout << num << " ";
    
    return 0;
}

//Write a program that prints a table indicating the number of occurrences of eachalphabet in the text entered as command line arguments.
#include <iostream>
#include <string>
#include <map>
using namespace std;

void countOccurrences(string str) {
    map<char, int> freq; // Corrected map declaration

    for (char c : str) { // Corrected loop declaration
        if (isalpha(c)) { // Check if the character is an alphabet
            freq[tolower(c)]++; // Convert character to lowercase and increment frequency
        }
    }

    cout << "Character Frequency Table:\n";
    for (auto pair : freq) { // Corrected loop declaration
        cout << pair.first << " -> " << pair.second << endl;
    }
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input); // Reads the entire line of input including spaces

    countOccurrences(input); // Fixed function name to match declaration
    return 0;
}

//##4 Write a menu driven program to perform string manipulation (without using inbuiltstring functions):
//a. Show address of each character in string
#include <iostream> 
#include <cstring> 
using namespace std; 

void displayASCII (string str) { 
   cout << "ASCII values: \n";
   for (char c: str) {  
      cout << c << " ->" << int(c) << endl;
    } 
}  

void concatenateStrings (char str1[], char str2[]) {  
   int i= strlen(str1), j = 0; 
   while (str2[j] != '\0') { 
      str1[i] = str2[j];  
      i++; j++;  
   }  
   str1[i] = '\0'; 
} 

bool compareStrings (char str1[], char str2[]) { 
   int i = 0; 
   while (str1[i] != '\0' && str2[i] != '\0') { 
       if (str1[i] != str2[i]) 
           return false; 
       i++;  
   }   
   return str1[i] = str2[i]; 
}

int stringLength(char* str) { 
   int len = 0; 
   while (*str != '\0') {  
       len++; 
       str++; 
   } 
return len; 
}

//b. Concatenate two strings
void toUppercase (char str[]) { 
   int i = 0; 
   while (str[i] != '\0') { 
       if (str[i] >= 'a' && str[i] <= 'z') { 
           str[i] = 32; 
       } 
       i++; 
   } 
} 

void reverseString(char str[]) { 
   int len = stringLength (str); 
   for (int i = 0; i < len / 2; i++) {
      swap(str[i], str[len-i-1]); 
   } 
} 

int main() { 
    char str1[100], str2[100]; 
    
    cout << "Enter first string: "; 
    cin >> str1; 
    cout << "Enter second string: "; 
    cin >> str2; 

    displayASCII(str1); 


    concatenateStrings (str1, str2); 
    cout << "Concatenated String: " << str1 << endl; 

    cout << "Strings are" << (compareStrings (str1, str2) ? "equal": "not equal") << endl; 

    cout << "Length of first string: " << stringLength(str1) << endl; 

    toUppercase(str1); 
    cout << "Uppercase String: "<< str1 << endl;

} 
//c. Compare two strings
void reverseString(char str[]) { 
   int len = stringLength(str); 
   for (int i = 0; i < len / 2; i++) { 
      swap(str[i], str[len i 1]); 
   } 
} 
int main() { 
   char str1[100], str2[100]; 

   cout << "Enter first string: "; 
   cin >> str1; 
   cout << "Enter second string: ";
   cin >> str2; 

   displayASCII(str1); 

   concatenateStrings (str1, str2); 
   cout << "Concatenated String: "<< str1 << endl; 

   cout << "Strings are "<< compareStrings(str1, str2)<< endl; 

   cout << "Length of first string:" << stringLength(str1) << endl; 

   cout << "Uppercase String:" << str1 << endl; 

   reverseString(str1); 
   cout << "Reversed String:" << str1 << endl; 
   return 0; 
}


//##5 Write a program to merge two ordered arrays to get a single ordered array

#include <iostream>
#include <vector>

using namespace std;

// Function to merge two sorted arrays
vector<int> mergeArrays(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> merged;
    int i = 0, j = 0;

    // Merge the arrays while both have elements left
    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            merged.push_back(arr1[i++]);
        } else {
            merged.push_back(arr2[j++]);
        }
    }

    // Add remaining elements from arr1, if any
    while (i < arr1.size()) {
        merged.push_back(arr1[i++]);
    }

    // Add remaining elements from arr2, if any
    while (j < arr2.size()) {
        merged.push_back(arr2[j++]);
    }

    return merged;
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {2, 4, 6, 8};

    // Merge the arrays
    vector<int> merged = mergeArrays(arr1, arr2);

    // Display the merged array
    cout << "Merged sorted array: ";
    for (int num : merged) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

//##6. Write a program to search a given element in a set of N numbers using Binary search(i) with recursion (ii) without recursion.
#include <iostream>
#include <vector>

using namespace std;

// Recursive binary search
int binarySearchRecursive(vector<int> &arr, int left, int right, int key) {
    if (left > right) return -1;  // Base case: key not found
    int mid = left + (right - left) / 2; // Avoid overflow in (left + right) / 2

    if (arr[mid] == key) return mid;
    if (arr[mid] > key) return binarySearchRecursive(arr, left, mid - 1, key);
    return binarySearchRecursive(arr, mid + 1, right, key);
}

// Iterative binary search
int binarySearchIterative(vector<int> &arr, int key) {
    int left = 0, right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) return mid;
        if (arr[mid] > key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1; // Key not found
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11}; // Initialize the array
    int key = 5;

    // Recursive search
    int indexRec = binarySearchRecursive(arr, 0, arr.size() - 1, key);
    cout << "Recursive Binary Search: "
         << (indexRec != -1 ? "Found at index " + to_string(indexRec) : "Not found")
         << endl;

    // Iterative search
    int indexIter = binarySearchIterative(arr, key);
    cout << "Iterative Binary Search: "
         << (indexIter != -1 ? "Found at index " + to_string(indexIter) : "Not found")
         << endl;

    return 0;
}

##7

#include <iostream>

using namespace std;

// Recursive GCD
int gcdRecursive(int a, int b) {
    return (b == 0) ? a : gcdRecursive(b, a % b);
}

// Non-recursive GCD (Iterative)
int gcdIterative(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "GCD (Recursive): " << gcdRecursive(a, b) << endl;
    cout << "GCD (Iterative): " << gcdIterative(a, b) << endl;

    return 0;
}


//##8Create a Matrix class. Write a menu-driven program to perform following Matrixoperations (exceptions should be thrown by the functions if matrices passed to them are incompatible and handled by the main() function):a. Sum b. Productc. Transpose

#include <iostream>
using namespace std;

class Matrix {
    int mat[3][3];

public:
    // Input matrix elements
    void input() {
        cout << "Enter matrix (3x3):\n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> mat[i][j];
            }
        }
    }

    // Display matrix elements
    void display() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Overload '+' operator for matrix addition
    Matrix operator+(Matrix m) {
        Matrix res;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                res.mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return res;
    }

    // Overload '*' operator for matrix multiplication
    Matrix operator*(Matrix m) {
        Matrix res;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                res.mat[i][j] = 0;
                for (int k = 0; k < 3; k++) {
                    res.mat[i][j] += mat[i][k] * m.mat[k][j];
                }
            }
        }
        return res;
    }

    // Transpose of the matrix
    Matrix transpose() {
        Matrix res;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                res.mat[i][j] = mat[j][i];
            }
        }
        return res;
    }
};

int main() {
    Matrix A, B, C;
    int choice;

    cout << "Enter elements for Matrix A:\n";
    A.input();

    cout << "Enter elements for Matrix B:\n";
    B.input();

    do {
        cout << "\nMenu:\n"
             << "1. Sum\n"
             << "2. Product\n"
             << "3. Transpose of Matrix A\n"
             << "4. Exit\n"
             << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                C = A + B;
                cout << "Sum of Matrices:\n";
                C.display();
                break;

            case 2:
                C = A * B;
                cout << "Product of Matrices:\n";
                C.display();
                break;

            case 3:
                C = A.transpose();
                cout << "Transpose of Matrix A:\n";
                C.display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 4);

    return 0;
}



//##9 Define a class Person having name as a data member. Inherit two classes Student and employee from Person. Student has additional attributes as course, marks and yearand Employee has department and salary. Write display() method in all the three classes to display the corresponding attributes. Provide the necessary methods to showruntime

#include <iostream>
using namespace std;

class Person {
protected:
    string name;
    int age;

public:
    // Input name and age
    void input() {
        cout << "Enter name and age: ";
        cin >> name >> age;
    }

    // Display name and age
    void display() {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Student : public Person {
    string course;

public:
    // Input student details
    void input() {
        Person::input(); // Input name and age
        cout << "Enter course: ";
        cin >> course;
    }

    // Display student details
    void display() {
        Person::display(); // Display name and age
        cout << "Course: " << course << endl;
    }
};

class Employee : public Person {
    int salary;

public:
    // Input employee details
    void input() {
        Person::input(); // Input name and age
        cout << "Enter salary: ";
        cin >> salary;
    }

    // Display employee details
    void display() {
        Person::display(); // Display name and age
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    Student s;
    Employee e;

    cout << "Enter student details:\n";
    s.input();

    cout << "Enter employee details:\n";
    e.input();

    cout << "\nStudent Details:\n";
    s.display();

    cout << "\nEmployee Details:\n";
    e.display();

    return 0;
}


//##10

#include <iostream> 
using namespace std; 

class Triangle { 
public: 
   // Area with base & height 
   double area(double base, double height) { 
   return 0.5 *base*height; 
   } 

   // Area with 3 sides (Heron's formula) 
   double area(double a, double b, double c) { 
      double s (a + b + c) / 2; 
      return sqrt(s* (s-a)*(s-b)*(s-c)); 
   } 
}; 

int main() { 
   Triangle t; 
   cout << "Area (Base, Height): " << t.area(5, 10) << endl; 
   cout << "Area (Three Sides): " << t.area(3, 4, 5) << endl; 
   return 0;
}

   
//##11Create a class Student containing fields for Roll No., Name, Class, Year and Total Marks. Write a program to store 5 objects of Student class in a file. Retrieve these records from the file and display them


#include <iostream> 
#include <stdexcept> 
using namespace std; 

class MatrixException: public exception { 
public: 
   const char* what() const throw() { 
      return "Matrix dimensions are incompatible!"; 
   } 
}; 

void checkCompatibility(int rows1, int cols1, int rows2, int cols2) { 
   if (cols1 != rows2) throw MatrixException(); 
} 

int main() { 
   try { 
      checkCompatibility(2, 6, 4, 2); 
   } catch (MatrixException e) { 
      cout << "Eггог:" <<<< e.what() << endl; 
   } 
   return 0; 
}   


##12


#include <iostream> 
#include <stdexcept> 
using namespace std; 

class PrimeException: public exception { 
public: 
   const char what() const throw() { 
       return "Number must be greater than 11"; 
   } 
}; 

// Function to check if a number is prime 
bool isPrime(int num) { 
   if (num < 2) 
      throw PrimeException(); 
   for(int i=2; i*i <=num; i++) { 
      if (num % i == 0) 
         return false; 
   }
   return true; 
}

int main() { 
   int num; 
   cout << "Enter a number: "; 
   cin >> num; 

   try { 
      if (isPrime(num)) 
      cout << num << " is a prime number.\n"; 
      else 
         cout << num << " is not a prime number.\n"; 
   } catch (PrimeException& e) { 
      cout << "Eггог: " <<e.what() << endl; 
   } 
   return 0;    
}


##13

#include <iostream>
using namespace std; 

class Student { 
public: 
   int rollNo; string name; 
   string className; 
   int year; 
   float totalMarks; 

   void input() { 
      cout << "Enter Roll No, Name, Class, Year, and Total Marks: ";
      cin>> rollNo >> name>> className >> year>> totalMarks; 
   } 

   void display() { 
      cout << "Roll No: " <<rollNo <<", Name: "<< name 
           << " , Class: " << className << ",Year:" <<year 
           << " , Total Marks: " << totalMarks << endl; 
   } 
}; 

int main() { 
   Student students [5]; 
 
   // Taking input for 5 students 
   for (int i = 0; i < 5; i++) { 
      cout << "Enter details for Student " << i +1 << ":\n"; 
      students[i].input(); 
   } 
cout<<"\nStudent Details: \n"; 
for (int i=0; i < 5; 1++) { 
students[i].display(); 
} 
return 0; 
} 

// #`14copy the contents of one file to another
#include <iostream>
#include <cstdio>  // For file handling functions

using namespace std;

int main() {
    FILE *source, *destination;
    char ch;

    // Open the source file in read mode
    source = fopen("source.txt", "r");
    if (source == nullptr) {
        cout << "Error: Source file not found or could not be opened." << endl;
        return 1;  // Exit if source file can't be opened
    }

    // Open the destination file in write mode
    destination = fopen("destination.txt", "w");
    if (destination == nullptr) {
        cout << "Error: Could not open destination file for writing." << endl;
        fclose(source);  // Close source file before exiting
        return 1;
    }

    // Copy contents from source to destination
    while ((ch = fgetc(source)) != EOF) {
        fputc(ch, destination);
    }

    cout << "File copy successful." << endl;

    // Close both files
    fclose(source);
    fclose(destination);

    return 0;
}
