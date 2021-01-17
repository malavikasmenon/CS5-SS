#include<stdio.h>
#include<string.h>
#include<stdlib.h>
  void main()
  {
    FILE *f1,*f2,*f3,*f4,*f5;
    int i,len,mntc,mdtc,index,flag=0,args=0,in;
    char label[20],operand[20],opcode[20],name[20],
            opcode1[20],operand1[20],arg[20];
    f1=fopen("input.txt","r");
    f2=fopen("mnt_tab.txt","r");
    f3=fopen("mdt_tab.txt","r");
    f4=fopen("arg_tab.txt","w+");
    f5=fopen("output.txt","w");
    fscanf(f1,"%s%s%s",label,opcode,operand);
    while(strcmp(opcode,"END")!=0)
   {
      if(strcmp(opcode,"MACRO")==0)
      {
        fscanf(f1,"%s%s%s",label,opcode,operand);
        while(strcmp(opcode,"MEND")!=0)
         fscanf(f1,"%s%s%s",label,opcode,operand);
      }
      else
     { flag=0;
        fscanf(f2,"%d%s%d",&mntc,name,&mdtc);
        while(!feof(f2))
       {
         if(strcmp(opcode,name)==0)
         {
           len=strlen(operand);
           fprintf(f4,"%d\t",++args);
           for(i=0;i<strlen(operand);i++)
            if(operand[i]!=',')
             fprintf(f4,"%c",operand[i]);
            else
             fprintf(f4,"\n%d\t",++args);
        
           fseek(f2,SEEK_SET,0);
           fseek(f4,SEEK_SET,0);
           fscanf(f3,"%d%s%s",&index,opcode1,operand1);
           while(mdtc!=index)
            fscanf(f3,"%d%s%s",&index,opcode1,operand1);
           fscanf(f3,"%d%s%s",&index,opcode1,operand1);
           while(strcmp(opcode1,"MEND")!=0)
           { if(operand1[0]=='?')
             { fseek(f4,SEEK_SET,0);
               fscanf(f4,"%d%s",&in,arg);
               i = operand1[1] - '0';
               while(in!=i)
                fscanf(f4,"%d%s",&in,arg);
               fprintf(f5,"-\t%s\t%s\n",opcode1,arg);
             }
             else
              fprintf(f5,"-\t%s\t%s\n",opcode1,operand1);
             fscanf(f3,"%d%s%s",&index,opcode1,operand1);
           }
           flag=1;
           break;
          }
          fscanf(f2,"%d%s%d",&mntc,name,&mdtc);
         }
        if(flag==0)
         fprintf(f5,"%s\t%s\t%s\n",label,opcode,operand);
        fseek(f2,SEEK_SET,0);
      }
      fscanf(f1,"%s%s%s",label,opcode,operand);   
    }
    fprintf(f5,"%s\t%s\t%s",label,opcode,operand);
    fclose(f1);
    fclose(f2);
    fclose(f3);
    fclose(f4);
    fclose(f5);
    printf("PASS 2 Successfully Completed");
    }
     
