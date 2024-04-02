#include <iostream>
using namespace std;

int main() {
    unsigned short data = 0xffee;
    unsigned char *ptr = (unsigned char*)(&data);
    cout << "待检验的数据： 0x" << hex << data << endl;
    cout << "低字节: " << hex << (int)(*ptr) << endl;
    cout << "高字节: " << hex << (int)(*(ptr+1)) << endl;
    cout << "小端存储方式" << endl;
}