import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        //3x5 + 5x3 = n;
        if(n%3==0){
            for(int i=0;i<n;i++) System.out.print(5);
        }else if(n%5==0){
            for (int i = 0; i < n; i++) {
                System.out.print(3);
            }
        }
        else{
            long temp = n;
            boolean there = false;
            long g = 3;
            long num = Long.MAX_VALUE;
            while(temp>0){
                temp-=g;
                if(temp>0&&temp%5==0){
                    there = true;
                    num = temp;
                }
                
            } 
            g = 5;
            temp = n;
            while(temp>0){
                temp-=g;
                if(temp>0&&temp%3==0){
                    there = true;
                    num = Math.min(num, temp);
                }
            }  
            System.out.println(there+","+num);
            if(there){
                for(int i=0;i<(n-num);i++) System.out.print(5);
                for(int i=0;i<(num);i++) System.out.print(3);   
            }
            else{
                System.out.print(-1);
            }
            sc.close();
        }
    }
}
