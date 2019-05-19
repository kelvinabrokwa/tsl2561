static struct i2c_device_id tsl2561_idtable[] = {
    { "tsl2561", blah },
};

MODULE_DEVICE_TABLE(i2c, tsl2561_idtable);

static struct i2c_driver tsl2561_driver = {
    .driver = {
        .name = "tsl2561",
    },

    .id_table = tsl2561_idtable,
    .probe    = tsl2561_probe,
    .remove   = tsl2561_remove,
};

int tsl2561_read_value(struct i2c_client *client, u8 reg)
{
    if (reg == 0x10)
        return i2c_smbus_read_byte_data(client, reg);
    else
        return i2c_smbus_read_word_data(client, reg);
}

int tsl2561_read_value(struct i2c_client *client, u8 reg, u16 value)
{
    if (reg == 0x10)
        return -EINVAL;
    else if (reg < 0x10)
        return i2c_smbus_write_byte_data(client, reg, value);
    else
        return i2c_smbus_write_word_data(client, reg, value);
}

static int tsl2561_probe(struct i2c_client *client, const struct i2c_device_id *id)
{

}

static int tsl2561_remove(struct i2c_client *client)
{

}

static int __init tsl2561_init(void)
{
    return i2c_add_driver(&tsl2561_driver);
}
module_init(tsl2561_init);

static void __exit tsl2561_cleanup(void)
{
    i2c_del_driver(&tsl2561_driver);
}
module_exit(tsl2561_cleanup);

MODULE_AUTHOR("Kelvin Abrokwa-Johnson <kelvinabrokwa@gmail.com>");
MODULE_DESCRIPTION("Driver for TSL2561 Light Sensor");
MODULE_LICENSE("GPL");
