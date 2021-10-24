package prac03_02;

public class Print2DArray_20164269 {

    public static void main(String[] args) {
        int n[][] = {{1}, {1,2,3}, {1}, {1,2,3,4}, {1,2}};
        int i,j;
       
        for(i=0;i<n.length;i++) {
            for(j=0;j<n[i].length;j++) {
                System.out.print(n[i][j] + "\t");
            }
            System.out.println();
        }
    }
}