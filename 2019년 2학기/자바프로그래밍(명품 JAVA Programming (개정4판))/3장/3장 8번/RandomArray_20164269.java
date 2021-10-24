package prac03_08;
import java.util.Scanner;

public class RandomArray_20164269 {

	public static boolean exists(int a[], int to, int r) {
		for (int j=0; j<to; j++)
			if (a[j] == r)
				return true; //a[j]�� r�� ���� ���
			return false; //������ ���� �ϳ��� ���� ���
	}
	
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("���� �?");
		int n = scanner.nextInt();
		
		if((n<1) || (n>100)) {
				System.out.print("1~100���̷� �Է��ϼ���!");
				scanner.close();
				return;
		}
		
		int array [] = new int [n]; //�������� �迭 ����
		
		for(int i=0; i<array.length; i++) //�迭 �ʱ�ȭ	
			array[i] = 0;
		
		for (int i=0; i<array.length; i++) {
			int r = (int)(Math.random()*100 + 1);
			
			if (exists(array, i, r)) {
				i--; //������ ���� ���� ��� i�� ����
			continue;
			}
			array[i] = r; // r�� array[i]�� ����
		}
		for (int i=0; i<array.length; i++) {
			System.out.print(array[i]+" ");
			if((i+1)%10 == 0) //�迭�� ���� 10�̻��� ��� 10���� ��� �� �ٹٲ�
				System.out.println();
		}
		scanner.close();
	}
}