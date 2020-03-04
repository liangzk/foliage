#include <stdarg.h>

void g(int a, va_list ap)
{
 	printf("%d\n", a);
	int tmp = va_arg(ap, int); 
 	printf("%d\n", tmp);
	tmp = va_arg(ap, int);
 	printf("%d\n", tmp);
}

void f(int a, ...)
{
	va_list list; 

	printf("%d\n", sizeof(list));
	va_start(list, a); 
	g(a, list);
	va_end(list);	
}

main()
{
	f(1, 2, 3);		
	return 0; 
}
