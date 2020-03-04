#include <bfd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc < 2) {
	printf("Usage:\n");
	exit(1); 
    }

    bfd_init(); 
    bfd_set_default_target("i686-pc-linux-gnu"); 
    
    bfd *pbfd = bfd_openr(argv[1], "i686-pc-linux-gnu"); 
    if (!pbfd) {
	perror("bfd_openr"); 
	exit(1);
    }

    char **matching;
    bfd_check_format(pbfd, bfd_archive); 
    bfd_check_format_matches(pbfd, bfd_object, &matching); 

    asection *psec = pbfd->sections; 

    int count = 0; 
    while (psec) {
	printf("Name: %s\n", psec->name); 
	if (psec->flags & SEC_READONLY && psec->flags & SEC_DATA) {
	    bfd_byte *data = 0; 
	    bfd_vma size = bfd_get_section_size(psec);
	    data = (bfd_byte *)malloc(size); 
	    count += size; 
	    bfd_get_section_contents(pbfd, psec, data, 0, size); 

	    printf("  Data and readonly: vma 0x%08lx, size %d, %c %c %c %c\n",
		   psec->vma, psec->size, data[0], data[1], data[2], data[3]); 
	}
	if (psec->flags & SEC_CODE)
	    printf("  Code section: vma 0x%08lx, size %d \n", 
	           psec->vma, psec->size); 
	psec = psec->next; 
    }

    printf("Total size of ro data: %d\n", count); 
}

