int main(void)
{
    unsigned char a, b, c;
    a = 0x3;                    //  0x3二进制表示为  0011
    b = a|0x8;                  //  0x80二进制表示为 1000 ,1000与上0011 为1011转为十进制为11
    c = b<<1;                   //  b << 1 也就是 1011右移1位为 10110 转为十进制为22
    printf("%d%d\n", b, c);     //  所以打印出 11和22
}