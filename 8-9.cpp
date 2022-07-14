#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// ダメでした
// void parens(int count, string ans, int len) {
//     if (ans.size() == len * 2) {
//         cout << ans << endl;
//         return;
//     }

//     ans += "(";
//     count--;
//     if (count == 0) {
//         ans += ")";
//         if (ans.size() == len * 2) {
//             cout << ans << endl;
//             return;
//         }
//         return ;
//     }


//     for (int i = count; count > 0; count--) 
//         parens(count , ans + "(", len);
    
//     ans += ")";
//     parens(count - 1, ans, len);
// }

// int main (void) {
//     parens(2, "", 2);
// }

