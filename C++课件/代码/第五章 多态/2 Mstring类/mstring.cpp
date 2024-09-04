#include "mstring.h"
#include <Cstring>

//默认构造函数  Mstring s;
Mstring::Mstring() {
    cout << "Mstring::Mstring()" << endl;
    _data = new char[DEFAULTLEN];
    _maxLen = DEFAULTLEN;
    _len = 0;
}

//带参数的构造函数 Mstring s("hello");
Mstring::Mstring(const char *data) {
    cout << "Mstring::Mstring(const char *data)" << endl;
    int len = strlen(data)+1;
    _data = new char[len];
    _maxLen = len;

    strcpy(_data, data);
    _len = len-1;
}

//拷贝构造函数  Mstring s1 = s;
Mstring::Mstring(const Mstring &t) {
    cout << "Mstring::Mstring(const Mstring &t)" << endl;
    _data = new char[t._maxLen];
    _maxLen = t._maxLen;
    _len = t._len;
    strcpy(_data, t._data);
}

//析构函数
Mstring::~Mstring() {
    cout << "Mstring::~Mstring()" << endl;
    if (_data)
        delete[] _data;
}

//重载=  s1 = s2    s3 = s1 = s2;
Mstring &Mstring::operator=(const Mstring &t) {
    cout << "Mstring &Mstring::operator=(const Mstring &t)" << endl;
    //释放原来申请的空间
    delete[] _data;
    //重新申请空间
    _data = new char[t._maxLen];
    _maxLen = t._maxLen;
    _len = t._len;

    strcpy(_data, t._data);

    return *this; //返回左操作数
}

//重载 <<
ostream & operator << (ostream &os, const Mstring &t) //cout << s1 << endl;
{
    //cout << "ostream & operator << (ostream &os, const Mstring &t)" << endl;
    os << t._data;
    return os;
}

//对_data指针所指向的堆空间进行扩容
//size: 需要扩容的大小
void Mstring::extend(u32_t size) {
    //保存原来空间的首地址
    char *tmp = _data;
    //为_data指针分配新的空间
    _data = new char[size];
    //将原来的空间中的内容拷贝到新的空间中
    strcpy(_data, tmp);
    //释放原来的空间
    delete[] tmp;

    _maxLen = size;
}

//重载[]
//index: 下标
char Mstring::operator[](u32_t index) {
    //if (index >= _maxLen)
    if (index >= _len)
    {
        cout << "index out of range"  << endl;
        return '\0';
    }
    return _data[index]; //return *(_data + index);
}

//重载 +  s1+s2
Mstring Mstring::operator+(const Mstring &t) {
    Mstring ret; //保存运算后的结果

    ret._maxLen = this->_maxLen + t._maxLen;
    ret._len  = this->_len + t._len;

    ret._data = new char[_maxLen];
    memset(ret._data, 0, _maxLen);
    strcat(ret._data, this->_data);
    strcat(ret._data, t._data);

    return ret;
}

//字符串追加函数  t = s1.append(s2);
Mstring &Mstring::append(const Mstring &t) {
    //1 空间足够 this->_len + t._len < this->_maxLen
    if (this->_len + t._len >= this->_maxLen)
    {
        //扩容
        extend(this->_len + t._len + 1);
    }
    strcat(_data, t._data);
    _len += t._len;

    return *this;
}

Mstring &Mstring::append(const char *data) {
    cout << "Mstring &Mstring::append(const char *data)" << endl;
    //this->_len + strlen(data) >= this->_maxLen)
    if (this->_len + strlen(data) >= this->_maxLen)
    {
        extend(this->_len + strlen(data) +1);
    }
    strcat(_data, data);
    _len += strlen(data);

    return *this;
}

//重载>   s1 > s2
bool Mstring::operator>(const Mstring &t) {
    //if (strcmp(_data, t._data) > 0)
    //return true;
    int i = 0;
    while (_data[i]!='\0' && t._data[i]!='\0')
    {
        if (_data[i] == t._data[i]) {
            i++;
            continue;
        }
        if (_data[i] > t._data[i])
            return true;
        else
            return false;
    }

    return false;
}

//重载<  s1 < s2
bool Mstring::operator<(const Mstring &t) {
    if (strcmp(_data, t._data) < 0)
        return true;
    return false;
}

//返回字符串的长度
u32_t Mstring::length() const {
    return _len;
}

void Mstring::destroy() {
    //释放_data 指针在堆上申请的空间
    if (_data)
        delete[] _data;
    _data = NULL;
}