#include<stdio.h>
#include<string.h>
#include<stdlib.h>
  void main()
  { int mntc=0,mdtc=0,args=0,i;
     FILE *f1,*f2,*f3,*f4;
     char label[20],opcode[20],operand[20];
     f1=fopen("input.txt","r");
     f2=fopen("mnt_tab.txt","w+");
     f3=fopen("mdt_tab.txt","w+");
     f4=fopen("arg_tab.txt","w+");
     fscanf(f1,"%s%s%s",label,opcode,operand);
     while(strcmp(opcode,"END")!=0)
     { 
       if(strcmp(opcode,"MACRO")==0)
       { mntc++;
          mdtc++;
          fprintf(f2,"%d\t%s\t%d\n",mntc,label,mdtc);
          fprintf(f3,"%d\t%s\t%s\n",mdtc,label,operand);
          fprintf(f4,"%d\t",++args);
          for(i=0;i<strlen(operand);i++)
          if(operand[i]!=',')
            fprintf(f4,"%c",operand[i]);
          else
            fprintf(f4,"\n%d\t",++args);
          fscanf(f1,"%s%s%s",label,opcode,operand);
          while(strcmp(opcode,"MEND")!=0)
          { mdtc++;
             fprintf(f3,"%d\t%s\t%s\n",mdtc,opcode,operand);
             fscanf(f1,"%s%s%s",label,opcode,operand);
          }
          mdtc++;
          fprintf(f3,"%d\t%s\t%s\n",mdtc,opcode,operand);
          }
          fscanf(f1,"%s%s%s",label,opcode,operand);
       }
     fclose(f1);
     fclose(f2);
     fclose(f3);
     printf("PASS 1 Successfully Completed\n");
   }  
