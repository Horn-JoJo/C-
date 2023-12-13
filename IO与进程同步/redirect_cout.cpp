#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    fstream file;
    file.open("cout.txt", ios::out);
    string line;

    //保存cin和cout的缓冲区buffer
    streambuf* stream_buf_cout = cout.rdbuf();
    streambuf* stream_buf_cin = cin.rdbuf();

    //获取文件file的缓冲区buffer 
    streambuf* stream_buf_file = file.rdbuf();

    //cout 重定向输出到文件file
    cout.rdbuf(stream_buf_file);
    cout << "The cout is redirected to file" << endl;

    //恢复重定
    cout.rdbuf(stream_buf_cout);
    cout << "hello world!!!" << endl;

    file.close();
    return 0;
}

