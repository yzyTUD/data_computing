
import java.util.Scanner;

public class Main {

        /**
         * @param args
         */
        public static void main(String[] args) {
                Main m=new Main();
//         System.out.println(m.getPrice(9));
                Scanner sc=new Scanner(System.in);
                while(sc.hasNextInt()){
                        int a=sc.nextInt();
                        System.out.println(m.getPrice(a));
                }

        }

        public  int getPrice(int n){
                if(n==1)
                        return 1;
                if(n==2)
                        return 2;
                if(n==3)
                        return 1;

                int c=1;
                int j=1;//周期
                int price=1;
                while(c<n){

                        for(int i=0;i<j;i++){
                                price++;
                                c++;
//                         System.out.println(c+":"+price);
                                if(c==n)
                                        return price;
                        }
                        price--;
                        c++;
//                 System.out.println(c+":"+price);
                        if(c==n)
                                return price;
                        j++;

                }

                return price;

        }

}

