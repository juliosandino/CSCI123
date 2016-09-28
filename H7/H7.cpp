#include <iostream>
using namespace std;

const int DECLARED_SIZE = 20;

void fill_array(int a[], int size, int& number_used);

int search(const int a[], int number_used, int target);

int theSmallest(int a[], int size, int& number_used);

int main() {
    int arr[DECLARED_SIZE];
    int list_size;
    int target;
    int smallest;

    fill_array(arr, DECLARED_SIZE, list_size);
    theSmallest(arr, list_size, smallest);
    cout << "Smallest number in array is : " << smallest << endl;

    char ans;
    int result;
    do{
        cout << "Enter a number to search for: ";
        cin >> target;

        result = search(arr, list_size, target);
        if (result == -1)
            cout << target << " is not on the list.\n";
        else
            cout << target << " is stored in array position "
            << result << endl
            << "(Remember: The first position is 0.)\n";

        cout << "Search again?(y/n followed by Return): ";
        cin >> ans;
    } while ((ans != 'n') && (ans != 'N'));

    cout << "End of program.\n";
    return 0;
}

void fill_array(int a[], int size, int& number_used) {
    cout << "Enter up to " << size << " non-negative whole numbers.\n"
         << "Mark the end of the list with a negative number.\n";
    int next;
    int index = 0;

    cin >> next;
    while ((next >= 0) && (index < size)) {
        a[index] = next;
        index++;
        cin >> next;
    }
    number_used = index;
}

int search(const int a[], int number_used, int target) {
    int index = 0;
    bool found = false;
    while ((!found) && (index < number_used))
        if (target == a[index])
            found = true;
        else 
             index++;

    if (found)
        return index;
    else
        return -1;
}

int theSmallest(int a[], int size, int& number_used) {
    int smallest = a[0];
    for (int i = 1; i < size; i++)
        if (a[i] < smallest)
            smallest = a[i];

    number_used = smallest;
}
