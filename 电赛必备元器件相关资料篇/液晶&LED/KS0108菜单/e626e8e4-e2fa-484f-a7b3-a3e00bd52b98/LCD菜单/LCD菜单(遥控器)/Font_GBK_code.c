// ------------------  汉字字模的数据结构定义 ------------------------ //
typedef struct typFNT_GB16			// 汉字字模数据结构
{
       unsigned char Index[2];		// 汉字内码索引
       unsigned char Msk[32];		// 点阵码数据
};


/////////////////////////////////////////////////////////////////////////
// 汉字字模表                                                          //
// 汉字库: 宋体16.dot 纵向取模下高位,数据排列:从左到右从上到下         //
/////////////////////////////////////////////////////////////////////////
struct typFNT_GB16 code GB_16[] =          // 数据表
{
"欢", 0x04,0x34,0xC4,0x04,0xC4,0x3C,0x20,0x10,0x0F,0xE8,0x08,0x08,0x28,0x18,0x00,0x00,
      0x10,0x08,0x06,0x01,0x82,0x8C,0x40,0x30,0x0C,0x03,0x0C,0x10,0x60,0xC0,0x40,0x00,

"迎", 0x40,0x42,0x44,0xC8,0x00,0xFC,0x04,0x02,0x82,0xFC,0x04,0x04,0x04,0xFE,0x04,0x00,
      0x00,0x40,0x20,0x1F,0x20,0x47,0x42,0x41,0x40,0x7F,0x40,0x42,0x44,0x43,0x40,0x40,

"使", 0x40,0x20,0xF8,0x07,0x04,0xF4,0x14,0x14,0x14,0xFF,0x14,0x14,0x14,0xF6,0x04,0x00,
      0x00,0x00,0xFF,0x00,0x80,0x43,0x45,0x29,0x19,0x17,0x21,0x21,0x41,0xC3,0x40,0x00,

"用", 0x00,0x00,0xFE,0x22,0x22,0x22,0x22,0xFE,0x22,0x22,0x22,0x22,0xFF,0x02,0x00,0x00,
      0x80,0x60,0x1F,0x02,0x02,0x02,0x02,0x7F,0x02,0x02,0x42,0x82,0x7F,0x00,0x00,0x00,

"菜", 0x04,0x04,0x24,0x64,0xA4,0x2F,0x64,0xA4,0x24,0x2F,0x94,0x54,0x14,0x06,0x04,0x00,
      0x02,0x42,0x42,0x22,0x12,0x0A,0x06,0xFF,0x06,0x0A,0x12,0x12,0x22,0x63,0x22,0x00,

"单", 0x00,0x00,0xF8,0x49,0x4A,0x4C,0x48,0xF8,0x48,0x4C,0x4A,0x49,0xFC,0x08,0x00,0x00,
      0x10,0x10,0x17,0x12,0x12,0x12,0x12,0xFF,0x12,0x12,0x12,0x12,0x13,0x18,0x10,0x00,

"演", 0x10,0x21,0x66,0x10,0x8C,0xA4,0xA4,0xA4,0xA5,0xE6,0xA4,0xA4,0xA4,0xB4,0x0C,0x00,
      0x04,0x04,0xFE,0x01,0x00,0x8F,0x4A,0x6A,0x0A,0x0F,0x0A,0x2A,0x4A,0xCF,0x00,0x00,

"示", 0x40,0x40,0x42,0x42,0x42,0x42,0x42,0xC2,0x42,0x42,0x42,0x43,0x42,0x60,0x40,0x00,
      0x00,0x10,0x08,0x04,0x06,0x40,0x80,0x7F,0x00,0x00,0x02,0x04,0x0C,0x18,0x00,0x00,

"系", 0x00,0x02,0x22,0x22,0x32,0x2E,0xA2,0x62,0x22,0x22,0x91,0x09,0x01,0x00,0x00,0x00,
      0x00,0x00,0x42,0x22,0x1A,0x43,0x82,0x7E,0x02,0x02,0x0A,0x13,0x66,0x00,0x00,0x00,

"统", 0x20,0x30,0xAC,0x63,0x30,0x88,0xC8,0xA8,0x99,0x8E,0x88,0xA8,0xCC,0x88,0x00,0x00,
      0x22,0x67,0x22,0x12,0x92,0x40,0x30,0x0F,0x00,0x00,0x3F,0x40,0x40,0x41,0x70,0x00
};
#define GB_16_num	sizeof(GB_16) / 34				//汉字个数
// 汉字表：
// 欢迎使用菜单演示系统
