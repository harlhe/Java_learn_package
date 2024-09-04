
#ifndef CODE_ARRAY_H
#define CODE_ARRAY_H

typedef unsigned int u32_t;

#define DefaultLen 4
//#define INDEXERROR 999999

class Array
{
//属性
private:
    int *data; //存储数据的指针
    u32_t len; //数组长度：空间的大小
    u32_t itemNum; //存储的数据的个数
//方法
public:
    static int INDEXERROR;
    Array(); //默认构造函数
    Array(const Array &); //拷贝构造函数
    Array(u32_t); //带参数的构造函数

    ~Array(); //析构函数

    //返回数组的长度
    u32_t length() const;
    //返回元素的个数
    u32_t get_itemNum() const;
    //返回指定位置的元素
    int getData(u32_t);
    //自动扩容函数
    void extend();
    //销毁动态数组
    void destroy();
    //在指定位置插入元素  
    void insert(u32_t, int);
    //删除指定位置的元素
    void remove_index(u32_t);
    //删除指定的元素
    void remove_data(int);
};

#endif //CODE_ARRAY_H
