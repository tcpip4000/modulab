#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <asm/current.h>
#include <linux/sched.h>

static int modulab(void)
{
	printk(KERN_INFO "modulab: modulab module being loaded. \n");
	printk(KERN_INFO "modulab: user space process is '%s'. \n", current->comm);
	printk(KERN_INFO "modulab: User space PID is '%i'. \n", current->pid);
	return 0;
}

static void bye(void)
{
	printk(KERN_INFO "modulab: module being unloaded. \n");
}

module_init(modulab);
module_exit(bye);

MODULE_AUTHOR("Juan P. Daza P.");
MODULE_LICENSE("GPL v2");
MODULE_DESCRIPTION("Experimental module");
MODULE_VERSION("0.0.1");



