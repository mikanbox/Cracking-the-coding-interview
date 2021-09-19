#include <stdio.h>
#include <string.h>
#include <cstdlib>
// g++ 1-9.c --sysroot=`xcrun --show-sdk-path`

// 愚直な解法
// string2 は string1の文字列をrotationしている　→　必ず部分文字列を含む

// index i を0から開始し、string2の i から 終端(文字列の長さ - 1)までの部分文字列が、string1 の部分文字列と一致するなら、
// string2 の 0 から i 番目の文字列が string1の N-iからN番目の文字列と一致するか確認する

// 問題点 : i が大きい時に、 isSubstring 使う意味がなくなる


// 例
// const char* string1 = "waterbottle";
// const char* string2 = "erbottlewat";


// for( int i = 0; i < string_size; i++) {
//     char* string2_substring = string2[i];

//      // string2_substring = wat の時にtrue
//     if (isSubstring(string1, string2_substring) ){
        

//         char* string1_substring = [N - i - 1];
//         // string1_substring = "erbottle"　となるのでこれが string2 に含まれていればtrue
//         if (isSubstring(string1_substring, string2) ) {

//         }
//     }
// }

// const char* string1 = "wat|erbottle";
// const char* string2 = "erbottle|wat";


// 解法2
// const char* string1 = "waterbottle";
// const char* string2 = "erbottle | wat";

// string2 の性質を考える
// - string2をあるindex i の前とあとで分割すると、両方ともstring1の部分文字列となる
// - string2をあるindex i の前とあとで分割して、順番を入れ替えると string 1 になる


// 解法3
// const char* string1 = "waterbottle";
// const char* string2_double = "erbottle wat | erbottle wat"; 

// 例外がないか検討
// 制約 : sizeof(string1) == sizeof(string2) 
// isSubstring(string1, string2_double) == true の時点で、 string2_double のうち、一致していない文字列部分の合計の長さは string2 と同じ
// string2_double は string2 2つを連結した文字列なので、一致していない文字列部分 の残りは元の文字列と一致する


// mallocは失敗する前提で書いて欲しいとのこと
// 以下パターンの考慮が抜けている
// waterbottlewarterbottle
// waterbottle

// [July 20, 2021, 4:08 PM] Iwashima, Kuniyuki: memcpy
// [July 20, 2021, 4:08 PM] Iwashima, Kuniyuki: len = strlen ()
// strcat : 呼び出し都度、1つめの引数の終端のポインタまで探索するためコストがかかる。

// [July 20, 2021, 4:10 PM] Itazuri, Takahiro: char* str1, str2;
// str2は char型として宣言される

// 関数名 : C言語は小文字と _ 　→　わりと宗教
// 


bool isSubstring(const char* string, const char* string2) {
    char* string_longer;
    char* string_shorter;
}


bool Solution (const char* string1, const char* string2) {
    char* string2_doublesize = (char*)malloc(strlen(string2) * 2 + 1);
    
    strcat(string2_doublesize, string2);
    strcat(string2_doublesize, string2);

    bool res = isSubstring(string1, string2_doublesize);

    free(string2_doublesize);
    return res;
}


int main(void) {
    const char* string1 = "waterbottle";
    const char* string2 = "erbottlewat";
    const char* string2_pattern2 = "terbottlewa";
    const char* string2_pattern3 = "lewaterbott";


    bool answer = Solution(string1, string2);

    // printf("%d",answer);

    return 0;
}

