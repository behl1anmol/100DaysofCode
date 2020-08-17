import java.net.*; 
import java.io.*; 
import java.util.*; 
import java.net.InetAddress; 
public class Subnetting {
    public static long ipToLong(InetAddress ip) {
        byte[] octets = ip.getAddress();
        long result = 0;
        for (byte octet : octets) {
            result <<= 8;
            result |= octet & 0xff;
        }
        return result;
    }

    public static void main(String[] args) throws UnknownHostException {
        Scanner Input = new Scanner(System.in);
        int t;
        int q;

        t=Input.nextInt();
        q=Input.nextInt();

        ArrayList<String>ipl = new ArrayList<String>();
        ArrayList<String>iph = new ArrayList<String>();
        ArrayList<String>loc = new ArrayList<String>();

        Input.nextLine();
        for(int i=0;i<t;i++){
            String l = Input.nextLine();
            String[] s = l.split(" ");
            String location = s[2];
            String ip1 = s[0].split("/")[0];
            String ip2 = s[1].split("/")[0];

            ipl.add(ip1);
            iph.add(ip2);
            loc.add(location);
            
        }
        Input.nextLine();
        for (int j=0;j<q;j++){
            String ipt = Input.nextLine();
            //System.out.println("inside second for");
            int flag = 0;

            for(int i=0;i<t;i++){
            long ipLo = ipToLong(InetAddress.getByName(ipl.get(i)));
            long ipHi = ipToLong(InetAddress.getByName(iph.get(i)));
            long ipToTest = ipToLong(InetAddress.getByName(ipt));

            if((ipToTest >= ipLo && ipToTest <= ipHi)){
                System.out.println(loc.get(i));
                flag=1;
                break;
                }   
            }
            if(flag==0){
                System.out.println("None");
            }
        }
    }
}