package prac06_08;
import java.util.Scanner;

public class StringRotate_20164269 {
	public static void main(String[] args) {
		System.out.print("문자열을 입력하세요. 빈 칸이 있어도 되고 영어 한글 모두 됩니다.");
		
		Scanner scanner = new Scanner(System.in);
		String text = scanner.nextLine();
		
		int len = text.length();
		for (int i=0; i<len; i++) {
			String first = text.substring(0, 1); //text의 첫 글자를 발췌하여 저장
			String last = text.substring(1); //text의 두 번째 글자부터 마지막까지 발췌하여 저장 
			text = last + first;
			System.out.println(text);
		}
		scanner.close();
	}
}