//
// Created by Administrator on 2021/7/29.
//
#include <iostream>
#include "array.h"

using namespace std;

//定义static成员变量
int Array::INDEXERROR = 999999;

//默认构造函数
Array::Array() {
    cout << "Array::Array()" << endl;
    data = new int[DefaultLen]; //默认分配了4个int类型的空间
    len = DefaultLen;
    itemNum = 0;
}

//带参数的构造函数
Array::Array(u32_t len) {
    cout << "Array::Array(u32_t len) " << endl;
    data = new int[len];
    this->len = len;
    itemNum = 0;
}

//拷贝构造函数 ,实现深拷贝 Array a = b;
Array::Array(const Array &t)
{
    cout << "Array::Array(const Array &t)" << endl;
    data = new int[t.len];
    len = t.len;
    itemNum = t.itemNum;

    for (int i = 0; i < len; i++)
        data[i] = t.data[i];
}

//析构函数
Array::~Array() {
    cout << "Array::~Array()" << endl;
    //释放空间
    if (data)
        delete[] data;
}

//返回数组的长度
u32_t Array::length() const{
    return len;
}

//返回元素的个数
u32_t Array::get_itemNum() const {
    return itemNum;
}

/* @breaf 返回指定位置的元素
 * @param index 下标
 * @return int, 下标对应的元素
 * */
int Array::getData(u32_t index) {
    if (index >= len)
    {
        cout << "index out of range !" << endl;
        return INDEXERROR;
    }
    return data[index];
}

//自动扩容
void Array::extend() {
    int *tmp = data; //使用临时指针保存原来堆空间的首地址
    //分配新的空间
    data = new int[2*len];
    //将原来空间的内容拷贝到新的空间中
    memcpy(data, tmp, sizeof(int)*len);
    len *= 2;
    //释放原来的空间
    delete[] tmp;
}

//销毁动态数组
void Array::destroy() {
    if (data) {
        delete[] data;
        data = NULL;
        len = 0;
        itemNum = 0;
    }
}

/* @breaf 在指定的位置插入一个元素
 * @param index 需要插入的位置（下标）
 * @param item 需要插入的元素
 * @return void
 * */
void Array::insert(u32_t index, int item) {
    //index>=len
    if (index >= len)
    {
        //数组满
        if (itemNum == len)
        {
            //1、扩容
            extend();
            //2、在下标为len的位置插入一个元素
            data[len] = item;
            itemNum++;
        }
        else //数组没满
        {
            //在下标为itemNum的位置插入一个元素
            data[itemNum] = item;
        }
    }
    else  //index<len
    {
        //数组满
        if (itemNum == len)
        {
            //1、扩容
            extend();
        }

        //2、index位置开始的 itemNum-index个元素往后移动一个位置
        for (int i = 0; i < itemNum-index; i++)
        {
            data[itemNum-i] = data[itemNum-1-i];
        }
        //3、将index位置的元素赋值为item
        data[index] = item;
        itemNum++;
    }
}