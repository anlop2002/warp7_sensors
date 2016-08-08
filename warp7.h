static int write_register(int file,unsigned char address,unsigned char reg,unsigned char data) 
{

   unsigned char output_buffer[2];
   struct i2c_rdwr_ioctl_data packets;
   struct i2c_msg messages[1];

    messages[0].addr  = address;
    messages[0].flags = 0;
    messages[0].len   = sizeof(output_buffer);
    messages[0].buf   = output_buffer;

    output_buffer[0] = reg;
    output_buffer[1] = data;

    packets.msgs  = messages;
    packets.nmsgs = 1;
    if(ioctl(file, I2C_RDWR, &packets) < 0) {
        perror("Error sending data");
        return 1;
    }

    return 0;
}


static int read_register(int file, unsigned char address, unsigned char reg, unsigned char *data) 
{
    unsigned char input_buffer, output_buffer;
    struct i2c_rdwr_ioctl_data packets;
    struct i2c_msg messages[2];


    output_buffer = reg;
    messages[0].addr  = address;
    messages[0].flags = 0;
    messages[0].len   = sizeof(output_buffer);
    messages[0].buf   = &output_buffer;

    messages[1].addr  = address;
    messages[1].flags = I2C_M_RD;
    messages[1].len   = sizeof(input_buffer);
    messages[1].buf   = &input_buffer;

 
    packets.msgs      = messages;
    packets.nmsgs     = 2;
    if(ioctl(file, I2C_RDWR, &packets) < 0) {
        perror("Error sending data");
        return 1;
    }
    *data = input_buffer;

    return 0;
}



