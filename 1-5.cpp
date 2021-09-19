#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// もんだい
// 3つの方法で文字列を操作 挿入、削除、入れ替え


// Example
// pale, ple -> true
// pales, pale -> true
// pale, bale -> true
// pale, bake -> false

// 入れ替え：左から1文字ずつ見ていって、一致しない箇所が1ついないならOK

// 挿入削除
// 左から1文字ずつ見て、一致しない箇所が見つかったら、今度は右から探索する。右から探索して一致しない箇所が左から見ていった箇所と一致すればOK


class hoge{
public:
    bool fuga(string s1, string s2){
        bool ret = false;

        if ( s1.size() == s2.size() ){
            int c=0;
            for(int i=0;i<s1.size();i++){
                if (s1[i] != s2[i])c++;
            }
            
            if (c <= 1)ret = true;
        }else if ( (s1.size() - s2.size()) * (s1.size() - s2.size()) ==1 ){
            string s_short,s_long;
            if (s1.size() < s2.size()){
                s_short = s1;
                s_long = s2;
            }else{
                s_short = s2;
                s_long = s1;
            }

            // 挿入 pattern  ple, prle
            // 削除 pattern  prle, ple
            // ple xple
            // ple plex

            int c = -1;
            for(int i=0;i<s_short.size();i++){
                if (s_short[i] != s_long[i]){
                    c=i;
                    break;
                }
            }
            cout << c << endl;
            
            // short : 必ず一文字足りない；追加する必要がある。
            // やりたいこと pale (short)　→ pal*e 

            //左からみていって、文字が一致しない場合に、
            // 入れ替え→次の添字から
            
            

            if (c >= 0){
                // for(int i=s_short.size()-1;i>=0;i--){
                //     if (s_short[ i  ] != s_long[  i+1  ] ){
                //         if (c==i+1)ret = true;
                //         break;
                //     }
                // }
                int i=s_long.size()-1;
                for(; i-1 >= 0; i--){
                    if (s_short[ i-1  ] != s_long[  i  ] ){
                        if (c==i)ret = true;
                        break;
                    }
                    // if (i-1==0)ret=true;
                }
                if (i == 0)ret=true;

            }else{
                ret = true;
            }

        }

        // cout << "fugafuga" << endl;
        return ret;
    }
};


int main()
{
	hoge hogehoge;
	// bool answer = hogehoge.fuga("pale", "pxlxe");
    // bool answer = hogehoge.fuga("pale", "palxe");
    bool answer = hogehoge.fuga("pale", "xpale");

    cout << answer << endl;
	return 0;
}

//g++ 1-5.cpp --sysroot=`xcrun --show-sdk-path`