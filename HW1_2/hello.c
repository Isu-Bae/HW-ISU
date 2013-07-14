#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/miscdevice.h>
#include <linux/sched.h>
#include <linux/poll.h>
#include <linux/version.h>

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,0)
#define preempt_get_count preempt_count
#endif

static struct file_operations char_fops = {
	.owner = THIS_MODULE,
};

static struct miscdevice char_dev = {
	.minor = MISC_DYNAMIC_MINOR,
	.name = "preempt_test",
	.fops = & char_fops
};
int __init init_hello(void)
{
	int ret;
	printk(KERN_ALERT "[Module Message] I will insert a misc driver.\n");
	ret = misc_register(&char_dev);
	if(ret) {
		printk(KERN_ERR "misc_register() failed.\n");
	}
	return ret;
}

void __exit exit_hello(void)
{
	misc_deregister(&char_dev);
	printk(KERN_ALERT "[Module Message] I will remove a misc driver\n");
}
module_init(init_hello);
module_exit(exit_hello);

MODULE_LICENSE("GPL");
