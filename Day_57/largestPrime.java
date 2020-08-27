import java.util.*; 

class largestPrime { 
public int seiveOfErathones(int a[], int size) 
{ 

	int maxElement = Arrays.stream(a).max().getAsInt(); 
	boolean vectorSeive[] = new boolean[maxElement+1]; 
		for(int i= 0;i<maxElement+1;i++) 
            vectorSeive[i] = true; 
	for (int i = 2; i * i <= maxElement; i++) { 
		if (vectorSeive[i] == true) { 
			for (int j = i * 2; j <= maxElement; j += i) 
                vectorSeive[j] = false; 
		} 
	} 

	int maximumPrimeNumber = Integer.MIN_VALUE; 
	for (int i = 0; i < size; i++) 
		if (vectorSeive[a[i]]) { 
			    maximumPrimeNumber = Math.max(maximumPrimeNumber, a[i]); 
		} 

	return maximumPrimeNumber; 
} 

	public static void main(String[] args) { 

        Scanner ip = new Scanner(System.in);
        String str = ip.nextLine();
        String[] strArray = str.split(",");
        int[] a = new int[strArray.length];
        for(int i = 0; i < strArray.length; i++) {
            a[i] = Integer.parseInt(strArray[i]);
        }


        int n = a.length;
        /*for(int i = 0; i < n;i++){
            System.out.println(a[i]);
        }*/
        largestPrime lp = new largestPrime();
        
    int e = lp.seiveOfErathones(a,n);
    System.out.println(e); 
	} 
} 
