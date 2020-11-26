#include <linux/module.h>
#include <linux/kernel.h>

int a,b;

int init_module(void){
    
    a = 5+10;
    b = 25-14;

    printk(KERN_INFO "5 + 10 is equal to %d",a);
    printk(KERN_INFO "25 - 14 is equal to %d",b);
    return 0;
}

void cleanup_module(void){
	printk(KERN_INFO "Module out");
}
