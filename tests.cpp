#include <gtest/gtest.h>
#include "bmstuList.h"
#include <string>

using namespace BMSTU;


TEST(linkedList, Default) {
    BMSTU::linckedList<int> a;
    ASSERT_EQ(a.size(), 0);
    ASSERT_TRUE(a.empty());
    ASSERT_EQ(a.begin(), a.end());
}

TEST(linkedList, Initializer) {
    BMSTU::linckedList<int> a = {1, 2, 3};

    ASSERT_FALSE(a.empty());

    ASSERT_EQ(a.size(), 3);

    ASSERT_EQ(a[0], 1);
    ASSERT_EQ(a[1], 2);
    ASSERT_EQ(a[2], 3);
}

TEST(linkedList, OtherConstructor) {
    BMSTU::linckedList<int> a1 = {1, 2, 3, 4, 5, 6, 7};
    BMSTU::linckedList<int> a2(a1.begin(), a1.end());

    ASSERT_FALSE(a2.empty());

    ASSERT_EQ(a2.size(), 7);

    ASSERT_EQ(a2[0], 1);
    ASSERT_EQ(a2[2], 3);
    ASSERT_EQ(a2[6], 7);
}

TEST(linkedList, EmptyTest) {
    BMSTU::linckedList<int> a;
    ASSERT_EQ(a.size(), 0);
}

TEST(linkedList, SizeTest) {
    BMSTU::linckedList<int> a;
    a.push_back(10);
    ASSERT_EQ(a.size(), 1);
    a.push_back(20);
    ASSERT_EQ(a.size(), 2);
    a.push_back(30);
    ASSERT_EQ(a.size(), 3);

    a.clear();
    ASSERT_EQ(a.size(), 0);
}

TEST(linkedList, PushBackTest) {
    BMSTU::linckedList<int> a;
    a.push_back(10);
    ASSERT_EQ(a[a.size() - 1], 10);
    a.push_back(20);
    ASSERT_EQ(a[a.size() - 1], 20);
    a.push_back(30);
    ASSERT_EQ(a[a.size() - 1], 30);
}

TEST(linkedList, PushFrontTest) {
    BMSTU::linckedList<int> a;
    a.push_front(10);
    ASSERT_EQ(a[0], 10);
    a.push_front(20);
    ASSERT_EQ(a[0], 20);
    a.push_front(30);
    ASSERT_EQ(a[0], 30);
}

TEST(linkedList, IndexTest) {
    BMSTU::linckedList<int> a;

    a.push_front(10);
    ASSERT_EQ(a[0], 10);

    a[0] = 20;
    ASSERT_EQ(a[0], 20);
}

TEST(linkedList, CompareTest) {
    BMSTU::linckedList<int> a1 = {1, 2, 3};

    BMSTU::linckedList<int> a2 = {1, 2, 3};

    ASSERT_TRUE(a1 == a2);

    a2.push_back(4);
    ASSERT_TRUE(a1 != a2);
}

TEST(linkedList, SwapTest) {
    BMSTU::linckedList<int> a1 = {1, 2, 3};
    BMSTU::linckedList<int> a2 = {1, 2, 3, 4};
    BMSTU::linckedList<int> a3 = {1, 2, 3};
    BMSTU::linckedList<int> a4 = {1, 2, 3, 4};

    swap(a1, a2);
    ASSERT_TRUE(a1 == a4);
    ASSERT_TRUE(a2 == a3);
}

TEST(linkedList, FromVector) {
    using namespace std;
    std::vector<std::string> my_vec = {"string1"s, "string3"s, "string4"s, "string5"s, "string6"s, "string7"s};
    BMSTU::linckedList<std::string> my_list(my_vec.begin(), my_vec.end());
    my_list.push_front("begin_string"s);
    my_list.push_back("end_string"s);
    my_vec.clear();
    my_vec.insert(my_vec.begin(), my_list.begin(), my_list.end());

    ASSERT_EQ((std::vector<std::string>{"begin_string"s,"string1"s, "string3"s, "string4"s, "string5"s, "string6"s, "string7"s, "end_string"s}), my_vec);
}

