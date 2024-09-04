#include <iostream>
#include <Cstring>
#include <vector>
#include <exception>

using namespace std;

//自定义一个异常
class FHeaderErr : public exception
{
public:
    const char *what() const throw()
    {
        return "frame header error";
    }
};

class FTailErr : public exception
{
public:
    const char *what() const throw()
    {
        return "frame tail error";
    }
};

int func(int a, int b)
{
    if (b)
        return a/b;
    else
    {
        cout << "division 0" << endl;
        throw "division 0";
       //throw 10;
    }
}

bool func2(char *str)
{
    if (!str)
        throw "NULL pointor";
    int len;
    len = strlen(str);
    //协议： ##name=zhangsan;age=18##
    if (!(str[0]=='#' && str[1]=='#'))  //帧头错误
    {
        //throw "frame header error ";
        FHeaderErr err;
        throw err;
    }

    if (!(str[len-1]=='#' && str[len-2]=='#')) //帧尾错误
    {
        FTailErr err;
        throw err;
    }
        //throw "frame tail error";

    return true;
}



int main()
{
    try {
        vector<int> arr(3, 10);
        for (int i = 0; i < 3; i++)
            cout << arr.at(i) << endl;

        arr.at(3) = 100; //抛出 out_of_range

        cout << "next"  << endl;
    }
    catch (out_of_range &err) {
        cout << "hello" << endl;
        cout << err.what() << endl;
    }

    try
    {
        int ret = func(10, 0);
        cout << "end ...." << endl;
    }
    catch (const char *msg) { //捕获 const char *
        cout << "err" << endl;
        cout << msg << endl;
    }
    catch (int msg)
    {

    }
    catch (FHeaderErr &err) {
       cout <<  err.what() << endl;
    }
    catch (FTailErr &err)
    {
        cout <<  err.what() << endl;
    }
    return 0;
}
