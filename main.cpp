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
