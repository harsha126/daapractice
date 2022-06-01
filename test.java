import java.util.*;
public class test{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of Array : ");
        int n = sc.nextInt();
        System.out.println("Enter the no of bricks : ");
        int k = sc.nextInt();
        int[] arr = new int[k];
        for(int i = 0;i<k;i++) arr[i] = sc.nextInt();
        System.out.println("enter the gap");
        int g = sc.nextInt();
        check(arr,new int[k],new int[k],n,0,g,k,new boolean[k]);
        sc.close();
    }

    public static void check(int[] arr,int[] pal,int[] temp,int n,int idx,int gap,int k,boolean[] visited){
        for(int i=0;i<k;i++){
            if(!visited[i]){
                visited[i] = true;
                for(int j=idx;j<n;j++){
                    temp[i] = arr[k];
                    pal[i] = idx;
                    
                }
            }
        }
    }

}