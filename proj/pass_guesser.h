//“猜密码-检查十进制数的二进制有多少个1，猜几次（包含多少种情况）”
import java.util.Scanner;
public class Main {

      public static void main(String[] args){

            Scanner in = new Scanner(System.in);
            int l = 0,r = 0,m = 0;
            int count = 0;
            if (in.hasNext()) {
                  l = in.nextInt();
                  r = in.nextInt();
                  m = in.nextInt();
            }

            if (l > r)
                  count = -1;
            for (int i = l; i <= r; i++) {
                  if (checkOne(i,m))
                        count++;
                  //System.out.println("count:" + count);
            }
            if (count == 0)
                  count = -1;
            System.out.println("" + count);
      }

      public static boolean checkOne(int n, int m){
            while (n != 0) {
                  if ((n&1) == 1)
                        m--;
                  n = n >> 1;
            }
            //System.out.println("m:" + m);
            if (m == 0)
                  return true;
            else
                  return false;
      }
}

