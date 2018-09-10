#include <linux/list.h>
#include <linux/types.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
// If you are using kmalloc or kzalloc() for memory allocation you have to include linux/slab.h they are called as slab allocators, these slab are chunks i.e. "cache" present in RAM and are physically contiguous. These slab allocator use underlying "Buddy System Algorithm", buddy allocator to provide more fine-grained allocation.
#include <linux/slab.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kanatip Chitavisutthivong");
MODULE_DESCRIPTION("Kernel Data Structure");
MODULE_VERSION("0.1");

static LIST_HEAD(student_list);

struct student {
	int grade;
	int id;
	struct list_head list;
};

int student_list_init(void)
{
	struct student *person;
	int i;
	for(i = 0; i < 5 ;i++) 
	{
		person = kmalloc(sizeof(*person), GFP_KERNEL);
		person->grade = 10-i;
		person->id = 1370139+(13*i);
		INIT_LIST_HEAD(&person->list);
		list_add_tail(&person->list, &student_list);
	}

	printk(KERN_INFO "Loading Module\n");	

	list_for_each_entry(person, &student_list, list) 
	{
		printk(KERN_INFO "Grade: %d ID: %d\n", person->grade, person->id);
	}
	return 0;
}	

void student_list_exit(void)
{
	struct student *person, *next;
	list_for_each_entry_safe(person, next, &student_list, list)
	{
		printk(KERN_INFO "Freeing node");
		list_del(&person->list);
		kfree(person);
	}
	printk(KERN_INFO "Removing Module\n");
}

module_init(student_list_init);
module_exit(student_list_exit);