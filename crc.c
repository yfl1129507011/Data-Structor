#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef unsigned short ushort;
typedef unsigned char uchar;
typedef unsigned int uint;


/*G16(x) = x16 + x12 + x5 + 1     1001000000100001*/
ushort crc16()
{
	return (ushort)( (1 << 16) | (1 << 12) | (1 << 5) | (1) );
}

ushort reverse(ushort data)
{
	ushort bit = 0, sum = 0;
	for (int i = 0; i < sizeof(ushort)*8; ++i)
	{
		sum = sum << 1;
		bit = 1 & data;
		data = data >> 1;
		sum = sum | bit;
	}

	return sum;
}

ushort checkCrc16(uchar *data, ushort len)
{
	ushort crcin = 0x0000;  // CRC的初始值
	ushort poly = crc16();  // CRC的多项式值
	
	while(len--)
	{
		crcin ^= *data++;  // crcin ^= *data; data++;
		for (int i = 0; i < 8; ++i)
		{
			if (crcin & 1)
			{
				crcin = (crcin >> 1) ^ reverse(poly);   // 0x8408 = reverse 0x1021
			}
			else
			{
				crcin = (crcin >> 1);
			}
		}

	}

	return crcin;
}

uint16_t crc16_ccitt(uint8_t *data, uint16_t len)
{
	uint8_t i;
	uint16_t crc = 0x0;
	while(len--)
	{
		crc ^= (uint16_t)(*data++) << 8;
		for (i = 0; i < 8; ++i)
		{
			if (crc & 0x8000)
			{
				crc = (crc << 1) ^ 0x1021;
			}
			else
			{
				crc = (crc << 1);
			}
		}
	}

	return crc;
}

uint16_t crc16_ccitt_update_ref(uint16_t crc, uint8_t data) {
    crc ^= (uint16_t)data << 8;
    
    for(uint8_t i = 0; i < 8; i++) {
        if(crc & 0x8000) {
            crc = (crc << 1) ^ 0x1021;
        } else {
            crc = (crc << 1);
        }
    }
    
    return crc;
}


int main()
{
	/*ushort crc = crc16();
	printf("%x\n", crc);
	ushort rcrc = reverse(crc);
	printf("%x\n", rcrc);*/

	/*uint8_t data[] = {0x40, 0x00, 0x56};
	ushort crc = checkCrc16(data, 3);
	printf("%x\n", crc);
	uint16_t crc1 = crc16_ccitt(data, 3);
	printf("%x\n", crc1);*/

	uint8_t data[] = {0x40, 0x00, 0x56};
	uint16_t crc_16_c = ((uint16_t)0x0);
    uint16_t len = sizeof(data);
    for(uint16_t n = 0; n < len; n++) {
        crc_16_c = crc16_ccitt_update_ref(crc_16_c, data[n]);
    }
    printf("%x\n", crc_16_c);

    uint16_t crc1 = crc16_ccitt(data, len);
	printf("%x\n", crc1);

	return 1;
}