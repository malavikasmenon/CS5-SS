#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{ 
    FILE *f1,*f2,*f3;
    char label[20], opcode[20], operand[20], op[20];
    int addr, locctr, op_value, start_addr, value, len;

    f1=fopen("program.txt","r");
    f2=fopen("symtab.txt","w");

    fscanf(f1,"%s %s %d",label,opcode,&addr);

    if(strcmp(opcode,"START")==0)
    { 
      start_addr=addr;
      locctr=start_addr;
      printf("\t%s\t%s\t%d",label,opcode,addr);
    }

    else
      locctr=0;
    
    fscanf(f1,"%s %s",label,opcode);
    //printf("Here %s %s", label, opcode);
    while(!feof(f1))
    { 
      fscanf(f1,"%s",operand);
      
      printf("\n%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
      if(strcmp(label,"-")!=0)
        fprintf(f2,"\n%d\t%s\n",locctr,label);
      f3=fopen("optab.txt","r");
      fscanf(f3,"%s %d",op,&op_value);
      while(!feof(f3))
      { if(strcmp(opcode,op)==0)
        { //printf("%s\n", opcode);
          locctr=locctr+3;
          break;
        }
        fscanf(f3,"%s %d",op,&op_value);
      }
      fclose(f3);
      if(strcmp(opcode,"WORD")==0)
        locctr=locctr+3;
      else if(strcmp(opcode,"RESW")==0)
      { value=atoi(operand);
        locctr=locctr+(3*value);
      }  
      else if(strcmp(opcode,"BYTE")==0)
      {
        if(operand[0]=='X')
          locctr=locctr+1;
        else
          { len=strlen(operand)-2;
            locctr=locctr+len;
          }
      }
      else if(strcmp(opcode,"RESB")==0)
      {
        value=atoi(operand);
        locctr=locctr+value;
      }
      fscanf(f1,"%s%s",label,opcode);
    }
    if(strcmp(opcode,"END")==0)
      printf("Program Length=%d",locctr-start_addr);
    fclose(f1);
    fclose(f2);
}

