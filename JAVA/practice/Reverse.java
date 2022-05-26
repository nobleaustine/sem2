import java.util.*;  
    class Reverse   
    {  
    public static void main(String[] args)  
    {  
    Scanner sc= new Scanner(System.in);     
    System.out.println("Enter any integer - ");  
    int a= sc.nextInt(); 
    int b=a;
    int sum=0;
    int rem=0;
    int count=0;
    
    while(b%10==0){
    b=b/10;
    count=count+1;
    }
    while(a!=0){
         rem=a%10;
         sum=sum*10+rem;
         a=a/10;
    }
    while(count!=0){
    System.out.print(0);
    count=count-1;
    }
    System.out.println(sum);
    }
    }