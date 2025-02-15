#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


#define size_gerador 7
#define size_hamming 4

unsigned char m_geradora[size_gerador] = {0b1101, 0b1011, 0b1000, 0b0111, 0b0100, 0b0010, 0b0001};
unsigned char m_hamming[size_hamming] = {0b1010101, 0b0110011, 0b0001111};

/*
void canal( char* in, char* out )
{
int i = 1, erro=0;
while (*in != '\0')
	{
        	erro=0;      
		i=(i+5)%7;
		if(i>3){erro=0;}else{erro=pow(2,i);} //função que gera os erros
		*out = (*in)^(char)(erro);
		out++;
		in++;
		i++;
	}
	*out = '\0';
}
*/	

/*
    Byte Stuffing
*/
void bytestuff(char* input, char* output)
{
   int i=0; //input index
   int j=0; //output index

   while(input[i] != '\0')
   {
       if(input[i] == 'H')
       {
           output[j] = input[i];
            output[j+1] = '&';
            j+=2;
       }
       
       else
       {
           output[j] = input[i];
           j++;
       }
       i++;   
   }
}

/*
    Byte Destuffing
*/
void bytedestuff(char* input, char* output)
{
    int i=0;
    int j=0;

    while(input[i] != '\0')
    {
        if(input[i] != '&')
        {
            output[j] = input[i];
            j++;
        }

        i++;
    }
}

/*
    Hamming Code
*/
void char_to_binary(char c, char* first, char* second)
{
    int j=0;
    int k=0;

    for (int i = 7; i >= 0; --i)
    {
        if(i > 3)
        {
            first[j] = (c & (1 << i)) ? '1' : '0';
            j++;
        }

        else
        {
            second[k] = (c & (1 << i)) ? '1' : '0';
            k++;
        }    
    }

    //Testes de print
    printf("First:\n");
    for(int i=0 ; first[i]!='\0'; i++)
    {
        printf("%c", first[i]);
    }
    printf("\nSecond:\n");

    for(int i=0 ; second[i]!='\0'; i++)
    {
        printf("%c", second[i]);
    }
    printf("\n");
    
}


int count_ones_for_XOR(int n)
{
    int count=0;
    // array to store binary number 
    int binaryNum[32]; 
  
    // counter for binary array 
    int i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binaryNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 

    for(int i=0 ; i<32 ; i++)
    {
        if(binaryNum[i] == 1)
        {
            count++;
        }
    }
    
    if(count % 2 == 0)
        return 0;

    else
        return 1;
}


int binary_to_decimal(char* input)
{
    int result=0, str_size = 0;

    for(int i=0 ; input[i] != '\0' ; i++)
        str_size++;

    for(int i=0 ; input[i] != '\0' ; i++)
    {
        if(input[i] == '1')
            result += pow(2, (str_size-i)-1);  //Conversão para decimal do numero em binario presente no array
    }
    return result;
}


void hcode(char* input, char* output)
{  
    char first[5];
    char second[5];
    int x[7];
    char x_char[7];
    int a=0;
    int left=0;
    int right=0;

    for(int i=0 ; input[i]!='\0' ; i++)
    {
        char_to_binary(input[i], first, second);

        left = binary_to_decimal(first);
        right = binary_to_decimal(second);

        printf("%d  %d\n\n", left, right);
        
        for(int j=0 ; j<size_gerador ; j++)
        {
            a = m_geradora[j] & left;

            x[j] = count_ones_for_XOR(a);

            //printf("%d", x[j]);
        }

        printf("\n");

        for(int j=0 ; j<size_gerador ; j++)
            printf("%d", x[j]);
    }
}
        
// hdecode(char*, char*);


int main()
{
    char a[100]; 
    char b[200]; 
    //char c[200];

    //strcpy ( a , "ABCDEFGHHHHHIJKLMNOPQR1234567890abcdefghijklmnopqrstuvxyz  :-))))))");

    strcpy(a, "A");

    //hcode(a,b);
    //bytestuff(b,c);
    //canal(c,d);
    //bytedestuff(d,e);
    //hdecode(e,f);

    /*printf("\n a %s",a);
    printf("\n b %s",b);
    printf("\n c %s",c);
    printf("\n d %s",d);
    printf("\n e %s",e);
    printf("\n f %s",f);*/

    
    /*unsigned char resposta[2];

   
    resposta[1] = code & code;*/

    //printf("%d\n", 0b0011 & 0b1111);
    

    //hcode(m_geradora,a);
    /*
    bytestuff(a,b);

    for(int i=0 ; b[i] != '\0'; i++)
    {
        printf("%c", b[i]);
    }

    printf("\n");

    bytedestuff(b,c);

    for(int i=0 ; c[i] != '\0'; i++)
    {
        printf("%c", c[i]);
    }*/

    hcode(a,b);
    
    return 0;
}


