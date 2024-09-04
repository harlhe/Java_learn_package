#include <iostream>
#include <string>

using namespace std;

class Test
{
public:
    void set_x(int x)
    {this->x = x;}

    int get_x() const
    {return x;}

private:
    int x;
};

int main() {
    /*
    string s1; //空字符串
    cout << s1 << endl;
    cout << s1.size() << endl;
    cout << s1.length() << endl;

    string s2("hello");
    cout << s2 << endl;
    cout << s2.size() << endl;
 //   cout << s2.length() << endl;

    string s3(4, 'k');
    cout << s3 << endl;

    string s4("12345", 1, 3);
    cout << s4 << endl;

    s1 = "hello"; //char *
    cout << s1 << endl;

    s1 = 'A'; //char
    cout << s1 << endl;
    */

    /*
    string s1("abcdef"), s2;
    //s2.assign(s1); //s2 = s1;
    s2 = s1;
    cout << s2 << endl;

    s2.assign(s1, 1, 3);
    cout << s2 << endl;

    char ch;
    ch = 'A';
    int x = 3;
    s2.assign(3, ch); //s2 = "BBB";
    cout << s2 << endl;
    */

    /*
    string s1 = "##temp=";
    string s2;

    float val = 33.6;
    s2 = to_string(val); //将float类型转换成 string对象

    string s3;
    s3 = s1 + s2;
    cout << s3 << endl;
    */

    /*
    string s1("123"), s2("abc");
    string s3;
    s3 = s1.append(s2); //将s2追加到s1的后面  s1 = s1 + s2;
    cout << s1 << endl;
    cout << s3 << endl;

    s1.append(s2, 1, 2);
    cout << s1 << endl;

    s1.append(3, 'k');
    cout << s1 << endl;

    s1.append("ABCDE", 2, 3);
    cout << s1 << endl;
    */

    /*
    string s1 = "hello";
    string s2 = "hello,world";

    bool ret;
    ret = s1 > s2;
    if (ret)
        cout << "s1 > s2" << endl;
    else
        cout << "s1 < s2" << endl;

    ret = s2 > s1;
    if (ret)
        cout << "s2 > s1" << endl;
    else
        cout << "s2 < s1" << endl;

    if (s1 == "zhangsan")
        ;
    cout << s2.compare(s1) << endl;

    cout << s1.compare(1,2,s2,0,3) << endl; //el, hel
    cout << s1.compare(0,2,s2) << endl; //he, hello,world
     */

    /*
    string s1 = "this is ok";
    string s2 = s1.substr(2, 4);
    cout << s2 << endl;

    s2 = s1.substr(3);
    cout << s2 << endl;
    */

    /*
    string s1 = "##temp=32.5;hum=67.6##";
    int pos;
    if ((pos = s1.find('x')) != string::npos)
        cout << pos << endl;
    else
        cout << "no x " << endl;

    if ((pos = s1.rfind('=')) != string::npos)
        cout << pos << endl;
    else
        cout << "no = " << endl;

    string names[4];
    names[0] = "zhanghua";
    names[1] = "lisi";
    names[2] = "lihua";
    names[3] = "zhangsan";

    //查找出名字中带hua的同学
    for (int i = 0; i < 4; i++)
    {
        if (names[i].find("hua") != string::npos)
            cout << names[i] << endl;
    }

    //查找出姓zhang的同学
    for (int i = 0; i < 4; i++)
    {
        if (names[i].find("zhang") == 0)
            cout << names[i] << endl;
    }
    */

#if 0
    string s1("Real steel abdcd");
   // s1.replace(1, 3, "123456", 2, 4);
    s1.replace(1, 3, 4, '0');

    int n = s1.find("0000");
    //判断是否找到了字串"0000"
    if (n != string::npos)
        s1.replace(n, 4, "kkk");
    cout << s1 << endl;

   // s1.erase(1, 3);
   // s1.erase(5);
   /*删除字符串中的steel
    * 1 先找到steel
    */
    n = s1.find("steel");
    if (n != string::npos)
    {
        //2、删除
        s1.erase(n, 5); //删除从下标n开始的所有的字符
    }

    cout << s1 << endl;
#endif

    string s1("Limitless"), s2("00");
    s1.insert(2, "123");
    cout << s1 << endl;

    s1.insert(3, s2);
    cout << s1 << endl;
    s1.insert(3, 5, 'X');
    cout << s1 << endl;

    //将"hello" 中的子串[1,3]插入到s1下标为3的位置
    s1.insert(3, "hello", 1, 3);
    cout << s1 << endl;

    //将string对象中的字串插入
    string s3("world");
    s1.insert(3, s3, 1, 3);
    cout << s1 << endl;
    
    return 0;
}
