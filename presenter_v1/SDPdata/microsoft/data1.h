	FILE *fo;
	int data_num,cluster_num,res_data_num;
	unsigned char char_array[]={ '0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};

unsigned char buf[]={

	
0x36,0x00,0x5d,
//*****************************************************
0x36,0x00,0x5a,

0x09,0x00,0x00,
0x0a,0x00,0x01,0x00,0x01,

0x09,0x00,0x01,
0x35,0x03,0x19,0x12,0x00,

0x09,0x00,0x04,
0x35,0x0d,
0x35,0x06,0x19,0x01,0x00,0x09,0x00,0x01,
0x35,0x03,0x19,0x00,0x01,

0x09,0x00,0x05,
0x35,0x03,0x19,0x10,0x02,

0x09,0x00,0x09,
0x35,0x08,0x35,0x06,0x19,0x12,0x00,0x09,0x01,0x00,

0x09,0x02,0x00,
0x09,0x01,0x00,

0x09,0x02,0x01,
0x09,0x05,0x7e,

0x09,0x02,0x02,
0x09,0x03,0x09,

0x09,0x02,0x03,
0x09,0x06,0x00,

0x09,0x02,0x04,
0x28,0x01,

0x09,0x02,0x05,
0x09,0x00,0x02

};

