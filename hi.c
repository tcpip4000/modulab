#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <asm/current.h>
#include <linux/sched.h>

static int hi(void)
{
	printk(KERN_INFO "hi module being loaded");
	printk(KERN_INFO "User space process is '%s'\n", current->comm);
	printk(KERN_INFO "User space PID is '%i'\n", current->pid);
	return 0;
}

static void bye(void)
{
	printk(KERN_INFO "hi module being UNloaded");
}

module_init(hi);
module_exit(bye);

MODULE_AUTHOR("Juan P Daza P");
MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Experimental module");

