package prac06_08;
import java.util.Scanner;

public class StringRotate_20164269 {
	public static void main(String[] args) {
		System.out.print("���ڿ��� �Է��ϼ���. �� ĭ�� �־ �ǰ� ���� �ѱ� ��� �˴ϴ�.");
		
		Scanner scanner = new Scanner(System.in);
		String text = scanner.nextLine();
		
		int len = text.length();
		for (int i=0; i<len; i++) {
			String first = text.substring(0, 1); //text�� ù ���ڸ� �����Ͽ� ����
			String last = text.substring(1); //text�� �� ��° ���ں��� ���������� �����Ͽ� ���� 
			text = last + first;
			System.out.println(text);
		}
		scanner.close();
	}
}