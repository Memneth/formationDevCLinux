#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("John Doe");
MODULE_DESCRIPTION("Module hello world");
MODULE_VERSION("Version 1.00");

int init_module(void)
{
	printk(KERN_INFO "[Hello world] - La fonction init_module() est appelée.\n");
	return 0;
}

void cleanup_module(void)
{
	printk(KERN_INFO "[Hello world] - La fonction cleanup_module() est appelée.\n");
}

