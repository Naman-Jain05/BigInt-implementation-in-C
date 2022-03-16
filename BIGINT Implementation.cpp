//BT20CSE087
#include<stdio.h>
#include<string.h>

int strlen(char * s) {   //returns length of our number
      int i = 0, sum = 0;
      char c = s[0];

      while(c != '\0') {
            sum++;
            c = s[++i];
      }
      return sum;
}

void strcpy(char dest[],char source[]) //copies source string to destination
{
    int i = 0;
    while (1)
    {
        dest[i] = source[i];

        if (dest[i] == '\0')
        {
            break;
        }

        i++;
    } 
}

void add()
{
	char a[1024],b[1024];
	int n1,n2;
	
	printf("\nEnter the first very long 1024 intbit Integer\n");
    scanf("%s",a);
    printf("\nEnter the second very long 1024 intbit Integer\n");
    scanf("%s",b);
    
	n1=strlen(a);
    n2=strlen(b);
	char res[1025];
    int i,j,carry=0,sum,k;
    i=n1-1;
    j=n2-1;
    k=n1>n2?n1:n2;
    res[k]='\0';
    k--;
   
    while(i>=0 && j>=0)
    {
        sum=(a[i]-48)+(b[j]-48)+carry;//ascii value of 0=48 
        res[k]=sum%10+48;
        carry=sum/10;
        i--;
        j--;
        k--;
    }
    
    if(i>=0)
    {
        while(i>=0)
        {
            sum=a[i]-48+carry;
            res[k]=sum%10+48;
            carry=sum/10;
            i--;
            k--;
        }
    }
    else if(j>=0)
    {
      while(j>=0)
        {
            sum=b[j]-48+carry;
            res[k]=sum%10+48;
            carry=sum/10;
            j--;
            k--;
        }  
    }
    
    if(carry>0)
    {
    	printf("\nAddition of the two BigInt=%d%s\n",carry,res);
	}
	else
	{
		printf("\nAddition of the two BigInt=%s\n",res);
	}
    
	
};

int isSmaller(char str1[],char str2[])
{
    int n1 = strlen(str1), n2 = strlen(str2),i;
 	if (n1 < n2)
        return 1;
    if (n2 < n1)
        return 0;
     
    for ( i = 0; i < n1; i++)
        if (str1[i] < str2[i])
               return 1;
        else if (str1[i] > str2[i])
               return 0;
     
        return 0;
}

void sub()
{
	
    char s[1024],t[1024];
    printf("\nEnter the first very long Integer\n");
    scanf("%s",s);
    printf("\nEnter the second very long Integer\n");
    scanf("%s",t);
    
    if (isSmaller(s,t))
    {
        char temp[1024];
        strcpy(temp,s);
        strcpy(s,t);
        strcpy(t,temp);
    }

	char res[1025];
 	int l1 = strlen(s), l2 = strlen(t),i,k,j,borrow=0,sub=0;
 	k=l1;
    res[k]='\0';
    k--;
    i=l1-1;
    j=l2-1;
    
    while(i>=0 && j>=0)
    {
        sub=(s[i]-48)-(t[j]-48)-borrow;//ascii value of 0=48 
        if (sub < 0) 
		{
            sub = sub + 10;
            borrow = 1;
        }
        else
        {
        	borrow = 0;
		}
        res[k]=sub+48;
        i--;
        j--;
        k--;
    }
    
    if(i>=0)
    {
        while(i>=0)
        {
            sub=s[i]-48-borrow;
            if (sub < 0)
			{
            	sub = sub + 10;
            	borrow = 1;
        	}
        	else
        	{
        		borrow = 0;
			}
        	res[k]=sub+48;
        	i--;
        	k--;
        }
    }
    
    printf("\nSubtraction of the two BigInt=%s\n",res);
}

void multiply()
{
	
	char p[1024],q[1024];
	int n1,n2;
	
	printf("\nEnter the first very long 1024 intbit Integer:\n");
    scanf("%s",p);
    printf("\nEnter the second very long 1024 intbit Integer:\n");
    scanf("%s",q);
    n1=strlen(p);
    n2=strlen(q);
	
    char res[2048];
    if(*p=='0'||*q=='0')
    {
    	printf("0");
    	return ;
	}
	int i,j;
    int num[n1+n2];
    
    for(i=0;i<n1+n2;i++)
    {
        num[i]=0;
    }
        
    for (i =n1-1; i >= 0; --i)
	 {
        for (j =n2-1; j >= 0; --j)// multiply for each digit
		{
            num[i + j + 1] += (p[i] - 48) * (q[j] - 48);//ascii value of 0=48 
            num[i + j] += num[i + j + 1] / 10;
            num[i + j + 1] %= 10;
        }
    }
        
    i = 0;
    while (i < n1+n2 && num[i] == 0) 
    {
        i++;
    }
        
    int index=0;
    while (i<n1+n2) 
    {
        res[index++]=num[i++] + 48;
    }
        
  	printf("\nMultiplication of the two BigInt=%s\n",res);
}


int main()
{
	int choice=0,run=1,n1=0,n2=0;

    while(run!=0)
	{
	
    printf("\npress: \t1 to add numbers \t2 to subtract numbers \t3 to multiply numbers\n\nchoice: ");
	scanf("%d",&choice);
    switch(choice)
    {
    	case 1:
    		add();
    		break;
    	case 2:
    		sub();
    		break;
    	case 3:
    		multiply();
    		break;
    	
    	default:
		   printf("wrong argument try next time\n");
		   break;		
	}
	printf("\npress 0 to exit 1 to continue:");
    scanf("%d",&run);
	}
	
	return 0;
}

