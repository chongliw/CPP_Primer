//
// Created by Chongli Wang on 9/13/15.
//

#include "text.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

void text01() {
//    using std::cin;
//    int num, num2;
//    std::cin >> num;
//    cin >> num2;
//    cout << num;    // error
}

void text02() {
//    string s1(10, 'c');
//    cout << s1 << endl;
//    string s;
//    cout << s << endl;
//    string s1, s2;
//    cin >> s1 >> s2;
//    cout << s1 << s2;
//    string s3;
//    getline(cin, s3);
//    cout << s3 << endl;
//    string s4;
//    cout << s4.empty() << endl;
//    s4 = "aabc";
//    cout << s4.empty() << s4 << s4.size() << endl;
//    cout << (s4.size() < -1) << endl; // be aware of this, it is true here

//    string s5(10, 'a');
//    string s6 = s5 + ", ";
//    string s7 = "hello" + ","; // error
//    string s8 = s6 + "hello" + ','; //ok
//    string s9 = "hello" + s5 + "!"; //ok
//    cout << s9 << endl;

//    ex 3.4
//    string s1, s2;
//    getline(cin, s1);
//    getline(cin, s2);
//    if (s1 > s2)
//        cout << s1 << " is larger " << endl;
//    else if (s1 < s2)
//        cout << s2 << " is larger " << endl;
//
//    auto sz1 = s1.size();
//    auto sz2 = s2.size();
//    if (sz1 < sz2)
//        cout << s2 << " is longer" << endl;
//    else if (sz1 > sz2)
//        cout << s1 << " is longer" << endl;

//    ex 3.5
//    string s1, s2;
//    cin >> s1 >> s2;
//    string s = s1 + s2;
//    cout << s << endl;
//    cout << s1 << " " << s2 << endl;

//    string test("where is my dinner?");
//    for (char c: test)
//        cout << c << endl;

//    string test("there   are   a lot of   spaces h  e  r  e! ");
//    decltype(test.size()) space_cnt = 0;
//    for (auto ch: test)
//        if (isspace(ch))
//            space_cnt++;
//    cout << space_cnt << " space chars in " << test << endl;
//    for (auto &ch: test)
//        ch = toupper(ch);
//    cout << test << endl;

//    vector<int> list(10, -1);
//    vector<string> slist = {"abc", "def", "ghi"};
//    cout << slist[0] << endl;
//    vector<int> ls;
//    for (int i = 0; i < 100; ++i)
//        ls.push_back(i);
//    cout << ls[45] << endl;
}

void text04() {
//    const int n = 2;
//    vector<string> vstr(n, "");
//    for (auto c = vstr.begin(); c != vstr.end(); ++c)
//        cin >> *c;
//    for (auto c = vstr.begin(); c != vstr.end(); ++c) {
//        cout << (*c).empty() << endl;
//        cout << c->size() << endl;
//    }

//    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
//    for (auto it = arr.begin(); it != arr.end(); ++it)
//        *it *= 2;
//     no write, read only, use cbegin and cend
//    for (auto it = arr.cbegin(); it != arr.cend(); ++it)
//        cout << *it << endl;
//    cout << arr.cend() - arr.cbegin() << endl;
//    cout << arr.cbegin() - arr.cend() << endl;

    // binary search
//    vector<int> arr = {0, 1, 3, 6, 9};
//    auto beg = arr.begin();
//    auto end = arr.end();
//    decltype(beg) mid;
//    int search = 4;
//    while(true) {
//        mid = beg + (end - beg) / 2;
//        if (mid == beg || *mid == search)
//            break;
//        if (*mid < search)
//            beg = mid + 1;
//        else
//            end = mid;
//
//    }
//    cout << *mid << endl;

//    vector<auto> test = {0, 1, 2, 3}; // error
}

void text05() {
//    constexpr unsigned sz = 10;
//    int arr[sz];
//    arr[0] = 10;
//    for(auto item: arr)
//        cout << item << endl;

//    char ch[] = "C++"; // of size 4
//    cout << sizeof(ch) << endl;
//    cout << ch[2] << ch[3] << endl; // +empty
//    int a[] = {1, 3, 4};
//    int b[]= a; //error
//    b = a; //error
//    int arr[10];
//    int (*ptr)[10] = &arr;
//    cout << arr << endl;

//    int arr[10] = {1};
//    for (auto it: arr)
//        cout << it << endl;

//     ex 3.31
//    constexpr int n = 10;
//    int a[n];
//    for (int i = 0; i < n; ++i)
//        a[i] = i;
//    for (auto num: a)
//        cout << num << " ";
//    cout << endl;

//    ex 3.32
//    int b[n];
//    for (int i = 0; i < n; i++)
//        b[i] = a[i];
//    for (auto item: b)
//        cout << item << " ";
//    cout << endl;
//
//    vector<int> arr1;
//    for (int i = 0; i < n; ++i)
//        arr1.push_back(i);
//    vector<int> arr2;
//    arr2 = arr1;
//    for (auto item: arr2)
//        cout << item << " ";
//    cout << endl;

//    string strs[]{"first", "second", "third"};
//    auto *ptr = &strs;
//    string *ptr1 = strs;
//    string *ptr2 = &strs[0];
//    cout << ptr << endl << ptr1 << endl << ptr2 << endl;

//    int nums[] = {3, 4, 5};
//    auto pt(nums); // int* type
//    cout << typeid(pt).name() << endl;
//    *nums = 1;
//    cout << nums[0] << endl;

//    int i = 0;
//    decltype(&i) pt{nullptr};
//    pt = &i;
//    cout << pt << endl;

//    int nums[] = {1, 3, 4};
//    int *pt = nums;
//    cout << pt[2] << endl;
//    cout << &nums[3] << endl; // valid

//    ex3.35
//    int nums[10];
//    for (auto pt = begin(nums); pt < end(nums); ++pt)
//        *pt = 1;
//    for (auto num: nums)
//        cout << num << endl;

//    const char ca[] = {'a', 'b', 'c'};
//    const char *ch = ca;
//    while(*ch) {
//        cout << *ch << endl;
//        ++ch;
//    }

//    ex.3.40
//    const char s1[]{"abcde"};
//    const char s2[]{"fghij"};
//    char s3[10];    // should be 11 chars, last one is \0
//    strcpy(s3, s1);
//    strcat(s3, s2);
//    for (auto ch: s3)
//        cout << ch;
//    cout << endl;
//    cout << strlen(s3);     // error here

//    ex3.41
//    const int arr[] = {1, 3, 5};
//    vector<int> varr(begin(arr), end(arr));
//    for(int num: varr)
//        cout << num << endl;
//    auto sz = varr.size();
//    int arr1[sz];
//    for (int i = 0; i < sz; ++i)
//        arr1[i] = varr[i];


}
