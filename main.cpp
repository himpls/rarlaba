#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

struct header{
    uint16_t crc;
    uint8_t type;
    uint16_t flags;
    uint16_t size;
};

struct file_head{
    uint32_t PackSize;
    uint32_t UnpSize;
    uint8_t HostOS;
    uint32_t FileCRC;
    uint32_t FileTime;
    uint8_t Unpver;
    uint8_t Method;
    uint16_t NameSize;
    uint32_t FileAttr;
    uint16_t FileName;
};

int main()
{
    ifstream file("C:\\laba2\\labaaa\\laba.rar", ios::binary);
    if (file.is_open())
    {
        file.seekg(0, ios::end);
        int size = file.tellg();
        file.seekg(0, ios::beg);
        vector <char> readfile(size, 0);
        file.read(readfile.data(), size);
        out(readfile, 20);
    }
    else
    {
        cout << "File is not opened" << endl;
    }
}
