#include<coding.h>

unsigned char encode(unsigned char c)
{
	c-=1;
    return c;
}
unsigned char decode(unsigned char c)
{
	c+=1;
    return c;
}
