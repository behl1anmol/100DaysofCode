import java.util.Scanner;
public class UserMainCode
{
    public int findKey(int a, int b, int c){
        if(a>=b && a>=c) return a;
        else if(b>=a && b>=c) return b;
        else return c;
    }
	public static void main(String[] args) {
	    Scanner sc = new Scanner(System.in);
	    int a = sc.nextInt();
	    int b = sc.nextInt();
	    int c = sc.nextInt();
	    sc.close();
	    UserMainCode mainobj = new UserMainCode();
	    String passcode = "";
	    for(int i=0;i<4;i++){
	        passcode=mainobj.findKey(a%10, b%10, c%10)+passcode;
	        a/=10;b/=10;c/=10;
	    }
	    System.out.println(passcode);
	}
}