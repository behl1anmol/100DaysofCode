import java.io.*;
import java.util.*;

class Main{
    
    public int findPassword(int input1, int input2, int input3, int input4, int input5){
        int maximum=-1, minimum=-1;
        boolean accounted = false;
        boolean isStable1 = true, isStable2 = true, isStable3=true, isStable4=true, isStable5=true;
        int a=input1, b=input2, c=input3, d=input4, e=input5;
        int hash[]=new int[10];
        while(a!=0){
            int dig = a%10;
            hash[dig]++;
            a/=10;
        }
        int count = 0;
        for(int i=0;i<10;i++){
            if(hash[i]!=0 && count==0) count = hash[i];
            if(hash[i]!=count && hash[i]!=0) isStable1=false;
        }
        
        for(int i=0;i<10;i++) hash[i]=0; count = 0;
        
        while(b!=0){
            int dig = b%10;
            hash[dig]++;
            b/=10;
        }
        for(int i=0;i<10;i++){
            if(hash[i]!=0 && count==0) count = hash[i];
            if(hash[i]!=count && hash[i]!=0) isStable2=false;
        }
        
        for(int i=0;i<10;i++) hash[i]=0; count = 0;
        
        while(c!=0){
            int dig = c%10;
            hash[dig]++;
            c/=10;
        }
        for(int i=0;i<10;i++){
            if(hash[i]!=0 && count==0) count = hash[i];
            if(hash[i]!=count && hash[i]!=0) isStable3=false;
        }
        
        for(int i=0;i<10;i++) hash[i]=0; count = 0;
        
        while(d!=0){
            int dig = d%10;
            hash[dig]++;
            d/=10;
        }
        for(int i=0;i<10;i++){
            if(hash[i]!=0 && count==0) count = hash[i];
            if(hash[i]!=count && hash[i]!=0) isStable4=false;
        }
        
        for(int i=0;i<10;i++) hash[i]=0; count = 0;
        
        while(e!=0){
            int dig = e%10;
            hash[dig]++;
            e/=10;
        }
        for(int i=0;i<10;i++){
            if(hash[i]!=0 && count==0) count = hash[i];
            if(hash[i]!=count && hash[i]!=0) isStable5=false;
        }
        
        if(isStable1){
            if(accounted && input1>maximum){
                maximum=input1;
            }
            if(accounted && input1<minimum){
                minimum=input1;
            }
            if(!accounted){maximum = input1; minimum=input1; accounted=true;}
        }
        if(isStable2){
            if(accounted && input2>maximum){
                maximum=input2;
            }
            if(accounted && input2<minimum){
                minimum=input2;
            }
            if(!accounted){maximum = input2; minimum=input2; accounted=true;}
        }
        if(isStable3){
            if(accounted && input3>maximum){
                maximum=input3;
            }
            if(accounted && input3<minimum){
                minimum=input3;
            }
            if(!accounted){maximum = input3; minimum=input3; accounted=true;}
        }
        if(isStable4){
            if(accounted && input4>maximum){
                maximum=input4;
            }
            if(accounted && input4<minimum){
                minimum=input4;
            }
            if(!accounted){maximum = input4; minimum=input4; accounted=true;}
        }
        if(isStable5){
            if(accounted && input5>maximum){
                maximum=input5;
            }
            if(accounted && input5<minimum){
                minimum=input5;
            }
            if(!accounted){maximum = input5; minimum=input5; accounted=true;}
        }
        return maximum-minimum;
    }
    public static void main(String[] args){
        Main u= new Main();
        System.out.println(u.findPassword(12,1313,122,678,898));

    }
}