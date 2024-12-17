#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>

using namespace std;

struct header{
    uint16_t crc;
    uint8_t type;
    uint16_t flags;
    uint16_t Size;
};

struct main_head{
    uint16_t HighPosAv;
    uint32_t PosAv;
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

void write (vector<char> &readfile, int index)
{
while(true)
{
    header* Pheader = reinterpret_cast<header*> (&readfile[index]);
    if (int(Pheader->type) != 116){
        break;
    }
    else{
        cout<<"File name: ";
        file_head* d_file = reinterpret_cast<file_head*> (&readfile[index + 7]);
        for(int i = index + 32; i < index + int(d_file->NameSize) + 32;i++){
            cout << readfile[i];
        }
        cout << endl;
        index += int(d_file->PackSize);
        index += Pheader->Size;
    }
    cout << endl;
}
}


int main()
{
    ifstream file("C:\\laba2\\labaaa\\Example.rar", ios::binary);
    if (file.is_open())
    {
        file.seekg(0, ios::end);
        int Sizefile = file.tellg();
        file.seekg(0, ios::beg);
        vector <char> readfile(Sizefile, 0);
        file.read(readfile.data(), Sizefile);
        write(readfile, 20);
    }
    else
    {
        cout << "File is not opened" << endl;
    }
}

