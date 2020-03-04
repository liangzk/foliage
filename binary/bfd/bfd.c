#include <bfd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc < 2) {
	fprintf(stderr, "Usage: %s binary\n", argv[0]); 
	exit(1); 
    }

    bfd_init(); 
    bfd_set_default_target("i686-pc-linux-gnu");

    bfd *pbfd = bfd_openr(argv[1], "i686-pc-linux-gnu");
    if (!pbfd) {
        perror("bfd_openr");
        exit(1);
    }

    Elf_Internal_Phdr *p;
    p = pbfd->tdata.elf_obj_data->phdr; 

    bfd_close(pbfd);

    return 0; 
}
