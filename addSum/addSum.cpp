// addSum.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "string.h"
unsigned char t_str_to_char(unsigned char *p)
{
    unsigned char val = 0;
    if (*p >= '0' && *p <= '9')
    {
        val |= *p - '0';
    }
    else if (*p == 'a' || *p == 'A')
    {
        val |= 0x0a;
    }
    else if (*p == 'b' || *p == 'B')
    {
        val |= 0x0b;
    }
    else if (*p == 'c' || *p == 'C')
    {
        val |= 0x0c;
    }
    else if (*p == 'd' || *p == 'D')
    {
        val |= 0x0d;
    }
    else if (*p == 'e' || *p == 'E')
    {
        val |= 0x0e;
    }
    else if (*p == 'f' || *p == 'F')
    {
        val |= 0x0f;
    }
    val <<= 4;
    p++;
    if (*p >= '0' && *p <= '9')
    {
        val |= *p - '0';
    }
    else if (*p == 'a' || *p == 'A')
    {
        val |= 0x0a;
    }
    else if (*p == 'b' || *p == 'B')
    {
        val |= 0x0b;
    }
    else if (*p == 'c' || *p == 'C')
    {
        val |= 0x0c;
    }
    else if (*p == 'd' || *p == 'D')
    {
        val |= 0x0d;
    }
    else if (*p == 'e' || *p == 'E')
    {
        val |= 0x0e;
    }
    else if (*p == 'f' || *p == 'F')
    {
        val |= 0x0f;
    }
    return val;
}

int main()
{
    unsigned char data_buff[10 * 1024] = { 0x00 };
    unsigned int csum = 0;
    unsigned char vall = 0;
    while (1)
    {
        csum = 0;
        memset(data_buff, 0x00, sizeof(data_buff));
        printf("请输入数据\r\n>>\r\n");
        scanf("%s", data_buff);
        printf("读取到的数据:\r\n%s\r\n", data_buff);

        for (int i = 0; i < strlen((char*)data_buff) / 2; i++)
        {
            vall = t_str_to_char(&data_buff[i * 2]);
            printf("0x%02X\r\n", vall);
            csum += vall;
        }
        printf("\r\n校验和为:%08X\r\n", csum);
    }
    return 0;
}

