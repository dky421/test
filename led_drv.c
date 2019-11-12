static int led_open(struct inod *inod, struct file *file)
{
  printk("led open\n");
  return 0;
}

static ssize_t led_write(struct file *file, const char __user *buf, size_t cnt, loff_t *ppos)
{
  printk("led write\n");
  return 0;
}

static struct file_operations led_fops = {
  .owner = THIS_MODULE;
  .open  = first_drv_open;
  .write = first_drv_write;
};

int led_init(void)
{
  register_chrdev(123, "led", &first_drv_fops);
  printk("led init\n")
  return 0;
}

void led_exit(void)
{
  unregister_chrdev(123, "led");
  printk("led exit\n");
}
