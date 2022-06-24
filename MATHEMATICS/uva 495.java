
import java.math.BigInteger;
import java.util.*;
public class Main {

    public static void main(String[] args) {
	// write your code here
        Scanner sc= new Scanner(System.in);//System.in is a standard input stream
        BigInteger[] series = new BigInteger[5010];
        series[0]=BigInteger.ZERO;
        series[1]=BigInteger.ONE;
        for(int i=2;i<=5000;i++){
            series[i]=series[i-2].add(series[i-1]);
        }
        while (sc.hasNext()) {
            int a=sc.nextInt();
             System.out.println("The Fibonacci number for "+a+" is " +series[a]);
        }
    }


}
