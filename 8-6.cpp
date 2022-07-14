#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void print_stack(stack<long> left, stack<long> center, stack<long> right) {
    cout << "left   :";
    while (!left.empty()) {
        cout << left.top() << " "; 
        left.pop(); 
    } cout << endl;

    cout << "center :";
    while (!center.empty()) {
        cout << center.top() << " "; 
        center.pop(); 
    } cout << endl;

    cout << "right  :";
    while (!right.empty()) {
        cout << right.top() << " "; 
        right.pop(); 
    } cout << endl;

    cout << "===" << endl;
}



void Solve(stack<long> &from, stack<long> &to, stack<long> &tmp, long amount) {
    if (amount > 1)
        Solve(from, tmp, to, amount - 1);

    // cout << "move " << from.top() << endl;
    to.push(from.top());
    from.pop();
    // print_stack(from, to, tmp);
    
    if (amount > 1)
        Solve(tmp, to, from, amount - 1);
}



int main (void) {
    long n;
    // pair<string,stack<long>> 
    stack<long> left;
    stack<long> center;
    stack<long> right;

    cin >> n;
    for (long i = n; i > 0 ; i--) 
        left.push(i);

    print_stack(left, center, right);
    Solve(left, right, center, n);
    print_stack(left, center, right);

}
