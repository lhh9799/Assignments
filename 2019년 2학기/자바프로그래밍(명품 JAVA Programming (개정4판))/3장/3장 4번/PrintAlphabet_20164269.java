package prac03_04;
import java.util.Scanner;

public class PrintAlphabet_20164269 {
    public static void main(String[] args) {
       
        Scanner scanner = new Scanner(System.in);
        System.out.print("�ҹ��� ���ĺ� �ϳ��� �Է��Ͻÿ�>>");
        String s = scanner.next();

        if(s.length() != 1) { // ���ڿ� s ���� s.length(){
            System.out.println("�����ϳ��� �Է�");
            scanner.close();
            //return ;
        }
        
        char c = s.charAt(0);
        if((c<'a') || (c>'z'))
        {
            System.out.print("�ҹ��� ���ĺ��� �ƴմϴ�.");
            scanner.close();
        }
        for(char i=c; i>='a'; i--) {
            for(char j='a';j<=i;j++)
                System.out.print(j);
            System.out.println();
        }
        scanner.close();
    }
}