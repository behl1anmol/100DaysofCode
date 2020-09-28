/*class UserMainCode{
    static int findTwoDigitRSF(int input1){
        while(input1 > 99)
            input1 = reduce(input1);
        return input1;
    }

    static int reduce(int value) {
        return (value <= 9 ? 0 : reduce(value / 10) * 10 + Math.abs(value / 10 % 10 - value % 10));
    }
}*/
import java.io.*;
import java.util.*;
class UserMainCode{
    public static String processWords(String input1,int input2){

        String[] s = input1.split(" ");

        String a = s[(input2%10)-1];
        System.out.println(a);
        String b = s[(input2/10)-1];
        System.out.println(b);

        int mida = (int)Math.ceil((double)a.length()/2);
        System.out.println(mida);
        int midb = (int)Math.ceil((double)b.length()/2);
        System.out.println(midb);
        String ans = new String();
        

        for (int i=midb-1;i>=0;i--){
            ans = ans + b.charAt(i);
        }
        System.out.println(ans);
        for(int i=midb;i<b.length();i++){
            ans = ans + b.charAt(i);
        }
        ans = ans + " ";
        for (int i=mida-1;i>=0;i--){
            ans = ans + a.charAt(i);
        }
        for(int i=mida;i<a.length();i++){
            ans = ans + a.charAt(i);
        }

        return ans;

    }
    public static void main(String[] arg) 
    { 
        int n = 41;
        String s = "Today is a nice day" ;
  
        // Passing n to RSF function and getting answer 
        
        String ans = processWords(s,n);
        // Printing the value stored in ans 
        System.out.println(ans); 
    } 
}