#include<stdio.h>
#include<elf.h>

#define FILE_PATH "/home/mariammostafa/task_2/task2"

int main(int argc,char**argv){


char*x_version;
char*x_type;
char*x_machine;

FILE* elfFile=fopen(FILE_PATH,"r");

Elf64_Ehdr elfHeader;

fread(&elfHeader,sizeof(elfHeader),1,elfFile);
printf("Elf Header:\n");
printf(" Magic:  ");
for (int i = 0; i < EI_NIDENT; ++i) {
        printf("%02x ", elfHeader.e_ident[i]);
    }
    printf("\n");

printf(" Class:                             ELF64\n ");

printf(" Data:                             2's complement,  llttle endian\n");

switch(elfHeader.e_version){
case 0:  x_version="(Invalid)";
break;
case 1: x_version="(current)";
break;
}


printf(" Version:                           %d %s\n",elfHeader.e_version,x_version);
printf(" OS/ABI:                            UNIX - System V\n");
printf(" ABI Version:                       %d\n",elfHeader.e_ident[EI_OSABI]);



switch(elfHeader.e_type){
case 0: x_type="ET_NONE: No file type";
break;
case 1: x_type="ET_REL: Relocatable file";
break;
case 2: x_type="ET_EXEC: Executable file";
break;
case 3: x_type="ET_DYN: Shared object file";
break;
case 4: x_type="ET_CORE: Core file";
break;
defult:
x_type="unkown e_type";
break;


}
printf(" type:                              %s\n ",x_type);

switch(elfHeader.e_machine){
case 0: x_machine="EM_NONE:No machine";
break;

case 2: x_machine="EM_SPARC:SPARC";
break;

case 3: x_machine="EM_386:Intel 80386";
break;

case 18: x_machine="EM_SPARC32PLUS:Sun SPARC 32+";
break;

case 43: x_machine="EM_SPARCV9:SPARC V9";
break;

case 62: x_machine="EM_AMD64:AMD64";
break;


}
printf("Machine:                           %s\n",x_machine);

printf(" Version:                           0x%u\n",elfHeader.e_version);
printf(" Entry point address:               0x%lx\n",elfHeader.e_entry);
printf(" Start of program header:           %ld (bytes into files)\n",elfHeader.e_phoff);
printf(" Start of section header:           %lu (bytes into file)\n",elfHeader.e_shoff);
printf(" Flags:                             0x%x\n",elfHeader.e_flags);
printf(" Size of this header:               %d (bytes)\n",elfHeader.e_ehsize);
printf(" Size of program headers:           %d (bytes) \n",elfHeader.e_phentsize);
printf(" Number of program headers:         %d \n",elfHeader.e_phnum);
printf(" Size of section heades:            %d (bytes) \n",elfHeader.e_shentsize);
printf(" Number of section headers:         %d \n",elfHeader.e_shnum);
printf(" Section header string table index: %d\n ",elfHeader.e_shstrndx);




return 0;
}
