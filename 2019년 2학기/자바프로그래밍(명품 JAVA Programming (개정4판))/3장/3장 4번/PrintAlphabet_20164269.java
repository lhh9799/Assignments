package prac03_04;
import java.util.Scanner;

public class PrintAlphabet_20164269 {
    public static void main(String[] args) {
       
        Scanner scanner = new Scanner(System.in);
        System.out.print("소문자 알파벳 하나를 입력하시오>>");
        String s = scanner.next();

        if(s.length() != 1) { // 문자열 s 길이 s.length(){
            System.out.println("문자하나만 입력");
            scanner.close();
            //return ;
        }
        
        char c = s.charAt(0);
        if((c<'a') || (c>'z'))
        {
            System.out.print("소문자 알파벳이 아닙니다.");
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