#include <stdio.h>
#include <stdint.h>
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>
#include "warp7.h"


int main() {
    int file, i;
    unsigned char data;
    int val1;
    int val2;
    int t_m;
    int t_l;

	if ((file = open("/dev/i2c-3", O_RDWR)) < 0) 
	{
    perror("Error openning file!");
    exit(1);
  }

//0x0C whoami verify
   if(read_register(file, 0x20, 0x0C, &data))
    exit(1);
   else
    printf("GET:Register[0x%02X]: 0x%02X\n" , 12 , data);

    close(file);
    return 0;
}


